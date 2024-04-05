//Coding ninjas : Middle of linked list

#include<bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node()
    {
        this->data = 0;
        next = NULL;
    }
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
    Node(int data, Node *next)
    {
        this->data = data;
        this->next = next;
    }
};

int length(Node *head)
{
    int count = 0;
    while (head != NULL)
    {
        count++;
        head = head->next;
    }
    return count;
}

Node *findMiddle(Node *head)
{
    int len = length(head);
    int pos = len / 2;

    Node *temp = head;

    while (pos != 0)
    {
        temp = temp->next;
        pos--;
    }
    return temp;
}


int main() {
    // Creating nodes
    Node *node1 = new Node(1);
    Node *node2 = new Node(2);
    Node *node3 = new Node(3);
    Node *node4 = new Node(4);
    Node *node5 = new Node(5);

    // Connecting nodes
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;

    // Finding the middle node
    Node *middleNode = findMiddle(node1);

    // Displaying the data of the middle node
    std::cout << "Middle node data: " << middleNode->data << std::endl;

    // Cleaning up memory
    delete node1;
    delete node2;
    delete node3;
    delete node4;
    delete node5;

    return 0;
}
