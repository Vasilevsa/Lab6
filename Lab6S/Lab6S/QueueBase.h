#pragma once

template <typename T>
class QueueBase
{
public:
	virtual void Push(const T& element) = 0; // Вставка (добавление) элемента
	virtual T Pop() = 0; // Удаление элемента
	virtual T Peek() const = 0; // Просмотр (взятие без удаления) элемента 
	virtual int GetSize() const = 0; // Возвращения кол-ва элементов
	virtual ~QueueBase() {}
};