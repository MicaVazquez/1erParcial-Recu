/*
 * validaciones.h
 *
 *  Created on: 14 abr. 2022
 *      Author: PC-INC
 */
//PROTOTIPO/FIRMA
#ifndef VALIDACIONES_H_
#define VALIDACIONES_H_
/**
 * @brief La funcion pide un entero positivo y valida que sea mayor que 0.
 *
 * @param mensaje  Mensaje para que el usuario sepa que ingresar.
 * @param error    Mensaje para que reingrese.
 * @return         Devuelve un entero.
 */

/**
 * @brief la funcion pide un palabra
 *
 * @param mensaje Mensaje para que el usuario sepa que ingresar
 * @param input lo que se ingresa
 * @param tamMin tamanio minimo
 * @param tamMax tamanio maximo
 */
void getString(char mensaje[],char input[],int tamMin,int tamMax);
/**
 * @brief la funcion pide un entero
 *
 * @param mensaje
 * @param numero
 * @param tamMin
 * @param tamMax
 */
void getInt(char mensaje[],int *numero,int tamMin,int tamMax);
void getFloat(char mensaje[],float *numero,float tamMin,float tamMax);
int getCaracter(char* pResultado, char* mensaje, char* mensajeError, char minimo, char maximo);



#endif /* VALIDACIONES_H_ */
