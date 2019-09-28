// lab paper set B, int array and strong num program, client side

#include"headers.h"

int main(void)
{
    int id, i;
    struct msgbuf v;
    printf("Enter 5 integers: \n");
    for(i = 0 ; i < 5 ; i++)
    {
        scanf(" %d", &v.data[i]);
    }
    v.mtype = 1;
    id = msgget(4, IPC_CREAT|0664);
    if(id < 0)
    {
        perror("msgget");
        return 0;
    }
    printf("id = %d \n", id);
    msgsnd(id, &v, sizeof(v.data), 0);
    perror("msgsnd");
    msgrcv(id, &v, sizeof(v), 2, 0);
    perror("msgrcv");
    if(v.data[0] == 0)
    {
        printf("No strong numbers...\n");
        return 0;
    }
    else
    {
        printf("Strong numbers are: \n");
        for(i = 0; (v.data[i]) && (i < 5) ; i++)
        {
            printf(" %d \n", v.data[i]);
        }
    }
    return 0;
}
