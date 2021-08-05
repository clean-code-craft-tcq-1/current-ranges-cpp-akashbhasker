#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include "test/catch.hpp"
#include "CurrentReadings.h"
#include <stdio.h>
#include <vector>


TEST_CASE(" Passing Test: Number of Ranges in the Current Readings Check for Minimum, Maximum values and total number of readings of ranges") {

	// Posistive : Number of Ranges in the Current Readings
	std::vector<CurrentReadingsParameters*> RangeAndReadings = {};
	processCurrentReadingsData({ 1, 2, 2, 3, 4, 14, 15, 16 }, RangeAndReadings);
	REQUIRE(RangeAndReadings.size() == 2);

	// Positive : Check for Minimum, Maximum values and total number of readings of ranges
	processCurrentReadingsData({ 1, 2, 2, 3, 4, 14, 15, 16 }, RangeAndReadings);

	REQUIRE(RangeAndReadings[0]->current_max == 4);
	REQUIRE(RangeAndReadings[1]->current_min == 14);
	REQUIRE(RangeAndReadings[0]->number_of_readings == 5);
	REQUIRE(RangeAndReadings[1]->number_of_readings == 3);

}

TEST_CASE(" Failing Test: Check for Number Of Current readings")
{
	std::vector<CurrentReadingsParameters*> RangeAndReadings = {};
	processCurrentReadingsData({}, RangeAndReadings);
	REQUIRE(RangeAndReadings.empty() == true);
}
