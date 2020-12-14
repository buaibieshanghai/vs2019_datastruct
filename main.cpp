#include <iostream>
#include "stack.h"
#include <string>
using namespace std;


class Expression{//表达式类
private:
	string str;			//表达式
	stack<int> numstack;  //数栈
	stack<char> charstack; //符号栈 
	
public:
	Expression(string str){
		this->str = str;
	}
	//输入表达式
	Expression(istream & is){
		cout << "请输入表达式:"<<endl;
		getline(is,str);
	}
	//计算结果
	//数栈出栈两个数字,符号栈出栈一个符号进行运算
	//操作成功返回true
	bool calculateone(){
		if(numstack.size()==0 || charstack.size()  ==0 ){
			return false;
		}

		int num2 = numstack.front();
		numstack.pop();
		int num1 = numstack.front();
		numstack.pop();
		
		char tempchar = charstack.front();
		charstack.pop();
		
		 int result;


		 switch(tempchar){
			case '+':
				result =  num1+num2;
				break;
			case '-':
				result =  num1-num2;
				break;
			case '*':
				result = num1* num2;
				break;
			case '/':
				result = num1/num2;
				break;
		}
		numstack.push(result);
	}
	
	void calculateresult(){
		//如果是操作数则直接入数栈
	for(string::iterator it = str.begin(),E= str.end() ; it!=E; it++){
		int index = returnindex(*it);
		if(index ==  -2){
			
		}
		//如果是操作数 直接入栈
		else if(index==-1){
			numstack.push((*it)-'0'); 
		}
		//如果是运算符,则需要判断
		else{
			
			//栈为空,则直接入栈
			if(charstack.size() == 0){
				charstack.push(*it);
			}
			else {
				//栈顶运算符优先级
			int indexfront = returnindex(charstack.front());
			//待入栈运算符优先级
			int indextemp = returnindex(*it); 
				//如果待入运算符优先级大于栈顶运算符优先级,则入栈
				if(indextemp > indexfront){
					charstack.push(*it);
				}
				//否则,数栈出栈两个数字,符号栈出栈一个符号进行运算
				else{
					calculateone();
					it--;
				}
			

			}
		} 
	}

	while(calculateone());
} 
	

	


	//输出结果
	/*
		测试
		3*1+2-3*4/2+2*3-4*3 =
		3+2-6+6-12=
		-7

	*/
	void printresult(){
		
		cout <<"操作数为:"<<endl;
		for(int i=0; i<numstack.size(); i++){
			
			cout << numstack[i]<<endl;
		}

		cout << "操作符为:"<<endl;
		for(int i=0; i<charstack.size(); i++){
			
			cout << charstack[i]<<endl;
		}

	}


	//返回操作符的优先级,如果不是操作符则返回-1,既不是操作数也不是操作符返回-2
	int returnindex(char operatorchar){
		switch(operatorchar){
			case '+':
				return 0;
				break;
			case '-':
				return 0;
				break;
			case '*':
				return 1;
				break;
			case '/':
				return 1;
				break;
			case '1':
			case '2':
			case '3':
			case '4':
			case '5':
			case '6':
			case '7':
			case '8':
			case '9':			
				return -1;
				break;
			default:
				return -2;
				break;

			break;
		}

	}
};
int main(){
	Expression expression(cin);
	expression.calculateresult();
	expression.printresult();
	
	system("pause");
	return 0;
}


