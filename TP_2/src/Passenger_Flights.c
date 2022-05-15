#include "Passenger_Flights.h"

int Passenger_Flights_Upload(sFlight listF[], int lenF, sPassenger listP[], int lenP){

	int rtn;
	int pass_Index;
	int fly_Index;
	sPassenger pAux;

	if(listF != NULL && listP != NULL)
	{
		if(lenF > 0 && lenP > 0)
		{
			pass_Index = sPassenger_findAvailableIndex(listP, lenP);

			sPassenger_addPassenger(listP, lenP, &pAux.id, pAux.name, pAux.lastName, &pAux.price,
					pAux.typePassenger, pAux.FK_flyCode);
			pAux.isEmpty = ADDED;
			fly_Index = sFlight_findAvailableIndex(listF, lenF);
			sFlights_addFlight(listF, lenF, fly_Index);
			if(continueOrNot("Confirmar el alta? (S/N)\n", "Error, reingrese (S/N)\n"))
			{
				strcpy(listF[fly_Index].flyCode, listP[pass_Index].FK_flyCode);
				listP[pass_Index] = pAux;
				puts("Carga exitosa.");
				system("pause");
				system("cls");
				rtn = 0;
			}
		}
		else
		{
			rtn = -1;
		}
	}
	else
	{
		rtn = -2;
	}

	return rtn;
}


int Passenger_Flights_printAll(sPassenger listP[], int lenP, sFlight listF[], int lenF, int status) {
	int rtn = 1;
	int i;
	int flag = 0;
	int indexFlight;


	puts("\n\t> LISTADO Pasajeros:");
	puts("+----+---------------+--------------+------------------+----------+----------------------+------------------+");
	printf("|%3s%12s%18s%20s%10s%23s%20s |\n", "ID", "NOMBRE", "APELLIDO",
			"CODIGO DE VUELO", "PRECIO", "TIPO DE PASAJERO", "ESTADO DE VUELO");
	puts("+----+---------------+--------------+------------------+----------+----------------------+------------------+");

	if (listP != NULL && listF != NULL)
	{
		if (lenP > 0 && lenF > 0)
		{
			for (i = 0; i < lenP; i++)
			{
				if (listP[i].isEmpty == status)
				{
					sPassenger_printPassenger(listP[i]);
					indexFlight = Passenger_Flights_FindFlightIndexByFlyCode(listP[i].FK_flyCode, listF, lenF);
					if(indexFlight > -1)
					{
						sFlight_printFlight(listF[indexFlight]);
					}
					flag = 1;
				}
			}
			puts("+----+---------------+--------------+------------------+----------+----------------------+------------------+");
		}
		else
		{
			rtn = -1;//ERROR - ARRAY LENGHT
		}
	}
	else
	{
		rtn = -2;//ERROR - ARRAY DOESN'T EXIST
	}

	if(flag == 0)
	{
		rtn = 0;//ERROR - NO COINCIDENCES WITH THE STATUS GIVEN
	}


	return rtn;
}


int Passenger_Flights_FindFlightIndexByFlyCode(char pFlyCode[], sFlight listF[], int lenF){

	int rtn;
	int i;

	if(listF != NULL)
	{
		if(lenF > 0)
		{
			for(i = 0; i < lenF; i++)
			{
				if(strcmp(pFlyCode, listF[i].flyCode) == 0)
				{
					rtn = i;
				}
			}
		}
		else
		{
			rtn = -1;
		}
	}
	else
	{
		rtn = -2;
	}

	return rtn;
}
