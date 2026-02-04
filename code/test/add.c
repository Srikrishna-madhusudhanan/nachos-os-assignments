/* add.c
 *	Simple program to test whether the systemcall interface works.
 *
 *	Just do a add syscall that adds two values and returns the result.
 *
 */

#include "syscall.h"

int main() {
    int result;

    // result = Add(42, 23);

    int i, j;
    for(i=0; i<10000; i++)
    {
	    for(j=0; j<20000; j++)
	    {
		    PrintString("Child");
		    PrintString("\n");
	    }
    }


    Halt();
    /* not reached */
}
