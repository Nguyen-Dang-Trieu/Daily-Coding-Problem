#include <iostream>
#include <stdint.h>  // To use uintptr_t
using namespace std;


struct Node {
    int data;
    Node * both; // XOR of next and previous
};

class XORLinkedList{
    private:
        Node* head;
        Node* tail;
        // XOR function for Node pointers
        Node* XOR(Node* a, Node* b);
    public:
        //Constructor to initialize an empty list
        XORLinkedList();

        // Print the elements of the list
        void print_list(); 
}

XORLinkedList::XORLinkedList(){
    head = tail = nullptr;
}

Node* XORLinkedList::XOR(Node* prev, Node* next){
    /* We use the uintptr_t data type because Bitwise operators require the two operands to be integers.
       => uintptr_t to convert the address type to integer*/
    uintptr_t both = (uintptr_t)prev ^ (uintptr_t)next;
    return (Node*)both; 
}
void XORLinkedList::print_list(){
    // rule: (A ^ B) ^A = B
    Node * current = head;
    Node * previous = nullptr;
    while(current != nullptr){
        cout << current->data << endl;
        Node * next = XOR(current->both,previous);
        previous = current;
        current = next;
    }
}


int main(){
    return 0;
}
