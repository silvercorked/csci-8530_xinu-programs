
#include <xinu.h>

// prints out the 32 bit addresses of the start and end of the
// text segment
// data segment
// and bss segment
// of the compiled xinu program
void printsegaddress() {
	// from /include/memory.h
	// extern int text; // start of text segment
	// extern int etext; // end of text segment
	// extern int data; // start of data segment
	// extern int edata; // end of data segment
	// extern int bss; // start of bss segment
	// extern int ebss; // end of bss segment
	// extern int end; // end of program
	kprintf(
		"\ttext: 0x%08x - 0x%08x (%u bytes)\n",
		(uint32) &text,
		(uint32) &etext - 1,
		((uint32) &etext) - (uint32) &text
	);
	kprintf(
		"\tdata: 0x%08x - 0x%08x (%u bytes)\n",
		(uint32) &data,
		(uint32) &edata - 1,
		((uint32) &edata) - (uint32) &data
	);
	kprintf(
		"\tbss: 0x%08x - 0x%08x (%u bytes)\n",
		(uint32) &bss,
		(uint32) &ebss - 1,
		((uint32) &ebss) - (uint32) &bss
	);

	return;
}
