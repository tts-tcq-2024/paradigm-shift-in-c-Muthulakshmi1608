#ifndef TEMPERATURE_STATUS_H
#define TEMPERATURE_STATUS_H

typedef struct {
    int lower_bound;
    int upper_bound;
    int (*temperature_ptr)();
} TEMP_RANGE;

int get_soc_status(float soc);
int low_temp_breach();
int low_temp_warning();
int temp_normal();
int high_temp_warning();
int high_temp_breach();
#endif
