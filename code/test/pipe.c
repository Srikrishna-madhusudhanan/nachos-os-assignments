#include "syscall.h"

int main()
{
    int r, w;
    int p1;
    int p2;

    Pipe(&r, &w);

    p1 = ExecPipe("../test/writer", r, w);
    Join(p1);

    p2 = ExecPipe("../test/upper", r, w);
    Join(p2);

    Exit(0);
}
