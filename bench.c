#include <sys/time.h>
#include <inttypes.h>
#include <string.h>
#include <errno.h>
#include "svsnprintf.c"

void
main(int argc, char **argv)
{
	char buf[1024], *ptr;
	unsigned int i;
	int us, s, cnt;
	struct timeval tv1, tv2;
	double f;

	if (argc != 2) {
		fprintf(stderr, "Usage: %s COUNT\n", argv[0]);
		exit(0);
	}
	errno = 0;
	cnt = strtol(argv[1], &ptr, 10);
	if (errno != 0) {
		fprintf(stderr, "COUNT is wrong: $s\n", strerror(errno));
		exit(1);
	}
	if (*ptr != '\0') {
		fprintf(stderr, "COUNT must be a positive number\n");
		exit(1);
	}
	if (cnt < 0) {
		fprintf(stderr, "COUNT must be a positive number\n");
		exit(1);
	}

	printf("svsnprintf: ");
	f = 1.002121970718271e+05;
	gettimeofday(&tv1, NULL);
	for (i = 0; i < cnt; i++) {
		ssnprintf(buf, 1024, "%f\n", f);
		i++;
		f += i;
	}
	gettimeofday(&tv2, NULL);
	s = tv2.tv_sec - tv1.tv_sec;
	us = tv2.tv_usec - tv1.tv_usec;
	if (us < 0) {
		s--;
		us = 1000000 - us;
	}
	printf("%u %%f formatting during %u.%u seconds\n", cnt, s, us);

	printf("printf: ");
	f = 1.002121970718271e+05;
	gettimeofday(&tv1, NULL);
	for (i = 0; i < cnt; i++) {
		snprintf(buf, 1024, "%f\n", f);
		i++;
		f += i;
	}
	gettimeofday(&tv2, NULL);
	s = tv2.tv_sec - tv1.tv_sec;
	us = tv2.tv_usec - tv1.tv_usec;
	if (us < 0) {
		s--;
		us = 1000000 - us;
	}
	printf("%u %%f formatting during %u.%u seconds\n", cnt, s, us);
}

