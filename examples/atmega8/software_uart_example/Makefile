# --
# Copyright (c) 2016, Lukasz Marcin Podkalicki <lpodkalicki@gmail.com>
# --

include ../mcu.in

PROGRAM_SRCS=\
        main.cpp

all:
	${CC} ${CFLAGS} -o ${TARGET}.o ${PROGRAM_SRCS} ${ATLIB_SRCS}
	${OBJCOPY} -j .text -j .data -O ihex ${TARGET}.o ${TARGET}.hex
	${LD} ${TARGET}.o -o ${TARGET}.elf
	${SIZE} -C --mcu=${MCU} ${TARGET}.elf

flash:
	${AVRDUDE} -p ${MCU} -c usbasp -U flash:w:${TARGET}.hex:i -F -P usb

fuse:
	$(AVRDUDE) -p ${MCU} -c usbasp -U hfuse:w:${FUSE_H}:m -U lfuse:w:${FUSE_L}:m

clean:
	rm -f *.o *.elf *.hex
