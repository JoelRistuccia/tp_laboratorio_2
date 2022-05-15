#ifndef ARRAYPASSENGER_H_
#define ARRAYPASSENGER_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "utn.h"

#define MAX_LEN_STRING 51
#define LEN_FLYCODE 10
#define MAX_PASSENGERS 2000

#define ADDED -1
#define AVAILABLE 0
#define REMOVED 1

#define TOURIST 1
#define EXECUTIVE 2
#define FIRST_CLASS 3

#define ACTIVE 2
#define UNACTIVE 1


typedef struct{

	int id;
	char name[MAX_LEN_STRING];
	char lastName[MAX_LEN_STRING];
	float price;
	char FK_flyCode[LEN_FLYCODE];
	int typePassenger;
	int isEmpty;

}sPassenger;

/// @fn int sPassenger_initPassenger(ePassenger[], int)
/// @brief To indicate that all position in the array are empty,
///  this function put the flag (isEmpty) in TRUE in all
///  position of the array
/// @param sPassenger list Pointer to array of passenger
/// @param len int Array length
/// @return int Return (-1) if Error [Invalid length] (-2) if Error [NULL pointer] - (0) if Ok
int sPassenger_initPassenger (sPassenger list[], int len);
/// @fn int addPassenger(sPassenger, int, int, char[], char[], float, int, char[], int)
/// @brief add in a existing list of passengers the values received as parameters
///  in the first empty position
/// @param sPassenger list Pointer to array of passenger
/// @param len int Array length
/// @param id int
/// @param name char*
/// @param lastName char*
/// @param price float
/// @param typePassenger int
/// @param flyCode char*
/// @param availableIndex int First available index to add
/// @return int Return (-1) if Error [Invalid length] (-2) if Error [NULL pointer] - (0) if Ok
int sPassenger_addPassenger(sPassenger listP[], int lenP, int *id, char name[],char lastName[], float *price,
		int typePassenger, char flyCode[]);
int sPassenger_getPassengerInfo(int *id, char name[],char lastName[], float *price, int typePassenger,
		char flyCode[]);
/// @fn int findPassengerById(sPassenger, int, int)
/// @brief find a Passenger by Id en returns the index position in array.
/// @param sPassenger list Pointer to array of passenger
/// @param len int Array length
/// @param id int id of the index to find
/// @return int Return index of the id given
int sPassenger_findPassengerById(sPassenger list[], int len, int id);
/// @fn int removePassenger(sPassenger, int, int)
/// @brief Remove a Passenger by Id (put isEmpty Flag in 1)
/// @param sPassenger list Pointer to array of passenger
/// @param len int Array length
/// @param id id int id of the index to remove
/// @return Return (-1) if Error [Invalid length] - (-2) if Error [NULL pointer] - (0) if Ok
int sPassenger_removePassenger(sPassenger list[], int len);
/// @fn int sortPassengers(sPassenger, int, int)
/// @brief Sort the elements in the array of passengers, the argument order
/// indicate UP or DOWN order
/// @param sPassenger list Pointer to array of passenger
/// @param len int Array length
/// @param order int Ordering criteria (0) Ascending - (1) Descending
/// @return Return (-1) if Error [Invalid length] - (-2) if Error [NULL pointer] - (-3) if Error
/// [Incorrect ordering criteria] - (0) if Ok
int sPassenger_sortPassengersByName(sPassenger list[], int len, int order);
/// @fn int sPassenger_findAvailableIndex(sPassenger[], int)
/// @brief Finds an available index in the array of passengers
/// @param sPassenger list Pointer to array of passenger
/// @param len int Array length
/// @return Return (-1) if Error [Index not found] - (-2) if Error [Invalid length] - (-3) if Error
/// [NULL pointer] - Returns available index found if OK
int sPassenger_findAvailableIndex(sPassenger list[], int len);
void sPassenger_printPassenger(sPassenger Passenger);
int sPassenger_Modify(sPassenger list[], int len);
sPassenger sPassenger_ModifyOne(sPassenger Passenger);
void sPassenger_hardCode(sPassenger list[]);
int sPassenger_sortPassengersByType (sPassenger list[], int len, int order);
#endif /* ARRAYPASSENGER_H_ */
