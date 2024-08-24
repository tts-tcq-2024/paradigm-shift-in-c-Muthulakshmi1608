#ifndef RANGE_CHECKER_H
#define RANGE_CHECKER_H
typedef struct {
    float lower_bound;
    float upper_bound;
    char* message;
    int value;
} Battery_Status_Range;

typedef struct{
  char* name;
  Battery_Status_Range ranges[10];
  bool isEarlyWarningRequired;
}BatteryParameter;


int get_battery_status(float value,Battery_Status_Range ranges[], int size);
#endif
