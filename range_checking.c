#include "soc_status.h"
#include "temperature_status.h"
#include "range_checking.h"
#include <stdio.h>
#include <stdbool.h>

int range_check(BATTERY_STATUS_RANGE *limit_check, float value)
{
  if ((value >= limit_check->lower_bound) && (value <= limit_check->upper_bound)) {
    return 1;
  }
  return 0;
}

int chargerate_range_check(BATTERY_STATUS_RANGE_CHARGERATE *limit_check, float value)
{
  if ((value >= limit_check->lower_bound)&&(value <= limit_check->upper_bound)) {
    return 1;
  }
  return 0;
}

int get_battery_status(float value,BATTERY_STATUS_RANGE ranges[], int size) {
    for (int i = 0; i < size; i++) {
        if (range_check(&ranges[i], value)) {
            return ranges[i].battery_status_ptr();
        }
    }
}
int get_battery_chargerate_status(float value,BATTERY_STATUS_RANGE_CHARGERATE ranges[], int size)
{
  for (int i = 0; i < size; i++) {
        if (chargerate_range_check(&ranges[i], value)) {
            return ranges[i].battery_status_chargerate_ptr();
        }
    }
}
  
