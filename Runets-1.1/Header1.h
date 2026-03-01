#pragma once
#include <iostream>
#include <stdio.h>
using namespace std;

struct node {
public:
	int data;
	node* next;
};

class masiv_class {
private:
	node* head;
	int size;
public:
	masiv_class() {
		head = nullptr;
		size = 0;
	};

	masiv_class(int _size) {
		head = nullptr;
		size = 0;
		for (int i{}; i < _size; i++) { // добавление эллементов

		}
	};
	masiv_class(masiv_class) {}; // copy

	~masiv_class() {
		node* current = head;
		node* prev = nullptr;
		while (current) {
			prev = current;
			current = current->next;
			delete prev;
		}
	};

	void author() {
		cout << endl << "Рунец Н. Р.";
	}

	int generator() {
		srand(time(nullptr));
		int num = rand() * 200 - 100;
	}

	void addElementFront(int data)
	{
		if (size == 0) {
			head = new node;
			head->data = data;
			head->next = nullptr;
		}
		else {
			node* tmpPoint = head;
			head = new node;
			head->next = tmpPoint;
			head->data = data;
		}
		size++;
	}

	void addElementRear(int _data) {
		if (count == 0) {
			head = new node;
			head->data = _data;
			head->next = nullptr;
		}
		else {
			node* current = head;
			node* prev = nullptr;
			while (current) {
				prev = current;
				current = current->next;
			}
			node* tmpNode = new node; // создаю временный узел
			tmpNode->next = nullptr;
			tmpNode->data = _data;
			prev->next = tmpNode;
		}
		count++;
	}
};