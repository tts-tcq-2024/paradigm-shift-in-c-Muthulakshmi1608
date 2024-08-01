#include <stdio.h>
#include <stdbool.h>
#include "chargerate_status.h"


int chargerate_normal()
{
  printf("chargerate is normal");
  return 1;
}

int high_chargerate_warning()
{
  printf("Warning: Approaching charge-peak\n");
  return 1;
}

int high_chargerate_breach()
{
  printf("chargerate out of range!\n");
  return 0;
}
