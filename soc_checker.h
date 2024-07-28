
#ifndef SOC_CHECKER_H
#define SOC_CHECKER_H

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

SOC_RANGE soc_ranges[] = {
    { 0.0, 20.0, low_soc_breach()},
    { 21.0, 24.0, low_soc_warning()},
    { 25.0, 75.0, normal()},
    { 76.0, 80.0, high_soc_warning()},
    { 81.0, 100.0, high_soc_breach()}
};

#endif
