#pragma once
//LinkedNode: This class will be used to store individual nodes of a doubly-linked list data structure.
// This class should end up being quite short and simple - no significant complexity is needed nor desired.
// The interface of LinkedNode should be exactly as follows:
class LinkedNode {
// The LinkedNode class will be the data type for individual nodes of a doubly−linked list data structure .
private:
// The value contained within this node.
    int m_nodeValue ;
// m_prevNode points to the node that comes before this node in the data structure.
// It will be nullptr if this is the first node.
    LinkedNode* m_prevNode;
// m_nextNode points to the node that comes after this node in the data structure.
// It will be nullptr if this is the last node.
    LinkedNode* m_nextNode;
public:
// The ONLY constructor for the LinkedNode class − it takes in the newly created node’s previous pointer, value, and next pointer, and assigns them.
// Input:
// − pointer to the node that comes before this node
// − value to be stored in this node
// − pointer to the node that comes after this one
    LinkedNode(int value, LinkedNode* prev, LinkedNode* next);
// Returns the value stored within this node
    int getValue () const;
// Returns the address of the node that comes before this node.
    LinkedNode* getPrev () const;
// Returns the address of the node that follows this node.
    LinkedNode* getNext () const;
// Sets the object’s previous node pointer to nullptr.
    void setPreviousPointerToNull ();
// Sets the object’s next node pointer to nullptr.
    void setNextPointerToNull ();
// This function DOES NOT modify "this" node.
// Instead, it uses the pointers contained within this node to change the previous and next nodes
// so that they point to this node appropriately.
// In other words, if "this" node is set up such that its prevNode pointer points to a node (call it "A"),
// and "this" node’s nextNode pointer points to another node (call it "B"),
// then calling setBeforeAndAfterPointers() results in the node we’re calling "A" to be updated
// so its "m_nextNode" points to "this" node, and the node we’re calling "B" is updated
// so its "m_prevNode" points to "this" node. "this" node itself remains unchanged .
    void setBeforeAndAfterPointers ();
};