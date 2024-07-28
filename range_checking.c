#include "soc_status.h"
#include "temperature_status.h"

int range_check(RANGE *limit_check, float value)
{
  if ((value >= limit_check->lower_bound) && (value <= limit_check->upper_bound)) {
    return 1;
  }
  return 0;
}

int get_battery_status(float value) {
    for (int i = 0; i < sizeof(ranges) / sizeof(ranges[0]); i++) {
       if(range_check(&ranges[i],value)){
            out_of_range_flg = ranges[i].soc_ptr();
            return out_of_range_flg;
        }
    }
}
