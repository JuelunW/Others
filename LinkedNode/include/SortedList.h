#pragma once
#include "LinkedNode.h"
#include "std_lib_facilities.h"
template < class T > class SortedList {
private :
    LinkedNode<T>* m_head;
    LinkedNode<T>* m_tail;
public :
    SortedList ();
    SortedList (const SortedList& source);
    SortedList& operator=(const SortedList& rhs);
    int getNumElems() const;
    pair<bool, T> getElemAtIndex(int index) const;
    void insertValue(T value);
    pair<bool , T> removeFront ();
    pair<bool , T> removeBack ();
    void printForward () const ;
    void printBackward () const ;
    void clear ();
    ~SortedList ();
};

#include "SortedList.inl"