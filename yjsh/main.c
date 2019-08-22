// main file for own shell

#include"yjsh_hf.h"

int main ( void )
{
    char str1[64], str2[64] = {0} , strexit[5]={"exit"}, **strcmd;
    int i = 0, b = 0;
    system("clear");
    while(1)
    {
        i++;
        //printf(BROWNBG);
        //printf(REDB);
        printf("%d). this_shell :  ", i);
        scanf(" %[^\n]", str2);
        if( str2[63] != '\0')
        {
            str2[63] = '\0';
        }
        strcnt( str2 );
        printf(" ';' is %d times . \n", count);
        strcmd = cmdarr( str2 );
        b = 0;
        while( b <= count )
        {
            printf("%s \n", strcmd[b++]);
        }
        cmdexc1(strcmd);
        if( strcmp(str2, strexit) == 0 )
        {
            printf("\n");
            break;
        }
        printf("\n");
    }
}