#ifndef FLIGHTS_H_
#define FLIGHTS_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "utn.h"


#define MAX_LEN_STRING 51
#define LEN_FLYCODE 10
#define MAX_FLIGHTS 100

#define ADDED -1
#define AVAILABLE 0
#define REMOVED 1

#define ACTIVE 2
#define UNACTIVE 1

typedef struct{

	char flyCode[LEN_FLYCODE];
	int statusFlight;

}sFlight;

int sFlights_initFlights (sFlight list[], int len);
int sFlight_findAvailableIndex(sFlight list[], int len);
int sFlights_addFlight (sFlight listF[], int lenF, int index);
int sFlight_findFlightByFlyCode(sFlight list[], int len, char flyCode[]);
void sFlight_printFlight(sFlight Flight);
void sFlight_hardCode(sFlight list[]);

#endif /* FLIGHTS_H_ */
