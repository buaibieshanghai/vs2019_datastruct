#include <iostream>
#include "stack.h"
#include <string>
using namespace std;
class Expression {//表达式类
private:
	string str;			//表达式
	stack<int> numstack;  //数栈
	stack<char> charstack; //符号栈 
public:
	//初始化
	Expression() {
		str = "";
	}
	//设置表达式
	void setstring() {
		cout << endl;
		cout << "----------------------请输入表达式(不支持负数和小数)----------------------" << endl;
		cout << endl;
		getline(cin,str);//读取回车
		getline(cin,str);
		if (!istrue(str)) {
			cout << endl;
			cout << "----------------------------表达式不合法!----------------------------" << endl;
			cout << endl;
			str = "";
		}
	}
	void calculateresult() {
		if (str=="") {
			return;
		} 
		//遍历表达式 
		for (int i = 0,index ; i<str.size();i++) {
			 index = returnindex(str[i]);
			 int tempnum = 0;
			 switch(index){
			 case -3:
				 //空格直接跳过
				 break;
			 case -5:
				 //左括号直接入符号栈
				 charstack.push(str[i]);
				 break;
			 case -1:
				 //右括号,需要不断弹出运算直到遇到左括号为值
				 if (returnindex(charstack.front())==-5) {
					 charstack.pop();
				 }
				 else {
					 popcalculate();
				 i--;
				 }
				 break;
			 case -2:
				 //如果遍历到数字,则遍历数字的下一位,将所有数字的和加在一起入栈
				 for (; i < str.size() && returnindex(str[i]) == -2; i++) {
					 tempnum = tempnum * 10 + str[i] - '0';
				 }
				 i--;
				//操作数入栈
				 numstack.push(tempnum);
				 break;
			 case 0:
			 case 1:
				 //遍历到运算符(+-*/ 右括号 )
				 //如果符号栈为空,则直接入符号栈
				 if (charstack.isEmpty()) {
					 charstack.push(str[i]);
				 }
				 else {
					 //否则和栈顶运算符比较运算级
					 //如果待入运算符优先级大于栈顶运算符优先级,则入栈
					 if (returnindex(str[i]) > returnindex(charstack.front())) {
						 charstack.push(str[i]);
					 }
					 else {
						 popcalculate();
						 i--;
					 }
				 }
			 }
		}
		//字符串扫描完后,将栈中所有数据弹出运算
		while (popcalculate());
		cout << endl;
		cout << "---------------------------表达式结果为" << numstack.front() << "---------------------------" << endl;
		cout << endl;
	}
private:
	//数栈出栈两个数字,符号栈出栈一个符号进行运算,
	//操作成功返回true,失败返回false
	bool popcalculate() {
		if (numstack.size() == 0 || charstack.size() == 0) {
			return false;
		}
		char tempchar = charstack.front();
		charstack.pop();
		int num2 = numstack.front();
		numstack.pop();
		int num1 = numstack.front();
		numstack.pop();
		int result = 0;
		switch (tempchar) {
		case '+':
			result = num1 + num2;
			break;
		case '-':
			result = num1 - num2;
			break;
		case '*':
			result = num1 * num2;
			break;
		case '/':
			result = num1 / num2;
			break;
		}
		numstack.push(result);
	}
	//返回字符的优先级
	// +-优先级为 0
	// */优先级为1
	// 括号优先级最低为-1
	
