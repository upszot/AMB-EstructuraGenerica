#include <stdio.h>
#include <stdlib.h>
#include "EstructuraGenerica.h"
//#include "susFunciones.h"
#define CANTIDAD 10
int main()
{
    eGenerica listadoGenerico[CANTIDAD];
    eGen_init(listadoGenerico,CANTIDAD);

    char seguir='s';
    int opcion;

    do
    {
        menu("\n1.  Mostrar el listado"
             "\n2.  Mostrar el listado con borrados y vacios"
             "\n3.  Alta"
             );
        scanf("%d",&opcion);
        switch(opcion)
        {
            case 1:
                eGen_mostrarListado(listadoGenerico,CANTIDAD);
                getchar();
                break;
            case 2:
                eGen_mostrarListadoConBorrados(listadoGenerico,CANTIDAD);
                getchar();
                break;
            case 3:
                eGen_alta(listadoGenerico,CANTIDAD);
                getchar();
                break;
            case 0://salir
                seguir = 'n';
                break;
        }//FIN switch(opcion)

    }while(seguir=='s');
    return 0;

}
