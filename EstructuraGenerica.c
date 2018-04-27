#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "EstructuraGenerica.h"
#include "GetDatosGenerica.h"
#define TAMANIO 10
#define OCUPADO 0
#define LIBRE 1


int eGen_baja(eGenerica listado[] ,int limite, int id)
{
    listado[eGen_buscarPorId(listado ,limite, id)].estado==0;
}

int eGen_modificacion(eGenerica listado[] ,int limite, int id)
{
    int retorno = -1;
    int posmodifica;
    posmodifica=eGen_buscarPorId(listado,limite,id);

    if(limite > 0 && listado != NULL)
    {
        retorno = -2;

        if(posmodifica >= 0)
        {
            retorno = 0;
            strcpy(listado[posmodifica].nombre,get_char("\n Ingrese Nombre: ",50));
            listado[posmodifica].estado = OCUPADO;
        }
    }
    return retorno;
}

int eGen_init( eGenerica listado[],int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && listado != NULL)
    {
        retorno = 0;
        for(i=0; i<limite; i++)
        {
            listado[i].estado= LIBRE;
            listado[i].idGenerica= 0;
        }
    }
    return retorno;
}

int eGen_buscarLugarLibre(eGenerica listado[],int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && listado != NULL)
    {
        retorno = -2;
        for(i=0;i<limite;i++)
        {
            if(listado[i].estado == LIBRE)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}

int eGen_siguienteId(eGenerica listado[],int limite)
{
    int retorno = 0;
    int i;
    if(limite > 0 && listado != NULL)
    {
        for(i=0; i<limite; i++)
        {
            if(listado[i].estado == OCUPADO)
            {
                    if(listado[i].idGenerica>retorno)
                    {
                         retorno=listado[i].idGenerica;
                    }

            }
        }
    }

    return retorno+1;
}


int eGen_buscarPorId(eGenerica listado[] ,int limite, int id)
{
    int retorno = -1;
    int i;
    if(limite > 0 && listado != NULL)
    {
        retorno = -2;
        for(i=0;i<limite;i++)
        {
            if(listado[i].estado == OCUPADO && listado[i].idGenerica == id)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}



int eGen_mostrarUno(eGenerica parametro)
{
     printf("\n %s - %d - %d",parametro.nombre,parametro.idGenerica,parametro.estado);
}

int eGen_mostrarListado(eGenerica listado[],int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && listado != NULL)
    {
        retorno = 0;
        for(i=0; i<limite; i++)
        {
            if(listado[i].estado==OCUPADO)
            {

                eGen_mostrarUno(listado[i]);
            }
        }
    }
    return retorno;
}


int eGen_mostrarListadoConBorrados(eGenerica listado[],int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && listado != NULL)
    {
        retorno = 0;
        for(i=0; i<limite; i++)
        {
            if(listado[i].estado==LIBRE)
            {
                printf("\n[LIBRE]");
            }
            eGen_mostrarUno(listado[i]);
        }
    }
    return retorno;
}




int eGen_alta(eGenerica  listado[],int limite)
{
    int retorno = -1;
    char nombre[50];
    int id;
    int indice;

    if(limite > 0 && listado != NULL)
    {
        retorno = -2;
        indice = eGen_buscarLugarLibre(listado,limite);
        if(indice >= 0)
        {
            //retorno = -3;
            id = eGen_siguienteId(listado,limite);

                retorno = 0;
                strcpy(listado[indice].nombre,get_char("\n Ingrese Nombre: ",50));
                listado[indice].idGenerica = id;
                listado[indice].estado = OCUPADO;
        }
    }
    return retorno;
}
