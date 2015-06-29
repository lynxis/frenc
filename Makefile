COPT   = -c -ms -mint32 -Wall --std=c99
ASMOPT = -o

OBJ    = main.o startup.o vectors.o isrhdl.o

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
