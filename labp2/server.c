// lab paper set B, int array and strong num program, client side

#include"headers.h"

int main(void)
{
    int id, c, i, j, k, l;
    struct msgbuf v, v1;
    id = msgget(4, IPC_CREAT|0664);
    if(id < 0)
    {
        perror("msgget");
        return 0;
    }
    printf("id = %d \n", id);
    msgrcv(id, &v, sizeof(v), 1, 0);
    perror("msgrcv");
    printf("The data received is : \n");
    for(i = 0; i < 5 ; i++)
    {
        printf(" %d  ", v.data[i]);
    }
    printf("\n");
    for(c=i=j=k=l=0 ; i < 5 ; i++)
    {
        k = v.data[i];
        while(k)
        {
            j = k % 10;
            k = k / 10;
            l = l + facto(j);
        }
        if(l == v.data[i])
        {
            v1.data[c] = v.data[i];
            c++;
        }
    }
    v1.mtype = 2;
    if(c < 5)
    {
        while(c < 5)
        {
            v1.data[c++] = 0;
        }
    }
    msgsnd(id, &v1, sizeof(v1.data), 0);
    perror("msgsnd");
    return 0;
}

int facto(int x)
{
    int ret = 1;
    while(x)
    {
        ret = ret * x--;
    }
    return ret;
}