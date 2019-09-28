// lab paper 1, practice file, string based question paper, client side

#include"headers.h"

int main(void)
{
    int id;
    struct msgbuf v;
    printf("Enter the string: \n");
    scanf(" %[^\n]", v.data);
    v.mtype = 1;
    id = msgget(4, IPC_CREAT|0664);
    if(id < 0)
    {
        perror("msgget");
        return 0;
    }
    printf("id = %d \n", id);
    msgsnd(id, &v, strlen(v.data)+1, 0);
    perror("msgsnd");
    printf("The output string is: \n");
    msgrcv(id, &v, sizeof(v), 2, 0);
    perror("msgrcv");
    printf(" %s \n", v.data);
    return 0;
}
