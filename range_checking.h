#ifndef RANGE_CHECKING_H
#define RANGE_CHECKING_H
typedef struct {
    float lower_bound;
    float upper_bound;
    char* message;
    int status;
} BATTERY_STATUS_RANGE;



int get_battery_status(float value,BATTERY_STATUS_RANGE ranges[], int size);
//int range_check(BATTERY_STATUS_RANGE *limit_check, float value);

//extern BATTERY_STATUS_RANGE soc_ranges[10];
//extern BATTERY_STATUS_RANGE temp_ranges[10];
//extern BATTERY_STATUS_RANGE chargerate_ranges[10];
#endif
