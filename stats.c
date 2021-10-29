#include "stats.h"
#include <math.h>

struct Stats compute_statistics(const double* numberset, int setlength) {

	struct Stats s = {0};
	int loops = setlength;
	double currnumber = 0;
	double maxnumber = 0;
	double minnumber = 0xFFFFFFFF;
	double accumulator = 0;

	// Return all fields as NaN in case of empty array
	if (setlength == 0)
	{
		s.average = NAN;
		s.min = NAN;
		s.max = NAN;
	}
	else
	{
		while (loops--)
		{
			currnumber = *numberset;
			// Look for MAX number
			if (currnumber > maxnumber)
			{
				maxnumber = currnumber;
			}
			// Look for MIN number
			if (currnumber < minnumber)
			{
				minnumber = currnumber;
			}
			// Sum up all values for average
			accumulator += currnumber;
			numberset++;
		}
		s.average = accumulator/setlength;
		s.min = minnumber;
		s.max = maxnumber;
	}
	return s;
}

void check_and_alert(double maxThreshold, alerter_funcptr alerters[], struct Stats computedStats)
{
	// Verify if max value is not NaN
	if (isnan(computedStats.max) == 0)
	{
		if (computedStats.max > maxThreshold)
		{
			alerters[0]();
			alerters[1]();
		}
	}
}

int emailAlertCallCount = 0;
int ledAlertCallCount = 0;
