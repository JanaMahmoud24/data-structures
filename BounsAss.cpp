// 1)Improved MakeNull Function for Doubly Linked List

void DoublyList::MakeNull() {
    Position curr = head;
    while (curr != nullptr) {
        Position temp = curr;
        curr = curr->next;
        delete temp;
    }
    head = nullptr;
    tail = nullptr;
    counter = 0;
}
















// 2)
//1- Singly Linked List 

#include <iostream>

typedef int ElementType;

// Definition of the node structure for Singly Linked List
class Node {
public:
    ElementType data;
    Node* next;
};

typedef Node* Position;

class SinglyList {
private:
    Position head;
    int counter;

public:
    SinglyList() {
        head = nullptr;
        counter = 0;
    }
    void MakeNull() {
        Position curr = head;
        while (curr != nullptr) {
            Position temp = curr;
            curr = curr->next;
            delete temp;
        }
        head = nullptr;
        counter = 0;
    }

    // Function to insert elements in sorted order
    void InsertSorted(ElementType x) {
        Position newNode = new Node;
        newNode->data = x;
        newNode->next = nullptr;

        if (head == nullptr || x < head->data) {
            newNode->next = head;
            head = newNode;
        } 
        else {
            Position curr = head;
            while (curr->next != nullptr && curr->next->data < x) {
                curr = curr->next;
            }
            newNode->next = curr->next;
            curr->next = newNode;
        }
        counter++;
    }

    // Function to print the list
    void PrintList() {
        Position p = head;
        while (p != nullptr) {
            std::cout << p->data << " -> ";
            p = p->next;
        }
        std::cout << "NULL\n";
    }};

int main() {
    SinglyList list;

    list.InsertSorted(10);
    list.InsertSorted(5);
    list.InsertSorted(20);
    list.InsertSorted(15);
    list.InsertSorted(7);

    std::cout << "Sorted Singly Linked List: ";
    list.PrintList();
    list.MakeNull();

    return 0;
}













// 2)
//2- Doubly Linked List 


#include <iostream>

typedef int ElementType;


class Node {
public:
    ElementType data;
    Node* next;
    Node* prev;
};

typedef Node* Position;

class DoublyList {
private:
    Position head;
    Position tail;
    int counter;

public:
    DoublyList() {
        head = nullptr;
        tail = nullptr;
        counter = 0;
    }


    void MakeNull() {
        Position curr = head;
        while (curr != nullptr) {
            Position temp = curr;
            curr = curr->next;
            delete temp;
        }
        head = nullptr;
        tail = nullptr;
        counter = 0;
    }

    void InsertSorted(ElementType x) {
        Position newNode = new Node;
        newNode->data = x;
        newNode->next = nullptr;
        newNode->prev = nullptr;


        if (head == nullptr) {  
            head = tail = newNode;
        } 
        else if (x < head->data) { 
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        } 
        else {
            Position curr = head;
            while (curr->next != nullptr && curr->next->data < x) {
                curr = curr->next;
            }

            newNode->next = curr->next;
            newNode->prev = curr;

            if (curr->next != nullptr) {
                curr->next->prev = newNode;
            } else {
                tail = newNode; 
            }
            curr->next = newNode;
        }
        counter++;
    }

    // Function to print the list
    void PrintList() {
        Position p = head;
        while (p != nullptr) {
            std::cout << p->data << " -> ";
            p = p->next;
        }
        std::cout << "NULL\n";
    }};

int main() {
    DoublyList list;

    list.InsertSorted(10);
    list.InsertSorted(5);
    list.InsertSorted(20);
    list.InsertSorted(15);
    list.InsertSorted(7);

    std::cout << "Sorted Doubly Linked List: ";
    list.PrintList();

    list.MakeNull(); 

    return 0;
}
