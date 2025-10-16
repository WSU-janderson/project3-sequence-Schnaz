/**
 * Sequence.cpp
 * Project 3 - Linked Sequence Data Structure
 * CS 3100 - Adam Hume
 *
 * This is the header file. It holds all the declarations for functions and variables
 * both public and private for the Sequence class and the SequenceNode class
 */

#ifndef PROJECT3_SEQUENCE_H
#define PROJECT3_SEQUENCE_H
#include <string>

class SequenceNode {
public: // to make it easier, we can make the data members public so we don't need getters and setters
    SequenceNode *next; // pointer to next Node. If node is the tail, next is nullptr
    SequenceNode *prev; // pointer to previous Node. If node is the head, prev is nullptr
    std::string item; // the element being stored in the node default constructor, ensure next and prev are nullptr

    // default class constructor set to populate next and prev with null pointers
    SequenceNode() : next(nullptr), prev(nullptr) {
    }

    /// parameterized constructor, next and prev are set to nullptr and the
    /// node's element is set to the given value
    SequenceNode(std::string item) : next(nullptr), prev(nullptr), item(item) {
    }
};

class Sequence {
private:
    SequenceNode *head; // Pointer to first element in the sequence
    SequenceNode *tail; // Pointer to last element in the sequence
    size_t sequenceSize; // Number of elements in the sequence

public:
    // Creates an empty sequence or a sequence with "sz" number of empty nodes
    Sequence(size_t sz = 0);

    // Creates a (deep) copy of sequence s
    Sequence(const Sequence &s);

    // Destroys all items in sequence and release all memory associated
    ~Sequence();

    // replace calling sequence with a deep copy of the other
    Sequence &operator=(const Sequence &s);

    // overload "[]" operator to work with sequence
    std::string &operator[](size_t position);

    // push value onto the end of the sequence.
    void push_back(std::string item);

    // delete last element of sequence (element at tail)
    void pop_back();

    // insert element into sequence at position.
    void insert(size_t position, std::string item);

    // Get first element in the sequence.
    std::string front() const;

    // Get last element in the sequence.
    std::string back() const;

    // Return true if the sequence has no elements, otherwise false.
    bool empty() const;

    // Return the number of elements in the sequence.
    size_t size() const;

    // free all memory (of elements) and remove from sequence
    void clear();

    // erase element and free memory at position.
    void erase(size_t position);

    // free memory and remove "count" number of elements at position.
    void erase(size_t position, size_t count);

    // allow elements to be output to stream by << by friending overload of << with Sequence.
    friend std::ostream &operator<<(std::ostream &os, const Sequence &s);
};

#endif //PROJECT3_SEQUENCE_H
