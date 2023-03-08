CC=cc

SDIR = ./src/
ODIR = ./obj/
CFLAGS=-I${IDIR}
LFLAGS=-L${LDIR}

demos: blink

blink:   ${SDIR}blink.c
	$(CC) -static -c ${SDIR}blink.c -o ${ODIR}blink.o
	$(CC) -o blink ${ODIR}blink.o

.PHONY: all clean

clean:
	rm -f ${LDIR}*.a
