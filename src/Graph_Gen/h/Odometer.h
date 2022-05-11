#ifndef ODOMETER_H
#define ODOMETER_H

#include <stdlib.h>
#include "../../Data_Structures/h/Definitions.h"

typedef unsigned char counter;
const size_t counter_size = sizeof(counter) * 8;
const size_t counter_MAX = (1 << counter_size) - 1;

typedef struct Odometer Odometer;
struct Odometer {
    size_t n;
    size_t nb_counters;
    size_t last_counter_max;
    counter* counters;
};

extern Odometer* newOdometer(int n);
extern BOOL inc(Odometer* o);
extern int bit(Odometer* o, int p);
extern void destroyOdometer(Odometer* o);


#endif