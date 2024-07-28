#include <stdio.h>
#include <assert.h>
#include <stdbool.h>

typedef struct {
    int lower_bound;
    int upper_bound;
    int *soc_ptr;
} SOC_RANGE;

SOC_RANGE soc_ranges[];

int get_soc_status(int soc);
int low_soc_breach();
int low_soc_warning();
int normal();
int high_soc_warning();
int high_soc_breach();
int soc_range_check(SOC_RANGE *soc_limit_check, int soc);
