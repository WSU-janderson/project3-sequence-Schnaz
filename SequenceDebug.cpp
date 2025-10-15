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
    Sequence seq(3);
    seq[0] = "zero";
    seq[1] = "one";
    seq[2] = "two";
    //seq[3] = "three";
    seq.push_back("three");
    seq.push_back("four");
    seq.push_back("five");
    seq.pop_back();
    seq.erase(3,2);
    seq.insert(0, "extra");
    //seq.push_back("pushback2");
    //seq.push_back("pushback3");
    seq.erase(3);
    cout << seq.front() << " " << seq.head->next->item << " " << seq.head->next->next->item << " ";
    if (seq.head->next->next->next == nullptr) {cout << "good\n";}
    cout << seq.back() << " " << seq.tail->prev->item << " " << seq.tail->prev->prev->item << " ";
    if (seq.tail->prev->prev->prev == nullptr) {cout << "good\n";}
    cout << seq.sequenceSize << "\n";
    cout << seq << endl;
    return 0;
}