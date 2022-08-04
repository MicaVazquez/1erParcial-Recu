/*
 * album.h
 *
 *  Created on: 30 abr. 2022
 *      Author: PC-INC
 */

#ifndef ALBUM_H_
#define ALBUM_H_

typedef struct
{
	int dia;
	int mes;
	int anio;

}eFecha;

typedef struct
{
	int codigoTipoArtista;//PK
	char descripcionTipoArtista[51];

}eTipoArtista;//(1, solista; 2, banda)

typedef struct
{
	int codigoDeArtista;//PK
	char nombreArtista[51];

}eArtista;

typedef struct
{
	int idPais;
	char descripcionPais[51];

}ePais;


typedef struct
{
	int codigoDeDiscografica;//PK
	char descripcionDiscografica[51];
}eDiscografica;

typedef struct
{
  int estado;
  int codigoTipoArtista;//FK
  int codigoDeArtista;//FK
  int codigoDeDiscografica;//FK
  int idPais; //FK
  int codigoDeAlbum;
  char titulo[51];
  eFecha fechaDePublicacion;
  int importe;

}eAlbum;

/**
 * @brief inicializa todos los estados en libre(0);
 *
 * @param list de albumes
 * @param len  tamanio
 * @return retorna -1 si len es menor que 0 y list es NULL, si esta ok retorna 0
 */
int eAlbum_inicializar(eAlbum* list, int len);
/**
 * @brief controla el alta de un pasajero
 *
 * @param list lista de albumes
 * @param len  tamanio de lista de albumes
 * @param listaDeTipoArtista  lista de tipo artista
 * @param limTipoArtista tamanio de lista de tipo artista
 * @param listaDeDiscograficas  lista
 * @param limDisc  tamanio de lista de discografia
 * @param listaDeArtistas
 * @param limArt  tamanio de lista de artistas
 * @param listaPais
 * @param limPais tamanio de lista de pais
 * @return
 */
int eAlbum_alta(eAlbum list[], int len,eArtista listaDeArtistas[], int limArt,eTipoArtista listaDeTipoArtista[],int limTipoArtista,eDiscografica listaDeDiscograficas[],int limDisc,ePais listaPais[],int limPais);

//void eAlbum_imprimirUno(eAlbum unAlbum);

//void eAlbum_imprimirTodos(eAlbum* list, int largo);
/**
 * @brief pide dia, mes y anio
 *
 * @return returna una variable de tipo eFecha
 */
eFecha pedirFecha();
/**
 * @brief busca en que este seteado en libre(0)
 *
 * @param list
 * @param len tamanio
 * @return retorna el primer indice libre encontrado
 */
int buscarLibre(eAlbum* list, int len);
/**
 * @brief recorre la lista de albumes
 *
 * @param list
 * @param len
 * @param codigo
 * @return retrona el indice que coincide el codigo
 */
int eAlbum_encontrarPorCodigo(eAlbum* list, int len,int codigo);
 /**
   * @brief cargar un album
  *
  * @param listaDeTipoArtista
  * @param limTipoArtista
  * @param listaDeDiscograficas
  * @param limDisc
  * @param listaDeArtistas
  * @param limArt
  * @param listaPais
  * @param limPais
  * @return devulve un album
  */
eAlbum cargarUno(eArtista listaDeArtistas[], int limArt,eTipoArtista listaDeTipoArtista[],int limTipoArtista,eDiscografica listaDeDiscograficas[],int limDisc,ePais listaPais[],int limPais);
/**
 * @brief modifica un album en cualquiera de sus campos
 *
 * @param list lista  de albumes
 * @param lenAlb tamanio lista  de albumes
 * @param listArt lista de artistas
 * @param lenArt tamanio de lista de artistas
 * @param listDisco lista de discograficas
 * @param lenDisc tamanio lista de discograficas
 * @param listTipoArt lista de tipo de artistas
 * @param lenTipoArt tamanio lista de tipo de artistas
 * @param listPais lista de paises
 * @param lenPais tamanio lista de paises
 */
