CFLAGS = -Wall
LDFLAGS =


all: libsvsnprintf.a

tests:: tests.c svsnprintf.c
	gcc -o $@ $< $(LDFLAGS)

tests::
	./tests

clean-all: clean
	rm -f libsvsnprintf.a

clean:
	rm -f *.o

lib%.a: %.o
	$(AR) rvs $@ $^

%.o: %.c
	$(CC) -c -o $@ $(CFLAGS) $<
