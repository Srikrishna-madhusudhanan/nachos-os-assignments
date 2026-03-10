#ifndef PIPEDESCRIPTOR_H
#define PIPEDESCRIPTOR_H

#define MAX_PIPE_DESCRIPTORS 64
#define PIPE_BUFFER_SIZE 256

enum DescriptorType {
    DESC_FILE,
    DESC_PIPE
};

enum PipeRole {
    PIPE_READ,
    PIPE_WRITE
};

struct PipeBuffer {
    char buffer[PIPE_BUFFER_SIZE];
    int readPos;
    int writePos;
    int size;

    PipeBuffer() {
        readPos = 0;
        writePos = 0;
        size = 0;
    }
};

struct PipeDescriptor {
    DescriptorType type;
    PipeRole role;
    PipeBuffer *pipe;
};

extern PipeDescriptor* pipeTable[MAX_PIPE_DESCRIPTORS];

int SysPipe(int *readfd, int *writefd);

#endif
