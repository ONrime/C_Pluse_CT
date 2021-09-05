//#include "pch.h"
#include "linked_list.h"
#include <iostream>

using namespace std;

template<typename Type>
Single_linkedlist<Type>::Single_linkedlist()
{
    head = nullptr;
    tail = nullptr;
}

template<typename Type>
Single_linkedlist<Type>::~Single_linkedlist()
{
}

template<typename Type>
int Single_linkedlist<Type>::get_length()
{
    return length;
}

template<typename Type>
bool Single_linkedlist<Type>::is_empty()
{
    if (this->head == nullptr) 
    {
        return true;
    }
    return false;
}

template<typename Type>
void Single_linkedlist<Type>::display()
{
    Node<Type>* n = head;
    cout << "List: ";
    for(int i=0; i< get_length();i++)
    {
        cout << n->data << ", ";
        n = n->next;
    }
    cout << endl;
}

template<typename Type>
void Single_linkedlist<Type>::push_back(Type data)
{
    Node<Type> *n = new Node<Type>(data, nullptr);
    if (is_empty()) // 만약 비여있다면 (== 머리가 nullptr이면)
    {
        head = n;
        tail = n;
    }
    else // 비여 있지 않다면
    {
        tail->next = n;
        tail = n;
    }
    length++;
}

template<typename Type>
Type Single_linkedlist<Type>::pop_back()
{

    return tail->data;
}

template<typename Type>
Type Single_linkedlist<Type>::back()
{
    return tail->data;
}

template<typename Type>
void Single_linkedlist<Type>::add(int pos, Type data)
{
    if (pos < 0 || pos > get_length() - 1) return;
    if (pos == 0) 
    {
        add_first(data);
        return;
    }
    if (pos == get_length() - 1)
    {
        add_last(data);
        return;
    }

    Node<Type>* n = new Node<Type>(data, nullptr);
    Node<Type>* current = head;

    for (int i = 1; i < get_length(); i++) 
    {
        if (pos == i)
        {
            n->next = current->next;
            current->next = n;
            break;
        }
        current = current->next;
    }
    length++;
}

template<typename Type>
void Single_linkedlist<Type>::add_first(Type data)
{
    Node<Type>* n = new Node<Type>(data, nullptr);
    if (is_empty()) // 만약 비여있다면 (== 머리가 nullptr이면)
    {
        head = n;
        tail = n;
    }
    else // 비여 있지 않다면
    {
        Node<Type>* temp = head;
        head = n;
        head->next = temp;
    }
    length++;
}

template<typename Type>
void Single_linkedlist<Type>::add_last(Type data)
{
    Node<Type>* n = new Node<Type>(data, nullptr);
    if (is_empty()) // 만약 비여있다면 (== 머리가 nullptr이면)
    {
        head = n;
        tail = n;
    }
    else // 비여 있지 않다면
    {
        tail->next = n;
        tail = n;
    }
    length++;
}

template<typename Type>
void Single_linkedlist<Type>::del(int pos)
{
    if (pos < 0 || pos > get_length() - 1) return;
    //if (pos == 0) add_first(data); front_pop
    //if (pos == get_length() - 1) add_last(data); back_pop
    Node<Type>* current = head;
    Node<Type>* temp = head;

    length--;
    for (int i = 0; i < get_length(); i++)
    {
        if (pos - 1 == i)
        {
            break;
        }
        else if (pos - 1 == -1) // 머리를 지울 때
        {
            head = current->next;
            free(current);
            return;
        }
        current = current->next;
    }
    temp = current->next->next;
    free(current->next);
    current->next = temp;
}

template<typename Type>
void Single_linkedlist<Type>::clear()
{
    Node<Type>* current = head;
    Node<Type>* temp = head;
    int before_length = length;
    for (int i = 0; i < before_length; i++)
    {
        current = temp;
        temp = temp->next;
        free(current);
        length--;
    }
}

template<typename Type>
void Single_linkedlist<Type>::replace(int pos, Type data)
{
    if (pos < 0 || pos > length - 1) return;
    Node<Type>* current = head;
    for (int i = 0; i < length; i++)
    {
        if (pos == i) 
        {
            current->data = data;
        }
        current = current->next;
    }
}

template<typename Type>
bool Single_linkedlist<Type>::is_in_list(Type data)
{
    return false;
}

/*int main()
{
    Single_linkedlist<int> list;
    int a = 10;
    float b = 2.0f;
    //list.push_back(a);
    list.add_first(a);
    list.add_first(30);
    list.add_last(20);
    list.add_last(40);
    list.add(2, 50);
    //list.del(list.get_length()-1);
    list.replace(3, 90);
    //list.clear();
    list.display();
    cout << "num: "<< list.get_length() << endl;
    //cout << "num: "<< list.pop_back() << endl;
    /*Mlinked_list<int> list;
    list.insert(3);
    if (!list.insert(3)) {
        std::cout << "false" << "\n";
    }
}*/