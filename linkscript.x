SEARCH_DIR (/home/lynxis/projects/coreboot/h8s/h8300-toolchain-builder/install/h8300-elf/lib)
OUTPUT_FORMAT("srec")
OUTPUT_ARCH(h8300:h8300s)
ENTRY(_startp)


MEMORY
{
	rom (rx) : ORIGIN = 0x0, LENGTH = 128K
	ram (!rx): ORIGIN = 0xffe080, LENGTH = 3968
	tiny (!rx): ORIGIN = 0xffff00, LENGTH = 128
}

SECTIONS 
{
	.vectors 0x0 : { *(.vectors) } >rom
	.text 0x200 : {
		*(.text);
		*(.rodata);
		_etext = ALIGN(32);
	} >rom

	.data : {
		_data = .;
		*(.data);
		_edata = .;
	} >ram AT>rom

	.bss : {
		_bss = .;
		*(.bss);
		_ebss = .;
	} >ram

	.stack : {
		_stack_last = .;
		. += 0x80;
		_stack = .;
		_stack_first = .;
		*(.stack)
	} >ram
}
