#include <iostream>
#include "cellular_automaton.h"
#include "constants.h"

using namespace std;

void test();

int main() {
    int dec = 0;
    bool world[MAX_ROW][MAX_COL];
    bool rule[8];
    while (true) {
        cout << ": ";
        cin >> dec;
        initialize(world);
        initBoolArray(rule, 8);
        dec_to_bin(dec, rule);
        automateAll(world, rule);
        print2d(world);
}

}

void test() {
    bool rule[8];
    initBoolArray(rule, 8);
    dec_to_bin(54, rule);
    printBoolArray(rule, 8);
    bool top[3] = {false, false, false};
    int topType = 0;
    bin_to_dec(top, topType);
    topType = 7 - topType;
    cout << topType << endl;
}