void eAlbum_modificar(eAlbum list[], int len,eArtista listaDeArtistas[], int tamArt, eTipoArtista listaDeTipoArtista[],int tamTipoArtista,eDiscografica listaDeDiscograficas[],int tamDisc,ePais listaPais[],int limPais);
/**
 * @brief setea el estado del album que se quiere dar de baja en -1
 *
 * @param list
 * @param len tamanio
 * @return devulve 1 si se dio de baja con exito y 0 si no
 */
int eAlbum_baja(eAlbum* list, int len,eArtista* listArt,int lenArt,eTipoArtista* listTipoArt, int lenTipoArt,eDiscografica* listDisco,int lenDisc,ePais* listPais,int lenPais);
/**
 * @brief calacula de promedio total y muestra los labumes que no sobrepasan ese promedio
 *
 * @param lista
 * @param tam
 */
void eAlbum_importeTotalPromedio(eAlbum lista[], int tam);
/**
 * @brief carga los albumes con datos
 *
 * @param lista
 */
void eAlbum_hardcodearDatos(eAlbum lista[]);
/**
 * @brief cuenta cuantos albumes son posteriores a 1999
 *
 * @param list lista de albumes
 * @param len tamanio
 */
void eAlbum_posterior(eAlbum list[], int len);
/**
 * @brief controla la parte de informar
 *
 * @param list lista de albumes
 * @param len tamanio de la lista
 */
void eAlbum_informar(eAlbum list[], int len);
/**
 * @brief controla la parte del listar
 *
 * @param list lista  de albumes
 * @param lenAlb tamanio lista  de albumes
 * @param listArt lista de artistas
 * @param lenArt tamanio de lista de artistas
 * @param listDisco lista de discograficas
 * @param lenDisc tamanio lista de discograficas
 * @param listTipoArt lista de tipo de artistas
 * @param lenTipoArt tamanio lista de tipo de artistas
 * @param listPais lista de paises
 * @param lenPais tamanio lista de paises
 */
void eAlbum_listar(eAlbum list[], int tam,eArtista listaArtistas[],int lenArt,eTipoArtista listaTipoArtista[],int lenTipoArtista,eDiscografica listaDiscograficas[],int lenDisc,ePais listaPais[],int lenPais);
/**
 * @brief inicializa tipo de artista con datos
 *
 * @param lista array
 * @param lim tamaño
 */
void hardcodearTipoArtista(eTipoArtista lista[], int lim);
/**
 * @brief inicializa discografias con datos
 *
 * @param lista array
 * @param lim tamaño
 */
void hardcodearDiscograficas(eDiscografica lista[], int lim);
/**
 * @brief inicializa artistas con datos
 *
 * @param lista array
 * @param lim  tamaño
 */
void hardcodearArtistas(eArtista lista[], int lim);
/**
 * @brief ordena por doble criterio: los albumes de forma descendente por importe y ascendente por titulo
 *
 * @param list array
 * @param len tamaño
 */
void ordenarAlbumes(eAlbum list[],int len);

/**
 * @brief la funcion lista todos los tipos de artistas
 *
 * @param albumes array album
 * @param len
 * @param listaDeTipoArtista
 * @param lenTipoArtista
 */
void listarTiposArtistas(eTipoArtista listaDeTipoArtista[], int lenTipoArtista);
/**
 * @brief la funcion lista todos los artistas
 *
 * @param albumes
 * @param len
 * @param listaDeArtistas
 * @param lenArt
 */
void listarArtistas(eArtista listaDeArtistas[], int lenArt);
/**
 * @brief la funcion lista todas las discograficas
 *
 * @param albumes
 * @param len
 * @param listaDeDiscograficas
 * @param lenDisc
 */
void listarDiscograficas(eDiscografica listaDeDiscograficas[], int lenDisc);

/**
 * @brief lista los ambumes posteriores a 1999
 *
 * @param list array
 * @param len tamaño
 */
void listarPosteriores(eAlbum list[],int len,eArtista* listArt,int lenArt,eTipoArtista* listTipoArtista,int lenTipoArt, eDiscografica* listDisco,int lenDisco,ePais* listPais,int lenPais);

/**
 * @brief lista albumes que no superan el rpomedio
 *
 * @param list array
 * @param tam  tamaño
 */
