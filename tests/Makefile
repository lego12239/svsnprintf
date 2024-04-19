all: tests tests2
	for i in $?; do\
		echo "RUN $$i:";\
		./$$i;\
	done

tests2: tests2.c ../svsnprintf.c
	gcc -o $@ $< $(LDFLAGS)

tests: tests.c ../svsnprintf.c
	gcc -o $@ $< $(LDFLAGS)
