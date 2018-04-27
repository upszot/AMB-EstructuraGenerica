#include <stdlib.h>
#include <string.h>
#include <stdio.h>

char *get_char(char *sms,int LongitudCadena)
{
    char *PTexto= (char *) malloc (sizeof(char)*LongitudCadena);
    char *TextoLibre=(char *) malloc (sizeof(char)*LongitudCadena+4);
    fflush(stdin);
    int flag=0;
    do
    {
        printf("%s ",sms);
        fgets(TextoLibre,LongitudCadena+3,stdin);
        if(flag==1)
        {
            printf("\n La longitud maxima del campo es: %d \n",LongitudCadena);
            system("pause");
            system("cls");
        }
        flag=1;
    }while(strlen(TextoLibre) >= LongitudCadena);

    strcpy(PTexto,TextoLibre);
    return PTexto;
}
