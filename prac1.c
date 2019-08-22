#include"./yjsh/yjsh_hf.h"

int main()
{
    char *ptr[] = {"ls", "-l", "-i", NULL};
    execvp(ptr[0], ptr);
}