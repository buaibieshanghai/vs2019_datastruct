#include <iostream>
#include "stack.h"
#include <string>
using namespace std;
class Expression {//���ʽ��
private:
	string str;			//���ʽ
	stack<int> numstack;  //��ջ
	stack<char> charstack; //����ջ 
public:
	//��ʼ��
	Expression() {
		str = "";
	}
	//���ñ��ʽ
	void setstring() {
		cout << endl;
		cout << "----------------------��������ʽ(��֧�ָ�����С��)----------------------" << endl;
		cout << endl;
		getline(cin,str);//��ȡ�س�
		getline(cin,str);
		if (!istrue(str)) {
			cout << endl;
			cout << "----------------------------���ʽ���Ϸ�!----------------------------" << endl;
			cout << endl;
			str = "";
		}
	}
	void calculateresult() {
		if (str=="") {
			return;
		} 
		//�������ʽ 
		for (int i = 0,index ; i<str.size();i++) {
			 index = returnindex(str[i]);
			 int tempnum = 0;
			 switch(index){
			 case -3:
				 //�ո�ֱ������
				 break;
			 case -5:
				 //������ֱ�������ջ
				 charstack.push(str[i]);
				 break;
			 case -1:
				 //������,��Ҫ���ϵ�������ֱ������������Ϊֵ
				 if (returnindex(charstack.front())==-5) {
					 charstack.pop();
				 }
				 else {
					 popcalculate();
				 i--;
				 }
				 break;
			 case -2:
				 //�������������,��������ֵ���һλ,���������ֵĺͼ���һ����ջ
				 for (; i < str.size() && returnindex(str[i]) == -2; i++) {
					 tempnum = tempnum * 10 + str[i] - '0';
				 }
				 i--;
				//��������ջ
				 numstack.push(tempnum);
				 break;
			 case 0:
			 case 1:
				 //�����������(+-*/ ������ )
				 //�������ջΪ��,��ֱ�������ջ
				 if (charstack.isEmpty()) {
					 charstack.push(str[i]);
				 }
				 else {
					 //�����ջ��������Ƚ����㼶
					 //���������������ȼ�����ջ����������ȼ�,����ջ
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
		//�ַ���ɨ�����,��ջ���������ݵ�������
		while (popcalculate());
		cout << endl;
		cout << "---------------------------���ʽ���Ϊ" << numstack.front() << "---------------------------" << endl;
		cout << endl;
	}
private:
	//��ջ��ջ��������,����ջ��ջһ�����Ž�������,
	//�����ɹ�����true,ʧ�ܷ���false
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
	//�����ַ������ȼ�
	// +-���ȼ�Ϊ 0
	// */���ȼ�Ϊ1
	// �������ȼ����Ϊ-1
	
	//���ַ���-2
	//�ո񷵻�-3
	//�������ŷ���-4
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
	//�жϱ��ʽ�Ƿ�Ϸ�
	bool istrue(string str) {
		if (str=="") {
			return false;
		}
		string tempstr;
		//�ж��Ƿ��г��˿ո�,-+*/()֮��ķ���,����ȥ���ո�
		for (int i = 0; i < str.length(); i++) {
			int index = returnindex(str[i]);
			if (index== -4 ) {
				return false;
			}
			else if(index!=-3){
				tempstr.push_back(str[i]);
			}
		}	
		//�����ַ���,�ж�()ǰ���Ƿ�Ϸ�,����Ϸ������ַ��� �����ŷ���,�ֱ����tempstr2������ջ
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
		//�ж������Ƿ�ƥ��
		if (!tmpstack.isEmpty()) {
			return  false;
		}
		//�ж�������Ƿ���ȷ
		for (int i = 0; i < tempstr2.length(); i++) {
			//���str��������,��Ҫ�ж�ǰ�����������
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
	   ����:
	   (�Ϸ�����)2*((((36+4)*5)+6)/2+(7*3+6)*9+3*2)

	   (���Ϸ�����)
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
	cout <<"                  |       ���ʽ����ϵͳ         |" << endl;
	cout <<"                  |       (1).������ʽ         |" << endl
		<< "                  |       (0).�˳�ϵͳ           |"  << endl;
	cout << "                   ------------------------------ " << endl;
	while (flag) {
		cout << endl;
		cout << "----------������Ҫ���еĲ���(1).������ʽ.(0).�˳�ϵͳ----------" << endl;
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
			cout << "------------------------------�˳�!------------------------------" << endl;
			cout << endl;
			break;
		default:
			cout << endl;
			cout << "------------------------------����0/1���!------------------------------" << endl;
			cout << endl;
			break;
		}
	}
	return 0;
}