	//数字返回-2
	//空格返回-3
	//其他符号返回-4
	int returnindex(char ch) {
		switch (ch) {
		case '+':		
		case '-':
			return 0;
			break;
		case '*':
		case '/':
			return 1; 
		case '(':
			return -5;
		case ')':
			return -1;
		case '0':
		case '1':
		case '2':
		case '3':
		case '4':
		case '5':
		case '6':
		case '7':
		case '8':
		case '9':
			return -2;
			break;
		case ' ':
			return -3;
			break;
		default: 
			return -4;
			break;
		}
	}
	//判断表达式是否合法
	bool istrue(string str) {
		if (str=="") {
			return false;
		}
		string tempstr;
		//判断是否有除了空格,-+*/()之外的符号,并且去除空格
		for (int i = 0; i < str.length(); i++) {
			int index = returnindex(str[i]);
			if (index== -4 ) {
				return false;
			}
			else if(index!=-3){
				tempstr.push_back(str[i]);
			}
		}	
		//遍历字符串,判断()前后是否合法,如果合法则将数字符号 和括号分离,分别加入tempstr2和括号栈
		string tempstr2;
		stack<char> tmpstack;
		for ( int i = 0; i < tempstr.length(); i++) {
			int index = returnindex(tempstr[i]);
			switch (index) {
			case -1:
				if (i>0 && i+1<tempstr.length()-1) {
					int leftindex = returnindex(tempstr[i - 1]);
					int rightindex = returnindex(tempstr[i + 1]);
					if (leftindex==0 || leftindex==1 ||leftindex==-5|| rightindex==-2||rightindex==-5) {
						return false;
					}	
				}
				if (tmpstack.isEmpty() || tmpstack.front() != '(') {
					tmpstack.push(str[i]);
				}
				else {
					tmpstack.pop();
				}
				break;
			case -5:
				if (i > 0 && i + 1 < tempstr.length() - 1) {
					int leftindex = returnindex(tempstr[i - 1]);
					int rightindex = returnindex(tempstr[i + 1]);
					if (leftindex == -2 || leftindex == -1 || rightindex == 0 || rightindex == 1||rightindex ==-1 ) {
						return false;
					}
				}
				tmpstack.push(str[i]);
				break;
			case -2:
			case 0:
			case 1:
				tempstr2.push_back(tempstr[i]);
				break;
			}
	}	
		//判断括号是否匹配
		if (!tmpstack.isEmpty()) {
			return  false;
		}
		//判断运算符是否正确
		for (int i = 0; i < tempstr2.length(); i++) {
			//如果str不是数字,则要判断前后必须是数字
			int index = returnindex(tempstr2[i]);
			if (index !=-2) {
				if (i - 1 < 0 || i + 1 >= tempstr2.length()|| returnindex(tempstr2[i - 1]) != -2 || returnindex(tempstr2[i + 1]) != -2) {
					return false;
				}
			}
		}
		return true;
	}
};
int main() {
	/*
	   测试:
	   (合法数据)2*((((36+4)*5)+6)/2+(7*3+6)*9+3*2)

	   (不合法数据)
	   3@4a
	   +3*2
	   3+-2
	   3*2+
	   3+2+(
	   3+2(
	   )+3*2
	   )3*2
	   3+()+2
	   3()2
	   2+(+3)
	   (3+2)(2+3)
	   2(2+3)
	   (2-)+3
	   (2)3+2
	   3+((2)*5))
   */
	Expression expression;
	bool flag = true;
	int a;
	cout <<"                   ------------------------------ "<< endl;
	cout <<"                  |       表达式计算系统         |" << endl;
	cout <<"                  |       (1).输入表达式         |" << endl
		<< "                  |       (0).退出系统           |"  << endl;
	cout << "                   ------------------------------ " << endl;
	while (flag) {
		cout << endl;
		cout << "----------输入你要进行的操作(1).输入表达式.(0).退出系统----------" << endl;
		cout << endl;	
		cin >> a;
		switch (a)
		{
		case 1:
			expression.setstring();
			expression.calculateresult();
			break;
		case 0:
			flag = false;
			cout << endl;
			cout << "------------------------------退出!------------------------------" << endl;
			cout << endl;
			break;
		default:
			cout << endl;
			cout << "------------------------------输入0/1序号!------------------------------" << endl;
			cout << endl;
			break;
		}
	}
	return 0;
}







