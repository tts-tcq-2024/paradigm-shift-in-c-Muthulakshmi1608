#ifndef RANGE_CHECKING_H
#define RANGE_CHECKING_H
typedef struct {
    int lower_bound;
    int upper_bound;
    int (*battery_status_ptr)();
} BATTERY_STATUS_RANGE;

int get_battery_status(float value);
int range_check(BATTERY_STATUS_RANGE *limit_check, float value);

extern BATTERY_STATUS_RANGE ranges[10];
#endif
