#include <iostream>
using namespace std;

struct Node{
  int info;
  Node *next;
};

class SortedSingly{
  private:
    Node *first, *last;
    int length;

  public:
    SortedSingly(){
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

        // Case 1: List is empty
        
        if (isEmpty()) {
            first = last = newNode; 
        }
        // Case 2: Item inserted at the beginning
    
        else if (item <= first->info) {
            newNode->next = first;
            first = newNode;
        }
        // Case 3: Iteminserted in the middle or at the end
        
        else {
            Node *current = first;
            while (current->next != NULL && current->next->info < item) {
                current = current->next;
            }
            newNode->next = current->next; 
            current->next = newNode;     
            // If newNode was inserted at the end
            if (newNode->next == NULL) {
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
    cout << "--- Sorted Singly Linked List ---" << endl;
    SortedSingly sortedL1;
    sortedL1.print(); 
	sortedL1.insertSorted(20);
	sortedL1.print(); 
	sortedL1.insertSorted(10);
	sortedL1.print();
	sortedL1.insertSorted(25);
	sortedL1.print();
	sortedL1.insertSorted(15);
	sortedL1.print();
    sortedL1.insertSorted(5);
    sortedL1.print(); 
    sortedL1.insertSorted(30);
    sortedL1.print(); 
	return 0;
}