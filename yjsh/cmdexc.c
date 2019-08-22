// the function that will execute the user supplied commands

#include"yjsh_hf.h"

int cmdexc1 ( char **list )
{
    int i = 0, j, k, child = 0, cnt = 0, b = 0;
    char **cmd;
    while ( child <= count)
    {
        if( fork() == 0 )
        {
            if( strchr(list[i], ' ') == 0 )
            {
                execlp(list[i], list[i] , NULL);
                exit(1);
            }
            else
            {
                j = k = 0;
                while(list[i][j])
                {
                    if( list[i][j++] == ' ' )
                    {
                        k++;
                    }
                }
                printf("k = %d \n", k);
                cmd = (char **)malloc( sizeof(char *)*(k+1) );
                j = k = 0;
                while(list[i][j])
                {
                    if( list[i][j++] == ' ' )
                    {
                        if( k == 0 )
                        {
                            continue;
                        }
                        cmd[cnt++] = (char *)malloc( sizeof(char *)*(k+1) );
                        k = 0;
                        continue; 
                    }
                    k++;
                }
                cmd[cnt] = (char *)calloc( sizeof(char *), (k+1) );
                cnt = k = j = 0;
                while(list[i][j])
                {
                    if( list[i][j] == ' ' )
                    {
                        cmd[cnt++][k] = '\0';
                        k = 0;
                        j++;
                        continue;
                    }
                    cmd[cnt][k++] = list[i][j++];
                }
                cmd[cnt][k] = '\0';
                while( b <= cnt )
                {
                    printf("%s \n", cmd[b++]);
                }
                execvp(cmd[0],cmd);
                exit(1);
            }
            
        }
        else
        {
            child++;
            i++;
            wait(0);
            printf("\n");
        }
    }
    
}