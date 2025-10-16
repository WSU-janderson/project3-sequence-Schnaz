/**
 * Sequence.cpp
 * Project 3 - Linked Sequence Data Structure
 * CS 3100 - Adam Hume
 *
 * This is the Class file, containing the implementation of all the
 * functions used with the Sequence class.
 * It also includes the override for the ostream's "<<" operator.
 */

#include "Sequence.h"

// Sequence(size) - Constructor
// Creates an empty sequence or a sequence with "sz" number of empty nodes
Sequence::Sequence(size_t sz) {
    sequenceSize = sz; // set number of nodes in sequence
    head = nullptr; // set pointer to head of sequence to null
    tail = nullptr; // set pointer to tail end of sequence to null

    // check if Sequence needs to be populated with nodes, initializing the first node if true
    if (sz > 0) {
        head = new SequenceNode;
        tail = head;

        // add remaining nodes to sequence linking the new node to the previous one and vice versa
        for (size_t i = 0; i < sequenceSize - 1; i++) {
            tail->next = new SequenceNode;
            tail->next->prev = tail;
            tail = tail->next;
        }
    }
}

// Sequence(Sequence) - Copy Constructor
// Creates a (deep) copy of sequence s
Sequence::Sequence(const Sequence &s) {
    sequenceSize = s.sequenceSize; // copy the number of nodes
    head = nullptr; // set pointer to head of sequence to null
    tail = nullptr; // set pointer to tail end of sequence to null

    // check if the sequence isn't empty
    if (sequenceSize > 0) {
        head = new SequenceNode;
        head->item = s.head->item;
        tail = head;
        SequenceNode *travel = s.head; // pointer to travel through sequence being copied (to copy items)

        // create and link up nodes in copied sequence, copying over the item in each node
        for (size_t i = 0; i < sequenceSize - 1; i++) {
            travel = travel->next;
            tail->next = new SequenceNode;
            tail->next->prev = tail;
            tail = tail->next;
            tail->item = travel->item;
        }
    }
}

// ~Sequence() - Deconstructor
// Destroys all items in sequence and release all memory associated with sequence
Sequence::~Sequence() {
    clear(); // This function destroys all nodes. Destroying Sequence here would cause problems as it is automatic
}

// operator=(Sequence) - overload "=" operator, returns a Sequence Object
// replace calling sequence with a deep copy of the other Sequence
Sequence &Sequence::operator=(const Sequence &s) {
    clear(); // clear out any existing nodes
    sequenceSize = s.sequenceSize; // copy the number of nodes
    head = nullptr; // set pointer to head of sequence to null
    tail = nullptr; // set pointer to tail end of sequence to null

    // check if the sequence isn't empty
    if (sequenceSize > 0) {
        head = new SequenceNode;
        head->item = s.head->item;
        tail = head;
        SequenceNode *travel = s.head; // pointer to travel through sequence being copied (to copy items)

        // create and link up nodes in copied sequence, copying over the item in each node
        for (size_t i = 0; i < sequenceSize - 1; i++) {
            travel = travel->next;
            tail->next = new SequenceNode;
            tail->next->prev = tail;
            tail = tail->next;
            tail->item = travel->item;
        }
    }
    return *this;
}

// operator[] - Overload "[]" operator, returns a string
// allow access of items in sequence using the "[]" operator
// throws exception if position is out of bounds
std::string &Sequence::operator[](size_t position) {
    // test for exception
    if ((position > sequenceSize - 1) || !(position + 1)) {
        throw std::exception();
    }

    // use a pointer to "travel" through the sequence and return the requested item
    SequenceNode *travel = head;
    for (size_t i = 0; i < position; i++) {
        travel = travel->next;
    }
    return travel->item;
}

// push_back(item)
// pushes a value stored within a node onto the end of the sequence.
void Sequence::push_back(std::string item) {
    // check if first node needs to be initialized.
    if (sequenceSize == 0) {
        head = new SequenceNode;
        head->item = item;
        tail = head;
        sequenceSize++;
        return;
    }

    // if not, attach the new node to the tail of the sequence with its item.
    tail->next = new SequenceNode;
    tail->next->prev = tail;
    tail = tail->next;
    tail->item = item;
    sequenceSize++;
}

