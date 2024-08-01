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

int get_battery_status(float value) {
  #ifdef SOC_CHECK
    for (int i = 0; i < sizeof(ranges) / sizeof(ranges[0]); i++) {
       if(range_check(&ranges[i],value)){
            return (ranges[i].battery_status_ptr());
            
        }
    }
  #ifdef TEMP_CHECK
  for (int i = 0; i < sizeof(temp_ranges) / sizeof(temp_ranges[0]); i++) {
       if(range_check(&temp_ranges[i],value)){
            return (temp_ranges[i].battery_status_ptr());
            
        }
    }
  #endif
}
