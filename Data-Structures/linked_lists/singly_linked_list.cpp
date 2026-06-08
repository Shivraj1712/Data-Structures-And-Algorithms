#include<iostream>
using namespace std;

class Node {
public:
    int val = -1 ;
    Node * next;
    Node (){
        this->next = nullptr;
    };
    Node(int val){
        this->val = val;
        this->next = nullptr;
    }
};

class SinglyLinkedList{
private:
    Node * head, * tail;
    int size = -1;
public:
    SinglyLinkedList(){
        this->size = 0 ;
        this->head = nullptr;
    }
    void insertAtFront(int val){
        if(this->size == 0){
            this->head = new Node(val);
            this->tail = this->head;
        }else{
            Node * temp = new Node(val);
            temp->next = this->head;
            this->head = temp;
        }
        this->size = this->size + 1;
    }
    void insertAtEnd(int val){
        if(this->size == 0){
            Node * temp = new Node(val);
            this->head = temp;
            this->tail = temp;
        }else{
            Node * temp = new Node(val);
            this->tail->next = temp;
            this->tail = temp;
        }
        this->size = this->size + 1;
    }
    void deleteTarget(int val){
        if(this->size == 0) return ;
        if(this->head->val == val){
            Node * temp = this->head;
            this->head = this->head->next;
            delete temp;
            if(this->head == nullptr){
                this->tail = nullptr;
            }
        }else if(this->tail->val == val){
            Node * temp = head;
            while(temp->next != this-> tail) temp = temp->next;
            delete this->tail;
            this->tail = temp;
            this->tail->next = nullptr;
        }else{
            Node * temp = head;
            while(temp->next != this->tail){
                if(temp->next->val == val){
                    Node * del = temp->next;
                    temp->next = temp->next->next ;
                    delete del;
                    break;
                }
                temp = temp->next;
            }
        }
        this->size = this->size - 1;
    }
};