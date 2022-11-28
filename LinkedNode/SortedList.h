#pragma once
#include "LinkedNode.h"
#include "std_lib_facilities.h"
// SortedList: This class will be used to store a doubly-linked list in an always-sorted manner,
// such that the user does not specify where in the list a new value should be inserted,
// but rather the new value is inserted in the correct place to maintain a sorted order.
// The interface to the SortedList should be exactly as follows:
class SortedList {
// The SortedList class does not store any data directly.
// Instead, it contains a collection of LinkedNode objects, each of which contains one element.
private :
// Points to the first node in a list, or nullptr if list is empty .
    LinkedNode* m_head;
// Points to the last node in a list, or nullptr if list is empty.
    LinkedNode* m_tail;
public :
// Default Constructor. It will properly initialize a list to be an empty list, to which values can be added.
    SortedList ();
// Copy constructor. It will make a complete(deep) copy of the list, such that one can be changed without affecting the other.
    SortedList (const SortedList& source);
// Copy assignment operator. It will make a complete(deep) copy of the list such that one can be changed without affecting the other.
    SortedList& operator=(const SortedList& rhs);
// Returns the number of nodes contained in the list.
    int getNumElems() const;
// Provides the value stored in the node at the index provided in the 0−based "index" parameter.
// If the index is out of range, then the function returns a pair with the first element set to false to indicate failure, and the contents of the second element is undefined. Otherwise, the function returns a pair with the first element set to true and the second element will contain a copy of the value at position "index".
    pair<bool, int> getElemAtIndex(int index) const;
// Allows the user to insert a value into the list. Since this is a sorted list, there is no need to specify where in the list to insert the element. It will insert it in the appropriate location based on the value being inserted. If the node value being inserted is found to be "equal to" one or more node values already in the list , the newly inserted node will be placed AFTER the previously inserted nodes.
    void insertValue(int value);
// Removes the front item from the list. If the list was empty, the function returns a pair with the first element set to false to indicate failure, and the contents of the second element is undefined. If the list was not empty and the first item was successfully removed, the function returns a pair with the first element set to true, and the second element will be set to the value that was removed.
    pair<bool , int> removeFront ();
// Removes the back item from the list. If the list was empty, the function returns a pair with the first element set to false to indicate failure, and the contents of the second element is undefined. If the list was not empty and the last item was successfully removed, the function returns a pair with the first element set to true, and the second element will be set to the value that was removed.
    pair<bool , int> removeBack ();
// Prints the contents of the list from head to tail to the screen.
// Begins with a line reading "Forward List Contents Follow:", then prints one list element per line, indented two spaces, then prints the line "End of List Contents" to indicate the end of the list.
    void printForward () const ;
// Prints the contents of the list from tail to head to the screen.
// Begins with a line reading "Backward List Contents Follow:", then prints one list element per line, indented two spaces, then prints the line "End of List Contents" to indicate the end of the list.
    void printBackward () const ;
// Clears the list to an empty state without resulting in any memory leaks.
    void clear ();
// Destructor, which will free up all dynamic memory associated with this list when the list is destroyed
// (i.e. when a statically allocated list goes out of scope or a dynamically allocated list is deleted).
    ~SortedList ();
};