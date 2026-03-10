#include "syscall.h"

#define ConsoleOutput 1

int main()
{
    char buf[20];
    int i;

    Read(buf,20,0);

    for(i=0;i<20;i++)
    {
        if(buf[i] >= 'a' && buf[i] <= 'z')
            buf[i] = buf[i] - 32;
    }

    Write(buf,20,ConsoleOutput);

    Exit(0);
}
