/**
 * SequenceDebug.cpp
 * Project 3
 * CS 3100
 *
 * In this file, you will write your tests as you implement Sequence. If you are using CLion, you need to select
 * SequenceDebug from the drop-down menu next to the Build (hammer icon) if it is on SequenceTestHarness
 */

#include "Sequence.h"

#include <iostream>


using namespace std;

int main() {
    cout << "Your project is ready to go!" << endl;
    Sequence seq(5);
    long val = 0;
    val += seq.size();
    seq[4]="one";
    seq[2]="two";
    seq[0]="three";
    seq.clear();
    cout << seq << endl;
    return 0;
}