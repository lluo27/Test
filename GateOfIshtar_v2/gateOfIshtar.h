/*
 * gateOfIshtar.h
 *
 *  Created on: 27 maj 2018
 *      Author: Lu Li
 */

#ifndef GATEOFISHTAR_H_
#define GATEOFISHTAR_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


typedef enum { false, true } bool;

typedef enum championE{
	Human,
	Wizard,
	Spirit,
	Giant,
	Vampire
}championE;

typedef enum godE{
	Janna, 		// Demon of Wind spawned
	Tiamat, 	// Goddess of Oceans spawned
	Mithra, 	// Goddess of sun spawned
	Warwick,	// God of war spawned
	Kalista, 	// Demon of agony spawned
	Ahri, 		// Goddess of wisdom spawned
	Brand, 		// God of fire spawned
	Rumble, 	// God of lightning spawned
	Skarner, 	// The scorpion demon spawned
	Luna 		// The goddess of the moon spawned
}godE;



//Function declarations
bool invisible_champion(championE champion);
bool holly_day(int day);
bool checkTimeSlot(int minute);
int calculate_damage_taken(struct tm date, championE champion);
int initialize_HP(championE champion);
int calculate_champion_health(championE champion, const char **date_string_intervals);



#endif /* GATEOFISHTAR_H_ */