void listarMenorAlPromedio(eAlbum list[],int tam,eArtista* listArt,int lenArt,eTipoArtista* listTipoArtista,int lenTipoArt, eDiscografica* listDisco,int lenDisco,ePais* listPais,int lenPais);

/**
 * @brief lista de albumes por cada artista
 *
 * @param albumes lista de albumes
 * @param tam  largo de la lista
 * @param artistas lista de artistas
 * @param lenArt  largo de la lista
 */
void listarAlbumesPorArtistas(eAlbum albumes[],int tam, eArtista* listArt,int lenArt,eTipoArtista* listTipoArtista,int lenTipoArt, eDiscografica* listDisco,int lenDisco,ePais* listPais,int lenPais);

/**
 * @brief muestra todos lo albumes que esten ocupados en la lista
 *
 * @param list lista  de albumes
 * @param lenAlb tamanio lista  de albumes
 * @param listArt lista de artistas
 * @param lenArt tamanio de lista de artistas
 * @param listDisco lista de discograficas
 * @param lenDisc tamanio lista de discograficas
 * @param listTipoArt lista de tipo de artistas
 * @param lenTipoArt tamanio lista de tipo de artistas
 * @param listPais lista de paises
 * @param lenPais tamanio lista de paises
 */
void eAlbum_muestraTodos(eAlbum* list, int lenAlb, eArtista* listArt,int lenArt,eTipoArtista* listTipoArt, int lenTipoArt,eDiscografica* listDisco,int lenDisc,ePais* listPais,int lenPais);
/**
 * @brief muestra solo uno
 *
 * @param unAlbum
 * @param unArtista
 * @param unTipoArtista
 * @param unaDiscografica
 * @param unPais
 */
void eAlbum_muestraUno(eAlbum unAlbum, eArtista unArtista, eTipoArtista unTipoArtista,eDiscografica unaDiscografica,ePais unPais);

/**
 * @brief busca el menor impoprte y mustra el mas barato de los albumes
 *
 * @param list lista de albumes
 * @param len  tamanio
 */
void listarMasBarato(eAlbum* list,int len,eArtista* listArt,int lenArt,eTipoArtista* listTipoArt, int lenTipoArt,eDiscografica* listDisco,int lenDisc,ePais* listPais,int lenPais);
/**
 * @brief busca el maximo año y minimo, y muestra los albumes por cada año
 *
 * @param list lista
 * @param len tamanio
 */
void listarAlbumesXAnio(eAlbum* list,int len,eArtista* listArt,int lenArt,eTipoArtista* listTipoArt, int lenTipoArt,eDiscografica* listDisco,int lenDisc,ePais* listPais,int lenPais);
/**
 * @brief encabezamiento
 *
 */
void eAlbum_header();
 /**
   * @brief inicializa con datos la lista de paises
  *
  * @param listPais array de tipo Pais
  * @param lenPais tamanio
  */
void hardcodearPaises(ePais* listPais, int lenPais);
/**
 * @brief muestra solo los albumes de argentina
 *
 * @param list lista de albumes
 * @param lenAlb tamanio de albumes
 * @param listArt lista de artistas
 * @param lenArt tamanio de artistas
 * @param listTipoArtista lista de tipo artista
 * @param lenTipoArt tamanio de tipo artista
 * @param listDisco lista de discografica
 * @param lenDisco tamanio de discograficas
 * @param listPais lista de paises
 * @param lenPais tamanio de paises
 */
void listarAlbumesArg(eAlbum* list,int lenAlb,eArtista* listArt,int lenArt,eTipoArtista* listTipoArtista,int lenTipoArt, eDiscografica* listDisco,int lenDisco,ePais* listPais,int lenPais);
/**
 * @brief muestra todos los albumes menos los de argentina
 *
 * @param list lista de albumes
 * @param lenAlb tamanio de albumes
 * @param listArt lista de artistas
 * @param lenArt tamanio de artistas
 * @param listTipoArtista lista de tipo artista
 * @param lenTipoArt tamanio de tipo artista
 * @param listDisco lista de discografica
 * @param lenDisco tamanio de discograficas
 * @param listPais lista de paises
 * @param lenPais tamanio de paises
 */
