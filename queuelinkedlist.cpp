#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

Node *front = NULL;
Node *rear = NULL;

void enqueue(int x)
{
    Node *newNode = new Node;
    newNode->data = x;
    newNode->next = NULL;

    if (front == NULL)
    {
        front = rear = newNode;
    }
    else
    {
        rear->next = newNode;
        rear = newNode;
    }
}

void dequeue()
{
    if (front == NULL)
    {
        cout << "Queue Underflow" << endl;
    }
    else
    {
        cout << "Deleted: " << front->data << endl;
        front = front->next;
    }
}

void display()
{
    Node *temp = front;

    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main()
{
    enqueue(10);
    enqueue(20);
    enqueue(30);

    display();

    dequeue();

    display();

    return 0;
}
