#ifndef TEMPERATURE_STATUS_H
#define TEMPERATURE_STATUS_H

#include <stdio.h>
#include <stdbool.h>

int low_temp_breach();
int low_temp_warning();
int temp_normal();
int high_temp_warning();
int high_temp_breach();
#endif