void listarTodosMenosArg(eAlbum* list,int lenAlb,eArtista* listArt,int lenArt,eTipoArtista* listTipoArtista,int lenTipoArt, eDiscografica* listDisco,int lenDisco,ePais* listPais,int lenPais);
/**
 * @brief muestra todos los paises

 * @param listPaises lista de paises
 * @param lenPais tamanio de lista de paises
 */
void listarPaises(ePais listPaises[], int lenPais);
/**
 * @brief imprime uno con todos los campos
 *
 * @param unAlbum
 * @param listArt lista de artistas
 * @param lenArt  tamanio de lista de artistas
 * @param listTipoArtista lista de tipo artistas
 * @param lenTipoArt tamanio lista de tipo artistas
 * @param listDisco lista de discograficas
 * @param lenDisco tamanio lista de discograficas
 * @param listPais lista de Pais
 * @param lenPais tamanio lista de paises
 */
void imprimirUnoCompleto(eAlbum unAlbum,eArtista* listArt,int lenArt,eTipoArtista* listTipoArtista,int lenTipoArt, eDiscografica* listDisco,int lenDisco,ePais* listPais,int lenPais);


/**
 * @brief pide unn artista y lista los albumes que le pertenecen
 *
 * @param list lista  de albumes
 * @param lenAlb tamanio lista  de albumes
 * @param listArt lista de artistas
 * @param lenArt tamanio de lista de artistas
 * @param listDisco lista de discograficas
 * @param lenDisc tamanio lista de discograficas
 * @param listTipoArt lista de tipo de artistas
 * @param lenTipoArt tamanio lista de tipo de artistas
 * @param listPais lista de paises
 * @param lenPais tamanio lista de paises
 */
void listarAlbumesArtistaDeterminado(eAlbum* listAlbumes,int lenAlb,eArtista* listArt,int lenArt,eTipoArtista* listTipoArtista,int lenTipoArt, eDiscografica* listDisco,int lenDisco,ePais* listPais,int lenPais);

/**
 * @brief pide un anio y si hay albumes de argentina en ese anio, los muestra.
 *
 * @param list lista  de albumes
 * @param lenAlb tamanio lista  de albumes
 * @param listArt lista de artistas
 * @param lenArt tamanio de lista de artistas
 * @param listDisco lista de discograficas
 * @param lenDisc tamanio lista de discograficas
 * @param listTipoArt lista de tipo de artistas
 * @param lenTipoArt tamanio lista de tipo de artistas
 * @param listPais lista de paises
 * @param lenPais tamanio lista de paises
 */
void listarAlbumesArgentinaAnioDeterminado(eAlbum* list,int lenAlb,eArtista* listArt,int lenArt,eTipoArtista* listTipoArtista,int lenTipoArt, eDiscografica* listDisco,int lenDisco,ePais* listPais,int lenPais);

/**
 * @brief ordena por anios
 *
 * @param list lista  de albumes
 * @param lenAlbum tamanio lista  de albumes
 */
void eAlbum_ordenarAnios(eAlbum* list, int lenAlbum);
/**
 * @brief
 *
 * @param listAlbumes
 * @param len
 * @param listArt
 * @param lenArt
 * @param listTipoArtista
 * @param lenTipoArt
 * @param listDisco
 * @param lenDisco
 * @param listPais
 * @param lenPais
 */
void informaSolistasAniPaisDeterminado(eAlbum* listAlbumes,int len,eArtista* listArt,int lenArt,eTipoArtista* listTipoArtista,int lenTipoArt, eDiscografica* listDisco,int lenDisco,ePais* listPais,int lenPais);
/**
 * @brief
 *
 * @param listaPais
 * @param lenPais
 * @param opcion
 */
void encontrarPais(ePais* listaPais, int lenPais,int opcion);
/**
 * @brief
 *
 * @param listAlbumes
 * @param len
 * @param listArt
 * @param lenArt
 * @param listTipoArtista
 * @param lenTipoArt
 * @param listDisco
 * @param lenDisco
 * @param listPais
 * @param lenPais
 */
void listarBandasExtranjeras(eAlbum* listAlbumes,int len,eArtista* listArt,int lenArt,eTipoArtista* listTipoArtista,int lenTipoArt, eDiscografica* listDisco,int lenDisco,ePais* listPais,int lenPais);
#endif /* ALBUM_H_ */
