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
		cout << "----------请输入表达式(不支持负数和小数)----------" << endl;
		getline(cin,str);
		getline(cin, str);
		if (!istrue(str)) {
			cout << "----------表达式不合法!----------" << endl;
			str = "";
		};

	}
	
	void calculateresult() {
		if (str=="") {
			cout << "----------请先输入表达式!----------" << endl;
			return;
		}
		//如果是操作数则直接入数栈
		for (int i = 0; i!=str.size();) {
			int index = returnindex(str[i]);
			if (index == -3) {
				i++;
			}
			//如果是操作数,则读取下一位直到没有数字 然后入栈
			else if (index == -2) {
				int tempindex = index;
				int tempnum=0;
				while (tempindex == -2) {
				tempnum = tempnum * 10+str[i] - '0';	
					i++;
					if (i == str.size()) {
						break;
					}
					tempindex = returnindex(str[i]);
				}
				numstack.push(tempnum);
			}
			//如果是运算符,则需要判断
			else {

				//栈为空或者是左括号,则直接入栈
				if (charstack.size() == 0 || str[i]=='(') {
					charstack.push(str[i]);
					i++;
				}
				//如果是右括号,则运算优先级最低
				else {
					//栈顶运算符优先级
					int indexfront = returnindex(charstack.front());
					//待入栈运算符优先级
					int indextemp = returnindex(str[i]);
					//如果待入运算符优先级大于栈顶运算符优先级,则入栈
					if (indextemp > indexfront) {
						charstack.push(str[i]);
						i++;
					}
					//否则,数栈出栈两个数字,符号栈出栈一个符号进行运算
					else {
						//判断待入栈运算符和栈顶运算符优先级都是-1,则弹出左括号
						if (indexfront==-1 && indextemp == -1) {
							charstack.pop();
							i++;
						}
						else {
							popcalculate();	
						}	
					}
				}
			}
		}
		//字符串扫描完后,将栈中所有数据弹出运算
		while (popcalculate());
		if (numstack.isEmpty()) {
			cout << "----------表达式有误,请重新输入!----------" << endl;
				return;
		}
		cout << "----------表达式结果为----------" << endl;
		cout << numstack.front()<<endl;
	}
	
