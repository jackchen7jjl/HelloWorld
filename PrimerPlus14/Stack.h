#pragma once
#ifndef STACK_H_
#define STACK_H_

template <typename T>
class Stack
{
private:
	enum
	{
		MAX = 10
	};
	T items[MAX];
	int top;

public:
	Stack();
	bool isEmpty();
	bool isFull();
	bool push(const T & item);
	bool pop(T & item);
};

template <typename T>
Stack<T>::Stack()
{
	top = 0;
}

template <typename T>
bool Stack<T>::isEmpty()
{
	return top == 0;
}

template <typename T>
bool Stack<T>::isFull()
{
	return top == MAX;
};

template <typename T>
bool Stack<T>::push(const T & item)
{
	if (top < MAX)
	{
		items[top++] = item;
		return true;
	}
	else
		return false;
}


template <typename T>
bool Stack<T>::pop(T & item)
{
	if (top > 0)
	{
		item = items[--top];
		return true;
	}
	else
		return false;
}

#endif // !STACK_H_