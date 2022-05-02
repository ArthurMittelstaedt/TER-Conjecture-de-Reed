#include "../c/mis.c"

int main(void) {
    LLV* lv = newLLV();
    addV(lv, '1');
    addV(lv, '2');
    addV(lv, '3');
    addV(lv, '4');
    LLN* ln = newLLN();
    //    AddNodeN(ln, '1');
    AddNodeN(ln, '3');
    AddNodeN(ln, '4');
    printV(LLVminusLLN(lv, ln, '*'));

}