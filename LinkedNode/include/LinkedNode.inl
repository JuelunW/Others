template < class T> LinkedNode<T>::LinkedNode(T value, LinkedNode<T>* prev, LinkedNode<T>* next){
    m_nodeValue = value;
    m_prevNode = prev;
    m_nextNode = next;
}

template < class T> T LinkedNode<T>::getValue () const{
    return m_nodeValue;
}

template < class T> LinkedNode<T>* LinkedNode <T>::getPrev () const{
    return m_prevNode;
}

template < class T> LinkedNode<T>* LinkedNode <T>::getNext () const{
    return m_nextNode;
}

template < class T> void LinkedNode <T>::setPreviousPointerToNull (){
    m_prevNode = nullptr;
}

template < class T> void LinkedNode <T>::setNextPointerToNull (){
    m_nextNode = nullptr;
}

template < class T> void LinkedNode <T>::setBeforeAndAfterPointers (){
    if(m_prevNode != nullptr){
        (*m_prevNode).m_nextNode = this;
    }
    if(m_nextNode != nullptr){
        (*m_nextNode).m_prevNode = this;
    }
}