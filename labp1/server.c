// lab paper 1, practice file, string based question paper, server side

#include"headers.h"

int main(void)
{
    int id, i, j, k, count;
    struct msgbuf v;
    char temp;
    id = msgget(4, IPC_CREAT|0664);
    if(id < 0)
    {
        perror("msgget");
        return 0;
    }
    printf("id = %d \n", id);
    msgrcv(id, &v, sizeof(v), 1, 0);
    printf("Data received = %s \n", v.data);
    for(i=j=k=count=0 ; v.data[i] ; i++)
    {
        if((v.data[i] == ' ') || ((v.data[i]) == '\0'))
        {
            if(count < 5)
            {
                j = i - count;
                for(k = i - 1 ; j < k ; j++, k--)
                {
                    temp = v.data[j];
                    v.data[j] = v.data[k];
                    v.data[k] = temp;
                }
                count = 0;
            }
            else
            {
                count = 0;
            }
        }
        else
        {
            count++;
        }
    }
    v.mtype = 2;
    msgsnd(id, &v, strlen(v.data)+1, 0);
    perror("msgsnd");
    return 0;
}
