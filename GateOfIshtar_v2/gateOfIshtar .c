/*
 * gateOfIshtar.c
 *
 *  Created on: 27 maj 2018
 *      Author: Lu Li
 */

#include "gateOfIshtar.h"



//Function declarations
bool invisible_champion(championE champion);
bool holly_day(int day);
bool checkTimeSlot(int minute);
int calculate_damage_taken(struct tm date, championE champion);
int initialize_HP(championE champion);
int calculate_champion_health(championE champion, const char **date_string_intervals);



/*******************************************************************
 *
 *  Initialize HP
 *   @param 	champion - type of the champion (e.g. 'Wizard', 'human')
 *   @return 	champion initial HP
 *
 ******************************************************************/
int initialize_HP(championE champion)
{
	int init_hp = 0;
	switch (champion)
	{
	case Human:
	case Wizard:
	case Spirit:
		init_hp = 100;
		break;
	case Giant:
		init_hp = 150;
		break;
	case Vampire:
		init_hp = 110;
		break;
	default:
		puts("Unfortunately, this champion doesn't belong to this world");
	}
	return init_hp;
}
/*******************************************************************
 *
 *  Calculate amount of health remained for a champion
 *   at the end of day
 *   @param 	champion - type of the champion (e.g. 'Wizard', 'human')
 *   @param 	date_string_intervals - list of date intervals strings
 *       		when a champion passing the gate (e.g. ['XXXX-XX-XX XX:XX'])
 *   @return 	Remaining HP of the champion
 *
 ******************************************************************/
int calculate_champion_health(championE champion, const char **date_string_intervals)
{
	int health = initialize_HP(champion);
	struct tm tm_start, tm_end;
	struct tm playTime = tm_start;

	strptime(date_string_intervals[0], "%Y-%m-%d %H:%M", &tm_start);
	strptime(date_string_intervals[1], "%Y-%m-%d %H:%M", &tm_end);

	for (int day = 0; day <= tm_end.tm_mday - tm_start.tm_mday; day ++)
	{// Firstly, loops through days

		int startHour = tm_start.tm_hour;
		int endHour = tm_end.tm_hour;

		//Reset the hour in the beginning of the next day.
		if (day > 0)
		{
			startHour = 0;
			playTime.tm_hour = 0;
		}

		if (tm_end.tm_mday > tm_start.tm_mday + day)
		{
			endHour = 24;
		}

		playTime.tm_mday += day;
		for (int hour = startHour; hour <= endHour; hour++)
		{// Damage once per hour

			if ((hour == endHour) && (playTime.tm_min >= tm_end.tm_min))
			{
				break;
			}

			int damage = calculate_damage_taken(playTime, champion);
			health = health - damage;
			if (health <= 0)
			{
				puts("A--Oh---- You are dead");
				health = 0;
				break;
			}
			playTime.tm_hour ++;
		}
	}

	printf("Your remaining HP is %d ...... \n",health);

	return health;

}

/*******************************************************************
 *
 *  Check if the time is within first two quarter of an hour or not
 *   @param 	minute
 *   @return 	true or false
 *
 ******************************************************************/
bool checkTimeSlot(int minute)
{
	if (minute >= 0 && minute <= 29)
	{
		return true;
	}
	else
	{
		return false;
	}
}

/*******************************************************************
 *
 *  Check if the day is holly day
 *   @param 	day
 *   @return 	true or false
 *
 ******************************************************************/
bool holly_day(int day)
{
	return (2 == day || 4 == day); // Tuesday and Thursday
}

/*******************************************************************
 *
 *  Check if the champion is visible or not
 *   @param 	champion 	player
 *   @return 	true or false
 *
 ******************************************************************/
bool invisible_champion(championE champion)
{
	bool res = false;

	switch (champion)
	{
	case Wizard :
	case Spirit :
		res = true;
		break;
	default:
		break;
	}

	return res;

}
/*******************************************************************
 *
 *  Calculate amount of damage taken
 *   @param date 		current time
 *   @param	champion	player
 *
 *   @ return 			damage token
 *
 ******************************************************************/
int calculate_damage_taken(struct tm date, championE champion)
{
	int damage = 0;

	if (holly_day(date.tm_wday) || invisible_champion(champion))
	  {
		  return 0;
	  }
	  else
	  {
		  switch (date.tm_hour)
		  {
		  case  6:
			  if (checkTimeSlot(date.tm_min))
				  damage = 7; // "Janna" demon of Wind spawned
			  else
				  damage = 18; //"Tiamat" goddess of Oceans spawned
			  break;
		  case 7:
			  damage = 25; //"Mithra" goddess of sun spawned
			  break;
		  case 8:
			  if (checkTimeSlot(date.tm_min))
				  damage = 18; // "Warwick" God of war spawned
			  else
				  damage = 7; // "Kalista" demon of agony spawned
			  break;
		  case 9:
		  case 10:
		  case 11:
		  case 12:
		  case 13:
		  case 14:
			  damage = 7; //"Kalista" goddess of Oceans spawned
			  break;
		  case 15:
			  if (checkTimeSlot(date.tm_min))
				  damage = 13; // "Ahri" goddess of wisdom spawned
			  else
				  damage = 25; // "Brand" god of fire spawned
			  break;
		  case 16:
			  damage = 25; //"Brand" god of fire spawned
			  break;
		  case 17:
			  damage = 18; // "Rumble" god of lightning spawned
			  break;
		  case 18:
		  case 19:
			  damage = 7; // "Skarner" the scorpion demon spawned
			  break;
		  case 20:
			  damage = 13; //"Luna" The goddess of the moon spawned
			  break;
		  default:
			  break; // Gods are sleeping :)
		  }
	  }
	    return damage;
}



