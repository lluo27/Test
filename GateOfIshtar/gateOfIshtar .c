/*
 * gateOfIshtar.c
 *
 *  Created on: 27 maj 2018
 *      Author: Lu Li
 */

#include "gateOfIshtar.h"



/*******************************************************************
 *
 *  Calculate amount of health remained for a champion
 *   at the end of day
 *   @param champion - type of the champion (e.g. 'Wizard', 'human')
 *   @param date_string_intervals - list of date intervals strings
 *       when a champion passing the gate (e.g. ['XXXX-XX-XX XX:XX'])
 *
 ******************************************************************/
int calculate_champion_health(champion, date_string_intervals)
{


}


/*******************************************************************
 *
 *  Calculate amount of damage taken
 *   @param
 *   @param
 *
 ******************************************************************/
calculate_damage_taken(date, champion)
{

}


bool holly_day(day)
{
	return ( "Tuesday" == day || "Thursday" == day );
}


bool invincible_champion(champion)
{
	bool res = false;

	switch (champion)
	{
	case 'Wizard' :
	case 'Spirit' :
		res = true;
		break;
	default:
		res = false;
		break;
	}

	return res;

}
