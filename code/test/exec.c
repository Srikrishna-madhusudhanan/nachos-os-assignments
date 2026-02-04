/* exec.c
 *	Simple program to test the exec system call.
 */

#include "syscall.h"
#define stdin 0
#define stdout 1

int main() {
    int pid;
    pid = Exec("../test/add");
    if (pid < 0) {
        Write("Exec failed: ", 14, stdout);
        PrintNum(pid);
    } else{
	int i, j;
	for(i=0; i<10000; i++)
	{
		for (j=0; j< 2000000; j++)
		{
		PrintString("Parent iteration ");
		PrintNum(i);
		PrintString("\n");
		}	

	}
       Join(pid);
       
    }
}
