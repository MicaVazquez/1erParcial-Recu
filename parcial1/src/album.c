/*
 * album.c
 *
 *  Created on: 30 abr. 2022
 *      Author: PC-INC
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "validaciones.h"
#include "album.h"

#define CANTDISC 5
#define MAX_TART 2
#define MAX_ART 5
#define MAX_DISC 5
#define MAX_PAIS 5

#define LIBRE 0
#define OCUPADO 1
#define BAJA -1
static int idIncremental = 1005;
static int eAlbum_obtenerID();
static int eAlbum_obtenerID()
{
	return idIncremental++;
}


void hardcodearTipoArtista(eTipoArtista lista[], int lim)
{
    int i;

    int codigoTipoArtista[] = {1,2};
    char descripcionTipoArtista[][51] = {"solista","banda"};

    if( lista != NULL && lim > 0)
    {
    	 for(i=0;i<lim;i++)
    	    {
    	    	lista[i].codigoTipoArtista = codigoTipoArtista[i];
    	    	strcpy(lista[i].descripcionTipoArtista,descripcionTipoArtista[i]);
    	    }
    }
}

void hardcodearDiscograficas(eDiscografica lista[], int lim)
{
	int codigoDeDiscografica []= {200,201,202,203,204};
	char descripcionDiscografica[][51] = {"Columbia Records","PolyGram","EMI","Island Records","Warner Music"};
	int i;


    if( lista != NULL && lim > 0)
    {
    	 for(i=0;i<lim;i++)
    	    {
    	    	lista[i].codigoDeDiscografica = codigoDeDiscografica[i];
    	    	strcpy(lista[i].descripcionDiscografica,descripcionDiscografica[i]);
    	    }
    }

}

void hardcodearArtistas(eArtista lista[], int lim)
{
	int codigoDeArtista[] = {100,101,102,103,104};
	char nombreArtista[][51] = {"Camilo","Beatles","Camila Cabello","Coldplay","Dua Lipa"};
	int i;


    if( lista != NULL && lim > 0)
    {
    	 for(i=0;i<lim;i++)
    	    {
    	    	lista[i].codigoDeArtista = codigoDeArtista[i];
    	    	strcpy(lista[i].nombreArtista,nombreArtista[i]);
    	    }
    }
}


eFecha pedirFecha()
{
    int dia;
    int mes;
    int anio;

    eFecha fecha;

    getInt("Dia: ",&dia,1,31);
    getInt("Mes: ",&mes,1,12);
    getInt("Anio: ",&anio,1902,3000);

    fecha.dia = dia;
    fecha.mes = mes;
    fecha.anio = anio;
    return fecha;
}

int eAlbum_inicializar(eAlbum* list, int len)
{  int retorno = -1;
   int i;
    if(list != NULL && len > 0)
    {
    	retorno =0;
    	for(i=0;i<len;i++)
    	{
            list[i].estado = LIBRE;

    	}
    }
	return retorno;
}


void eAlbum_imprimirUno(eAlbum unAlbum)
{

	printf("|%-20s|%-2d/%-2d/%-2d|%-20d|%-20d|\n",unAlbum.titulo,
									  unAlbum.fechaDePublicacion.dia,
									  unAlbum.fechaDePublicacion.mes,
									  unAlbum.fechaDePublicacion.anio,
									  unAlbum.importe,
									  unAlbum.codigoDeAlbum);
}

void eAlbum_imprimirTodos(eAlbum* list, int largo)
{
	int i=0;
    printf("Titulo               Fecha de publ.      Importe        Codigo de album\n");
    if(list != NULL && largo > 0)
    {
		for(i=0;i<largo;i++)
		{
			if(list[i].estado == OCUPADO)
			{
				eAlbum_imprimirUno(list[i]);
			}
		}
    }
}

int eAlbum_alta(eAlbum list[], int len,eArtista listaDeArtistas[], int limArt,eTipoArtista listaDeTipoArtista[],int limTipoArtista,eDiscografica listaDeDiscograficas[],int limDisc,ePais listaPais[],int limPais)
{

	int indiceLibre;
    int rtn=-1;
	 if(list != NULL && len > 0)
	 {
       indiceLibre =  buscarLibre(list,len);

       if(indiceLibre != -1)
       {

           list[indiceLibre] = cargarUno(listaDeArtistas,limArt,listaDeTipoArtista,limTipoArtista,listaDeDiscograficas,limDisc,listaPais,limPais);
    	   list[indiceLibre].codigoDeAlbum = eAlbum_obtenerID();
    	   list[indiceLibre].estado = OCUPADO;

    	   rtn=0;
       }
       else
       {
    	   printf("No hay espacio...");
       }

	 }
	 return rtn;
}


int buscarLibre(eAlbum* list, int len)
{
	int i;
	int indice=-1;
	for(i=0;i<len;i++)
	{
		if(list[i].estado == LIBRE)
		{
			indice=i;
			break;
		}
	}
 return indice;
}


eAlbum cargarUno(eArtista listaDeArtistas[], int limArt,eTipoArtista listaDeTipoArtista[],int limTipoArtista,eDiscografica listaDeDiscograficas[],int limDisc,ePais listaPais[],int limPais)
{
	eAlbum unAlbum;

	int codigoTipoArtista;//FK
	int codigoDeArtista;//FK
	int codigoDeDiscografica;//FK
	int idPais;//FK
	char titulo[51];
	eFecha fechaDePublicacion;

	int importe;

    getString("\nIngrese el titulo del album: ",titulo,1,51);
    fechaDePublicacion = pedirFecha();
    getInt("\nIngrese el importe: ",&importe,1,9999999);

    printf("\nElija un artista: ");

    listarArtistas(listaDeArtistas, limArt);

    getInt("\nIngrese el codigo del artista: ",&codigoDeArtista,100,104);

    printf("\n\nElija una discografica: ");

    listarDiscograficas(listaDeDiscograficas, limDisc);

    getInt("\nIngrese el codigo de la discografica: ",&codigoDeDiscografica,200,204);

    printf("\n\nElija un tipo de artista: ");

    listarTiposArtistas(listaDeTipoArtista, limTipoArtista);

    getInt("\n Ingrese opcion de tipo de artista: ",&codigoTipoArtista,1,2);


    printf("\n\n Elija un pais: ");//elije

    listarPaises(listaPais, limPais);

    getInt("\n Ingrese opcion de pais: ",&idPais,300,305);


    strncpy(unAlbum.titulo,titulo,sizeof(unAlbum.titulo));
    unAlbum.fechaDePublicacion = fechaDePublicacion;
    unAlbum.importe = importe;
    unAlbum.codigoDeArtista = codigoDeArtista;
    unAlbum.codigoDeDiscografica = codigoDeDiscografica;
    unAlbum.codigoTipoArtista = codigoTipoArtista;
    unAlbum.idPais = idPais;



	  return unAlbum;
}


int eAlbum_encontrarPorCodigo(eAlbum* list, int len,int codigo)
{
	int i;
   int indice = -1;

	if(list != NULL && len > 0)
	{
        for(i=0;i<len;i++)
        {
        	if(list[i].codigoDeAlbum == codigo && list[i].estado == OCUPADO)
        	{
        		indice = i;
               break;
        	}
        }
	}
   return indice;
}

void eAlbum_modificar(eAlbum list[], int len,eArtista listaDeArtistas[], int tamArt, eTipoArtista listaDeTipoArtista[],int tamTipoArtista,eDiscografica listaDeDiscograficas[],int tamDisc,ePais listaPais[],int limPais)
{
	int auxCodigo;
    int datoEncontrado;
    int opcionModificar;
    int codigoDeArtista;
    int codigoDeDiscografica;
    int codigoTipoArtista;
    int idPais;

	eAlbum_muestraTodos(list, len, listaDeArtistas, tamArt, listaDeTipoArtista, tamTipoArtista, listaDeDiscograficas, tamDisc, listaPais, limPais);
	getInt("\nIngrese el codigo del album a modificar: ",&auxCodigo,1000,999999);
	datoEncontrado = eAlbum_encontrarPorCodigo(list, len,auxCodigo);
	if(datoEncontrado != -1 )
	{
		printf("\nSe encontro el dato: \n");

		eAlbum_header();
		imprimirUnoCompleto(list[datoEncontrado], listaDeArtistas, tamArt, listaDeTipoArtista, tamTipoArtista, listaDeDiscograficas, tamDisc, listaPais, limPais);


		do{
			getInt("\n\nQue desea modificar?\n1. Titulo\n2. Fecha de publicacion\n3. Importe\n4. Artista\n5. Discografica \n6. Tipo de artista\n7. Pais\n8. Volver al menu principal \nOpcion: ",&opcionModificar,1,8);
			switch(opcionModificar)
			{

			case 1:
				getString("\nIngrese titulo: ",list[datoEncontrado].titulo , 1, 51);
				break;
			case 2:
				list[datoEncontrado].fechaDePublicacion = pedirFecha();
				break;
			case 3:
				getInt("\nIngrese importe: ",&list[datoEncontrado].importe, 1, 999999);
				break;
			case 4:
				printf("\nElija un artista: ");
				listarArtistas(listaDeArtistas, tamArt);
				getInt("\nIngrese el codigo del artista: ",&codigoDeArtista,100,104);
				list[datoEncontrado].codigoDeArtista = codigoDeArtista;
				break;

			case 5:
				printf("\nElija una discografica: ");
				listarDiscograficas(listaDeDiscograficas, tamDisc);
				getInt("\nIngrese el codigo de la discografica: ",&codigoDeDiscografica,200,204);
				list[datoEncontrado].codigoDeDiscografica = codigoDeDiscografica;
				break;
			case 6:
				printf("\nElija un tipo de artista: ");
				listarTiposArtistas(listaDeTipoArtista, tamTipoArtista);
				getInt("\nIngrese opcion de tipo de artista: ",&codigoTipoArtista,1,2);
				list[datoEncontrado].codigoTipoArtista = codigoTipoArtista;
				break;
			case 7:
				printf("\n\n Pais: ");//elije
				listarPaises(listaPais, limPais);
				getInt("\n Ingrese opcion de pais: ",&idPais,300,305);
				list[datoEncontrado].idPais = idPais;
				break;
			case 8:
				// salir
				break;
			}

		}while(opcionModificar != 7);

	}
	else
	{
		printf("No se encontro el dato");
	}
}

int eAlbum_baja(eAlbum* list, int len,eArtista* listArt,int lenArt,eTipoArtista* listTipoArt, int lenTipoArt,eDiscografica* listDisco,int lenDisc,ePais* listPais,int lenPais)
{
	int auxCodigo;
	int datoEncontrado;
	char confirmar;
	int rtn = 0;

    eAlbum_muestraTodos(list, len, listArt, lenArt, listTipoArt, lenTipoArt, listDisco, lenDisc, listPais, lenPais);
	getInt("\nIngrese el codigo del album a dar de baja: ",&auxCodigo,1000,999999);
	datoEncontrado = eAlbum_encontrarPorCodigo(list, len,auxCodigo);

	if(datoEncontrado != -1)
	{
		eAlbum_header();
		imprimirUnoCompleto(list[datoEncontrado], listArt, lenArt, listTipoArt, lenTipoArt, listDisco, lenDisc, listPais, lenPais);

		getCaracter(&confirmar, "Dar de baja? [S|N]: ", "Error.", 'n', 's');
		confirmar = toupper(confirmar);

		if(confirmar == 'S')
		{
			list[datoEncontrado].estado = BAJA;
			rtn = 1;
			printf("Se han borrado los datos...");
		}
		else
		{
			printf("No se han borrado los datos...");
		}

	}
	return rtn;
}




void eAlbum_hardcodearDatos(eAlbum lista[])
{
	  int tam = 5;

	  int codigoTipoArtista[]={1,2,1,2,1};
	  int codigoDeArtista[]={100,101,102,103,104};
	  int codigoDeDiscografica[]={200,201,202,203,204};
	  int estado[]={OCUPADO,OCUPADO,OCUPADO,OCUPADO,OCUPADO};
	  int codigoDeAlbum[]={1000,1001,1002,1003,1004};
	  char titulo[][51]={"Mis manos","Help","Familia","Ghost Stories","Future Nostalgia"};
	  eFecha fechaDePublicacion[]={{4,3,2021},{6,8,1965},{8,4,2022},{19,4,2014},{27,3,2020}};
	  int idPais[]={300,301,302,303,304};

	  int importe[]={3000,8000,4000,5000,3500};

	  int i;
	  for(i=0;i<tam;i++)
	  {
		  lista[i].codigoTipoArtista = codigoTipoArtista[i];
		  lista[i].codigoDeArtista = codigoDeArtista[i];
		  lista[i].codigoDeDiscografica = codigoDeDiscografica[i];
		  lista[i].estado = estado[i];
		  lista[i].codigoDeAlbum = codigoDeAlbum[i];
		  strcpy(lista[i].titulo,titulo[i]);
		  lista[i].fechaDePublicacion = fechaDePublicacion[i];
		  lista[i].importe = importe[i];
		  lista[i].idPais = idPais[i];
	  }


}


void eAlbum_importeTotalPromedio(eAlbum lista[], int tam)
{   int i;
    int acumulador = 0;
    int contador = 0;
    int contadorMenores = 0;
    float promedio;
	if(lista != NULL && tam > 0)
	{
		for(i=0;i<tam;i++)
		{
			if(lista[i].estado == OCUPADO)
			{
				acumulador+= lista[i].importe;
				contador++;
			}
		}

	}
	if(contador != 0)
	{
	  printf("\nEl total de los importes: %d\n",acumulador);
      promedio = (float)acumulador/contador;
      printf("\nEl promedio de los importes: %.2f\n",promedio);

      for(i=0;i<tam;i++)
      {
    	  if(lista[i].estado == OCUPADO && lista[i].importe < promedio)
    	  {
              contadorMenores++;
    	  }
      }

      if(contadorMenores > 0)
      {
    	  printf("\nLa cantidad de albumes que no superan el promedio: %d\n",contadorMenores);
      }

	}

}

void eAlbum_posterior(eAlbum list[], int len)
{
	int i;
	int contador = 0;

   if(list != NULL && len > 0)
   {
		for(i=0;i<len;i++)
		{
			if(list[i].fechaDePublicacion.anio > 1999 && list[i].estado == OCUPADO)
			{
				contador++;
			}
		}

		if(contador != 0)
		{
			printf("\n Cantidad de álbumes cuya fecha de publicación es posterior a 31/12/1999 es: %d\n",contador);
		}
   }
}


void eAlbum_informar(eAlbum list[], int len)
{
	int opcionInformar;
	do
	{
		getInt("\nQue desea informar?\n1.Total y promedio de los importes, y cuántos álbumes no superan ese promedio.\n2.Albumes posteriores a 31/12/1999.\n3. Volver al menu\nOpcion: ",&opcionInformar,1,4);
		switch(opcionInformar)
		{
		case 1:
			eAlbum_importeTotalPromedio(list,len);
			break;

		case 2:
			eAlbum_posterior(list,len);
			break;

		case 3:
			//SALIR
			break;
		}

	}while(opcionInformar != 3);
}


void eAlbum_listar(eAlbum list[], int tam,eArtista listaArtistas[],int lenArt,eTipoArtista listaTipoArtista[],int lenTipoArtista,eDiscografica listaDiscograficas[],int lenDisc,ePais listaPais[],int lenPais)
{
	int opcionListar;


	do
	{
		getInt("\n\nQue desea listar?\
				\n 1.Todas las discograficas.\
				\n 2.Todos los tipos de artistas musicales.\
				\n 3.Todos los artistas.\
				\n 4.Todos los albumes.\
				\n 5.Todos los paises\
				\n 6.Listado ordenado de los albumes por importe/titulo\
				\n 7.Los álbumes cuya fecha de publicación es posterior a 31/12/1999.\
				\n 8.Todos los álbumes que no superan el promedio de los importes.\
				\n 9.Todos los álbumes de un artista determinado.\
				\n 10.Todos los álbumes de cada año.\
				\n 11.El álbum o los álbumes más baratos.\
				\n 12.Listar todos los albumes que no sean de Argentina.\
				\n 13.Listar todos los albumes de Argentina que correspondan a un año determinado\
				\n 14.Informar la cantidad de solistas de un año y país determinado.\
				\n 15.Realizar un solo listado de todos los álbumes de bandas extranjeras. .\
				\n 16.Volver al menu.\nOpcion:",&opcionListar,1,16);

		switch(opcionListar)
		{
			case 1:
				listarDiscograficas(listaDiscograficas, lenDisc);
				break;
			case 2:
				listarTiposArtistas(listaTipoArtista, lenTipoArtista);
				break;
			case 3:
				listarArtistas(listaArtistas, lenArt);
				break;
			case 4:
				printf("\n -ALBUMES-\n");
				eAlbum_muestraTodos(list, tam, listaArtistas,lenArt,listaTipoArtista,lenTipoArtista,listaDiscograficas, lenDisc,listaPais,lenPais);
				break;
			case 5:
				listarPaises(listaPais, lenPais);
				break;
			case 6:
                ordenarAlbumes(list, tam);
                eAlbum_muestraTodos(list, tam, listaArtistas,lenArt,listaTipoArtista,lenTipoArtista,listaDiscograficas, lenDisc,listaPais,lenPais);
				break;
			case 7:
				listarPosteriores(list,tam,listaArtistas,lenArt,listaTipoArtista,lenTipoArtista,listaDiscograficas, lenDisc,listaPais,lenPais);
				break;
			case 8:
                listarMenorAlPromedio(list, tam,listaArtistas, lenArt, listaTipoArtista, lenTipoArtista, listaDiscograficas, lenDisc, listaPais, lenPais);
				break;
			case 9:
				listarAlbumesArtistaDeterminado(list, tam, listaArtistas, lenArt, listaTipoArtista, lenTipoArtista, listaDiscograficas, lenDisc, listaPais, lenPais);
				break;
			case 10:
				listarAlbumesXAnio(list, tam,listaArtistas, lenArt, listaTipoArtista, lenTipoArtista, listaDiscograficas, lenDisc, listaPais, lenPais);
				break;
			case 11:
				listarMasBarato(list, tam,listaArtistas, lenArt, listaTipoArtista, lenTipoArtista, listaDiscograficas, lenDisc, listaPais, lenPais);
				break;
			case 12:
				listarTodosMenosArg(list, tam,listaArtistas, lenArt, listaTipoArtista, lenTipoArtista, listaDiscograficas, lenDisc, listaPais, lenPais);
				break;
			case 13:
				listarAlbumesArgentinaAnioDeterminado(list, tam,listaArtistas, lenArt, listaTipoArtista, lenTipoArtista, listaDiscograficas, lenDisc, listaPais, lenPais);
				break;
			case 14:
				informaSolistasAniPaisDeterminado(list, tam, listaArtistas, lenArt, listaTipoArtista, lenTipoArtista, listaDiscograficas, lenDisc, listaPais, lenPais);
				break;
			case 15:
				listarBandasExtranjeras(list, tam, listaArtistas, lenArt, listaTipoArtista, lenTipoArtista, listaDiscograficas, lenDisc, listaPais, lenPais);
				break;
			case 16:
				//salir
				break;
		}

	}while(opcionListar != 16);
}


void listarDiscograficas(eDiscografica listaDeDiscograficas[], int lenDisc)
{
	int i;
	printf("\n -DISCOGRAFICAS-");
	 for(i=0;i<lenDisc;i++)
	    {
	    	printf("\n\n %d-%s",listaDeDiscograficas[i].codigoDeDiscografica,listaDeDiscograficas[i].descripcionDiscografica);
	    }

}

void listarArtistas(eArtista listaDeArtistas[], int lenArt)
{
	int i;

	printf("\n -ARTISTAS-");

	for(i=0;i<lenArt;i++)
	{
		printf("\n\n %d-%s",listaDeArtistas[i].codigoDeArtista,listaDeArtistas[i].nombreArtista);
	}
}


void listarTiposArtistas(eTipoArtista listaDeTipoArtista[], int lenTipoArtista)
{
	int i;

	printf("\n -TIPO DE ARTISTAS-");

	for(i=0;i<lenTipoArtista;i++)
	{
		printf("\n\n %d-%s",listaDeTipoArtista[i].codigoTipoArtista,listaDeTipoArtista[i].descripcionTipoArtista);
	}
}

void ordenarAlbumes(eAlbum list[],int len)
{
	int i;
	int j;

	eAlbum aux;

	if(list != NULL && len>0)
	{
		printf("\n -Lista ordenada- \n");
       for(i=0;i<len-1;i++)
       {
    	   for(j=i+1;j<len;j++)//importe-descendente
    	   {
              if(list[i].importe<list[j].importe)
              {
            	  aux = list[i];
            	  list[i] = list[j];
            	  list[j] = aux;
              }
              else
              {
            	  if(list[i].importe == list[j].importe)//si son iguales
            	  {
            		  if(stricmp(list[i].titulo,list[j].titulo)>0)//ascendete-titulo
            		  {
            			  aux = list[i];
            			  list[i] = list[j];
            			  list[j] = aux;
            		  }
            	  }
              }
    	   }
       }
	}
}

void listarPosteriores(eAlbum list[],int len,eArtista* listArt,int lenArt,eTipoArtista* listTipoArtista,int lenTipoArt, eDiscografica* listDisco,int lenDisco,ePais* listPais,int lenPais)
{
	int i;

	if(list != NULL && len > 0)
	{    printf("\n-Albumes despues de 1999-\n");
		 eAlbum_header();
		for(i=0;i<len;i++)
		{
			if(list[i].estado==OCUPADO)
			{
				if(list[i].fechaDePublicacion.anio>=2000)
				{
                    imprimirUnoCompleto(list[i], listArt, lenArt, listTipoArtista, lenTipoArt, listDisco, lenDisco, listPais, lenPais);
				}
			}
		}
	}
}

void listarMenorAlPromedio(eAlbum list[],int tam,eArtista* listArt,int lenArt,eTipoArtista* listTipoArtista,int lenTipoArt, eDiscografica* listDisco,int lenDisco,ePais* listPais,int lenPais)
{
	 int i;
	    int acumulador = 0;
	    int contador = 0;
	    float promedio;

		if(list != NULL && tam > 0)
		{
			for(i=0;i<tam;i++)
			{
				if(list[i].estado == OCUPADO)
				{
					acumulador+= list[i].importe;
					contador++;
				}
			}

		}

		if(contador != 0)
		{
			promedio = (float)acumulador/contador;

			printf("\n-Albumes que no superan el promedio-\n");
			eAlbum_header();
			for(i=0;i<tam;i++)
			{
				if(list[i].estado == OCUPADO && list[i].importe < promedio)
				{
					imprimirUnoCompleto(list[i], listArt, lenArt, listTipoArtista, lenTipoArt, listDisco, lenDisco, listPais, lenPais);
				}
			}
		}
}

void listarAlbumesPorArtistas(eAlbum albumes[],int tam, eArtista* listArt,int lenArt,eTipoArtista* listTipoArtista,int lenTipoArt, eDiscografica* listDisco,int lenDisco,ePais* listPais,int lenPais)
{
	int i;
	int j;

	if(albumes != NULL && tam > 0 && listArt != NULL && lenArt > 0)
	{

		eAlbum_header();
		for(i=0; i<lenArt; i++)
		{
			printf("\n%s\n", listArt[i].nombreArtista);
			for(j=0;j<tam;j++)
			{
				if(listArt[i].codigoDeArtista==albumes[j].codigoDeArtista)
				{

					imprimirUnoCompleto(albumes[j], listArt, lenArt, listTipoArtista, lenTipoArt, listDisco, lenDisco, listPais, lenPais);
				}
			}
		}
	}
}



void eAlbum_muestraTodos(eAlbum* list, int lenAlb, eArtista* listArt,int lenArt,eTipoArtista* listTipoArt, int lenTipoArt,eDiscografica* listDisco,int lenDisc,ePais* listPais,int lenPais)
{
	int i;
	int j;
	int k;
	int l;
	int m;

    eAlbum_header();
    if(list != NULL && lenAlb > 0)
    {
		for(i=0;i<lenAlb;i++)
		{
			if(list[i].estado == OCUPADO)
			{
				for(j=0;j<lenArt;j++)
				{
                    if(list[i].codigoDeArtista == listArt[j].codigoDeArtista)//mismo codigo de artista
                    {
                    	for(k=0;k<lenTipoArt;k++)
                    	{
                    		if(list[i].codigoTipoArtista == listTipoArt[k].codigoTipoArtista)// mismo codigo de tipo
                    		{
                    			for(l=0;l<lenDisc;l++)
                    			{
                    				if(list[i].codigoDeDiscografica == listDisco[l].codigoDeDiscografica)// misma discografica
                    				{
                    					for(m=0;m<lenPais;m++)//mismo pais
                    					{
                    						if(list[i].idPais == listPais[m].idPais)
                    						{

                    							eAlbum_muestraUno(list[i], listArt[j], listTipoArt[k],listDisco[l],listPais[m]);
                    							break;
                    						}
                    					}
                                       break;
                    				}
                    			}
                    			break;
                    		}
                    	}
                    	break;
                    }
				}
			}
		}
    }
}



void eAlbum_muestraUno(eAlbum unAlbum, eArtista unArtista, eTipoArtista unTipoArtista,eDiscografica unaDiscografica,ePais unPais)
{

	printf("|%-20d$|%-2d/%-2d/%-2d|%-20s|%-20d|%-20s|%-8s|%-20s|%s\n",unAlbum.importe,
									  unAlbum.fechaDePublicacion.dia,
									  unAlbum.fechaDePublicacion.mes,
									  unAlbum.fechaDePublicacion.anio,
									  unAlbum.titulo,
									  unAlbum.codigoDeAlbum,
									  unArtista.nombreArtista,
									  unTipoArtista.descripcionTipoArtista,
									  unaDiscografica.descripcionDiscografica,
									  unPais.descripcionPais);
}


void listarMasBarato(eAlbum* list,int len,eArtista* listArt,int lenArt,eTipoArtista* listTipoArt, int lenTipoArt,eDiscografica* listDisco,int lenDisc,ePais* listPais,int lenPais)
{
	int i;
	int flagMenor = 0;
	int menorImporte;



	if(list != NULL)
	{
		for(i=0;i<len;i++)// recorre lista de album
		{
			if(list[i].estado == OCUPADO)
			{
				if(list[i].importe<menorImporte || flagMenor == 0)
				{
					menorImporte = list[i].importe;
					flagMenor=1;
				}
			}
		}
	}

	if(i == len)
	{
		printf("\nEl album o los albumes mas baratos: \n");
		eAlbum_header();
		for(i=0;i<len;i++)// recorre lista de album
		{
			if(list[i].estado == OCUPADO)
			{
				if(list[i].importe == menorImporte)
				{
					menorImporte = list[i].importe;
					imprimirUnoCompleto(list[i], listArt, lenArt, listTipoArt, lenTipoArt, listDisco, lenDisc, listPais, lenPais);
				}
			}
		}

	}
}

void listarAlbumesXAnio(eAlbum* list,int len, eArtista* listArt,int lenArt,eTipoArtista* listTipoArt, int lenTipoArtista,eDiscografica* listDisco,int lenDisco,ePais* listPais,int lenPais)
{
	int minAnio;
	int maxAnio;
	int flagAnioMax=0;
	int flagAnioMin=0;
	int i;
	int j;
	int k;
    int flagAnioAlbum = 0;

	for(i=0;i<len;i++)
	{
       if(list[i].estado == OCUPADO)
       {
			if(list[i].fechaDePublicacion.anio>maxAnio || flagAnioMax ==0)
			{
				maxAnio = list[i].fechaDePublicacion.anio;
				flagAnioMax=1;
			}

			if(list[i].fechaDePublicacion.anio<minAnio || flagAnioMin ==0)
			{
				minAnio = list[i].fechaDePublicacion.anio;
				flagAnioMin=1;
			}
       }

	}

	eAlbum_header();
	for(j=minAnio;j<maxAnio+1;j++)//recorro anios
	{

		for(k=0;k<len;k++)// recorro albumes en fecha.anio
		{
			if(list[k].fechaDePublicacion.anio == j && list[k].estado == OCUPADO)
			{
				if(flagAnioAlbum == 0)
				{
					printf("\nAlbum del %d\n", j);

					flagAnioAlbum = 1;
				}
				imprimirUnoCompleto(list[k], listArt, lenArt, listTipoArt, lenTipoArtista, listDisco, lenDisco, listPais, lenPais);
				printf("\n");
			}
		}
		flagAnioAlbum = 0;
	}

}

void eAlbum_header()
{
	printf("Importe               Fecha de publ.      Titulo        Codigo de album       Artista            Tipo      Discografica        Pais\n");
}


void hardcodearPaises(ePais* listPais, int lenPais)
{
	 int i;
	 int id [5]= {300,301,302,303,304};
	 char descripcion [5][51] = {"Colombia","Inglaterra","Cuba","Estados Unidos","Argentina"};

	    if( listPais != NULL && lenPais > 0)
	    {
	    	 for(i=0;i<lenPais;i++)
	    	    {
	    	    	strcpy(listPais[i].descripcionPais,descripcion[i]);
	    	    	listPais[i].idPais = id[i];
	    	    }
	    }
}

void listarTodosMenosArg(eAlbum* list,int lenAlb,eArtista* listArt,int lenArt,eTipoArtista* listTipoArtista,int lenTipoArt, eDiscografica* listDisco,int lenDisco,ePais* listPais,int lenPais)
{
	int i;
	if(list != NULL)
	{
		printf("\nTodos los albumes que no son de Argentina\n");
		eAlbum_header();
		for(i=0;i<lenAlb;i++)
		{
          if(list[i].estado ==OCUPADO)
          {
        	  if(list[i].idPais != 304)//argentina
        	  {
        		  imprimirUnoCompleto(list[i], listArt, lenArt, listTipoArtista, lenTipoArt, listDisco, lenDisco, listPais, lenPais);
        	  }
          }
		}
	}
}

void listarAlbumesArg(eAlbum* list,int lenAlb,eArtista* listArt,int lenArt,eTipoArtista* listTipoArtista,int lenTipoArt, eDiscografica* listDisco,int lenDisco,ePais* listPais,int lenPais)
{
	    int minAnio;
		int maxAnio;
		int flagAnioMax=0;
		int flagAnioMin=0;
		int i;
		int j;
		int x;
	    int flagAnioAlbum = 0;

		for(i=0;i<lenAlb;i++)
		{
	       if(list[i].estado == OCUPADO)
	       {
	    	   if(list[i].idPais == 304)
	    	   {
	    		   if(list[i].fechaDePublicacion.anio>maxAnio || flagAnioMax ==0)
	    		   {
	    			   maxAnio = list[i].fechaDePublicacion.anio;
	    			   flagAnioMax=1;
	    		   }

	    		   if(list[i].fechaDePublicacion.anio<minAnio || flagAnioMin ==0)
	    		   {
	    			   minAnio = list[i].fechaDePublicacion.anio;
	    			   flagAnioMin=1;
	    		   }
	    	   }

	       }

		}

		printf("\n Albumes de Argentina\n");
		for(j=minAnio;j<maxAnio+1;j++)//recorro anios
		{

			for(x=0;x<lenAlb;x++)// recorro albumes en fecha.anio
			{
				if(list[x].fechaDePublicacion.anio == j && list[x].estado == OCUPADO && list[x].idPais == 304)
				{
					if(flagAnioAlbum == 0)
					{
						printf("\nAlbum del %d\n", j);
						flagAnioAlbum = 1;
					}
					imprimirUnoCompleto(list[x], listArt, lenArt, listTipoArtista, lenTipoArt, listDisco, lenDisco, listPais, lenPais);
				}
			}
			flagAnioAlbum = 0;
		}

}

void listarPaises(ePais listPaises[], int lenPais)
{
	int i;
	printf("\n -PAISES-");
	for(i=0;i<lenPais;i++)
	{
		printf("\n\n %d-%s",listPaises[i].idPais,listPaises[i].descripcionPais);
	}

}

void imprimirUnoCompleto(eAlbum unAlbum,eArtista* listArt,int lenArt,eTipoArtista* listTipoArtista,int lenTipoArt, eDiscografica* listDisco,int lenDisco,ePais* listPais,int lenPais)
{
	int i;
	int j;
	int y;
	int x;

   if(listArt != NULL && listTipoArtista != NULL && listDisco != NULL && listPais != NULL)
   {
	   printf("|%-20d$|%-2d/%-2d/%-2d|%-20s|%-20d",unAlbum.importe,
	   									  unAlbum.fechaDePublicacion.dia,
	   									  unAlbum.fechaDePublicacion.mes,
	   									  unAlbum.fechaDePublicacion.anio,
	   									  unAlbum.titulo,
	   									  unAlbum.codigoDeAlbum);

      for(i=0;i<lenArt;i++)//recorro artistas
      {
    	  if(listArt[i].codigoDeArtista == unAlbum.codigoDeArtista)
    	  {
             printf("|%-20s",listArt[i].nombreArtista);
             break;
    	  }
      }

      for(j=0;j<lenTipoArt;j++) //recorro tipo artistas
      {
    	  if(listTipoArtista[j].codigoTipoArtista == unAlbum.codigoTipoArtista)
    	  {
    		 printf("|%-8s",listTipoArtista[j].descripcionTipoArtista);
    		 break;
    	  }
      }

      for(y=0;y<lenDisco;y++)//recorro discograficas
      {
    	  if(listDisco[y].codigoDeDiscografica == unAlbum.codigoDeDiscografica)
    	  {
    		  printf("|%-20s",listDisco[y].descripcionDiscografica);
    		  break;
    	  }
      }

      for(x=0;x<lenPais;x++)//recorro paises
      {
    	  if(listPais[x].idPais == unAlbum.idPais)
    	  {
    		  printf("|%s\n",listPais[x].descripcionPais);
    		  break;
    	  }
      }
   }
}

void listarAlbumesArtistaDeterminado(eAlbum* listAlbumes,int lenAlb,eArtista* listArt,int lenArt,eTipoArtista* listTipoArtista,int lenTipoArt, eDiscografica* listDisco,int lenDisco,ePais* listPais,int lenPais)
{
	int opcionArtista;
	int i;
	int j;
	int flagTitulo = 0;

	listarArtistas(listArt, lenArt);

	getInt("\nElija un artista: ", &opcionArtista,100,99999);


		if(listAlbumes != NULL && lenAlb > 0 && listArt != NULL && lenArt > 0)
		{
           for(i=0;i<lenAlb;i++)
           {
              if(listAlbumes[i].codigoDeArtista == opcionArtista)
              {
            	  if(flagTitulo == 0)
            	  {
            		  for(j=0;j<lenArt;j++)
            		  {
            			  if(listArt[j].codigoDeArtista == opcionArtista)//recorro lista de artistas
            			  {
            				   printf("\n -%s- \n",listArt[j].nombreArtista);
            				   break;
            			  }
            		  }
            		  flagTitulo = 1;
            	  }
            	  imprimirUnoCompleto(listAlbumes[i], listArt, lenArt, listTipoArtista, lenTipoArt, listDisco, lenDisco, listPais, lenPais);
              }
           }
		}
}

void listarAlbumesArgentinaAnioDeterminado(eAlbum* list,int lenAlbum,eArtista* listArt,int lenArt,eTipoArtista* listTipoArtista,int lenTipoArt, eDiscografica* listDisco,int lenDisco,ePais* listPais,int lenPais)
{
    int opcionAnio;
    int flag = 0;

	int i;

	eAlbum_ordenarAnios(list, lenAlbum);

	getInt("\n Ingrese el año que se quiere mostrar: ", &opcionAnio, 1900, 9999);

	printf("\n Año -%d-\n",opcionAnio);

	for(i=0;i<lenAlbum;i++)
	{
		if(list[i].estado == OCUPADO)
		{
			if(list[i].idPais == 304 && list[i].fechaDePublicacion.anio == opcionAnio)
			{
				eAlbum_header();
				imprimirUnoCompleto(list[i], listArt, lenArt, listTipoArtista, lenTipoArt, listDisco, lenDisco, listPais, lenPais);
				flag = 1;
			}
		}
	}

	if(!flag)
	{
		printf("\n No se encontro albumes de argentina de ese año...");
	}
}

void eAlbum_ordenarAnios(eAlbum* list, int lenAlbum)
{
	int i;
	int j;
	eAlbum aux;


	for(i=0;i<lenAlbum;i++)
	{
		for(j=i+1;j<lenAlbum;j++)
		{
			if(list[i].fechaDePublicacion.anio > list[j].fechaDePublicacion.anio)
			{
				aux = list[i];
				list[i] = list[j];
				list[j] = aux;
			}
		}
	}
}


void informaSolistasAniPaisDeterminado(eAlbum* listAlbumes,int len,eArtista* listArt,int lenArt,eTipoArtista* listTipoArtista,int lenTipoArt, eDiscografica* listDisco,int lenDisco,ePais* listPais,int lenPais)
{
	int optionPais;
	int optionAnio;
	int i;
	int contadorSolistas = 0;

	 getInt("\n Ingrese el año que se quiere : ", &optionAnio, 1900, 9999);
     listarPaises(listPais, lenPais);

     getInt("\n Elija un pais: ",&optionPais , 300, 304);


     for(i=0;i<len;i++)
     {
    	 if(listAlbumes[i].estado == OCUPADO)
    	 {
    		 if(listAlbumes[i].codigoTipoArtista == 1)
    		 {
    			 if(listAlbumes[i].fechaDePublicacion.anio == optionAnio)
    			 {
    				 if(listAlbumes[i].idPais == optionPais)
    				 {
                        contadorSolistas++;
    				 }
    			 }
    		 }
    	 }
     }

     if(contadorSolistas > 0)
     {
    	 printf("\n %d ",optionAnio);
    	 encontrarPais(listPais, lenPais, optionPais);
    	 printf("\n La cantidad de solistas es en esa año y pais es:  %d",contadorSolistas);
     }
     else
     {
    	 printf("\n No se encontraron solistas en ese año y pais...");
     }

}

void encontrarPais(ePais* listaPais, int lenPais,int opcion)
{
  int i;

  for(i=0;i<lenPais;i++)
  {
	  if(listaPais[i].idPais == opcion)
	  {
		  printf("\n %s ",listaPais[i].descripcionPais);
	  }
  }
}

void listarBandasExtranjeras(eAlbum* listAlbumes,int len,eArtista* listArt,int lenArt,eTipoArtista* listTipoArtista,int lenTipoArt, eDiscografica* listDisco,int lenDisco,ePais* listPais,int lenPais)
{
	int i;
	if(listAlbumes != NULL)
	{
		printf("\nTodos los albumes listado de bandas extranjeras\n");
		eAlbum_header();
		for(i=0;i<len;i++)
		{
			if(listAlbumes[i].estado ==OCUPADO)
			{
				if(listAlbumes[i].codigoTipoArtista == 2)
				{
					if(listAlbumes[i].idPais != 304)//argentina
					{
						imprimirUnoCompleto(listAlbumes[i], listArt, lenArt, listTipoArtista, lenTipoArt, listDisco, lenDisco, listPais, lenPais);
					}
				}
			}
		}
	}
}
