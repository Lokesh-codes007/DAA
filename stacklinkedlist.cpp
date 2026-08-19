#include <iostream>
using namespace std;
struct Node
{
    int data;
    Node *next;
};

Node *top = NULL;

void push(int x)
{
    Node *newNode = new Node;
    newNode->data = x;
    newNode->next = top;
    top = newNode;
}

void pop()
{
    if (top == NULL)
    {
        cout << "Stack Underflow" << endl;
    }
    else
    {
        cout << "Deleted: " << top->data << endl;
        top = top->next;
    }
}

void peek()
{
    if (top == NULL)
        cout << "Stack is Empty" << endl;
    else
        cout << "Top Element: " << top->data << endl;
}

void display()
{
    Node *temp = top;

    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main()
{
    push(10);
    push(20);
    push(30);

    display();
    peek();

    pop();
    display();

    return 0;
}