private:
	//判断表达式是否合法
	bool istrue(string str) {
		bool flag = true;
		//判断是否有除了空格,-+*/()之外的符号
		for (int i = 0; i < str.length(); i++) {
			if (returnindex(str[i]) == -4) {
				flag = false;
				cout << "---------------表达式不合法(包含不合法的运算符或字母)---------------" << endl;	
			}
		}
		//去除空格,判断括号是否正确
		string tempstr;
		
		for (int i = 0; i < str.length(); i++) {
			if (str[i] != ' ' ) {
				tempstr.push_back(str[i]);
			}
		}
		//遍历字符串,判断()前后是否合法
		for (int i = 0; i < tempstr.length(); i++) {
			//如果左括号 右边是符号或者右括号
			if (tempstr[i]=='(') {
				if (i-1<0) {
					if (returnindex(tempstr[i+1])==0|| returnindex(tempstr[i + 1]) == 1 || tempstr[i+1] == ')' ) {
						flag = false;
						cout << "---------------表达式不合法(左括号右边有运算符或者右括号)---------------" << endl;
					
					}
				}
				else if (i + 1 >= tempstr.length()) {
						flag = false;
						cout << "---------------表达式不合法(左括号在最右端)---------------" << endl;
						
					
				}
				else {
					if (returnindex(tempstr[i + 1]) == 0 || returnindex(tempstr[i + 1]) == 1 || tempstr[i + 1] == ')') {
						flag = false;
						cout << "---------------表达式不合法(左括号右边有运算符或者右括号)---------------" << endl;
					
					}
					if (returnindex(tempstr[i - 1]) == -2 || tempstr[i - 1] == ')') {
						flag = false;
						cout << "---------------表达式不合法(左括号左边有数字或者右括号)---------------" << endl;

					}
				}

			}
			//如果是右括号
			if (tempstr[i]==')') {
				if (i - 1 < 0) {
					cout << "---------------表达式不合法(右括号在最左端)---------------" << endl;
				}
				else if (i + 1 >= tempstr.length()) {
					if (returnindex(tempstr[i - 1]) == 0 || returnindex(tempstr[i - 1]) == 1 || tempstr[i - 1] == '(') {
						flag = false;
						cout << "---------------表达式不合法(右括号左边有运算符或者左括号)---------------" << endl;
					}
				}
				else {
					if (returnindex(tempstr[i - 1]) == 0 || returnindex(tempstr[i - 1]) == 1 || tempstr[i - 1] == '(') {
						flag = false;
						cout << "---------------表达式不合法(右括号左边有运算符或者左括号)---------------" << endl;

					}
					if (returnindex(tempstr[i + 1]) == -2 || tempstr[i  + 1] == '(') {
						flag = false;
						cout << "---------------表达式不合法(右括号右边有数字或者左括号)---------------" << endl;

					}
				}
			}
		}
		//去除空格和括号,判断运算符和数字是否正确
		tempstr = "";
		for (int i = 0; i < str.length(); i++) {
			if (str[i] != ' ' && str[i] != '(' && str[i] != ')') {
				tempstr.push_back(str[i]);
			}
		}
		
		for (int i = 0; i < tempstr.length(); i++) {
			//如果str不是数字,则要判断前后必须是数字
			if (returnindex(tempstr[i]) != -2) {
				if (i - 1 < 0 || i + 1 >= tempstr.length()) {
					flag = false;
					cout << "---------------表达式不合法(运算符左右没有数字)---------------" << endl;

				}
				else {
					if (returnindex(tempstr[i - 1]) != -2 || returnindex(tempstr[i + 1]) != -2) {
						flag = false;
						cout << "---------------表达式不合法(运算符左右没有数字)---------------" << endl;

						
					}
				}
			}
		}
		//只留下括号,判断括号是否合法
		stack<char> tmpstack;
		for (int i = 0; i < str.length(); i++) {
			if (str[i]=='(' || str[i]==')') {
				if (tmpstack.isEmpty()) {
					tmpstack.push(str[i]);
				}
				//左括号直接入栈
				else if (str[i] == '(') {
					tmpstack.push(str[i]);
				}
				//右括号则判断栈顶是否是左括号,若是则弹出栈顶的左括号
				else {
					if (tmpstack.front()=='(') {
						tmpstack.pop();
					}
					else {
						tmpstack.push(str[i]);
					}
				}
			}
			
		} 
		
		if (!tmpstack.isEmpty()) {
			flag = false;
			cout << "---------------表达式不合法(括号不匹配)---------------" << endl;
		}
		if (flag == false) {
			str = "";
		}
		return flag;
		
	}

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
		int result;
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
	
	//返回操作符的优先级,如果不是操作符则返回-1,既不是操作数也不是操作符返回-2
	int returnindex(char operatorchar) {
		switch (operatorchar) {
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
		case '(':
		case ')':
			return -1;
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
};
int main() {
	bool flag = true;
	int a;
	cout <<" ------------------------------ "<< endl;
	cout <<"|       表达式计算系统         |" << endl;
	cout <<"|       (1).输入表达式         |" << endl
		<< "|       (2).计算结果           |" << endl
		<< "|       (0).退出系统           |"  << endl;
	cout << " ------------------------------ " << endl;
	Expression expression;
	while (flag) {
		
		cout << "----------输入你要进行的操作(1).输入表达式.(2).计算结果.----------" << endl;
		cin >> a;
		switch (a)
		{
		case 1:
			expression.setstring();
			break;
		case 2:
			expression.calculateresult();
			break;
		case 0:
			flag = false;
			cout << "退出!" << endl;
			break;
		default:
			break;
		}
	}
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
	return 0;
}







