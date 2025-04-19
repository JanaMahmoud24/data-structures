#include <iostream>
using namespace std;

struct Node {
    int data;      
    Node* next;
    Node* prev;
};

class DoublyList {
private:
    Node* head;     
    Node* tail;     
    int length;

public:
    DoublyList() {
        head = NULL;
        tail = NULL;
        length = 0;
    }

    void MakeNull() {
        Node* current;
        while (head != NULL) {
            current = head;
            head = head->next;    
            delete current;       
        }
        tail = NULL;
        length = 0;
    }

    void PrintList() {
        Node* p = head; 
        while(p != NULL) {
            cout << p->data << " ";
            p = p->next;
        }
        	cout << endl;
    }
    
     void InsertAtStart(int x) {
        Node* newNode = new Node;
        newNode->data = x;
        newNode->next = head;
        newNode->prev = NULL;
        if(head != NULL) {
            head->prev = newNode;
        }
        head = newNode;
        if(tail == NULL) {
            tail = head;
        }
        length++;
    }
};

int main() {
    DoublyList L;

    L.InsertAtStart(10);
    L.InsertAtStart(20);
    L.InsertAtStart(30);

    cout << "List before MakeNull:" << endl;
    L.PrintList(); 

    L.MakeNull(); 

    cout << "List after MakeNull:" << endl;
    L.PrintList(); 
    return 0;
} 