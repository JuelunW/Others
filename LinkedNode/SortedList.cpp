#include "SortedList.h"
SortedList::SortedList (){
    m_head = nullptr;
    m_tail = nullptr;
}

SortedList::SortedList (const SortedList& source){
    m_head = source.m_head;
    m_tail = source.m_tail;
}

SortedList& SortedList::operator=(const SortedList& rhs){
    m_head = rhs.m_head;
    m_tail = rhs.m_tail;
}

int SortedList::getNumElems() const{
    if(m_head == nullptr || m_tail == nullptr) return 0;
    if(m_head == m_tail) return 1;

    int num = 1;
    LinkedNode* tmp = m_head;
    while(tmp->getNext() != nullptr){
        num += 1;
        tmp = tmp->getNext();
    }
    return num;
}

pair<bool, int> SortedList::getElemAtIndex(int index) const{
    pair<bool, int> result;
    result.first = false;
    if(index >= getNumElems()) return result;

    result.first = true;
    LinkedNode* tmp = m_head;
    for(int i = 1; i <= index; i++){
        tmp = tmp->getNext();
    }
    result.second = tmp->getValue();
    return result;
}

void SortedList::insertValue(int value){
    LinkedNode* prev = nullptr;
    LinkedNode* next = m_head;

    int num  = getNumElems();
    for(int i = 0; i < num; i++){
        if(value < next->getValue()) break;
        next = next->getNext();
        if(next == nullptr) prev = m_tail;
        else prev = next->getPrev();
    }


    LinkedNode* temp;
    temp = new LinkedNode(value, prev, next);
    temp -> setBeforeAndAfterPointers();

    if(prev == nullptr) m_head = temp;
    if(next == nullptr) m_tail = temp;
}

pair<bool , int> SortedList::removeFront (){
    pair<bool , int> result;

    if(m_head == nullptr){
        result.first = false;
        return result;
    }

    result.first = true;
    result.second = m_head->getValue();

    m_head = m_head->getNext();
    m_head->setPreviousPointerToNull();
    return result;
}

pair<bool , int> SortedList::removeBack (){
    pair<bool , int> result;

    if(m_tail == nullptr){
        result.first = false;
        return result;
    }

    result.first = true;
    result.second = m_tail->getValue();

    m_tail = m_tail->getPrev();
    m_tail->setNextPointerToNull();
    return result;
}

void SortedList::printForward () const {
    cout << "Forward List Contents Follow:" << endl;
    LinkedNode* tmp = m_head;
    int num  = getNumElems();
    for(int i = 0; i < num; i++){
        cout << "  " << tmp->getValue() << endl;
        tmp = tmp->getNext();
    }
    cout << "End of List Contents" << endl;
}

void SortedList::printBackward () const {
    cout << "Backward List Contents Follow:" << endl;
    LinkedNode* tmp = m_tail;
    int num  = getNumElems();
    for(int i = 0; i < num; i++){
        cout << "  " << tmp->getValue() << endl;
        tmp = tmp->getPrev();
    }
    cout << "End of List Contents" << endl;
}

void SortedList::clear (){
    m_head = nullptr;
    m_tail = nullptr;
}

SortedList::~SortedList (){
    LinkedNode* tmp = m_head;
    int num  = getNumElems();
    for(int i = 0; i < num; i++){
        delete [] tmp;
        tmp = tmp->getNext();
    }
}