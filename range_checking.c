#include "soc_status.h"
#include "temperature_status.h"
#include "range_checking.h"
#include <stdio.h>
#include <stdbool.h>

bool out_of_range_flg=true;

int range_check(BATTERY_STATUS_RANGE *limit_check, float value)
{
  if ((value >= limit_check->lower_bound) && (value <= limit_check->upper_bound)) {
    return 1;
  }
  return 0;
}

int get_battery_status(float value) {
    for (int i = 0; i < sizeof(ranges) / sizeof(ranges[0]); i++) {
       if(range_check(&ranges[i],value)){
            out_of_range_flg = ranges[i].battery_status_ptr();
            return out_of_range_flg;
        }
    }
}
