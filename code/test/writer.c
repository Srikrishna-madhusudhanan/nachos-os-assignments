#include "syscall.h"

#define ConsoleInput 0
#define ConsoleOutput 1

int main()
{
    char msg[20];
    int n;

    Write("Enter message: ",15,ConsoleOutput);

    n = Read(msg,5,ConsoleInput);

    WritePipe(msg,n);   // send only actual bytes

    Exit(0);
}