// pop_back()
// delete last element of sequence. (element at tail)
// throws exception if no nodes in sequence.
void Sequence::pop_back() {
    // Test for exception
    if (empty()) {
        throw std::exception();
    }

    // Check if this is the last node in the sequence
    if (sequenceSize == 1) {
        delete tail;
        head = nullptr;
        tail = nullptr;
        sequenceSize--;
        return;
    }

    // Otherwise, move the tail pointer back, delete the last node and remove the dangling pointer
    tail = tail->prev;
    delete tail->next;
    tail->next = nullptr;
    sequenceSize--;
}

// insert(position, item)
// insert element into sequence at position.
// throws exception if position is outside Sequence.
void Sequence::insert(size_t position, std::string item) {
    // Test for exception
    if ((position > sequenceSize - 1) || !(position + 1)) {
        throw std::exception();
    }

    // Have a pointer "travel" to the point a node is to be inserted
    SequenceNode *travel = head;
    for (size_t i = 0; i < position; i++) {
        travel = travel->next;
    }

    // Check if position for insertion is at start of sequence, assign head to new node if so.
    if (position == 0) {
        head = new SequenceNode;
        head->next = travel;
        travel->prev = head;
        head->item = item;
        sequenceSize++;
        return;
    }

    // Otherwise, the node will be placed between two others, and will have more next/prev pointers to link
    travel->prev->next = new SequenceNode;
    travel->prev->next->prev = travel->prev;
    travel->prev = travel->prev->next;
    travel->prev->next = travel;
    travel->prev->item = item;
    sequenceSize++;
}

// front(), returns item as string
// Gets the item in the first node of the sequence.
// Throws exception if sequence is empty.
std::string Sequence::front() const {
    if (empty()) {
        throw std::exception();
    }
    return head->item;
}

// back(), returns item as string
// Get last element in the sequence.
// Throws exception if sequence is empty.
std::string Sequence::back() const {
    if (empty()) {
        throw std::exception();
    }
    return tail->item;
}

// empty()
// Return true if the sequence has no elements, otherwise return false.
bool Sequence::empty() const {
    if (sequenceSize) return false;
    return true;
}

// size(), returns number of nodes as a size_t
// Return the number of elements in the sequence.
size_t Sequence::size() const {
    return sequenceSize;
}

// clear()
// free all memory (of elements) and remove from sequence
void Sequence::clear() {
    // loop through sequence running pop_back to delete all the nodes
    for (size_t i = sequenceSize; i; i--) {
        pop_back();
    }
    sequenceSize = 0;
}

// erase(position)
// erase node and free memory at position.
// throws exception if position is out of bounds
void Sequence::erase(size_t position) {
    // test for exception
    if ((position > sequenceSize - 1) || !(position + 1)) {
        throw std::exception();
    }

    // traverse Sequence to position
    SequenceNode *travel = head;
    for (size_t i = 0; i < position; i++) {
        travel = travel->next;
    }

    // Check if deleting last node in sequence, assigning head and tail to null if true.
    if (sequenceSize == 1) {
        delete travel;
        sequenceSize--;
        head = nullptr;
        tail = nullptr;
        return;
    }

    // Check if deleting first node in sequence to determine if the head pointer needs to change
    if (position == 0) {
        head = travel->next;
        head->prev = nullptr;
    } else travel->prev->next = travel->next;

    // Check if deleting last node in sequence to determine if the tail pointer needs to change
    if (position == sequenceSize - 1) {
        tail = travel->prev;
        tail->next = nullptr;
    } else travel->next->prev = travel->prev;

    delete travel;
    sequenceSize--;
}

// erase(position, count)
// delete "count" number of elements from position, freeing assigned memory.
// throws exception if position is out of bounds or count goes out of bounds (or is negative)
void Sequence::erase(size_t position, size_t count) {
    // test for exception
    if ((position > sequenceSize - 1) || !(position + 1) || (count + position > sequenceSize) || !(count + 1)) {
        throw std::exception();
    }

    // Call delete(position) function "count" number of times to remove that many nodes from position.
    for (size_t i = 0; i < count; i++) {
        erase(position);
    }
}

// operator<<(output stream, Sequence) - Overload "<<" operator, returns an output stream
// allows for all items held within nodes to be output to stream by <<
std::ostream &operator<<(std::ostream &os, const Sequence &s) {
    //iterate through Sequence until a null pointer is reached, adding each item to the output stream
    SequenceNode *travel = s.head;
    while (travel != nullptr) {
        os << travel->item + " ";
        travel = travel->next;
    }
    return os;
}
