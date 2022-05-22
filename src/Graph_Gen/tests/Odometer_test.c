#include "../c/Odometer.c"

int main(void) {
    Odometer* o = newOdometer(8);
    printOdometer(o);
    while (inc(o)) {
        printOdometer(o);
    }
}