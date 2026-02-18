#include "syscall.h"


void getcmd1(char buffer[], char arg1[], int pipeloc)
{
	int i;
	for(i=0; i< pipeloc; i=i+1)
	{
		arg1[i] = buffer[i];
	}
}

void getcmd2(char buffer[], char arg2[], int pipeloc, int endindex)
{
	int j;
	int i;
	i=0;
	for(j=pipeloc+1; j < endindex; j=j+1)
	{
		arg2[i++] = buffer[j];
	}
}

int main() {
    SpaceId newProc;
    OpenFileId input = _ConsoleInput;
    OpenFileId output = _ConsoleOutput;
    char prompt[2], ch, buffer[60];
    char arg1[60], arg2[60];
    int i;
    int j;
    int k;

    prompt[0] = '-';
    prompt[1] = '-';

    while (1) {
	int topipe = 0;
	int pipeloc = 0;
        Write(prompt, 2, output);

        i = 0;

        do {
           Read(&buffer[i], 1, input);
	  if (buffer[i] == '|')
	  {
		  topipe = 1;
		  pipeloc = i;
		  getcmd1(buffer, arg1, pipeloc);
	  } 

        } while (buffer[i++] != '\n');

        buffer[--i] = '\0';

	if(topipe)
	{
		getcmd2(buffer, arg2, pipeloc, i);
	}

        if (i > 0) {
	    PrintString("The buffer value is: " );
	    PrintString(buffer);
	    if (topipe)
	    {
		    PrintString(" and I found a pipe at char ");
		    PrintNum(pipeloc);
		    PrintString(", the commands are: ");
		    PrintString(arg1);
		    PrintString(" ");
		    PrintString(arg2);
		    PrintString("\n");

	    }
	    else{
            PrintString("\n");
            newProc = Exec(buffer);
            Join(newProc);
	    }
        }

	topipe = 0;
	pipeloc = 0;
    }
}
