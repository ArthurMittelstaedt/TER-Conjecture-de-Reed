#ifndef ODOMETER_C
#define ODOMETER_C

#include "../h/Odometer.h"

Odometer* newOdometer(int n) {
    size_t nb_counter_needed = (n + counter_size - 1) / counter_size;
    Odometer* newO = malloc(sizeof(Odometer));
    newO->n = n;
    newO->nb_counters = nb_counter_needed;
    counter* counters = malloc(sizeof(counter) * nb_counter_needed);
    for (int i = 0; i < nb_counter_needed; i++)
        counters[i] = 0;
    newO->counters = counters;
    newO->last_counter_max = (1 << (n - counter_size * (nb_counter_needed - 1))) - 1;
    return newO;
}

BOOL inc(Odometer* o) {
    int i = 0;
    while ((o->counters[i] == counter_MAX) && (i < o->nb_counters)) {
        o->counters[i] = 0;
        i++;
    }
    if (i < o->nb_counters) {
        o->counters[i]++;
        if (o->counters[i] > o->last_counter_max) {
            return FALSE;
        }
        else return TRUE;
    }
    else return FALSE;
}

int bit(Odometer* o, int p) {

}

void destroyOdometer(Odometer* o) {

}
#endif