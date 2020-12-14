#pragma once

template <class T>
class stack {
private:
	T* p_array;//数组指针
	int top;	//标识栈顶
	int caps;	//最大容量
public:
	stack() {
		caps = 10;
		p_array = new T[caps];  //默认容量10
		top = 0;
	}

	//判断栈是否为空
	bool isEmpty() {
		if (top == 0) {
			return true;
		}
		else {
			return false;
		}
	}
	//顺序栈扩容
	void addcaps() {
		caps = caps * 2;
		T* newarray = new T[caps];
		for (int i = 0; i < top; i++) {
			newarray[i] = p_array[i];
		}

		delete p_array;
		p_array = newarray;
	}
	//元素入栈
	void push(T data) {
		if (top == caps) {
			addcaps();
		}

		p_array[top] = data;

		top++;
	}
	//弹出元素
	void pop() {
		if (isEmpty()) {

			return;
		}
		top--;

	}
	//显示栈顶元素
	int front() {
		if (isEmpty()) {
			return -1;
		}
		else {
			return p_array[top - 1];
		}
	}

	T operator[](int i) {

		return p_array[i];
	}

	int size() {
		return top;
	}

};
