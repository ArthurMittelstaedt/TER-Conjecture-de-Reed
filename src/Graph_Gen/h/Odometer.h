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

    size_t highest_bit;
    size_t highest_bit_in_last_counter;
    size_t last_counter_used;

    size_t curBit;
    size_t curCnt;
};

extern Odometer* newOdometer(int n);
extern BOOL inc(Odometer* o);
extern int bit(Odometer* o, int p);
extern void destroyOdometer(Odometer* o);
extern void printOdometer(Odometer* o);
extern int odoStartIt(Odometer* o);
extern int odoNextIt(Odometer* o);
extern int odoEndIt(Odometer* o);


#endif