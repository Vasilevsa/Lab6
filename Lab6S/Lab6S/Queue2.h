#pragma once

#include "QueueBase.h"
#include "List2.h"

template<typename T>
class Queue2 : public QueueBase<T>
{
private:

	List2<T> list;

public:

	Queue2();

	Queue2(const Queue2& other);

	Queue2(Queue2&& other);

	~Queue2() override;

	int GetSize() const override;

	void Push(const T& element) override;

	T Pop() override;

	T Peek() const override;

	Queue2& operator=(const Queue2& other);
	Queue2& operator=(Queue2&& other);

	template<typename T>
	friend std::ostream& operator<< (std::ostream& os, const Queue2<T>& obj);
};

template<typename T>
Queue2<T>::Queue2() { }

template<typename T>
Queue2<T>::Queue2(const Queue2& other)
{
	list = other.list;
}

template<typename T>
Queue2<T>::Queue2(Queue2&& other)
{
	list = std::move(other.list);
}

template<typename T>
Queue2<T>::~Queue2() {}

template<typename T>
int Queue2<T>::GetSize() const
{
	return list.getsize();
}

template<typename T>
void Queue2<T>::Push(const T& element)
{
	list.push_back(element);
}

template<typename T>
T Queue2<T>::Pop()
{
	return list.pop_front();
}

template<typename T>
T Queue2<T>::Peek() const
{
	return list.sel_el(0);
}

template<typename T>
Queue2<T>& Queue2<T>::operator=(const Queue2<T>& other)
{
	if (this == &other)
	{
		return *this;
	}

	list->clear();

	list = other.list;
}

template<typename T>
Queue2<T>& Queue2<T>::operator=(Queue2<T>&& other)
{
	if (this == &other)
	{
		return *this;
	}

	list->clear();

	list = std::move(other.list);
}

template<typename T>
std::ostream& operator<<(std::ostream& os, const Queue2<T>& obj)
{
	for (size_t i = 0; i < obj.list.getsize(); i++)
	{
		os << obj.list.sel_el(i) << " ";
	}

	os << std::endl;

	return os;
}