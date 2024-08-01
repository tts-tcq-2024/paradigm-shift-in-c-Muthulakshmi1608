#ifndef RANGE_CHECKING_H
#define RANGE_CHECKING_H
typedef struct {
    int lower_bound;
    int upper_bound;
    int (*battery_status_ptr)();
} BATTERY_STATUS_RANGE;

typedef struct {
    int upper_bound;
    int (*battery_status_chargerate_ptr)();
} BATTERY_STATUS_RANGE_CHARGERATE;

int get_battery_status(float value,BATTERY_STATUS_RANGE ranges[], int size);
int get_battery_chargerate_status(float value,BATTERY_STATUS_RANGE_CHARGERATE ranges[], int size);
int range_check(BATTERY_STATUS_RANGE *limit_check, float value);
int chargerate_range_check(BATTERY_STATUS_RANGE_CHARGERATE *limit_check, float value);

extern BATTERY_STATUS_RANGE soc_ranges[10];
extern BATTERY_STATUS_RANGE temp_ranges[10];
extern BATTERY_STATUS_RANGE_CHARGERATE chargerate_ranges[10];
#endif
