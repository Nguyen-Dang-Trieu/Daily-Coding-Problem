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
        void get(int index);
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

void XORLinkedList::get(int index){
    if(index < 0){
        cout << "Index out of bound" << endl;
        return;
    }
    
    Node* current = head;
    Node* previous = nullptr;
    
    for(int i = 0; i <= index; i++){
        Node* next = XOR(current->both, previous);
        if(i == index){
            cout << current->data << endl;
        }
        previous = current;
        current = next;
    }
}

void XORLinkedList::print_list(){
    Node* current = head;
    Node* previous = nullptr;
    while(current != nullptr){
        cout << current->data << " ";
        Node* next = XOR(current->both, previous);
        previous = current;
        current = next;
    }
}
int main(){
    XORLinkedList list;
    list.add_at_tail(10);
    list.add_at_tail(20);
    list.add_at_tail(30);
    list.add_at_tail(40);
    list.print_list();
    
    printf("\n");
    list.get(1);
    return 0;
}
