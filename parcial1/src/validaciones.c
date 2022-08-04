/*
 * validaciones.c
 *
 *  Created on: 14 abr. 2022
 *      Author: PC-INC
 */
//CUERPO/DESARROLLO
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void getString(char mensaje[],char input[],int tamMin,int tamMax)
{
    int i;
    int retorno;

    do
    {
        retorno=1;
        printf(mensaje);
        fflush(stdin);
        gets(input);

        if(strlen(input)>=tamMin && strlen(input)<=tamMax)
        {
            for(i=0; i<strlen(input); i++)
            {
                if((input[i]<'a' || input[i]>'z') && (input[i]<'A' || input[i]>'Z')&& (input[i] != ' '))
                {
                    retorno=0;
                    break;
                }
            }

        }

        if(retorno==0)
        {
            printf("error\n");
        }

    }
    while(retorno==0);
}



void getInt(char mensaje[],int *numero,int tamMin,int tamMax)
{
    char ingreso[50];
    int retorno=0;
    int flag=1;
    int auxiliar=0;
    int i;

    do
    {
        printf(mensaje);
        fflush(stdin);
        gets(ingreso);

            for(i=0;i<=strlen(ingreso);i++)
            {
                if(ingreso[i]=='.')
                {
                    flag=0;
                    break;
                }
            }

            auxiliar=atoi(ingreso);

            if(auxiliar>=tamMin && auxiliar<=tamMax && flag==1)
            {
                *numero=auxiliar;
                retorno=1;

            }

        if(retorno==0)
            {
                printf("error\n");
            }


    }while(retorno==0);


}



void getFloat(char mensaje[],float *numero,float tamMin,float tamMax)
{
    char ingreso[50];
    int retorno=0;
    int flag=0;
    float auxiliar;
    int i;



    do
    {
        printf(mensaje);
        fflush(stdin);
        gets(ingreso);

        for(i=0;i<=strlen(ingreso);i++)
        {
            if(ingreso[i]=='.')
            {
                flag++;

                if(flag==2)
                {
                    break;
                }
            }
        }

        auxiliar=atof(ingreso);

        if(auxiliar>=tamMin && auxiliar<=tamMax &&flag!=2)
        {
            *numero=auxiliar;
            retorno=1;

        }
        if(retorno==0)
        {
            printf("error\n");
        }


    }while(retorno==0);

}

int getCaracter(char* pResultado, char* mensaje, char* mensajeError, char minimo, char maximo)
{
    int retorno = -1;
    char bufferChar;

    if(pResultado != NULL && mensaje != NULL && mensaje != NULL && minimo <= maximo)
    {
        do
        {
            printf("%s", mensaje);
            fflush(stdin);
            scanf("%c",&bufferChar);

            if(bufferChar >= minimo && bufferChar <= maximo)
            {
                *pResultado = bufferChar;
                retorno = 0;
                break;
            }
            else
            {
                printf("%s", mensajeError);

            }

        }while(retorno==-1);
    }
    return retorno;
}
