#include "temperature_status.h"


int low_temp_breach()
{
  printf("Temperature out of range!\n");
  return 1;
}

int low_temp_warning()
{
  printf("Warning: Approaching discharge\n");
  return 1;
}

int temp_normal()
{
  printf("Temperature is normal");
  return 1;
}

int high_temp_warning()
{
  printf("Warning: Approaching charge-peak\n");
  return 1;
}

int high_temp_breach()
{
  printf("Temperature out of range!\n");
  return 0;
}
