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


    cout << "Test front exception\n";
    try {
        cout << seq2.front();
    }
    catch (exception &e) {
        cout << e.what() << endl;
        cout << "exception thrown" << endl << endl;
    }

    cout << "Test back exception\n";
    try {
        cout << seq2.back();
    }
    catch (exception &e) {
        cout << e.what() << endl;
        cout << "exception thrown" << endl << endl;
    }

    cout << "Does empty work?\n";
    if (seq2.empty()) cout << "seq 2 is empty!\n";
    if (!seq1.empty()) cout << "seq 1 is full!\n\n";

    cout << "Copy seq 1 to seq 2!\n";
    seq2 = seq1;
    cout << seq1.size() << " nodes" << endl << seq2 << endl << endl;

    cout << "Was the copy deep? subtract values and compare Sequences\n";
    seq2.erase(0);
    seq2.erase(2,2);
    cout << seq1.size() << " nodes" << endl << seq1 << endl;
    cout << seq2.size() << " nodes" << endl << seq2 << endl << endl;

    cout << "Test erase exception 1\n";
    try {
        seq2.erase(2);
    }
    catch (exception &e) {
        cout << e.what() << endl;
        cout << "exception thrown" << endl << endl;
    }

    cout << "Test erase exception 2\n";
    try {
        seq1.erase(0, 6);
    }
    catch (exception &e) {
        cout << e.what() << endl;
        cout << "exception thrown" << endl << endl;
    }

    Sequence seq3(seq1);
    cout << "test copy constructor\n";
    seq3.erase(4);
    seq3.erase(1,2);
    cout << seq1.size() << " nodes" << endl << seq1 << endl;
    cout << seq3.size() << " nodes" << endl << seq3 << endl << endl;

    //memory leak test. Deconstructor calls clear which calls delete.
    for (int i = 1000; i > 0; i--) {
        Sequence *bad = new Sequence(100);
        delete bad;
    }

    cout << "Your project is ready to go!" << endl;
    return 0;
}
