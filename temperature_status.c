#include "temperature_status.h"

bool out_of_range_temp_flg = true;

int low_temp_breach()
{
  printf("Temperature out of range!\n");
  out_of_range_temp_flg = false;
  return out_of_range_temp_flg;
}

int low_temp_warning()
{
  printf("Warning: Approaching discharge\n");
  return out_of_range_temp_flg;
}

int temp_normal()
{
  printf("Temperature is normal");
  return out_of_range_temp_flg;
}

int high_temp_warning()
{
  printf("Warning: Approaching charge-peak\n");
  return out_of_range_temp_flg;
}

int high_temp_breach()
{
  printf("Temperature out of range!\n");
  out_of_range_temp_flg = false;
  return out_of_range_temp_flg;
}
