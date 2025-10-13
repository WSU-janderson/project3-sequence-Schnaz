/*
/ Adam Hume
/ Project 3 - Linked Sequence Data Structure
/
/ This is the header file. It holds all the declarations for
/ functions and variables both public and private for the Sequence class
*/

#include "Sequence.h"

// Creates an empty sequence (numElts == 0) or a sequence of numElts items
// indexed from 0 ... (numElts - 1).
Sequence::Sequence(size_t sz) {
    sequenceSize = sz;
    head = nullptr;
    tail = nullptr;
    if (sz > 0) {
        head = new SequenceNode;
        tail = head;
        for (size_t i = 0; i < sequenceSize - 1; i++) {
            SequenceNode* hold = tail;
            tail = new SequenceNode;
            hold->next = tail;
            tail->prev = hold;
        }
    }
}
// Creates a (deep) copy of sequence s
Sequence::Sequence(const Sequence& s) {
    sequenceSize = s.sequenceSize;
    if (sequenceSize > 0) {
        head = new SequenceNode;
        head->item = s.head->item;
        tail = head;
        SequenceNode* travel = s.head;
        for (size_t i = 0; i < sequenceSize - 1; i++) {
            SequenceNode* hold = tail;
            travel = travel->next;
            tail = new SequenceNode;
            tail->item = travel->item;
            hold->next = tail;
            tail->prev = hold;
        }
    }
}
// Destroys all items in the sequence and release the memory
// associated with the sequence
Sequence::~Sequence() {
    clear();
}
// The current sequence is released and replaced by a (deep) copy of sequence
// s. A reference to the copied sequence is returned (return *this;).
Sequence& Sequence::operator=(const Sequence& s) {
    clear();
    sequenceSize = s.sequenceSize;
    if (sequenceSize > 0) {
        head = new SequenceNode;
        head->item = s.head->item;
        tail = head;
        SequenceNode* travel = s.head;
        for (size_t i = 0; i < sequenceSize - 1; i++) {
            SequenceNode* hold = tail;
            travel = travel->next;
            tail = new SequenceNode;
            tail->item = travel->item;
            hold->next = tail;
            tail->prev = hold;
        }
    }
    return *this;
}
// The position satisfies ( position >= 0 && position <= last_index() ).
// The return value is a reference to the item at index position in the
// sequence. Throws an exception if the position is outside the bounds
// of the sequence
std::string& Sequence::operator[](size_t position) {
    if ( position > sequenceSize - 1 ) {
        throw std::exception();
    }
    else {
        SequenceNode* travel = head;
        for (size_t i = 0; i < position; i++) {
            travel = travel->next;
        }
        return travel->item;
    }
}
// The value of item is appended to the sequence.
void Sequence::push_back(std::string item) {
    tail->next = new SequenceNode;
    tail->next->prev = tail;
    tail = tail->next;
}
// The item at the end of the sequence is deleted and size of the sequence is
// reduced by one. If sequence was empty, throws an exception
void Sequence::pop_back() {
    tail->prev = tail;
    delete tail->next;
    tail->next = nullptr;
}
// The position satisfies ( position >= 0 && position <= last_index() ). The
// value of item is inserted at position and the size of sequence is increased
// by one. Throws an exception if the position is outside the bounds of the
// sequence
void Sequence::insert(size_t position, std::string item) {

}
// Returns the first element in the sequence. If the sequence is empty, throw an
// exception.
std::string Sequence::front() const {

}
// Return the last element in the sequence. If the sequence is empty, throw an
// exception.
std::string Sequence::back() const {

}
// Return true if the sequence has no elements, otherwise false.
bool Sequence::empty() const {

}
// Return the number of elements in the sequence.
size_t Sequence::size() const {
return sequenceSize;
}
// All items in the sequence are deleted and the memory associated with the
// sequence is released, resetting the sequence to an empty state that can have
// items re-inserted.
void Sequence::clear() {
erase(0, sequenceSize);
}
// The item at position is removed from the sequence, and the memory
// is released. If called with an invalid position throws an exception.
void Sequence::erase(size_t position) {

}
// The items in the sequence at ( position ... (position + count - 1) ) are
// deleted and their memory released. If called with invalid position and/or
// count throws an exception.
void Sequence::erase(size_t position, size_t count) {
    SequenceNode* travel=head;
    for ( size_t i = 0; i < position; i++ ) {

    }
    for ( size_t i = position; i < position + count; i++ ) {

    }
}
// Outputs all elements (ex: <4, 8, 15, 16, 23, 42>) as a string to the output
// stream. This is *not* a method of the Sequence class, but instead it is a
// friend function
std::ostream& operator<<(std::ostream& os, const Sequence& s) {
    SequenceNode* travel=s.head;
    while (travel != nullptr) {
        os << travel->item + " ";
        travel = travel->next;
    }
    return os;
}