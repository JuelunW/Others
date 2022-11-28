#include "LinkedNode.h"
LinkedNode::LinkedNode(int value, LinkedNode* prev, LinkedNode* next){
    m_nodeValue = value;
    m_prevNode = prev;
    m_nextNode = next;
}

int LinkedNode::getValue () const{
    return m_nodeValue;
}

LinkedNode* LinkedNode::getPrev () const{
    return m_prevNode;
}

LinkedNode* LinkedNode::getNext () const{
    return m_nextNode;
}

void LinkedNode::setPreviousPointerToNull (){
    m_prevNode = nullptr;
}

void LinkedNode::setNextPointerToNull (){
    m_nextNode = nullptr;
}

void LinkedNode::setBeforeAndAfterPointers (){
    if(m_prevNode != nullptr){
        (*m_prevNode).m_nextNode = this;
    }
    if(m_nextNode != nullptr){
        (*m_nextNode).m_prevNode = this;
    }
}