#pragma once
#include <iostream>
#include "QueueBase.h"

template<typename T>
class Queue1 : public QueueBase<T>
{
private:

	T* arr;

	int size, head, tail, count;

public:

	Queue1(const int size); // Инициализация

	Queue1(const Queue1& other); // Копирование

	Queue1(Queue1&& other); // Перемещение

	Queue1& operator=(const Queue1& other); // Присваивание

	Queue1& operator=(Queue1&& other); // Присваивание с перемещением

	~Queue1() override; // Деструктор

	int GetSize() const override;

	void Push(const T& element) override; // Вставка элемента

	T Pop() override; // Удаление элемента

	T Peek() const override; // Просмотр элемента

	template<typename T>
	friend std::ostream& operator <<(std::ostream& os, const Queue1<T>& obj); // Вывод
};

template<typename T>
Queue1<T>::Queue1(const int size) : size(size), arr(new T[size]), head(0), tail(0), count(0) { }

template<typename T>
Queue1<T>::Queue1(const Queue1& other) : size(other.size), arr(new T[other.size]), head(other.head), tail(other.tail), count(other.count)
{
	for (int i = 0; i < size; ++i)
	{
		arr[i] = other.arr[i];
	}
}

template<typename T>
Queue1<T>::Queue1(Queue1&& other) : size(other.size), count(other.count), head(other.head), tail(other.tail), arr(other.arr)
{
	other.arr = nullptr;
	other.size = NULL;
	other.count = NULL;
	other.head = NULL;
	other.tail = NULL;
}

template<typename T>
Queue1<T>& Queue1<T>::operator=(const Queue1& other)
{
	if (this == &other)
	{
		return *this;
	}

	delete[] arr;

	size = other.size;
	arr = new T[other.size];

	for (int i = 0; i < size; ++i)
	{
		arr[i] = other.arr[i];
	}
}

template<typename T>
Queue1<T>& Queue1<T>::operator=(Queue1&& other)
{
	if (this == &other)
	{
		return *this;
	}

	delete[] arr;

	size = other.size;
	count = other.count;
	head = other.head;
	tail = other.tail;
	arr = other.arr;

	other.arr = nullptr;
	other.size = NULL;
	other.count = NULL;
	other.head = NULL;
	other.tail = NULL;
}

template<typename T>
Queue1<T>::~Queue1()
{
	delete[] arr;
	arr = nullptr;
	size = NULL;
	count = NULL;
	head = NULL;
	tail = NULL;
}

template<typename T>
int Queue1<T>::GetSize() const
{
	return this->count;
}

template<typename T>
void Queue1<T>::Push(const T& element)
{
	if (count < size)
	{
		arr[tail] = element;

		tail = (tail + 1) % size;

		count++;
	}
	else
	{
		std::cout << "Очередь переполнена! Аварийное завершение программы!" << "\n";
		abort();
	}
}

template<typename T>
T Queue1<T>::Pop()
{
	if (count > 0)
	{
		T element = arr[head];
		head = (head + 1) % size;
		count--;

		return element;
	}
	else
	{
		std::cout << "Очередь пуста! Аварийное завершение программы!" << "\n";
		abort();
	}
}

template<typename T>
T Queue1<T>::Peek() const
{
	return arr[head];
}

template<typename T>
std::ostream& operator << (std::ostream& os, const Queue1<T>& obj)
{
	Queue1<T> temp = obj;

	os << "Текущая очередь => ";

	for (int i = 0; i < temp.size; i++)
	{
		if (temp.count > 0)
		{
			os << temp.arr[temp.head] << " ";
			temp.head = (temp.head + 1) % temp.size;
			temp.count--;
		}
	}

	os << "\n";

	return os;
}