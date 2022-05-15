#ifndef PASSENGER_FLIGHTS_H_
#define PASSENGER_FLIGHTS_H_

#include "ArrayPassenger.h"
#include "Flights.h"

int Passenger_Flights_Upload(sFlight listF[], int lenF, sPassenger listP[], int lenP);
int Passenger_Flights_printAll(sPassenger listP[], int lenP, sFlight listF[], int lenF, int status);
int Passenger_Flights_FindFlightIndexByFlyCode(char pFlyCode[], sFlight listF[], int lenF);

#endif /* PASSENGER_FLIGHTS_H_ */
