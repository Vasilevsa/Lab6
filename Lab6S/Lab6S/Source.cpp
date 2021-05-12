#include <iostream>
#include "Queue1.h"
#include "Queue2.h"

using namespace std;

template<typename T>
void MyFuncWithPointer(QueueBase<T>* s)
{
	cout << s->Peek() << endl;
}

template<typename T>
void MyFuncWithReference(QueueBase<T>& s)
{
	cout << s.Peek() << endl;
}

int main()
{
	setlocale(LC_ALL, "Ru");

	Queue1<int> z1(5);

	z1.Push(1);
	z1.Push(2);
	z1.Push(5);
	z1.Push(6);
	z1.Push(9);

	cout << z1;
	cout << "Число элементов в очереди: " << z1.GetSize() << " Первый элемент в очереди " << z1.Peek() << endl;

	Queue2<int> z2;
	z2.Push(1);
	z2.Push(2);
	z2.Push(5);
	z2.Push(6);
	z2.Push(9);

	cout << z2;
	cout << "Число элементов в очереди: " << z2.GetSize() << " Первый элемент в очереди " << z2.Peek() << endl;

	cout << endl << "Вызов функции с аргументом указателя" << endl;
	cout << "Элемент из первой очереди" << endl;
	MyFuncWithPointer(&z1);
	cout << "Элемент из второй очереди" << endl;
	MyFuncWithPointer(&z2);
	cout << endl << "Вызов функции с аргументом ссылки" << endl;
	cout << "Элемент из первой очереди" << endl;
	MyFuncWithReference(z1);
	cout << "Элемент из второй очереди" << endl;
	MyFuncWithReference(z2);


	return 0;
}