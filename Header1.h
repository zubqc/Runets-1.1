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
		for (int i{}; i < _size; i++) addElementFront(generator());
	};
	masiv_class(masiv_class &_other) {
		head = nullptr;
		size = 0;
		for (int i = 0; i < _other.size; i++)
			addElementEnd(_other.getElement(i));
	};

	~masiv_class() {
		node* current = head;
		node* prev = nullptr;
		while (current) {
			prev = current;
			current = current->next;
			delete prev;
		}
	};

	node* gethead() {
		return this->head;
	}
	int getsize() {
		return this->size;
	}

	void author() {
		cout << endl << "Рунец Н. Р." << endl << "Вариант 19";
	}

	int generator() {
		//srand(time(nullptr));
		//int num = rand() % 201 - 100;
		int rangeMin = -101;
		int rangeMax = 101;
		int num = ((double)rand() / RAND_MAX) * (rangeMax - rangeMin) + rangeMin;
		return num;
	}

	void addElementFront(int _data)
	{
		if (size == 0) {
			head = new node;
			head->data = _data;
			head->next = nullptr;
		}
		else {
			node* tmpPoint = head;
			head = new node;
			head->next = tmpPoint;
			head->data = _data;
		}
		size++;
	}

	void addElementEnd(int _data) {
		if (size == 0) {
			head = new node;
			head->data = _data;
			head->next = nullptr;
		}
		else {
			node* current = head;
			//node* prev = nullptr;
			while (current->next) {
				//prev = current;
				current = current->next;
			}
			node* tmpNode = new node; 
			tmpNode->next = nullptr;
			tmpNode->data = _data;
			current->next = tmpNode;
		}
		size++;
	}

	void insertElement(int pos, int data) {
		if (size > 0) {
			if ((pos >= 0) && (pos <= size)) {
				if (pos == 0) {
					addElementFront(data);
				}
				if ((pos > 0) and (pos < size)) {
					int index = 0;
					node* current = head;
					node* prev = nullptr;
					while (current) {
						if (index == pos) {
							node* tmpPoint = new node;
							tmpPoint->next = current;
							tmpPoint->data = data;
							prev->next = tmpPoint;
							break;
						}
						prev = current;
						current = current->next;
						index++;
					}
					size++;
				}
				if (pos == size) {
					addElementEnd(data);
				}
			}
		}
	}

	void setElement(int pos, int data) {
		if (size > 0)
			if ((pos >= 0) and (pos < size))
			{
				node* current = head;
				int index = 0;
				while (current) {
					if (index == pos)
						current->data = data;
					current = current->next;
					index++;
				}
			}
	}

	int getElement(int pos)
	{
		int element = -1;
		if (size > 0)
			if ((pos >= 0) and (pos < size))
			{
				node* current = head;
				int index = 0;
				while (current) {
					if (index == pos)
					{
						element = current->data;
						break;
					}
					current = current->next;
					index++;
				}
			}
		return element;
	}

	void delElement(int pos) {
		if (size > 0)
			if ((pos >= 0) and (pos < size))
			{
				int index = 0;
				node* current = head;
				node* prev = nullptr;
				if (size > 1)
					while (current) {
						if (index == pos) {
							node* tmpPoint = current;
							prev->next = current->next;
							delete tmpPoint;
							break;
						}
						prev = current;
						current = current->next;
						index++;
					}
				else {
					delete head;
					head = nullptr;
				}
				size--;
			}
	}

	void display() {
		node* current = head;
		cout << endl << "__Display__";
		while (current) {
			cout << endl << current->data << endl;
			current = current->next;
		}
	}

	bool operator=(const masiv_class& _other)
	{
		node* current = this->head;
		node* prev = nullptr;
		while (current) {
			prev = current;
			current = current->next;
			delete prev;
		}
		this->size = 0;
		current = _other.head;
		while (current) {
			this->addElementEnd(current->data);
			current = current->next;
		}
		return true;
	}

	int operator|(const masiv_class _other) {
		node* current = this->head;
		int sum = 0;
		for (int i{}; i < this->size;i++) {
			if (i % 2 == 1)
			{
				sum = sum | current->data;
			}
			current = current->next;
		}
		current = _other.head;
		for (int i{}; i < _other.size; i++) {
			if (i % 2 == 1)
			{
				sum = sum | current->data;
			}
			current = current->next;
		}
		return sum;
	}

	friend int operator*(const masiv_class ths) {
		node* current = ths.head;
		int sum = 1;
		for (int i{}; i < ths.size; i++) {
			if (current->data > 0) {
				sum = sum * current->data;
			}
			current = current->next;
		}
		return sum;
	}

	//int operator-(const masiv_class other) {
	//	node* current = this->head;
	//	int max1 = -100, max2 = -100;
	//	for (int i{}; i < this->size; i++) {
	//		if (current->data > max) {
	//			max1 = current->data;
	//		}
	//		current = current->next;
	//	}
	//	current = other.head;
	//	for (int i{}; i < other.size; i++) {
	//		if (current->data > max) {
	//			max2 = current->data;
	//		}
	//		current = current->next;
	//	}
	//	return(abs(max1-max2))
	//}
};
