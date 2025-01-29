#ifndef EASYTRIP_LINKEDLIST_H
#define EASYTRIP_LINKEDLIST_H

#include <iostream>
#include "Node.h"


template<class T>
class LinkedList {
private:
    Node<T>* Head;

public:
    // Constructor
    LinkedList() : Head(nullptr) {
    }

    // Basic Operations
    bool isEmpty() const {
        return Head == nullptr;
    }

    void insertAtBeg(T data) {
        Node<T>* newNode = new Node<T>(data);
        
        Head = newNode;
    }

    void insertAtEnd(T data) {
        Node<T>* newNode = new Node<T>(data);
        if (Head==nullptr) {
            Head = newNode;
        } else {
            Node<T>* temp = Head;
            while (temp->getNext() != nullptr) {
                temp = temp->getNext();
            }
            temp->setNext(newNode);
        }
    }


    void insertAtIndex(int index, T data) {
        if (index < 0) {
            std::cerr << "Invalid index" << std::endl;
            return;
        }
        if (index == 0) {
            insertAtBeg(data);
            return;
        }
        Node<T>* temp = Head;
        for (int i = 0; temp != nullptr && i < index - 1; i++) {
            temp = temp->getNext();
        }
        if (temp == nullptr || temp->getNext() == nullptr) {
            std::cerr << "Index out of bounds" << std::endl;
            return;
        }
        Node<T>* newNode = new Node<T>(data);
        newNode->setNext(temp->getNext());
        temp->setNext(newNode);
    }

    void printList() const {
        Node<T>* temp = Head;
        if (Head==nullptr) {
            std::cout << "List is Empty" << std::endl;
        } else {
            while (temp != nullptr) {
                std::cout << temp->getData() << " -> ";
                temp = temp->getNext();
            }
            std::cout << "end" << std::endl;
        }
    }

    // Advanced Operations
     LinkedList<T> merge(const LinkedList<T>& list1, const LinkedList<T>& list2) {
        LinkedList<T> mergedList;
        Node<T>* temp1 = list1.Head;
        Node<T>* temp2 = list2.Head;
        while (temp1 != nullptr) {
            mergedList.insertAtEnd(temp1->getData());
            temp1 = temp1->getNext();
        }
        while (temp2 != nullptr) {
            mergedList.insertAtEnd(temp2->getData());
            temp2 = temp2->getNext();
        }
        return mergedList;
    }

    // Utility Functions

    void remove(T data) {
        if (Head == nullptr) {
            std::cerr << "List is empty" << std::endl;
            return;
        }
        Node<T>* temp = Head;
        Node<T>* prev = nullptr;
        if (temp != nullptr && temp->getData() == data) {
            Head = temp->getNext();
            delete temp;
            return;
        }
        while (temp != nullptr && temp->getData() != data) {
            prev = temp;
            temp = temp->getNext();
        }
        if (temp == nullptr) {
            std::cerr << "Element not found" << std::endl;
            return;
        }
        prev->setNext(temp->getNext());
        delete temp;
    }
    T  getItemAtIndex(int index){
        if (index < 0) {
            std::cerr << "Invalid index" << std::endl;
            return T();
        }
        Node<T>* temp = Head;
        for (int i = 0; temp != nullptr && i < index; i++) {
            temp = temp->getNext();
        }
        if (temp == nullptr) {
            std::cerr << "Index out of bounds" << std::endl;
            return T();
        }
        return temp->getData();
    }
    int getLength(){
        if (Head == nullptr) {
            return 0;
        }
        Node<T>* temp = Head;
        int length = 0;
        while (temp->getNext() != nullptr) {
            length++;
            temp = temp->getNext();
        }
        return length;
    }
};

#endif //EASYTRIP_LINKEDLIST_H
