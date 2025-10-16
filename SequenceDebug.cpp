/**
 * SequenceDebug.cpp
 * Project 3
 * CS 3100 - Adam Hume
 *
 * In this file, you will write your tests as you implement Sequence. If you are using CLion, you need to select
 * SequenceDebug from the drop-down menu next to the Build (hammer icon) if it is on SequenceTestHarness
 */

#include "Sequence.h"

#include <iostream>


using namespace std;

int main() {

    string str;

    // Populate first sequence by filling blank members
    Sequence seq1(3);
    seq1[0]="one";
    seq1[1]="two";
    seq1[2]="three";

    // Test default constructor for sequence and the push_back() function
    Sequence seq2;
    seq2.push_back("A");
    seq2.push_back("B");
    seq2.push_back("C");

    // Print results
    cout << "Test []overload\n" << seq1.size() << " nodes" << endl << seq1 << endl << endl;
    cout << "Test pushback\n" << seq2.size() << " nodes" << endl << seq2 << endl << endl;

    // Test pop_back
    seq2.pop_back();
    seq2.pop_back();
    seq2.pop_back();
    cout << "Test popback x 3\n" << seq2.size() << " nodes" << endl << seq2 << endl;

    cout << "Test popback exception\n";
    try {
        seq1[3]="four";
    }
    catch (exception &e) {
        cout << e.what() << endl;
        cout << "exception thrown" << endl << endl;
    }

    seq1.insert(0,"counting:");
    seq1.insert(3,"five");
    cout << "Test insert\n" << seq1.size() << " nodes" << endl << seq1 << endl << endl;

    cout << "Test insert exception\n";
    try {
        seq1.insert(5,"did you catch the monty python reference?");
    }
    catch (exception &e) {
        cout << e.what() << endl;
        cout << "exception thrown" << endl << endl;
    }

    cout << "Front: " + seq1.front() << endl << "Back: " + seq1.back() << endl << endl;

    cout << "Your project is ready to go!" << endl;
    return 0;
}
