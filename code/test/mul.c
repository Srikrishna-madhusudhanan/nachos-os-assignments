/* add.c
 *	Simple program to test whether the systemcall interface works.
 *
 *	Just do a add syscall that adds two values and returns the result.
 *
 */

#include "syscall.h"

int main() {
    int result;

    result = Mul(42, 2);
    PrintNum(result);
    PrintString("\n"); 

    Halt();
    /* not reached */
}
