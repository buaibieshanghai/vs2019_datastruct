#include <iostream>
using namespace std;
#define datatype char
class Stack {
private:
	datatype* p_array;//数组指针
	int top;	//标识栈顶
	int caps;	//最大容量
public:
	Stack() {
		caps = 10;
		p_array = new datatype[caps];  //默认容量10
		top = 0;
	}
	Stack(int max) {
		caps = max;
		p_array = new datatype[caps];
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
		datatype* newarray = new datatype[caps];
		for (int i = 0; i < top; i++) {
			newarray[i] = p_array[i];
		}
		//int * p_temp = p_array;
		delete p_array;
		p_array = newarray;
	}
	//元素入栈
	void push(int data) {
		if (top == caps) {
			addcaps();
		}

		p_array[top] = data;
		top++;
	}
	//弹出元素
	datatype pop() {
		if (isEmpty()) {
			cout << "栈为空，无法取出元素" << endl;
			return -1;
		}
		top--;
		return p_array[top];
	}
	//显示栈顶元素
	void returntop() {
		if (isEmpty()) {
			cout << "栈为空，无法显示元素" << endl;
		}
		else {
			cout << p_array[top - 1];
		}
	}

	void showstack() {
		cout << "栈内元素为：";
		for (int i = 0; i < top; i++) {
			cout << p_array[i] << ' ';
		}
		cout << endl;

	}

};

int main() {

	Stack stack;

	int num;
	int jinzhi;
	//数组保存对应进制的范围 2进制是0-1 16进制是 0-f 
	char array[16] = { '0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F' };


	while (true) {
		cout << "请输入非负十进制整数(1到2147483647) 和 转换后的进制(2-16)" << endl;
		cin >> num;
		cin >> jinzhi;


		while (num != 0) {
			stack.push(array[num % jinzhi]);    //将余数入栈

			num = num / jinzhi;    //更新 num 直到num等于0

		}
		//由于转换后的进制数是 和入栈的顺序相反 所以要将元素依次出栈并且输出
		cout << "转换后的" << jinzhi << "进制数为:";
		while (!stack.isEmpty()) {  //栈不为空,则出栈
			cout << stack.pop();
		}
		cout << endl;
	}

	return 0;
}