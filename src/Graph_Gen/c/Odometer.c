#ifndef ODOMETER_C
#define ODOMETER_C

#include "../h/Odometer.h"
#include <stdio.h>

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

    newO->highest_bit = 0;
    newO->highest_bit_in_last_counter = 0;
    newO->last_counter_used = 0;
    return newO;
}

BOOL inc(Odometer* o) {
    int i = 0;
    while ((o->counters[i] == counter_MAX) && (i < o->nb_counters)) {
        o->counters[i] = 0;
        i++;
    }
    if (i < o->nb_counters) {
        o->counters[i] = o->counters[i] + (counter)1;
        if (i >= o->last_counter_used) {
            if (i == o->last_counter_used) {
                if (o->counters[i] >= 1 << (o->highest_bit_in_last_counter)) {
                    o->highest_bit_in_last_counter++;
                    o->highest_bit++;
                }
            }
            else if (i > o->last_counter_used) {
                o->last_counter_used++;
                o->highest_bit_in_last_counter = 0;
                o->highest_bit++;
            }
        }
        if (i == o->nb_counters - 1 && (o->counters[i] > o->last_counter_max)) {
            return FALSE;
        }
        else return TRUE;
    }
    else return FALSE;
}

int bit(Odometer* o, int p) {
    size_t c_index = (p - 1) / counter_size;
    size_t index_in_c = (p - 1) % counter_size;
    return (o->counters[c_index] >> index_in_c) & 1;
}

void destroyOdometer(Odometer* o) {
    free(o->counters);
    free(o);
}

void printOdometer(Odometer* o) {
    for (size_t i = o->n; i > 0; i--)
        printf("%d", bit(o, i));

    printf("(");
    for (int i = o->nb_counters - 1; i >= 0; i--) {
        printf("%d ", o->counters[i]);
    }
    printf(")");

    printf(" | hb : %d", o->highest_bit);
    printf(" | hblc : %d", o->highest_bit_in_last_counter);
    printf(" | lcu : %d", o->last_counter_used);
    printf(" | lcmax : %d", o->last_counter_max);
    //printf(" | cmax : %d", counter_MAX);
    printf("\n");
}

int odoStartIt(Odometer* o) {
    o->curBit = 1;
    o->curCnt = 0;
    return (o->counters[o->curCnt] >> (o->curBit - 1)) & 1;
}

int odoNextIt(Odometer* o) {
    if (o->curBit == counter_MAX) {
        o->curBit = 0;
        o->curCnt++;
    }
    else {
        o->curBit++;
    }
    return (o->counters[o->curCnt] >> (o->curBit - 1)) & 1;
}

int odoEndIt(Odometer* o) {
    return (o->curCnt > o->last_counter_used) ||
        ((o->curCnt == o->last_counter_used) && (o->curBit > o->highest_bit));
};

#endif