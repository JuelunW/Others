template < class T> SortedList<T>::SortedList (){
    m_head = nullptr;
    m_tail = nullptr;
}

template < class T> SortedList<T>::SortedList (const SortedList<T>& source){
    m_head = source.m_head;
    m_tail = source.m_tail;
}

template < class T> SortedList<T>& SortedList<T>::operator=(const SortedList<T>& rhs){
    m_head = rhs.m_head;
    m_tail = rhs.m_tail;
}

template < class T> int SortedList<T>::getNumElems() const{
    if(m_head == nullptr || m_tail == nullptr) return 0;
    if(m_head == m_tail) return 1;

    int num = 1;
    LinkedNode<T>* tmp = m_head;
    while(tmp->getNext() != nullptr){
        num += 1;
        tmp = tmp->getNext();
    }
    return num;
}

template < class T> pair<bool, T> SortedList<T>::getElemAtIndex(int index) const{
    pair<bool, T> result;
    result.first = false;
    if(index >= getNumElems()) return result;

    result.first = true;
    LinkedNode<T>* tmp = m_head;
    for(int i = 1; i <= index; i++){
        tmp = tmp->getNext();
    }
    result.second = tmp->getValue();
    return result;
}

template < class T> void SortedList<T>::insertValue(T value){
    LinkedNode<T>* prev = nullptr;
    LinkedNode<T>* next = m_head;

    int num  = getNumElems();
    for(int i = 0; i < num; i++){
        if(value < next->getValue()) break;
        next = next->getNext();
        if(next == nullptr) prev = m_tail;
        else prev = next->getPrev();
    }


    LinkedNode<T>* temp;
    temp = new LinkedNode<T>(value, prev, next);
    temp -> setBeforeAndAfterPointers();

    if(prev == nullptr) m_head = temp;
    if(next == nullptr) m_tail = temp;
}

template < class T> pair<bool , T> SortedList<T>::removeFront (){
    pair<bool , T> result;

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

template < class T> pair<bool , T> SortedList<T>::removeBack (){
    pair<bool , T> result;

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

template < class T> void SortedList<T>::printForward () const {
    cout << "Forward List Contents Follow:" << endl;
    LinkedNode<T>* tmp = m_head;
    int num  = getNumElems();
    for(int i = 0; i < num; i++){
        cout << "  " << tmp->getValue() << endl;
        tmp = tmp->getNext();
    }
    cout << "End of List Contents" << endl;
}

template < class T> void SortedList<T>::printBackward () const {
    cout << "Backward List Contents Follow:" << endl;
    LinkedNode<T>* tmp = m_tail;
    int num  = getNumElems();
    for(int i = 0; i < num; i++){
        cout << "  " << tmp->getValue() << endl;
        tmp = tmp->getPrev();
    }
    cout << "End of List Contents" << endl;
}

template < class T> void SortedList<T>::clear (){
    m_head = nullptr;
    m_tail = nullptr;
}

template < class T> SortedList<T>::~SortedList (){
    LinkedNode<T>* tmp = m_head;
    int num  = getNumElems();
    for(int i = 0; i < num; i++){
        delete [] tmp;
        tmp = tmp->getNext();
    }
}