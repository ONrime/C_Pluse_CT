#include "MyStack.h"
#include <iostream>


template<typename T>
MyStack<T>::MyStack()
{
	Head = nullptr;
	Tail = nullptr;
	Length = 0;
}

template<typename T>
MyStack<T>::~MyStack()
{
}

template<typename T>
MyStack<T>::MyStack(MyStack& In)
{
	this->Tail = In->Tail;
	this->Length = In->Length;
}

template<typename T>
bool MyStack<T>::Empty()
{
	return Head == nullptr;
}

template<typename T>
void MyStack<T>::Push(T Data)
{
	MyStackNode<T> *In= new MyStackNode<T>(Data, nullptr);
	if (Tail != nullptr)
	{
		In->Next = Tail;
		Tail = In;
	}
	else {
		Tail = In;
		Head = In;
	}
	Length++;
}

template<typename T>
T MyStack<T>::Pop()
{
	T Out = Tail->Data;
	Tail = Tail->Next;
	return Out;
}
