#include <iostream>
using namespace std;
class QueueNode {
public:
	QueueNode* next;
	int data;
	QueueNode() : next(NULL), data(-1) {}
	QueueNode(int data) : next(NULL), data(data) {}
};
class Queue {
private:
	QueueNode* front;
	QueueNode* rear;
public:
	Queue() {
		rear = front = NULL;
	}
	void push() {
		cout << "输入你要添加的元素:";
		int data;
		cin >> data;
		QueueNode* tempNode = new QueueNode(data);
		if (rear == NULL && front == NULL) {
			rear = front = tempNode;

		}
		else {
			rear->next = tempNode;
			rear = rear->next;
		}
	}
	void pop() {
		if (rear == NULL && front == NULL) {
			cout << "队列为空,无法出列" << endl;

		}
		else {
			if (rear == front) {
				cout << "出队:" << front->data;
				delete front;
				rear = NULL;
				front = NULL;
			}
			else {
				cout << "出队:" << front->data;
				front = front->next;

			}
		}
	}
	void showQueue() {
		cout << "队列:";
		QueueNode* temp = front;
		while (temp != NULL) {
			cout << temp->data << " ";
			temp = temp->next;
		}
		cout << endl;
	}
};
int main() {
	Queue queue;
	bool flag = true;
	int a;
	cout << "单链表基本操作" << endl;

	while (flag) {
		cout << "(1).添加元素" << endl
			<< "(2).删除元素" << endl
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