#include <stdio.h>
#include <assert.h>
#include <soc_checker.h>

int low_soc_breach()
{
  printf("State of Charge out of range!\n");
  out_of_range_flg = true;
  return out_of_range_flg;
}

int low_soc_warning()
{
  printf("Warning: Approaching discharge\n");
  return out_of_range_flg;
}

int normal()
{
  printf("SOC is normal");
  return out_of_range_flg;
}

int high_soc_warning()
{
  printf("Warning: Approaching charge-peak\n");
  return out_of_range_flg;
}

int high_soc_breach()
{
  printf("State of Charge out of range!\n");
  out_of_range_flg = true;
  return out_of_range_flg;
}

int soc_range_check(SOC_RANGE soc_lower_limit_check,SOC_RANGE soc_lower_limit_check, int soc)
{
  if (soc >= soc_ranges[i].lower_bound && soc <= soc_ranges[i].upper_bound) {
    return 1;
  }
  return 0;
}

int get_soc_status(int soc) {
  
    for (int i = 0; i < sizeof(soc_ranges) / sizeof(soc_ranges[0]); i++) {
       // if (soc >= soc_ranges[i].lower_bound && soc <= soc_ranges[i].upper_bound) {
       if(soc_range_check(soc_ranges[i].lower_bound,soc_ranges[i].upper_bound,soc)){
            out_of_range_flg = soc_ranges[i].soc_ptr;
            return out_of_range_flg;
        }
    }
}
