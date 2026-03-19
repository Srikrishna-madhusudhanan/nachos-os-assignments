#include "syscall.h"

int main() {
    PrintNum(1);
    PrintString("Going to sleep: ");
    Sleep2(4); // 4 means 4000 ticks
    PrintNum(2);
    PrintString("\n");
    PrintString("Woke up from sleep!");
    Exit(0);
}
