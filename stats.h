#ifdef __cplusplus
extern "C" {
#endif

struct Stats {
	double average;
	double min;
	double max;
};

struct Stats compute_statistics(const double* numberset, int setlength);

typedef void (*alerter_funcptr)();
void check_and_alert(double maxThreshold, alerter_funcptr alerters[], struct Stats computedStats);

extern int emailAlertCallCount;
extern int ledAlertCallCount;

#ifdef __cplusplus
}
#endif
