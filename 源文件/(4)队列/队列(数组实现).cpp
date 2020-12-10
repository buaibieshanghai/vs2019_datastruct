/*
一、实验目的
1、掌握队列的类型定义方法。
2、理解和掌握循环队列解决假溢出的方法。
二、实验内容
1、利用循环队列模拟舞伴配对问题：在舞会上，男、女各自排成一队。
	舞会开始时。依次从男队和女队的队头各出一人配成舞伴。
	如果两队初始人数不等，则较长的那一队中未配对者等待下一轮舞曲。   
2、假设初始男、女人数及性别已经固定，舞会的轮数从键盘输入。
	试模拟解决上述舞伴配对问题。   
3、要求：从屏幕输出每一轮舞伴配对名单，如果在该轮有未配对的，
	能够从屏幕显示下一轮第一个出场的未配对者的姓名。
*/


#include <iostream>
using namespace std;
//数组实现的队列
class Queue{
private:
	int *p_array;    //指针
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
			
		}else {
			int data;
			cout << "请输入你要入队的元素" << endl;
			cin >> data;

			if (rear == length) {
				for (int i = 0; i < rear - front; i++) {
					p_array[i] = p_array[i + front];
				}
				rear = rear - front;
				front = 0;
				
			}
			p_array[rear] = data;
			rear++;

		}

	}
	//出队
	void pop() {
		if (rear == front) {
			cout << "队列为空,无法出队" << endl;
		}
		else {
			cout << "出队元素为" << p_array[front] << endl;
			front++;
		}	
	}
	//显示队列元素
	void showQueue() {
		cout << "队列元素为:";
		for (int i = front; i != rear; i++) {
			cout << p_array[i]<<" ";
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

