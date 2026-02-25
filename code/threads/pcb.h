#ifndef PCB_H
#define PCB_H

class PCB {
   private:
    Semaphore *joinsem;
    Semaphore *exitsem;
    Semaphore *multex;

    int exitcode;
    int numwait;

    Thread *thread;
    char filename[128];

   public:
    int parentID;
    int processID;
    PCB();
    PCB(int id);
    ~PCB();

    //added for assignment-4 pipe function
    char* pipeFileName;
    int pipeRole; //0 = read, 1= write

    int Exec(char *filename, int pid);
    int Exec2(char* filename, int pid, int priority);
    int GetID();
    int GetNumWait();

    void JoinWait();
    void ExitWait();
    void JoinRelease();
    void ExitRelease();

    void IncNumWait();
    void DecNumWait();

    void SetExitCode(int ec);
    int GetExitCode();

    void SetFileName(char *fn);
    char *GetFileName();
};

#endif
