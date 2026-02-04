/* exec.c
 *	Simple program to test the exec system call.
 */

#include "syscall.h"
#define stdin 0
#define stdout 1

int main() {
    int pid;
    int pid2;
    int pid3;
    pid = Exec2("../test/mul", 9);
    pid2 = Exec2("../test/add", 5);
    pid3 = Exec2("../test/abs", 12);
    if (pid < 0) {
        Write("Exec failed: ", 14, stdout);
        PrintNum(pid);
    } else{
	int i, j;
	for(i=0; i<10; i++)
	{
		for (j=0; j< 2; j++)
		{
		PrintString("Parent iteration ");
		PrintNum(i);
		PrintString("\n");
		}	

	}
       Join(pid);
       Join(pid2);
       Join(pid3);
       
    }
}
