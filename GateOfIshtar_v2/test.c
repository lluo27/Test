/*
 * test.c
 *
 *  Created on: 27 maj 2018
 *      Author: Lu Li
 */

#include "gateOfIshtar.h"
#include "assert.h"

int main(void)
{
	int expectedResult, result;
	championE champion = Human;

	//Test step 1 : Verify no damage taken in Holly days

	const char *strings[] = {"2018-05-22 04:10","2018-05-22 23:10"};
	expectedResult= 100;
    result = calculate_champion_health(champion, strings);
    assert(result == expectedResult);

    strings[0] = "2018-05-24 04:10";
    strings[1] = "2018-05-24 23:10";
    champion = Vampire;
    expectedResult= 110;
    result = calculate_champion_health(champion, strings);
    assert(result == expectedResult);

    //Test step 2 : Verify no damage take for Wizard and Spirit
    expectedResult= 100;
    champion = Wizard;
    result = calculate_champion_health(champion, strings);
    assert(result == expectedResult);

    champion = Spirit;
    result = calculate_champion_health(champion, strings);
    assert(result == expectedResult);

    //Test step 3: Verify the remaining HP is correct within a day

    //3.1 Verify the first minute
    strings[0] = "2018-05-23 06:00";
    strings[1] = "2018-05-23 06:01";
    champion = Giant;
    expectedResult= 143;
    result = calculate_champion_health(champion, strings);
    assert(result == expectedResult);

    //3.2 Verify the result is the same when the enter time is 00:00
    // 	  since no damage before 06:00;
    strings[0] = "2018-05-23 00:00";
    result = calculate_champion_health(champion, strings);
    assert(result == expectedResult);

    // 3.3 Verify different time slots
    strings[0] = "2018-05-23 06:32";
    strings[1] = "2018-05-23 06:33";
    expectedResult= 132;
    result = calculate_champion_health(champion, strings);
    assert(result == expectedResult);

    strings[1] = "2018-05-23 17:32";
    expectedResult= 8;
    result = calculate_champion_health(champion, strings);
    assert(result == expectedResult);

    // 3.4 Verify HP is lost when champion stays for 1 minute more
    strings[1] = "2018-05-23 17:33";
    expectedResult= 0;
    result = calculate_champion_health(champion, strings);
    assert(result == expectedResult);

    //3.5 Verify the HP stays 0 when the champion is dead.
    strings[0] = "2018-05-23 00:00";
    strings[1] = "2018-05-23 23:59";
    expectedResult= 0;
    result = calculate_champion_health(champion, strings);
    assert(result == expectedResult);

    //Test step 4: Verify the remaining HP is correct for champions stay over a night.

    strings[0] = "2018-05-25 20:00";
    strings[1] = "2018-05-26 06:01";
    champion = Human;
    expectedResult= 80;
    result = calculate_champion_health(champion, strings);
    assert(result == expectedResult);
}


