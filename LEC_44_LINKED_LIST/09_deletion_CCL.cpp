#include <iostream>
using namespace std;

class Node
{
    // Node Creation and linked list start
public:
    int data;
    Node *next;

    // Constructor
    Node(int d)
    {
        this->data = d;
        this->next = NULL;
    }

    // Destructor
    ~Node()
    {
        int value = this->data;
        if (this->next != NULL)
        {
            delete next;
            next = NULL;
        }
        cout << "memory is free for node with data " << value << endl;
    }
};

void insertNode(Node *&tail, int element, int d)
{
    // Assuming that the element is present in the list

    // empty list
    if (tail == NULL)
    {
        Node *newNode = new Node(d);
        tail = newNode;
        newNode->next = newNode;
    }
    else
    {
        // non empy list
        // assuming that the element is present in the list
        Node *curr = tail;
        while (curr->data != element)
        {
            curr = curr->next;
        }
        // element foudn -> curr is represinting element wala node
        Node *temp = new Node(d);
        temp->next = curr->next;
        curr->next = temp;
    }
}

void print(Node *tail)
{
    Node *temp = tail;
    if(tail==NULL)
    {
        cout<<"List is Empty"<<endl;
        return;
    }
    do
    {
        cout << tail->data << " ";
        tail = tail->next;
    } while (tail != temp);
    cout << endl;
}

// Deletion in circular list or CCL
void deleteNode(Node *&tail, int value)
{
    // if list is EMPTY
    if (tail == NULL)
    {
        cout << " list is empty , please check again " << endl;
        return;
    }
    else
    {
        // if list is NON-EMPTY
        // assuming that "value " is present in the linked list
        Node *prev = tail;
        Node *curr = prev->next;

        while (curr->data != value)
        {
            prev = curr;
            curr = curr->next;
        }
        prev->next = curr->next;
        // only 1 node linkedlist then do this
        if (curr == prev)
        {
            tail = NULL;
        }

        // for linked list greater or equal to 2
        else if (tail == curr)
        {
            tail = prev;
        }
        curr->next = NULL;
        delete curr;
    }
}
int main()
{
    Node *tail = NULL;
    // empty list me insert karre hai
    insertNode(tail, 5, 3);
    print(tail);
    /*
        insertNode(tail, 3, 5);
        print(tail);

        insertNode(tail, 5, 7);
        print(tail);

        insertNode(tail, 7, 9);
        print(tail);

        insertNode(tail, 5, 6);
        print(tail);

        insertNode(tail, 9, 10);
        print(tail);

        insertNode(tail, 3, 4);
        print(tail);
    */
    deleteNode(tail, 3);
    print(tail);
    return 0;
}