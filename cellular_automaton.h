//
// Created by evelyn on 8/24/18.
//

#ifndef CELLULAR_AUTOMATION_CELLULAR_AUTOMATION_H
#define CELLULAR_AUTOMATION_CELLULAR_AUTOMATION_H

#include "constants.h"
#include <string>
using namespace std;

void initialize(bool world[][MAX_COL]);     //init with one living cell at the center of 1st row
void dec_to_bin(int dec, bool bin[]);       //convert the decimal int to a boolean array (length = 8)
int bin_to_dec(bool bin[], int &dec);       //convert the boolean array (length = 3) to
void automateCell(bool world[][MAX_COL], int row, int col, bool rule[]); //determine whether this "cell" should be alive or dead
    //so gets the "top" len = 3 bin array fist, determine topType
    //then according to the rule
    //determine whether the cell should be alive
//int topType(bool world[][MAX_COL], int row, int col);    //returns 0-7
//    //take the 3 cells on top of the current cell
//    //as a bool array, convert to dec, then get 7-d
void automateRow(bool world[][MAX_COL], int row, bool rule[]);    //develop the next row according to the row before...
    //using the "rule" described by the bin array
    //start from the 1st col
void automateAll(bool world[][MAX_COL], bool rule[]);    //generate all rows..
    //start from the 1st row
void print2d(bool world[][MAX_COL]);        //print the world array

void printBoolArray(bool boolArray[], int size);
void initBoolArray(bool boolArray[], int size);
#endif //CELLULAR_AUTOMATION_CELLULAR_AUTOMATION_H
