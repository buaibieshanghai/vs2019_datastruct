#include <iostream>
using namespace std;
//数组实现的循环队列
class Queue {
private:
	int* p_array;    //指针
	int front;     //队列头
	int rear;      //队列尾后一个位置
	int length;    //队列最大存储的元素个数

	//队列头 指向首元素
	//队列尾 指向尾元素的下一个位置
	//队列尾 - 队列头 = 队列元素个数
	//队列尾 - 队列头 = 0    说明 队列元素为空
	//队列尾 - 队列头 = length 说明 队列已满 不可以添加元素

	//队列尾 - 队列头 < length 且 队列尾 不等于 length 
	//    说明队列未满,可以添加元素,不需要 移动现有元素位置
	//队列尾 - 队列头 < length 且 队列尾 = length 
	//    说明队列未满,可以添加元素,但需要 移动现有元素位置
public:
	Queue() {
		length = 10;
		p_array = new int[length];
		rear = front = 0;
	}
	Queue(int length) {
		this->length = length;
		p_array = new int[length];
		rear = front = 0;
	}
	//入队
	void push() {
		//队列尾 - 队列头 = length 说明 队列已满 不可以添加元素
		if (rear - front == length) {
			cout << "队列已满,不可以添加元素" << endl;

		}
		else {
			int data;
			cout << "请输入你要入队的元素" << endl;
			cin >> data;
			p_array[rear % length] = data;
			rear++;
			cout << "添加成功" << endl;
		}

	}
	//出队
	void pop() {
		if (rear == front) {
			cout << "队列为空,无法出队" << endl;
		}
		else {
			cout << "出队元素为" << p_array[front % length] << endl;
			front++;
		}
	}
	//显示队列元素
	void showQueue() {
		cout << "队列元素为:";
		for (int i = front; i != rear; i++) {
			cout << p_array[i % length] << " ";
		}
	}
};





int main() {

	Queue queue;
	bool flag = true;
	int a;
	cout << "数组队列基本操作" << endl;

	while (flag) {
		cout << "(1).入队" << endl
			<< "(2).出队" << endl
			<< "(3).显示元素" << endl
			<< "(0).退出" << endl;
		cout << "输入你要进行的操作:" << endl;
		cin >> a;
		switch (a)
		{
		case 1:
			queue.push();
			break;
		case 2:
			queue.pop();
			break;
		case 3:
			queue.showQueue();

			break;
		case 0:
			flag = false;
			cout << "退出!" << endl;
			break;
		default:
			break;
		}
	}


	return 0;
}