COPT   = -c -ms -Wall --std=c99
ASMOPT = -o

OBJ    = test.o common.o ringbuffer.o led.o sleep.o serial.o pmh4.o init.o main.o startup.o vectors.o isrhdl.o adc.o

AS := h8300-hms-as
GCC := h8300-hms-gcc
OBJCOPY := h8300-hms-objcopy
OBJDUMP := h8300-hms-objdump

blinkled.mot: blinkled
	$(OBJCOPY) -O srec blinkled blinkled.mot

blinkled: $(OBJ)
	$(GCC) -ms -nostdlib -T linkscript.x -o $@ $^

%.o: %.c
	$(GCC) ${COPT} $<

%.o: %.s
	$(AS) ${ASMOPT} $@ $<

clean:
	rm -f blinkled blinkled.srec *.o
