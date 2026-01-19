#ifndef BOTKIFY_LINKED_LIST_H
#define BOTKIFY_LINKED_LIST_H

#include "main.h"

template <class T>
class BotkifyLinkedList
{
private:
    class Node
    {
    public:
        T data;
        Node* next;
        Node* extra;

        Node(): next(nullptr), extra(nullptr){}
        Node(const T& data, Node* next = nullptr, Node* extra = nullptr): data(data), next(next), extra(extra){}
    };
    Node* head;
    Node* tail;
    int count;

public:
    // Constructor
    BotkifyLinkedList(): head(nullptr), tail(nullptr), count(0){}
    // Destructor
    ~BotkifyLinkedList(){
        this->clear();
    }

    // Enqueue
    void add(T e){
        Node *node = new Node(e);
        if (this->head == nullptr){
            this->head = node;
        } else {
            this->tail->next = node;
        }
        this->tail = node;
        this->count++;
    }
    void add(int index, T e){
        if (index < 0 || index > this->count) {
            throw out_of_range("Index is invalid!");
        }

        Node* node = new Node(e);  

        if (index == 0) {
            node->next = this->head;
            this->head = node;
            if (this->count == 0){
                this->tail = node;
            }
        } else if (index == count){
            this->tail->next = node;
            this->tail = node;
        } else {
            Node* p = this->head;
            for (int i = 0; i < index - 1; ++i) {
                p = p->next;
            }
            node->next = p->next;
            p->next = node;
        }
        this->count++;
    }

    // Dequeue
    T removeAt(int index){
        if (index < 0 || index >= this->count) {
            throw out_of_range("Index is invalid!");
        }

        Node* delnode = nullptr;
        T removedValue;

        if (index == 0) {
            delnode = this->head;
            removedValue = delnode->data;
            this->head = delnode->next;
            if (count == 1) {
                tail = nullptr;
            }
        } else {
            Node* prev = this->head;
            for (int i = 0; i < index - 1; ++i) {
                prev = prev->next;
            }
            delnode = prev->next;            
            removedValue = delnode->data;
            if (delnode->next == nullptr){
                tail = prev;
                prev->next = nullptr;
            } else{
                prev->next = delnode->next;
            }
        }

        delete delnode;
        this->count--;
        return removedValue;
    }
    bool removeItem(const T& item) {
        if (count == 0) return false;

        if (this->head->data == item) {
            Node* del = this->head;
            this->head = this->head->next;
            if (del == this->tail) this->tail = head;  
            delete del;
            this->count--;
            if (count == 0) this->tail = nullptr;
            return true;
        }

        Node* prev = this->head;
        while (prev->next != nullptr && !(prev->next->data == item)) {
            prev = prev->next;
        }
        if (prev->next == nullptr) return false; 

        Node* del = prev->next;
        prev->next = del->next;
        if (del == this->tail) this->tail = prev;           
        delete del;
        this->count--;
        return true;
    }

    bool empty() const{
        return (this->count == 0);
    }

    int size() const{
        return this->count;
    }

    void clear(){
        Node *node;
        while (this->head != nullptr) {
            node = this->head;
            this->head = this->head->next;
            delete node;
        }
        this->head =nullptr;
        this->tail =nullptr;
        this->count = 0;

    }

    T& get(int index) const{
        if (index < 0 || index >= this->count) {
            throw out_of_range("Index is invalid!");
        }

        Node *node = this->head;
        for (int i = 0; i < index; ++i) {
            node = node->next;
        }
        return node->data;
    }

    string toString() const{
        Node* node = this->head;
        stringstream ss;
        while (node != nullptr) {
            ss << node->data;
            if (node->next != nullptr) ss << ",";
            node = node->next;
        }
        return ss.str();
    }
};

#endif // BOTKIFY_LINKED_LIST_H
