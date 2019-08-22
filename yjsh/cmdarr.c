// this function will make 2d array of commands seperated by semicolons

#include"yjsh_hf.h"

char** cmdarr ( const char *carray )
{
    int i, j, k, cnt;
    char **dptr;
    dptr = (char **)malloc( sizeof(char*)*(count+1) );
    i = j = k = cnt = 0;
    while( carray[i] )
    {
        if( carray[i++] == ';' )
        {
            if(cnt == 0)
            {
                continue;
            }
            dptr[j++] = (char *)malloc( sizeof(char)*(cnt+1) );
            cnt = 0;
            continue;
        }
        cnt++;
    }
    dptr[j] = (char *)malloc( sizeof(char)*(cnt+1) );
    j = i = 0;
    while( carray[i] )
    {
        if( carray[i] == ';' )
        {
            dptr[j++][k] = '\0';
            k = 0;
            i++;
            continue;
        }
        dptr[j][k++] = carray[i++];
    }
    dptr[j][k] = '\0';
    return dptr;
}