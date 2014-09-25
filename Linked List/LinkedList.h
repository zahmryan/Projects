/**
 * A doubly-linked list.
 * Stub written by James Daly, 5 Sept 2014
 * Completed by [YOUR NAME]
 */

#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include "Node.h"
#include <iostream>
#include <functional>

template<class T> class LinkedList
{
public:
	LinkedList();
	LinkedList(const LinkedList<T>& other);
	~LinkedList();

	void operator=(const LinkedList<T>& other);
	
	// These methods are provided for you
	void Clear();
	void Display() const;
	bool IsEmpty() const;
	int Size() const;
	
	// Methods to add data to the front or the back of the list
	// These should run in O(1) time
	void PushFront(const T &t);
	void PushBack(const T &t);
	void PopFront();
	void PopBack();
	
	// These methods can run in O(n) time
	void Filter(std::function<bool (const T)> isIn);
	void ForEach(std::function<void (const T)> func) const;
	
private:
	Node<T>* head;
	Node<T>* tail;
	int size;
	
	// You can put helper methods here
};

/**
 * Default constructor
 * Creates an empty list
 * You are allowed (but not required) to change this method
 */
template <class T> LinkedList<T>::LinkedList():
	head(nullptr),
	tail(nullptr),
	size(0)
{
	// Empty
}

/**
 * Copy Constructor
 * Creates a shallow copy of the other list
 */
template <class T> LinkedList<T>::LinkedList(const LinkedList<T> & other) : LinkedList() {
	auto insertItem = [=](T x){ this->PushBack(x); };
	other.ForEach(insertItem);
}

template <class T> LinkedList<T>::~LinkedList() {
	Clear();
}

/**
 * Assignment operator
 * Creates a shallow copy of the other list
 */
template <class T> void LinkedList<T>::operator=(const LinkedList<T> & other) {
	if (this != &other) {
		Clear();
		auto insertItem = [=](T x){ this->PushBack(x); };
		other.ForEach(insertItem);
	}
}

/**
 * Removes all elements from this list
 */
template <class T> void LinkedList<T>::Clear() {
	while(!IsEmpty()) {
		PopFront();
	}
}

/**
 * Prints the contents of this list to the console
 */
template <class T> void LinkedList<T>::Display() const {
	using namespace std;
	auto printItem = [](T x) { cout << x << " "; };
	ForEach(printItem);
	cout << endl;
}

/**
 * Checks if the list contains no items
 */
template <class T> bool LinkedList<T>::IsEmpty() const{
	return size == 0;
}

/**
 * Counts the number of items in the list
 */
template <class T> int LinkedList<T>::Size() const {
	return size;
}

/**
 * Adds the item to the front of the list
 */
template <class T> void LinkedList<T>::PushFront(const T &t) {
	Node<T>* load = new Node<T>(t);
	if (IsEmpty()){
		this->head = load;
		this->tail = this->head;
	}
	else{
		load->prev = this->head;
		this->head->next = load;
		this->head = load;
	}
	this->size += 1;
}

/**
 * Adds the item to the back of the list
 */
template <class T> void LinkedList<T>::PushBack(const T &t) {
	Node<T>* load = new Node<T>(t);
	if (IsEmpty()){
		this->tail = load;
		this->head = this->tail;
	}
	else{
		load->next = this->tail;
		this->tail->prev = load;
		this->tail = load;
	}
	this->size += 1;
}

/**
 * Removes the item at the front of the list
 */
template <class T> void LinkedList<T>::PopFront() {
	if (this->Size() > 1){
		this->head = this->head->prev;
		this->head->next = nullptr;
	}
	else{
		this->head = nullptr;
		this->tail = nullptr;
	}
	this->size -= 1;
}

/**
 * Removes the item at the back of the list
 */
template <class T> void LinkedList<T>::PopBack() {
	if (this->Size() > 1){
		this->tail = this->tail->prev;
		this->tail->prev = nullptr;
	}
	else{
		this->head = nullptr;
		this->tail = nullptr;
	}
	this->size -= 1;
}

/**
 * Edits this list to keep only the items where isIn(x) returns true
 * Other items are deleted
 */
template <class T> void LinkedList<T>::Filter(std::function<bool (const T)> isIn) {
	using namespace std;
	int count = 0;
	int size = this->Size();
	while (count < size){
		Node<T>* node = this->head;
		if (isIn(node->payload)){
			Node<T>* temp = this->head;
			this->PopFront();
			this->PushBack(temp->payload);
		}
		else{
			this->PopFront();
		}
		count++;
	}
}

/**
 * Executes func(x) on each x in the list
 */
template <class T> void LinkedList<T>::ForEach(std::function<void (const T)> func) const {
	int count = 0;
	Node<T>* node = this->head;
	while (count < this->Size()){
		func(node->payload);
		node = node->prev;
		count++;
	}
}
#endif