#include <iostream>
using namespace std;
class Stack{
private:
	int *p_array;//数组指针
	int top;	//标识栈顶
	int caps;	//最大容量
public:
	Stack(){
		caps = 10;
		p_array = new int[caps];  //默认容量10
		top=0;	
	} 
	Stack(int max){
		caps =max;
		p_array = new int[caps];
		top=0;
	}
	//判断栈是否为空
	bool isEmpty(){
		if(top==0){
			return true;
		}
		else{
			return false;
		}
	}
	//顺序栈扩容
	void addcaps(){
		caps = caps * 2;
		int * newarray =  new int[caps];
		for(int i=0;i <top;i++ ){
			newarray[i] = p_array[i];
		}
		//int * p_temp = p_array;
		delete p_array;
		p_array = newarray;
	}
	//元素入栈
	void push(){
		if(top==caps ){
			addcaps();
		}
		cout << "输入你要入栈的数据：";
		int data;
		cin >> data;
		p_array[top]= data;
		top++;
	}
	//弹出元素
	int pop(){
		if(isEmpty()){
		cout << "栈为空，无法取出元素"<<endl;
		return -1;
		}
		top--;
		return p_array[top];		
	}
	//显示栈顶元素
	void returntop(){
		if(isEmpty()){
			cout << "栈为空，无法显示元素"<<endl;
		}
		else{
			cout << p_array[top-1];
		}
	}

	void showstack(){
		cout << "栈内元素为：";
		for(int i=0; i<top; i++){
			cout << p_array[i]<<' ';
		}
		cout << endl;

	}

}; 

int main(){

	Stack stack ;
	bool flag = true;
	int a;
	cout << "顺序栈基本操作" << endl;
	
	
	while(flag) {
		cout << "(1).元素入栈" << endl
			<< "(2).元素出栈" << endl
			<< "(3).显示所有元素" << endl
			<< "(4).显示栈顶元素"<<endl
			<< "(5).栈是否为空"<<endl
			<< "(0).退出" << endl;
		cout << "输入你要进行的操作:" << endl;
		cin >> a;
		switch (a)
		{
		case 1:
			stack.push();
			break;
		case 2:
			if(stack.isEmpty()){
				cout << "栈元素为空，请加入元素"<<endl;
				
				break;
			}
			else{
				cout << "弹出的元素为：" <<stack.pop()<<endl;
			}
			
			break;
		case 3:
			stack.showstack();

			break;
		case 4:
			stack.returntop();
			break;
		case 5:
			if(stack.isEmpty()){
				cout << "栈为空"<<endl;
			}else{
				cout << "栈不为空" <<endl;

			}
			
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