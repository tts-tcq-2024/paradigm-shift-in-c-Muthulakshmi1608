
#ifndef SOC_STATUS_H
#define SOC_STATUS_H

typedef struct {
    int lower_bound;
    int upper_bound;
    int (*soc_ptr)();
} SOC_RANGE;

int get_soc_status(float soc);
int low_soc_breach();
int low_soc_warning();
int normal();
int high_soc_warning();
int high_soc_breach();
int batteryIsOk(float temperature, float soc, float chargeRate);
int soc_range_check(SOC_RANGE *soc_limit_check, float soc);

extern SOC_RANGE soc_ranges[10];


#endif
