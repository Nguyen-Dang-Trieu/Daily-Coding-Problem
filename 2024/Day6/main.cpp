#include <iostream>
#include <stdint.h>

using namespace std;

struct Node{
    int data;
    Node* both;
};

class XORLinkedList {
    private:
        Node* head;
        Node* tail;
        Node* XOR(Node* a, Node* b);
    public:
        XORLinkedList();
        
        void add_at_tail(int insert_data);
        void print_list();
        
};

XORLinkedList::XORLinkedList(){
    head = tail = nullptr;
}

Node* XORLinkedList::XOR(Node* prev, Node* next){
    uintptr_t both = (uintptr_t)prev ^ (uintptr_t)next;
    return (Node*)both;
}

void XORLinkedList::add_at_tail(int data){
    Node* new_node = new Node();
    new_node->data = data;
    new_node->both = XOR(tail, nullptr);
    
    if(tail == nullptr){
        head = new_node;
    }
    else {
        tail->both = XOR(XOR(tail->both, nullptr), new_node);
    }
    tail = new_node;
}

void XORLinkedList::print_list(){
    Node* current = head;
    Node* previous = nullptr;
    while(current != nullptr){
        cout << current->data << endl;
        Node* next = XOR(current->both, previous);
        previous = current;
        current = next;
    }
}
int main(){
    XORLinkedList list;
    list.add_at_tail(10);
    list.add_at_tail(20);
    list.print_list();
    return 0;
}
