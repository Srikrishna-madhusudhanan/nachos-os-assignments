#include "syscall.h"

int main()
{
    int r, w;

    Pipe(&r, &w);

    ExecPipe("../test/writer", r, w);
    ExecPipe("../test/upper", r, w);

    Exit(0);
}
