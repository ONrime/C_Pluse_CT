#pragma once

#include <iostream>

template<typename T>
class MyStackNode
{
	T Data;
	MyStackNode<T>* Next = nullptr;

	MyStackNode(T _Data, MyStackNode<T>* _Next) : Data(_Data), Next(_Next) {}
	MyStackNode(MyStackNode& In) { this->Data = In->Data; this->Next = In->Next; }
	~MyStackNode() {}
};

template<typename T>
class MyStack
{
	MyStackNode<T>* Head = nullptr;
	MyStackNode<T>* Tail = nullptr;
	int Length = 0;

public:
	MyStack();
	~MyStack();
	MyStack(MyStack& In);

	bool Empty();
	void Push(T Data);
	T Pop();

};
