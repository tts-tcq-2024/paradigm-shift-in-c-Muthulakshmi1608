#include <stdio.h>
#include <stdbool.h>
#include "soc_status.h"


int low_soc_breach()
{
  printf("State of Charge out of range!\n");
  out_of_range_flg = false;
  return 1;
}

int low_soc_warning()
{
  printf("Warning: Approaching discharge\n");
  return 1;
}

int normal()
{
  printf("SOC is normal");
  return 1;
}

int high_soc_warning()
{
  printf("Warning: Approaching charge-peak\n");
  return 1;
}

int high_soc_breach()
{
  printf("State of Charge out of range!\n");
  out_of_range_flg = false;
  return 0;
}


