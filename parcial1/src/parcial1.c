/*
 ============================================================================
 Name        : parcial1.c
 Author      : Micaela
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "validaciones.h"
#include "album.h"

#define CANT 10
#define CANTDISC 5
#define MAX_TART 2
#define MAX_ART 5
#define MAX_DISC 5
#define MAX_PAIS 5

int main(void)
{
	setbuf(stdout,NULL);
	eAlbum albumes[CANT];
	eArtista listaDeArtistas[MAX_ART];
	eTipoArtista  listaDeTipoArtista[MAX_TART];
	eDiscografica listaDeDiscograficas[MAX_DISC];
	ePais listaPaises[MAX_PAIS];

	int contadorDatos=5;

	int opcion;

    eAlbum_inicializar(albumes, CANT);
    eAlbum_hardcodearDatos(albumes);
    hardcodearTipoArtista(listaDeTipoArtista,MAX_TART);
    hardcodearDiscograficas(listaDeDiscograficas, MAX_DISC);
    hardcodearArtistas(listaDeArtistas, MAX_ART);
    hardcodearPaises(listaPaises,MAX_PAIS);


	 do{
	    	getInt("\n\nMENU\n1. Alta\n2. Baja\n3. Modificar\n4. Informar\n5. Listar \n6. Salir\n Opcion: ",&opcion,1,6);
	    	switch(opcion)
	    	{

	    	case 1://ALTA
	    		if(eAlbum_alta(albumes, CANT,listaDeArtistas, MAX_ART,listaDeTipoArtista,MAX_TART,listaDeDiscograficas, MAX_DISC,listaPaises,MAX_PAIS)!=-1)
	    		{
	    			contadorDatos++;
	    		}

	    		break;

	    	case 2://BAJA
	    		if(contadorDatos > 0)
	    		{
	    			if(eAlbum_baja(albumes, CANT,listaDeArtistas, MAX_ART,listaDeTipoArtista,MAX_TART,listaDeDiscograficas, MAX_DISC,listaPaises,MAX_PAIS)==1)
	    			{
	    				contadorDatos--;
	    			}
	    		}
	    		else
	    		{
	    			printf("No existen datos cargados...");
	    		}
	    		break;
	    	case 3://MODIFICAR
	    		if( contadorDatos > 0)
	    		{
                     eAlbum_modificar(albumes, CANT,listaDeArtistas, MAX_ART,listaDeTipoArtista,MAX_TART,listaDeDiscograficas, MAX_DISC,listaPaises,MAX_PAIS);

	    		}
	    		else
	    		{
	    			printf("No existen datos cargados...");
	    		}
	    		break;
	    	case 4://INFORMAR
	    		if( contadorDatos > 0)
	    		{
	    		   eAlbum_informar(albumes,CANT);

	    		}
	    		else
	    		{
	    			printf("No existen datos cargados...");
	    		}
	    		break;
	    	case 5://LISTAR
	    		if( contadorDatos > 0)
	    		{

	    			eAlbum_listar(albumes,CANT,listaDeArtistas, MAX_ART,listaDeTipoArtista,MAX_TART,listaDeDiscograficas, MAX_DISC,listaPaises,MAX_PAIS);
	    		}
	    		else
	    		{
	    			printf("No existen datos cargados...");
	    		}
	    		break;
	    	case 6:
	    		printf("Saliendo del menu.");
	    		break;


	    	}
	 }while(opcion != 6);






	return EXIT_SUCCESS;
}

