PROJECT := libsvsnprintf
TARGET_TYPE ?= liba
SOURCES := svsnprintf.c

include .proj.mk/c-proj.mk

bench: bench.c $(SOURCES)
	$(CC) -o $@ bench.c

install: $(TARGET)
	install -d $(D)/lib $(D)/include
	install -m 0444 $(TARGET) $(D)/lib
	install -m 0444 svsnprintf.h $(D)/include
