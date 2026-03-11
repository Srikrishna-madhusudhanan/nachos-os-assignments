#include "syscall.h"

#define ConsoleOutput 1

int main()
{
    char buf[100];
    int i,n;

    n = ReadPipe(buf,100);

    for(i=0;i<n;i++)
    {
        if(buf[i] >= 'a' && buf[i] <= 'z')
            buf[i] = buf[i] - 32;
    }

    Write(buf,n,ConsoleOutput);

    Exit(0);
}
