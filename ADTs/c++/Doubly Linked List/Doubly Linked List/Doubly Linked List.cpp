// Doubly Linked List.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <iostream>
using namespace std;

struct Node
{
	Node() {}
	Node(int data) : data(data) {}
	Node(int data, Node* prev, Node* next) : data(data), prev(prev), next(next) {}
	~Node() { cout << "Node with data: " << data << " being deleted" << endl; }

	int data = 0;
	Node* prev = nullptr;
	Node* next = nullptr;
};

struct BST
{
	BST() {}
	~BST()
	{
		while (head != nullptr)
		{
			Node* next = head->next;
			delete head;
			head = next;
		}
	}

	void addFirst(int data)
	{
		Node* newNode = new Node(data);
		size++;
		// alternative would be to check sizes (size == 0)
		if (head == nullptr && tail == nullptr) { head = newNode; }
		// (size == 1)
		else if (tail == nullptr)
		{
			head->prev = newNode;
			newNode->next = head;
			tail = head;
			head = newNode;
		}
		// (size > 1)
		else
		{
			head->prev = newNode;
			newNode->next = head;
			head = newNode;
		}
	}

	void addLast(int data)
	{
		Node* newNode = new Node(data);
		size++;
		//again, size can also be used for logic
		if (head == nullptr && tail == nullptr) 
		{ 
			cout << "empty list! Node: " << newNode->data << " will be added to front of list" << endl;
			head = newNode; 
		}
		else if (tail == nullptr)
		{
			head->next = newNode;
			newNode->prev = head;
			tail = newNode;
		}
		else
		{
			tail->next = newNode;
			newNode->prev = tail;
			tail = newNode;
		}
	}

	Node* head = nullptr;
	Node* tail = nullptr;
	int size = 0;
};

ostream& operator<<(std::ostream& os, const BST* rhs)
{
	Node* currNode = rhs->head;
	while (currNode != nullptr)
	{
		cout << currNode->data << ' ';
		currNode = currNode->next;
	}
	return os;
}


int main()
{
	cout << "======================Testing addFirst======================" << endl;
	BST* bst = new BST();
	bst->addFirst(3);
	cout << bst << endl;
	bst->addFirst(2);
	cout << bst << endl;
	bst->addFirst(1);
	cout << bst << endl;

	cout << "======================Testing addLast======================" << endl;
	BST* bstL = new BST();
	bstL->addLast(1);
	cout << bstL << endl;
	bstL->addLast(2);
	cout << bstL << endl;
	bstL->addLast(3);
	cout << bstL << endl;
	bstL->addLast(4);
	cout << bstL << endl;

	delete bst;
	delete bstL;
    return 0;
}

