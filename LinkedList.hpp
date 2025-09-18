#ifndef LINKED_LIST_HPP
#define LINKED_LIST_HPP


#include <iostream>
using namespace std;

template <typename T>
class LinkedList{
    private:
        int length;
        struct Node {
            T value;
            Node* next;

            Node(T v = T(), Node* n = nullptr)
            : value(v), next(n) { }
        };

        // a pointer to the front of the list
        Node* head;

    public:
        // default constructor
        LinkedList();

        // destructor
        ~LinkedList();

        LinkedList(const LinkedList<T>& other);

        LinkedList<T>& operator=(const LinkedList<T>& other);

        // add the argument to the end of the list
        void append(const T&);

        // remove all elements in the list, resetting to the initial state
        void clear();

        // return the element at the given position (argument)
        T getElement(int) const;

        // return the current length of the list
        int getLength() const;

        // insert the given element (argument 2) at
        // the given position (argument 1)
        void insert(int, const T&);

        // determine if the list currently empty
        bool isEmpty() const;

        // remove the element at the given position (argument)
        void remove(int);

        // replace the element at the given position (argument 1) with
        // the value given (argument 2)
        void replace(int, const T&);

        // overloaded stream insertion operator to make printing easier
        template <typename U>
        friend ostream& operator<<(ostream&, const LinkedList<U>&);
};

#include "LinkedList.tpp"
#endif
