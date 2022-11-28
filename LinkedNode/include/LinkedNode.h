#pragma once
template < class T> class LinkedNode {
private:
    T m_nodeValue ;
    LinkedNode<T>* m_prevNode;
    LinkedNode<T>* m_nextNode;
public:
    LinkedNode(T value, LinkedNode* prev, LinkedNode* next);
    T getValue () const;
    LinkedNode<T>* getPrev () const;
    LinkedNode<T>* getNext () const;
    void setPreviousPointerToNull ();
    void setNextPointerToNull ();
    void setBeforeAndAfterPointers ();
};

#include "LinkedNode.inl"