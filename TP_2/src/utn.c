#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "utn.h"


float sumar(float num1, float num2) {
	float rtn;
	rtn = num1 + num2;

	return rtn;
}

float restar(float num1, float num2) {
	float rtn;

	rtn = num1 - num2;

	return rtn;
}

float multiplicar(float num1, float num2) {
	float rtn;
	rtn = num1 * num2;

	return rtn;
}

float dividir(float num1, float num2) {
	float rtn;

	rtn=num1/num2;
	if(num2==0){
		rtn=0;
	}
	return rtn;

	return rtn;
}

int utn_myGets(char cadena[], int longitud){

	int retorno = -1;

	fflush(stdin);
	if(cadena != NULL && longitud > 0 && fgets(cadena, longitud, stdin))
	{
		if(cadena[strlen(cadena)-1] == '\n')
		{
			cadena[strlen(cadena)-1] = '\0' ;
		}
		retorno = 0;//OK
	}
	return retorno;
}


int utn_Get_Int(int *pResultado){

	int retorno = -1;
	char buffer[64];

	utn_myGets(buffer, 64);

	if(utn_esNumerica(buffer)==0)
	{
		*pResultado = atoi(buffer);
		retorno = 0;
	}

	return retorno;
}


int utn_esNumerica (char cadena[]){

	int retorno = 0;
	int i = 0;

	if(cadena != NULL && strlen(cadena) > 0)
	{
		while(cadena[i] != '\0')
		{
			if(cadena[i] < 48 || cadena[i] > 57)
			{
				retorno = -1;
				break;
			}
			i++;
		}
	}
	return retorno;
}

int getInt(char mensaje[],int reintentos, int minimo, int maximo, char mensajeError[], int *pNumeroIngresado){

	int retorno= -1;
	int auxiliarInt;
	int retornoScanf;

	if(mensaje!=NULL && reintentos>0 && minimo<maximo && mensajeError!=NULL && pNumeroIngresado!=NULL){

		printf("%s", mensaje);
		retornoScanf= scanf(" %d", &auxiliarInt);
		do{
			if(auxiliarInt<minimo || auxiliarInt>maximo || retornoScanf!=1)
			{
				printf("%s", mensajeError);
				retornoScanf= scanf(" %d", &auxiliarInt);
				reintentos--;
			}
			else
			{
				*pNumeroIngresado=auxiliarInt;
				reintentos=0;
				retorno=0;
			}

		}while(reintentos>0);
	}
	return retorno;
}


int getFloat(char mensaje[],int reintentos, int minimo, int maximo, char mensajeError[], float *pNumeroIngresado){

	int retorno= -1;
	float auxiliarFloat;
	int retornoScanf;

	if(mensaje!=NULL && reintentos>0 && minimo<maximo && mensajeError!=NULL && pNumeroIngresado!=NULL){

		printf("%s", mensaje);
		retornoScanf= scanf(" %f", &auxiliarFloat);
		do{
			if(auxiliarFloat<minimo || auxiliarFloat>maximo || retornoScanf!=1)
			{
				printf("%s", mensajeError);
				retornoScanf= scanf(" %f", &auxiliarFloat);
				reintentos--;
			}
			else
			{
				*pNumeroIngresado=auxiliarFloat;
				reintentos=0;
				retorno=0;
			}

		}while(reintentos>0);
	}

	return retorno;
}

int utn_getNumero(int *pResultado, char mensaje[], char mensajeError[], int minimo, int maximo, int reintentos){

	int retorno = -1;
	int num;

	while(reintentos>0)
	{
		printf(mensaje);
		if((utn_Get_Int(&num))!=0)
		{
			reintentos--;
			printf(mensajeError);
			fflush(stdin);
		}

		if(num<=maximo && num>=minimo)
		{
			break;
		}
	}

	if(reintentos!=0)
	{
		retorno = 0;
		*pResultado = num;
	}

	return retorno;

}


int continueOrNot(char message[], char errorMessage[]){

	int rtn = -1;//RETURN -1 IF ERROR
	char answer;

	if(message != NULL && errorMessage != NULL)
	{
		printf(message);
		getChar(&answer);
		answer = toupper(answer);

		while(answer != 83 && answer != 78)
		{
			printf(errorMessage);
			getChar(&answer);
			answer = toupper(answer);
		}

		if(answer==83)
		{
			rtn = 1;//RETURN 1 IF IT DOES WANT TO CONTINUE
		}
		else
		{
			rtn = 0;//RETURN 0 IF IT DOESN'T WANT TO CONTINUE
		}
	}

	return rtn;
}

int getChar(char *character){

	int rtn = -1;//ERROR - NULL POINTER

	if(character != NULL)
	{
		fflush(stdin);
		fgets(character, 2, stdin);
		rtn = 0;
	}

	return rtn;//RETURN 0 IF OK

}


int getEmail(char message[], char errorMessage, int retries, char email[]) {
	int rtn;
	char auxiliary[25];
	int i;
	int flag1 = 0;
	int flag2 = 0;

	if(email != NULL)
	{
		while(retries > 0)
		{
			printf(message);
			utn_myGets(auxiliary, 25);
			for(i=0; i > 25; i++)
			{
				if(flag1 == 0 && auxiliary[i] == '@')
				{
					flag1 = 1;
					continue;
				}
				if(flag1 == 1 && flag2 == 0 && auxiliary[i] == '.')
				{
					flag2 = 1;
					break;
				}
			}

			if(flag1 == 0 || flag2 == 0)
			{
				retries--;
			}
		}

	}
	else
	{
		rtn = -1;//ERROR NULL POINTER
	}

	return rtn;
}
