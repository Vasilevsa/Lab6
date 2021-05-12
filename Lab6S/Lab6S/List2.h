#pragma once

#include <iostream>

template<typename T>
class List2 // ����� ���������� ����������� ������
{
private:

	class Node // ����� ���������
	{
	public:
		Node(T data = T(), Node* pNext = nullptr, Node* pBack = nullptr); // ����������� ���������

		Node* pNext, * pBack;
		T data;
	};

	Node* head; // ������ ������ ��������� 
	Node* tail; // ������ ����� ��������� 
	int size; // ���-�� ��������

public:

	List2(); // ����������

	List2(const List2& other);

	List2(List2&& other);

	~List2(); // ���������� 

	void push_front(const T& data); // �������� ������� � ������

	void push_back(const T& data); // �������� � ������� � �����

	T pop_front(); // ������� ������� �� ������

	T removeAT(const int index); // ������� ��������� ������� 

	T pop_back(); // ������� ������� �� �����

	void clear(); // ������� ��� ��������

	int getsize() const; // ���-�� �������� 

	T& sel_el(const int index) const; 

	List2& operator=(const List2& other);

	List2& operator=(List2&& other);

};

template<typename T>
List2<T>::Node::Node(T data, Node* pNext, Node* pBack) : data(data), pNext(pNext), pBack(pBack)
{ }

template<typename T>
List2<T>::List2() : size(0), head(nullptr), tail(nullptr) // ����������� 
{ }

template<typename T>
List2<T>::List2(const List2& other) : size(0), head(nullptr), tail(nullptr)
{
	for (int i = 0; i < other.size; i++)
	{
		this->push_back(other.sel_el(i));
	}
}

template<typename T>
List2<T>::List2(List2&& other) : size(other.size), head(other.head), tail(other.tail)
{
	other.size = NULL;
	other.head = nullptr;
	other.tail = nullptr;
}

template<typename T>
List2<T>::~List2() // ����������
{
	clear(); // �������� ���� ��������
}

template<typename T> // �������� ������� � ������
void List2<T>::push_front(const T& data) // �������� ������� � ������
{
	if (size == 0)
	{
		Node* p = new Node(data);
		head = p;
		tail = p;
	}
	else
	{
		Node* current = this->head;
		head = new Node(data, head, nullptr);
		current->pBack = head;
	}
	size++;
}

template<typename T> // �������� � ������� � �����
void List2<T>::push_back(const T& data) // �������� � ������� � �����
{
	if (size > 1) // ���� ���� ����� 1 ���������
	{
		Node* temp = tail;

		tail = new Node(data, head, tail);

		temp->pNext = tail;

		head->pBack = tail;
	}
	else if (size == 1) // ���� ���� 1 ��������
	{
		tail = new Node(data, head, tail);

		head->pNext = tail;
		head->pBack = tail;
	}
	else // ���� �������� ���
	{
		head = tail = new Node(data);

		head->pNext = tail;
		head->pBack = tail;

		tail->pNext = head;
		tail->pBack = head;
	}
	size++;
}

template<typename T> // ������� ������� �� ������
T List2<T>::pop_front() // ������� ������� �� ������
{
	Node* current = head;

	T data = head->data;

	head = current->pNext;

	delete current;

	if (size > 1)
		head->pBack = nullptr; // �������� ��������� �� ����. ��������� � ������
	else
		tail = head;  // �������� �����, ����� ��� �� ���� ������

	size--;

	return data;
}

template<typename T> // ������� ��������� ������� 
T List2<T>::removeAT(const int index) // ������� ��������� ������� 
{
	if (index > this->size - 1) // ���� ��������� ������ ��������� ��� ������ ������
	{
		std::cout << "��������� ������ ��������� ��� ������!" << std::endl;
		return T();
	}

	int indexmax = size - 1, indexmin = 0, resmax = size - 1, resmin = 0; // ������� ��������� ������� ������� �������
	resmax -= index;
	resmin += index;

	if (index == indexmin || index == indexmax)
	{
		if (index == indexmin)
			return pop_front();
		else
			return pop_back();
	}
	else if (resmin < resmax || resmin == resmax)
	{
		int counter = 0; // ����� ���������, � ������� ���������
		Node* current = this->head;
		T data = NULL;
		while (current != nullptr)
		{
			if (counter == index)
			{
				(current->pBack)->pNext = current->pNext;
				(current->pNext)->pBack = current->pBack;

				data = current->data;
				delete current;
				break;
			}
			current = current->pNext;
			counter++;
		}
		size--;
		return data;
	}
	else if (resmin > resmax)
	{
		int counter = size - 1; // ����� ���������, � ������� ���������
		Node* current = this->tail;
		T data = NULL;
		while (current != nullptr)
		{
			if (counter == index)
			{
				(current->pBack)->pNext = current->pNext;
				(current->pNext)->pBack = current->pBack;
				
				data = current->data;
				delete current;
				break;
			}
			current = current->pBack;
			counter--;
		}
		size--;
		return data;
	}
}

template<typename T> // ������� ������� �� �����
T List2<T>::pop_back() // ������� ������� �� �����
{
	Node* current = tail;

	T data = tail->data;

	tail = current->pBack;

	delete current;

	if (size > 1)
		tail->pNext = nullptr; // �������� ����� ������, �.�. ��������� �� ����. ���������
	else
		head = tail; // �������� ������, ����� ��� �� ���� ������

	size--;

	return data;
}

template<typename T> // ������� ��� ��������
void List2<T>::clear() // ������� ��� ��������
{
	while (size) // ���� ���� �� ����� 0
	{
		pop_front();
	}
}

template<typename T>
inline int List2<T>::getsize() const
{
	return size;
}

template<typename T>
T& List2<T>::sel_el(const int index) const 
{
	if (index > this->size - 1) // ���� ��������� ������ ��������� ��� ������ ������
	{
		std::cout << "��������� ������ ��������� ��� ������! ��������� ���������� ��������" << std::endl;
		abort();
	}

	int indexmax = size - 1, indexmin = 0; // ������� ��������� ������� ������� �������
	indexmax -= index; // ���. ���-�� �����, ������ ��� ������� �� ��������� �� ������
	indexmin += index; // ���. ���-�� �����, ������ ��� ������� �� ��������� �� ������

	if (indexmin < indexmax || indexmin == indexmax)
	{
		int counter = 0; // ����� ���������, � ������� ���������
		Node* current = this->head;
		while (current != nullptr)
		{
			if (counter == index)
			{
				return current->data;
			}
			current = current->pNext;
			counter++;
		}
	}
	else if (indexmin > indexmax)
	{
		int counter = size - 1; // ����� ���������, � ������� ���������
		Node* current = this->tail;
		while (current != nullptr)
		{
			if (counter == index)
			{
				return current->data;
			}
			current = current->pBack;
			counter--;
		}
	}
}

template<typename T>
List2<T>& List2<T>::operator=(const List2& other)
{
	size = 0;
	head = nullptr;
	tail = nullptr;

	if (this == &other)
	{
		return *this;
	}

	clear();

	for (int i = 0; i < other.size; i++)
	{
		this->push_back(other.sel_el(i));
	}
}

template<typename T>
List2<T>& List2<T>::operator=(List2&& other)
{
	if (this == &other)
	{
		return *this;
	}

	clear();

	size = other.size;
	this->head = other.head;
	this->tail = other.tail;

	other.size = NULL;
	other.head = nullptr;
	other.tail = nullptr;
}