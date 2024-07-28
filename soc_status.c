#include <stdio.h>
#include <stdbool.h>
#include "soc_status.h"

bool out_of_range_flg = true;

int low_soc_breach()
{
  printf("State of Charge out of range!\n");
  out_of_range_flg = false;
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
  out_of_range_flg = false;
  return out_of_range_flg;
}


