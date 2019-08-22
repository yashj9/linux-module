// function for finding number of semicolons in a string and remove redundent spaces

#include"yjsh_hf.h"

int strcnt ( char *str )
{
    int i = 0, cnt = 0, f1 = 0, f2 = 0, j = 0, k = 0;
    count = 0;
    while( str[i] )
    {
        if( str[i] == ' ' )
        {
            f1 = 1;
        }
        else
        {
            f1 = 0;
        }
        if( f1 == 1 )
        {
            if( ((str[i+1] == ' ') || (str[i+1] == ';')) || (f2 == 1) )
            {
                for( j = i+1 ; str[j] == ' ' ; j++ );
                if((f2 == 1) || (str[i+1] == ';'))
                {
                    k = i;
                }
                else
                {
                    k = i+1;
                }
                while( str[j] )
                {
                    str[k++] = str[j++];
                }
                str[k] = str[j];
            }
        }
        else
        {
            f2 = 0;
        }
        if( str[i++] == ';' )
        {
            f2 = 1;
            count++;
        }
    }
    return count;
}
