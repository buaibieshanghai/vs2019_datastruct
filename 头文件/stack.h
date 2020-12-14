#pragma once

template <class T>
class stack {
private:
	T* p_array;//����ָ��
	int top;	//��ʶջ��
	int caps;	//�������
public:
	stack() {
		caps = 10;
		p_array = new T[caps];  //Ĭ������10
		top = 0;
	}

	//�ж�ջ�Ƿ�Ϊ��
	bool isEmpty() {
		if (top == 0) {
			return true;
		}
		else {
			return false;
		}
	}
	//˳��ջ����
	void addcaps() {
		caps = caps * 2;
		T* newarray = new T[caps];
		for (int i = 0; i < top; i++) {
			newarray[i] = p_array[i];
		}

		delete p_array;
		p_array = newarray;
	}
	//Ԫ����ջ
	void push(T data) {
		if (top == caps) {
			addcaps();
		}

		p_array[top] = data;

		top++;
	}
	//����Ԫ��
	void pop() {
		if (isEmpty()) {

			return;
		}
		top--;

	}
	//��ʾջ��Ԫ��
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
