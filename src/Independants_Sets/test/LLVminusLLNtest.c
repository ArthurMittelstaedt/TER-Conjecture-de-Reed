#include "../c/mis.c"

int main(void) {
    LLV* lv = newLLV();
    addV(lv, '1');
    addV(lv, '2');
    addV(lv, '3');
    addV(lv, '4');
    LLN* ln = newLLN();
    //    AddNodeN(ln, '1');
    addN(ln, '3');
    addN(ln, '4');
    printV(LLVminusLLN(lv, ln, '*'));

}