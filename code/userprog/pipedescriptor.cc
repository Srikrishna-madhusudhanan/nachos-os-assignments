#include "pipedescriptor.h"
#include <cstddef>

PipeDescriptor* pipeTable[MAX_PIPE_DESCRIPTORS] = {NULL};
//PipeDescriptor *pipeTable = NULL;

int SysPipe(int *readfd, int *writefd)
{
    PipeBuffer *pipe = new PipeBuffer();

    int r = -1;
    int w = -1;

    for(int i = 0; i < MAX_PIPE_DESCRIPTORS; i++)
    {
        if(pipeTable[i] == NULL)
        {
            if(r == -1)
                r = i;
            else
            {
                w = i;
                break;
            }
        }
    }

    if(r == -1 || w == -1)
        return -1;

    pipeTable[r] = new PipeDescriptor;
    pipeTable[w] = new PipeDescriptor;

    pipeTable[r]->type = DESC_PIPE;
    pipeTable[r]->role = PIPE_READ;
    pipeTable[r]->pipe = pipe;

    pipeTable[w]->type = DESC_PIPE;
    pipeTable[w]->role = PIPE_WRITE;
    pipeTable[w]->pipe = pipe;

    *readfd = r;
    *writefd = w;

    return 0;
}
