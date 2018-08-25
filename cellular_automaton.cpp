//
// Created by evelyn on 8/24/18.
//

#include "cellular_automaton.h"
#include "constants.h"
#include <iostream>
#include <string>

using namespace std;

void initialize(bool world[][MAX_COL]) {
    int n = MAX_COL/2;
    for(int r = 0; r < MAX_ROW; r++) {
        for(int c = 0; c < MAX_COL; c++) {
            world[r][c] = false;
        }
    }
    world[0][n] = true;
}

void dec_to_bin(int dec, bool bin[]) { //WORKS
    //NOTE: ONLY FOR 8 DIGITS BIN ARRAY
    int p2 = 1,  //power of 2
        times = 0; //times dec needs to be modded
    while (p2 < dec) {
        //find how many times dec can be divided by 2
        times ++;
        p2 *= 2;
    }
    for (int i = 0; i < times; i++) {
        bin[7-i] = dec % 2;
        dec /= 2;
    }
}

int bin_to_dec(bool bin[], int &dec) { //WORKS
    //NOTE: ONLY FOR 3 DIGITS BIN ARRAY
    int p2 = 1;  //power of 2
    for(int i = 0; i < 3; i++) {
        if (bin[2-i]) {
            dec += p2;
        }
        p2 *= 2;
    }
}

void automateCell(bool world[][MAX_COL], int row, int col, bool rule[]) {
    bool top[3];
    int topType = 0;
    for(int i = 0; i < 3; i++) {
        top[i] = world[row - 1][col - 1 + i];
    }
    bin_to_dec(top, topType);
    topType = 7 - topType;
    if(rule[topType]) {
        world[row][col] = true;
    }
}

//int topType(bool world[][MAX_COL], int row, int col) {
//
//}

void automateRow(bool world[][MAX_COL], int row, bool rule[]) {
    for (int c = 1; c < MAX_COL; c++) {
        automateCell(world, row, c, rule);
    }
}

void automateAll(bool world[][MAX_COL], bool rule[]) {
    for (int r = 1; r < MAX_ROW; r++) {
        automateRow(world, r, rule);
    }
}

void print2d(bool world[][MAX_COL]) {
    for(int r = 0; r < MAX_ROW; r++) {
        for(int c = 0; c < MAX_COL; c++) {
            if(world[r][c])
                cout << "■ ";
            else
                cout << ". ";
        }
        cout << endl;
    }
}

void printBoolArray(bool *boolArray, int size) {
    for (int i = 0; i < size; i++) {
        cout << boolArray[i] << ' ';
    }
    cout << endl;
}

void initBoolArray(bool boolArray[], int size) {
    for (int i = 0; i < size; i++) {
        boolArray[i] = false;
    }
}
























