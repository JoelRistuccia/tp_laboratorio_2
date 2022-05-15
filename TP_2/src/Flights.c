#include "Flights.h"


int sFlights_initFlights (sFlight list[], int len) {
	int i;
	int rtn = 0;

	if (list != NULL)//VERIFIES IF THE ARRAY EXISTS
	{
		if(len > 0)//VERIFIES IF ARRAY LENGHT IS LARGER THAN 0
		{
			for (i = 0; i < len; i++) {
				list[i].statusFlight = UNACTIVE;//SET ISEMPTY FIELD AS AVAILABLE
			}
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

	return rtn;//RETURN 0 IF OK
}



int sFlight_findAvailableIndex(sFlight list[], int len) {

	int rtn = 0;
	int flag = 0;
	int i;

	if (list != NULL)
	{
		if (len > 0)
		{
			for (i = 0; i < len; i++)
			{
				if (list[i].statusFlight == UNACTIVE)
				{
					flag = 1;
					rtn = i;
					break;
				}
			}

			if (flag == 0)
			{
				rtn = -1;//ERROR - INDEX NOT FOUND
			}
		}
		else
		{
			rtn = -2;//ERROR - ARRAY LENGHT
		}
	}
	else
	{
		rtn = -3;//ERROR - ARRAY DOESN'T EXIST
	}

	return rtn;//RETURNS AVAILABLE INDEX
}


int sFlights_addFlight (sFlight listF[], int lenF, int index){

	int rtn;

	if(listF != NULL)
	{
		if(lenF > 0)
		{
			if(index > -1)
			{
				getInt("Ingrese el estado del vuelo (1. Activo / 2. Inactivo)\n", 10, 1, 2,
						"Error, reingrese\n" , &listF[index].statusFlight);
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


int sFlights_findFlightById(sFlight list[], int len, char id[]){

	int rtn;
	int i;

	if(list != NULL)//VERIFIES IF THE ARRAY EXISTS
	{
		if(len > 0)//VERIFIES IF ARRAY LENGHT IS LARGER THAN 0
		{
			for (i = 0; i < len; i++)//LOOP OVER THE ARRAY
			{
				//VERIFY IF ID EXISTS AND IF ITS STATE IS "ADDED"
				if(list[i].flyCode == id)
				{
					rtn = i;//RETURNS INDEX OF ID GIVEN
					break;
				}
				else
				{
					rtn = -1;//ERROR - ID DOESN'T EXISTS
				}
			}
		}
		else
		{
			rtn = -2;//ERROR - ARRAY LENGHT
		}
	}
	else
	{
		rtn = -3;//ERROR - ARRAY DOESN'T EXIST
	}

	return rtn;
}


int sFlight_RemoveFlight(sFlight list[], int len, char flyCode[]){


	int rtn = 0;//RETURN 0 IF OK
	int indexDelete;

	if (list != NULL)
	{
		if (len > 0)
		{
			printf("Ingrese el codigo de vuelo del vuelo que desea dar de baja:\n");
			fflush(stdin);
			utn_myGets(flyCode, MAX_LEN_STRING);
			indexDelete = sFlight_findFlightByFlyCode(list, len, flyCode);
			if (indexDelete < 0)
			{
				rtn = -1;//ERROR - INDEX NOT FOUND
			}
			else
			{
				if(continueOrNot("Desea confirmar el cambio? (S/N)", "Error, reingrese (S/N)")){
					list[indexDelete].statusFlight = UNACTIVE;
					printf("Baja exitosa.\n");
					system("pause");
				}

			}
		}
		else
		{
			rtn = -2;//ERROR - ARRAY LENGHT
		}
	}
	else
	{
		rtn = -3;//ERROR - ARRAY DOESN'T EXIST
	}

	return rtn;
}


int sFlight_findFlightByFlyCode(sFlight list[], int len, char flyCode[]){

	int rtn;
	int i;

	if(list != NULL)//VERIFIES IF THE ARRAY EXISTS
	{
		if(len > 0)//VERIFIES IF ARRAY LENGHT IS LARGER THAN 0
		{
			for (i = 0; i < len; i++)//LOOP OVER THE ARRAY
			{
				//VERIFY IF ID EXISTS AND IF ITS STATE IS "ADDED"
				if(list[i].flyCode == flyCode && list[i].statusFlight == ACTIVE)
				{
					rtn = i;//RETURNS INDEX OF ID GIVEN
					break;
				}
				else
				{
					rtn = -1;//ERROR - ID DOESN'T EXISTS
				}
			}
		}
		else
		{
			rtn = -2;//ERROR - ARRAY LENGHT
		}
	}
	else
	{
		rtn = -3;//ERROR - ARRAY DOESN'T EXIST
	}

	return rtn;
}


void sFlight_printFlight(sFlight Flight){

	if(Flight.statusFlight == ACTIVE)
	{
		printf("%12s", "ACTIVO");
	}
	else
	{
		printf("%15s", "INACTIVO");
	}
	printf("%8s", "|\n");
}


void sFlight_hardCode(sFlight list[]){

	strcpy(list[0].flyCode, "ABC123");
	list[0].statusFlight = 2;

	strcpy(list[1].flyCode, "LOL345");
	list[1].statusFlight = 2;

	strcpy(list[2].flyCode, "ACV138");
	list[2].statusFlight = 2;

}
