/* add.c
 *	Simple program to test whether the systemcall interface works.
 *
 *	Just do a add syscall that adds two values and returns the result.
 *
 */

#include "syscall.h"

int main() {
    int result;
/*
    int x = -23;
    result = Abs(x);

    PrintNum(result);
    PrintString("\n");
*/
    int i, j;
    for(i=0; i<10; i++)
    {
	    for(j=0; j<20; j++)
	    {
		    PrintString("Abs");
		    PrintString("\n");
	    }
    }


    //Halt();
    /* not reached */
}
