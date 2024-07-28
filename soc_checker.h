
#ifndef SOC_CHECKER_H
#define SOC_CHECKER_H

typedef struct {
    int lower_bound;
    int upper_bound;
    int *soc_ptr;
} SOC_RANGE;

SOC_RANGE soc_ranges[] = {
    { 0, 20, "low_soc_breach" },
    { 21, 24, "low_soc_warning" },
    { 25, 75, "normal" },
    { 76, 80, "high_soc_warning" },
    { 81, 100, "high_soc_breach" }
};

int get_soc_status(int soc);
int low_soc_breach();
int low_soc_warning();
int normal();
int high_soc_warning();
int high_soc_breach();
int soc_range_check(SOC_RANGE *soc_limit_check, int soc);

#endif
