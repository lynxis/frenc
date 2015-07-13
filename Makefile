COPT   = -c -ms -Wall --std=c99
ASMOPT = -o

OBJ    = sleep.o serial.o pmh4.o main.o startup.o vectors.o isrhdl.o adc.o

AS := h8300-hms-as
GCC := h8300-hms-gcc
OBJCOPY := h8300-hms-objcopy

blinkled: $(OBJ)
	$(GCC) -ms -nostdlib -T linkscript.x -o $@ $^

%.o: %.c
	$(GCC) ${COPT} $<

%.o: %.s
	$(AS) ${ASMOPT} $@ $<

clean:
	rm -f blinkled blinkled.srec *.o
