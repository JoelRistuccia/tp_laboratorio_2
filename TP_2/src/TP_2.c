#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "utn.h"
#include "Passenger_Flights.h"

#define LEN_FLYCODE 10
#define MAX_PASSENGERS 2000
#define MAX_FLIGHTS 100

int main(void) {
	setbuf(stdout, NULL);//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

	sPassenger passengerList[MAX_PASSENGERS];
	sFlight flightList[MAX_FLIGHTS];

	int option;
	int orderCriteria;

	sPassenger_initPassenger(passengerList, MAX_PASSENGERS);
	sFlights_initFlights(flightList, MAX_FLIGHTS);

	do{
		puts("\t\t\t::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::");
		puts("\t\t\t:: *BIENVENIDO A LA BASE DE DATOS DE AEROLINEAS ARGENTINAS* ::");
		puts("\t\t\t::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n\n");


		getInt("Ingrese la opcion deseada:\n"
				"1. Alta de pasajero\n"
				"2. Modificar datos\n"
				"3. Baja de pasajero\n"
				"4. Informes\n"
				"5. Carga forzada\n"
				"6. Salir\n\n", 10, 1, 10, "Error, reingrese\n", &option);

		switch(option)
		{
		case 1:
			system("cls");
			Passenger_Flights_Upload(flightList, MAX_FLIGHTS, passengerList, MAX_PASSENGERS);
			break;
		case 2:
			system("cls");
			sPassenger_Modify(passengerList, MAX_PASSENGERS);
			break;
		case 3:
			system("cls");
			Passenger_Flights_printAll(passengerList, MAX_PASSENGERS, flightList, MAX_FLIGHTS, ADDED);
			sPassenger_removePassenger(passengerList, MAX_PASSENGERS);
			break;
		case 4:
			system("cls");
			getInt("Ingrese el orden deseado: (1. Ascendente 2. Descendente)\n",
					10, 1, 2, "Error, reingrese", &orderCriteria);
			sPassenger_sortPassengersByName(passengerList, MAX_PASSENGERS, orderCriteria);
			system("pause");
			system("cls");
			break;
		case 5:
			system("cls");
			if(continueOrNot("Usted ha ingresado la opcion CARGA FORZADA, desea continuar?"
					" (S/N)\n", "Error, reingrese\n"))
			{
				sPassenger_hardCode(passengerList);
				sFlight_hardCode(flightList);
				system("pause");
				system("cls");
			}
			break;

		}//END SWITCH




	} while(option != 6);













}
