#include "stats.h"
#include "alerts.h"

void emailAlerter(void)
{
	emailAlertCallCount++;
}

void ledAlerter(void)
{
	ledAlertCallCount++;
}
