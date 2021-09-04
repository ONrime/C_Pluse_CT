#pragma once

#include <iostream>
template <typename Type>
class Node {
public:
	Type data;
	Node<Type>* next = nullptr;

	template <typename Type>
	friend class Mlinked_list;

	Node(Type d, Node<Type>* n) : data(d), next(n){}
	~Node() {};
};

template <typename Type>
class Single_linkedlist {
private:
	Node<Type>* head;
	Node<Type>* tail;
	int length = 0;

public:
	Single_linkedlist();
	~Single_linkedlist();
	
	void push_back(Type data);
	Type pop_back();
	Type back();

	void add(int pos, Type data);
	void add_first(Type data);
	void add_last(Type data);
	void del(int pos);
	void clear();
	void replace(int pos, Type data);
	bool is_in_list(Type data);
	int get_length();
	bool is_empty();
	void display();
	// 복사 생성자 + 대입 연산자 넣기
};
/*
template<typename Type>
inline Mylinked_list<Type>::Mylinked_list()
{
	head = nullptr;
	tail = nullptr;
}

template<typename Type>
inline Mylinked_list<Type>::~Mylinked_list()
{
	Node<Type>* current_node = head;
	while (current_node) {
		Node<Type>* del_next = current_node->next;
		delete current_node;
		current_node = del_next;
	}
}

template<typename Type>
inline int Mylinked_list<Type>::get_lenght()
{
	Node<Type>* current_node = head;
	int count = 0;
	while (current_node) {
		current_node = current_node->next;
		count++;
	}
	return count;
}

template<typename Type>
inline bool Mylinked_list<Type>::is_empty()
{
	if (!head) {
		return true;
	}
	return false;
}

template<typename Type>
inline bool Mylinked_list<Type>::insert(Type data, int postion)
{
	if (!head) { return false; }
	Node<Type>* current_node = head;
	int cp = 1;
	while (cp != postion) {
		current_node= current_node->next;
		cp++;
	}
	if (!current_node) { return false; }
	
	Node<Type>* insert_node= new Node<Type>(data, current_node->next);
	current_node->next = insert_node;
	if (current_node == head) {
		head = insert_node;
	}
	if (current_node == tail) {
		tail = insert_node;
	}
	return true;
}

template<typename Type>
inline void Mylinked_list<Type>::push_front(Type data)
{
	Node<Type>* insert_node = new Node<Type>(data, head);
	head = insert_node;
	if (!tail) {
		tail = insert_node;
	}
}

template<typename Type>
inline void Mylinked_list<Type>::push_back(Type data)
{
	Node<Type>* insert_node = new Node<Type>(data, nullptr);
	tail->next = insert_node;
	tail = insert_node;
	if (!tail) {
		tail = insert_node;
	}

	return false;
}

template<typename Type>
inline bool Mylinked_list<Type>::del(Type data, int postion)
{
	return false;
}

template<typename Type>
inline Type Mylinked_list<Type>::pop_front()
{
	return Type();
}

template<typename Type>
inline bool Mylinked_list<Type>::replace(Type data, int postion)
{
	return false;
}

template<typename Type>
inline void Mylinked_list<Type>::empty_node()
{
	Node<Type>* current_node = head->next;
	while (current_node) {
		Node<Type>* del_next = head->next;
		delete current_node;
		current_node = del_next;
	}
	head->next = nullptr;
}

template<typename Type>
inline Node<Type> Mylinked_list<Type>::find(Type data)
{
	return Node<Type>();
}
*/


