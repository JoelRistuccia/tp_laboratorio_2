#include "ArrayPassenger.h"

static int sPassenger_GetId(void);

static int sPassenger_GetId(void){
	static int Pass_id = 1000;
	return ++Pass_id;
}


int sPassenger_initPassenger (sPassenger list[], int len) {
	int i;
	int rtn = 0;

	if (list != NULL)//VERIFIES IF THE ARRAY EXISTS
	{
		if(len > 0)//VERIFIES IF ARRAY LENGHT IS LARGER THAN 0
		{
			for (i = 0; i < len; i++) {
				list[i].isEmpty = AVAILABLE;//SET ISEMPTY FIELD AS AVAILABLE
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


int sPassenger_addPassenger(sPassenger listP[], int lenP, int *id, char name[],char lastName[], float *price,
		int typePassenger, char flyCode[]){

	int rtn = 0;//RETURN 0 IF OK
	int availableIndex;

	if(listP != NULL)//VERIFIES IF THE ARRAY EXISTS
	{
		if(lenP > 0)//VERIFIES IF ARRAY LENGHT IS LARGER THAN 0
		{
			availableIndex = sPassenger_findAvailableIndex(listP, lenP);//SEARCH FIRST AVAILABLE INDEX
			if(availableIndex > -1)//IF FOUND AN AVAILABLE INDEX ASKS FOR PASSENGER DATA
			{
				sPassenger_getPassengerInfo(id, name, lastName, price, typePassenger, flyCode);
			}
			else
			{
				printf("Error, lista llena");//ERROR - INDEX NOT FOUND
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

	return rtn;
}


int sPassenger_findPassengerById(sPassenger list[], int len, int id){

	int rtn;
	int i;

	if(list != NULL)//VERIFIES IF THE ARRAY EXISTS
	{
		if(len > 0)//VERIFIES IF ARRAY LENGHT IS LARGER THAN 0
		{
			for (i = 0; i < len; i++)//LOOP OVER THE ARRAY
			{
				//VERIFY IF ID EXISTS AND IF ITS STATE IS "ADDED"
				if(list[i].id == id && list[i].isEmpty == ADDED)
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


int sPassenger_removePassenger(sPassenger list[], int len){

	int rtn = 0;//RETURN 0 IF OK
	int indexDelete;
	int idToRemove;

	if (list != NULL)
	{
		if (len > 0)
		{
			utn_getNumero(&idToRemove, "Ingrese el ID del pasajero que desea dar de baja:\n",
					"Error, reingrese\n", 1000, 3000, 10);
			indexDelete = sPassenger_findPassengerById(list, len, idToRemove);
			if (indexDelete < 0)
			{
				rtn = -1;//ERROR - INDEX NOT FOUND
			}
			else
			{
				if(continueOrNot("¿Desea confirmar la baja del pasajero? (S/N)\n",
						"Error, ingrese nuevamente: (S/N)\n")){
					list[indexDelete].isEmpty = REMOVED;
					printf("Baja exitosa.\n");
					system("pause");
					system("cls");
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


int sPassenger_sortPassengersByName(sPassenger list[], int len, int order){

	int rtn;
	int i;
	int j;
	sPassenger aux;

	if (list != NULL)
	{
		if(len > 0)
		{
			switch (order){
			case 1:
				for (i = 0; i < len - 1; i++)
				{
					for (j = i + 1; j < len; j++)
					{
						//VERIFY IF ISEMPTY STATE IS "ADDED" IN BOTH
						if (list[i].isEmpty == ADDED && list[j].isEmpty == ADDED)
						{
							if (list[i].lastName[0] > list[j].lastName[0])//ORDERING CRITERIA - ASCENDENT
							{
								aux = list[i];//EXCHANGE ARRAY POSITIONS
								list[i] = list[j];
								list[j] = aux;
							}
						}
					}
				}
				rtn = 0;//RETURN 0 IF OK
				break;
			case 2:
				for (i = 0; i < len - 1; i++) {
					for (j = i + 1; j < len; j++) {
						//VERIFY IF ISEMPTY STATE IS "ADDED" IN BOTH
						if (list[i].isEmpty == ADDED && list[j].isEmpty == ADDED) {
							if (list[i].lastName[0] < list[j].lastName[0])//ORDERING CRITERIA - DESCENDENT
							{
								aux = list[i];//EXCHANGE ARRAY POSITIONS
								list[i] = list[j];
								list[j] = aux;
							}
						}
					}
				}

				rtn = 0;//RETURN 0 IF OK
				break;
			default:
				rtn = -1;//ERROR - INCORRECT ORDER
				break;
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


int sPassenger_sortPassengersByCode (sPassenger list[], int len, int order)
{
	int rtn;
	int i;
	int j;
	sPassenger aux;

	if (list != NULL)
	{
		if(len > 0)
		{
			switch (order)
			{
			case 1:
				for (i = 0; i < len - 1; i++)
				{
					for (j = i + 1; j < len; j++)
					{
						//VERIFY IF ISEMPTY STATE IS "ADDED" IN BOTH
						if (list[i].isEmpty == ADDED && list[j].isEmpty == ADDED)
						{
							if (list[i].FK_flyCode[0] > list[j].FK_flyCode[0])//ORDERING CRITERIA - ASCENDENT
							{
								aux = list[i];//EXCHANGE ARRAY POSITIONS
								list[i] = list[j];
								list[j] = aux;
							}
						}
					}
				}
				rtn = 0;//RETURN 0 IF OK
				break;
			case 0:
				for (i = 0; i < len - 1; i++) {
					for (j = i + 1; j < len; j++) {
						//VERIFY IF ISEMPTY STATE IS "ADDED" IN BOTH
						if (list[i].isEmpty == ADDED && list[j].isEmpty == ADDED) {
							if (list[i].FK_flyCode[0] < list[j].FK_flyCode[0])//ORDERING CRITERIA - DESCENDENT
							{
								aux = list[i];//EXCHANGE ARRAY POSITIONS
								list[i] = list[j];
								list[j] = aux;
							}
						}
					}
				}

				rtn = 0;//RETURN 0 IF OK
				break;
			default:
				rtn = -1;//ERROR - INCORRECT ORDER
				break;
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


int sPassenger_findAvailableIndex(sPassenger list[], int len) {

	int rtn = 0;
	int flag = 0;
	int i;

	if (list != NULL)
	{
		if (len > 0)
		{
			for (i = 0; i < len; i++)
			{
				if (list[i].isEmpty == AVAILABLE)
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


void sPassenger_printPassenger(sPassenger Passenger) {

	printf("|%d|", Passenger.id);
	printf("%9s", Passenger.name);
	printf("%7s", "|");
	printf("%12s", Passenger.lastName);
	printf("%3s", "|");
	printf("%11s", Passenger.FK_flyCode);
	printf("%8s", "|");
	printf("%8.2f", Passenger.price);
	printf("%3s", "|");

	if(Passenger.typePassenger == TOURIST)
	{
		printf("%14s", "TURISTA");
		printf("%9s", "|");
	}
	else
	{
		if(Passenger.typePassenger == EXECUTIVE)
		{
			printf("%15s", "EJECUTIVO");
			printf("%8s", "|");
		}
		else
		{
			printf("%18s", "PRIMERA CLASE");
			printf("%5s", "|");
		}
	}

}



int sPassenger_Modify(sPassenger list[], int len) {

	int rtn = -1;
	int idToModify;
	int indexToModify;
	sPassenger auxiliary;

	if(list != NULL)
	{
		if(len > 0)
		{
			printf("\n\nIngrese el ID del cual desea modificar los datos:\n");
			fflush(stdin);
			utn_Get_Int(&idToModify);

			while(sPassenger_findPassengerById(list, len, idToModify) == -1)//LOOK FOR THE INDEX OF THE ID
			{
				puts("Error, no existe el ID, ingrese otro:");
				utn_Get_Int(&idToModify);//ERROR - ID DOESN'T EXISTS
			}

			indexToModify = sPassenger_findPassengerById(list, len, idToModify);//SAVE THE INDEX OF THE ID

			auxiliary = sPassenger_ModifyOne(list[indexToModify]);//ASKS FOR THE DATA TO MODIFY
			//ASKS TO CONFIRM CHANGES
			if(continueOrNot("¿Confirmar cambios? (S/N)", "Error, reingrese (S/N)"))
			{
				list[indexToModify] = auxiliary;
				rtn = 1;
				printf("Modificacion exitosa.\n");
				system("cls");
			}
		}
		else
		{
			rtn = -1;//ERROR - ARRAY LENGHT
		}
	}
	else
	{
		rtn = -2;//ERROR - NULL POINTER
	}

	return rtn;
}


sPassenger sPassenger_ModifyOne(sPassenger Passenger){

	sPassenger auxiliary = Passenger;
	int chosenOption;

	puts("Seleccione la opcion del dato a modificar\n"
			"1. Nombre\n"
			"2. Apellido\n"
			"3. Precio\n"
			"4. Codigo de vuelo\n"
			"5. Tipo de pasajero");

	utn_Get_Int(&chosenOption);//ASKS FOR THE FIELD TO MODIFY
	while(chosenOption < 1 || chosenOption > 5)
	{
		puts("Error, reingrese");
		utn_Get_Int(&chosenOption);
	}
	//ASKS FOR NEW DATA FOR THE FIELD CHOSEN
	switch(chosenOption){
	case 1:
		puts("Ingrese el nombre del pasajero:");
		fflush(stdin);
		utn_myGets(auxiliary.name, MAX_LEN_STRING);
		break;
	case 2:
		puts("Ingrese el apellido del pasajero:");
		fflush(stdin);
		utn_myGets(auxiliary.lastName, MAX_LEN_STRING);
		break;
	case 3:
		getFloat("Ingrese el precio\n", 10, 0, 100000, "Error, reingrese precio\n", &auxiliary.price);
		break;
	case 4:
		puts("Ingrese el codigo de vuelo:");
		fflush(stdin);
		utn_myGets(auxiliary.FK_flyCode, MAX_LEN_STRING);
		break;
	case 5:
		utn_getNumero(&auxiliary.typePassenger, "Ingrese el tipo de pasajero: 1. Primera clase / 2. Ejecutivo / 3. Turista\n",
				"Error, reingrese tipo de pasajero:\n", 1, 3, 10);
		break;
	}

	return auxiliary;//RETURN A COPY OF THE VARIABLE WITH THE CHOSEN FIELDS MODIFIED
}


void sPassenger_hardCode(sPassenger list[]){

	list[0].id = 1000;
	list[0].isEmpty = ADDED;
	strcpy(list[0].FK_flyCode, "ABC123");
	strcpy(list[0].name, "Juana");
	strcpy(list[0].lastName, "Diarco");
	list[0].price = 200;
	list[0].typePassenger = TOURIST;

	list[1].id = 1001;
	list[1].isEmpty = ADDED;
	strcpy(list[1].FK_flyCode, "ACV138");
	strcpy(list[1].name, "Mario");
	strcpy(list[1].lastName, "Bravo");
	list[1].price = 300;
	list[1].typePassenger = FIRST_CLASS;

	list[2].id = 1002;
	list[2].isEmpty = ADDED;
	strcpy(list[2].FK_flyCode, "ABC123");
	strcpy(list[2].name, "Pedro");
	strcpy(list[2].lastName, "Gomez");
	list[2].price = 700;
	list[2].typePassenger = EXECUTIVE;

	list[3].id = 1003;
	list[3].isEmpty = ADDED;
	strcpy(list[3].FK_flyCode, "LOL345");
	strcpy(list[3].name, "Mariano");
	strcpy(list[3].lastName, "Golez");
	list[3].price = 900;
	list[3].typePassenger = TOURIST;

	list[4].id = 1004;
	list[4].isEmpty = ADDED;
	strcpy(list[4].FK_flyCode, "ABC123");
	strcpy(list[4].name, "Milena");
	strcpy(list[4].lastName, "Ristuccia");
	list[4].price = 1000;
	list[4].typePassenger = EXECUTIVE;

	list[5].id = 1005;
	list[5].isEmpty = ADDED;
	strcpy(list[5].FK_flyCode, "LOL345");
	strcpy(list[5].name, "Diego");
	strcpy(list[5].lastName, "Maradona");
	list[5].price = 550;
	list[5].typePassenger = EXECUTIVE;
}


int sPassenger_sortPassengersByType (sPassenger list[], int len, int order)
{
	int rtn;
	int i;
	int j;
	sPassenger aux;

	if (list != NULL)
	{
		if(len > 0)
		{
			switch (order){
			case 1:
				for (i = 0; i < len - 1; i++)
				{
					for (j = i + 1; j < len; j++)
					{
						//VERIFY IF ISEMPTY STATE IS "ADDED" IN BOTH
						if (list[i].isEmpty == ADDED && list[j].isEmpty == ADDED)
						{
							if (list[i].typePassenger > list[j].typePassenger)//ORDERING CRITERIA - ASCENDENT
							{
								aux = list[i];//EXCHANGE ARRAY POSITIONS
								list[i] = list[j];
								list[j] = aux;
							}
						}
					}
				}
				rtn = 0;//RETURN 0 IF OK
				break;
			case 2:
				for (i = 0; i < len - 1; i++) {
					for (j = i + 1; j < len; j++) {
						//VERIFY IF ISEMPTY STATE IS "ADDED" IN BOTH
						if (list[i].isEmpty == ADDED && list[j].isEmpty == ADDED) {
							if (list[i].typePassenger < list[j].typePassenger)//ORDERING CRITERIA - DESCENDENT
							{
								aux = list[i];//EXCHANGE ARRAY POSITIONS
								list[i] = list[j];
								list[j] = aux;
							}
						}
					}
				}

				rtn = 0;//RETURN 0 IF OK
				break;
			default:
				rtn = -1;//ERROR - INCORRECT ORDER
				break;
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


int sPassenger_getPassengerInfo(int *id, char name[],char lastName[], float *price, int typePassenger,
		char flyCode[]){

	int rtn;

	if(name != NULL && lastName != NULL && flyCode != NULL)
	{
		*id = sPassenger_GetId();
		puts("Ingrese el nombre del pasajero:");
		fflush(stdin);
		utn_myGets(name, MAX_LEN_STRING);
		system("cls");
		puts("Ingrese el apellido del pasajero:");
		fflush(stdin);
		utn_myGets(lastName, MAX_LEN_STRING);
		system("cls");
		getFloat("Ingrese el precio\n", 10, 0, 100000, "Error, reingrese precio\n", price);
		system("cls");
		fflush(stdin);
		utn_getNumero(&typePassenger, "Ingrese el tipo de pasajero: 1. Primera clase / 2. Ejecutivo / 3. Turista\n",
				"Error, reingrese tipo de pasajero:\n", 1, 3, 10);
		system("cls");
		puts("Ingrese el codigo de vuelo:");
		fflush(stdin);
		utn_myGets(flyCode, MAX_LEN_STRING);
		system("pause");
		system("cls");

		rtn = 0;
	}
	else
	{
		rtn = -1;
	}

	return rtn;
}
