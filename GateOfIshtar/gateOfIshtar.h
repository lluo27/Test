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

enum bool{
	false,
	true
}bool;

enum champions{
	Human,
	Wizard,
	Spirit,
	Giant,
	Vampire
}champion;

enum gods{
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
}god;

enum days{
	Monday,
	Tuesday,
	Wednesday,
	Thursday,
	Friday,
	Saturday,
	Sunday
}day;

#endif /* GATEOFISHTAR_H_ */
