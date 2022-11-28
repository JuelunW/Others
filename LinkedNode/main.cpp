#include "std_lib_facilities.h"
#include "LinkedNode.h"
#include "SortedList.h"

int main()
{
    LinkedNode* head;
    LinkedNode* temp;
    head = new LinkedNode(1, nullptr, nullptr);
    temp = new LinkedNode(2, head, nullptr);
    temp -> setBeforeAndAfterPointers();
    temp = new LinkedNode(3, temp, nullptr);
    temp -> setBeforeAndAfterPointers();


    temp = head;
    while(temp != nullptr) {
        cout << temp -> getValue() << endl;
        temp = temp -> getNext();
    }

    cout << "//////" << endl;

    SortedList myList;

    myList.insertValue(5);
    //cout << myList.getNumElems() << endl;
    //myList.printForward();
    myList.insertValue(10);
    myList.insertValue(1);
    myList.insertValue(5);

    myList.printForward();
    myList.printBackward();


    int size = myList.getNumElems();
    cout << "\nThe number of elements is " << size << endl;

    cout << "\nGet element at index\n";
    pair<bool, int> tmp;
    for(int i = 0; i < size; i++){
        tmp = myList.getElemAtIndex(i);
        cout << "index " << i << ": " << tmp.second << endl;
    }


    tmp = myList.removeFront();
    if(tmp.first) cout << "\nRemove front element value: " << tmp.second << endl;
    else cout << tmp.first << endl;
    myList.printForward();


    tmp = myList.removeBack();
    if(tmp.first) cout << "\nRemove back element value: " << tmp.second << endl;
    else cout << tmp.first << endl;
    myList.printBackward();

    cout << "\nClear\n";
    myList.clear();
    cout << myList.getNumElems() << endl;

    return 0;
}