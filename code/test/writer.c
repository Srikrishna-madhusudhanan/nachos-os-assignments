#include "syscall.h"

#define ConsoleInput 0
#define ConsoleOutput 1

int main()
{
    char msg[20];

    Write("Enter message: ",15,ConsoleOutput);

    Read(msg,20,ConsoleInput);

    Write(msg,20,1);   // write to pipe (fd=1 if write descriptor)

    Exit(0);
}
