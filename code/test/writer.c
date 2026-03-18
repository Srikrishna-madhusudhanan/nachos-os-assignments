#include "syscall.h"

#define ConsoleInput 0
#define ConsoleOutput 1

int main()
{
    char msg[100];
    int n;
    int len;

    Write("Enter length of message: ",25,ConsoleOutput);
    len = ReadNum();

    Write("Enter message: ",15,ConsoleOutput);

    n = Read(msg,len,ConsoleInput);

    /* send length first */
    WritePipe((char*)&len, sizeof(int));
    
    WritePipe(msg,n);   // send actual bytes

    Exit(0);
}
