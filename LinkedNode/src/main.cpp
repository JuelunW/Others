#include "std_lib_facilities.h"
#include "LinkedNode.h"
#include "SortedList.h"

int main()
{
    LinkedNode<string>* head;
    LinkedNode<string>* temp;
    head = new LinkedNode<string>("one", nullptr, nullptr);
    temp = new LinkedNode<string>("two", head, nullptr);
    temp -> setBeforeAndAfterPointers();
    temp = new LinkedNode<string>("three", temp, nullptr);
    temp -> setBeforeAndAfterPointers();


    temp = head;
    while(temp != nullptr) {
        cout << temp -> getValue() << endl;
        temp = temp -> getNext();
    }

    cout << "//////" << endl;

    SortedList<string> myList;
    pair<bool, string> tmp;

    myList.insertValue("one");
    //cout << myList.getNumElems() << endl;
    //myList.printForward();
    myList.insertValue("two");
    myList.insertValue("three");
    myList.insertValue("four");

    myList.printForward();
    myList.printBackward();


    int size = myList.getNumElems();
    cout << "\nThe number of elements is " << size << endl;

    cout << "\nGet element at index\n";
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