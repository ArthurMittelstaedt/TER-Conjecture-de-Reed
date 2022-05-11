#include "../c/Odometer.c"

int main(void) {
    Odometer* o = newOdometer(9);
    printOdometer(o);
    while (inc(o)) {
        printOdometer(o);
    }
}