
#include <xinu.h>

int stackdepth() {
	unsigned long* top_esp; // end of function (frame) stack
	unsigned long* top_ebp; // frame pointer
	struct procent* proc = &proctab[currpid];
	int depth = 0;
	asm("movl %%esp, %0":"=r"(top_esp)::);
	asm("movl %%ebp, %0":"=r"(top_ebp)::);
	
	while (top_esp < (unsigned long*) proc->prstkbase) {
		kprintf(
			"depth: %d, esp: 0x%08x, ebp: 0x%08x, stack frame size: %d bytes\n",
			++depth,
			top_esp,
			top_ebp,
			((uint32) top_ebp) - (uint32) top_esp
		);	
		top_esp = top_ebp; // move to next function
		// this technique from system/stacktrace.c
		// takes address (return address) (to prev function) and 
		top_ebp = (unsigned long*) *top_esp++; // jump to next frame pointer
		top_esp++;
		
	}

	return depth;
}

void stackdepthTestFunc3() {
	kprintf("In stackdepthTestFunc3, stack depth = %d\n", stackdepth());
}

void stackdepthTestFunc2() {
	kprintf("In stackdepthTestFunc2, stack depth = %d\n", stackdepth());
	stackdepthTestFunc3();
}

void stackdepthTestFunc1() {
	kprintf("In stackdepthTestFunc1, stack depth = %d\n", stackdepth());
	stackdepthTestFunc2();
}

