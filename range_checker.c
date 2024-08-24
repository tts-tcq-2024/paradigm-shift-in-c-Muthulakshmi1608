#include "range_checker.h"
#include <stdio.h>
#include <stdbool.h>

int range_check(Battery_Status_Range *limit_check, float value) {
    if ((value > limit_check->lower_bound) && (value < limit_check->upper_bound)) {
        return limit_check->value;
    }
    return 0;
}

int filter_nonwarning_ranges(BatteryParameter *bp, Battery_Status_Range filtered_ranges[], int size) {
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (bp->ranges[i].value != 1) {
            filtered_ranges[count++] = bp->ranges[i];
        }
    }
    return count;
}

int filter_ranges(BatteryParameter *bp, Battery_Status_Range filtered_ranges[], int size) {
    if (bp->isEarlyWarningRequired) {
        // Copy all ranges to the filtered array if early warning is required
        for (int i = 0; i < size; i++) {
            filtered_ranges[i] = bp->ranges[i];
        }
        return size;  // Return the full size
    } else {
        return filter_nonwarning_ranges(bp, filtered_ranges, size);  // Filter non-warning ranges
    }
}

int get_battery_status(float value, BatteryParameter *bp, int size) {
    Battery_Status_Range filtered_ranges[10];  // Temporary array for filtered ranges
    int i;
    int range_size = filter_ranges(bp, filtered_ranges, size);  // Filter the ranges based on the flag
    for (i = 0; i < range_size; i++) {
        int status = range_check(&(filtered_ranges[i]), value);
        if (status != 0) {
            printf("%s\n", filtered_ranges[i].message);  // Print the corresponding message
            return status;  // Return the matching range's value
        }
    }
    printf("%s\n", filtered_ranges[0].message);
    return 0;  // Return 0 if no range matched
}


  
