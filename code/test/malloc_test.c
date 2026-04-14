#include "syscall.h"
#include "malloc.h"
int main() {
    char *p = malloc(100);
    char *q = malloc(50);
    
    if (p == 0 || q == 0) {
        PrintString("Allocation failed\n");
    }
    else{

    // Write to allocated memory
    p[0] = 'A';
    p[99] = 'Z';

    q[0] = 'B';
    q[49] = 'Y';

    PrintNum(p);
    PrintString("\n");
    PrintNum(q);

    free(p);
    free(q);

    PrintString("Free Successful\n");
    }

    Halt();
}
