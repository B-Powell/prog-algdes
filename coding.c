#include <stdio.h>
#include <string.h>
#include <stdlib.h>



 typedef struct CodeT
 {
     char from[28];
     char to[28];
 };


 void encodeStr (char *read_in, char *put_out, struct CodeT code);
 void decodeStr (char *read_in, char *put_out, struct CodeT code);



int main(void)
{


    struct CodeT code=
    {
        .from ="abcdefghijklmnopqrstuvwxyz",
        .to =  ".172093%@#+!:_-$^*()854=6?>"
    };

   char read_in[28];
   char put_out[28];

    do
    {
        printf("Enter a line of text :\n");
        fflush(stdin);
        fgets(read_in, 28, stdin);
        int i = 0;
        for (i; i < 28; i++)
        {
            if (read_in[i] == '\n')
                read_in[i] = '\0';
        }

        printf("The encoded string after encoding is:" );
        encodeStr(read_in, put_out , code);
        printf("%s\n\n", put_out);

        printf("The decoded string after encoding  is:" );
        decodeStr(read_in, put_out, code);
        fflush(stdin);


    } while (read_in[0] != '\0');

   return 0;
}

void encodeStr (char *read_in, char *put_out, struct CodeT code)
{
    int i = 0, j;

    for (i; ((i < 28) && (read_in[i] != '\0')); i++)
    {
        j = 0;
        for(j; j < 28 ;j++)
        {
            if (read_in[i] == code.from[j])
            {
                put_out[i] = code.to[j];
                break;
            }

            else
            {
                put_out[i] = read_in[i];
                break;
            }
        }
    }


    return;
}

void decodeStr(char *read_in, char *put_out, struct CodeT code)
{
    int i = 0, j;

    for (i; ((i < 28) && (put_out[i] != '\0')); i++)
    {
        j = 0;
        for(j; j < 28 ;j++)
        {
            if (put_out[i] == code.to[j])
                read_in[i] = code.from[j];
            else
            {
                read_in[i] = put_out[i];
                break;
            }
        }
    }


    return;
}
