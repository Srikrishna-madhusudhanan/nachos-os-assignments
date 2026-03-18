#include "syscall.h"

#define ConsoleOutput 1

int main()
{
    char buf[100];
    int i,n;

    //n = ReadPipe(buf,100);

    /* read length first */
    ReadPipe((char*)&n, sizeof(int));

    /* then read exactly n bytes */
    ReadPipe(buf, n);

    for(i=0;i<n;i++)
    {
        if(buf[i] >= 'a' && buf[i] <= 'z')
            buf[i] = buf[i] - 32;
    }

    Write(buf,n,ConsoleOutput);
    PrintString("\n");

    Exit(0);
}
