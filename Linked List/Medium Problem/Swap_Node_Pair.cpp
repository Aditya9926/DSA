#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

class Solution
{
public:
    Node *swappair(Node *head)
    {
        if (head == NULL || head->next == NULL)
        {
            return head;
        }

        Node *prev = NULL;
        Node *first = head;
        Node *second = head->next;

        while (first != NULL && second != NULL)
        {
            Node *third = second->next;
            second->next = first;
            first->next = third;
            if (prev != NULL)
            {
                prev->next = second;
            }
            else
            {
                head = second;
            }

            prev = first;
            first = third;
            if (third != NULL)
            {
                second = first->next;
            }
            else
            {
                second = NULL;
            }
        }
        return head;
    }
};

int main(){
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    
    Solution sol;
    head = sol.swappair(head);
    Node* curr = head;
    while(curr != NULL){
        cout << curr->data << " ";
        curr = curr->next;
    }
    return 0;
}