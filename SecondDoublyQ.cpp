#include <iostream>
using namespace std;

struct Node{
  int info;
  Node *next;
  Node *prev; 
};

class SortedDoubly{ 
  private:
    Node *first, *last;
    int length;

  public:
    SortedDoubly(){
        first = last = NULL; 
        length = 0;
    }
    bool isEmpty(){
        return (length == 0);
    }

    void insertSorted(int item){
        Node *newNode = new Node;
        newNode->info = item;
        newNode->next = NULL;
        newNode->prev = NULL; 

        // Case 1: List is empty
        
        if (isEmpty()) {
            first = last = newNode;
        }
        // Case 2: Item is smaller than or equal to the first item (insert at beginning)
        
        else if (item <= first->info) {
            newNode->next = first;  
            first->prev = newNode; 
            first = newNode;      
        }
        // Case 3: Item inserted in the middle or at the end
        
        else {
            Node *current = first;
            while (current->next != NULL && current->next->info < item) {
                current = current->next;
            }
            newNode->next = current->next; 
            newNode->prev = current;    
            current->next = newNode;       

            if (newNode->next != NULL) {
                 newNode->next->prev = newNode;
            }
            // newNode was inserted at the end
            else {
                last = newNode;
            }
        }
        length++;
    }
    void print(){
        Node *current = first;
        cout << "List (" << length << " items): ";
        while (current != NULL){
            cout << current -> info << " ";
            current = current -> next;
        }
        cout << endl;
    }
};

int main() {
    cout << "--- Sorted Doubly Linked List ---" << endl;
    SortedDoubly sortedDL1;
    sortedDL1.print();
	sortedDL1.insertSorted(20);
	sortedDL1.print();     
	sortedDL1.insertSorted(10);
	sortedDL1.print();       
	sortedDL1.insertSorted(25);
	sortedDL1.print();         
	sortedDL1.insertSorted(15);
	sortedDL1.print();          
    sortedDL1.insertSorted(5);
    sortedDL1.print();      
    sortedDL1.insertSorted(30);
    sortedDL1.print();        
	return 0;
}