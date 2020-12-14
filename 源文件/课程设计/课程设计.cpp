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
		cout << "----------��������ʽ(��֧�ָ�����С��)----------" << endl;
		getline(cin,str);
		getline(cin, str);
		if (!istrue(str)) {
			cout << "----------���ʽ���Ϸ�!----------" << endl;
			str = "";
		};

	}
	
	void calculateresult() {
		if (str=="") {
			cout << "----------����������ʽ!----------" << endl;
			return;
		}
		//����ǲ�������ֱ������ջ
		for (int i = 0; i!=str.size();) {
			int index = returnindex(str[i]);
			if (index == -3) {
				i++;
			}
			//����ǲ�����,���ȡ��һλֱ��û������ Ȼ����ջ
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
			//����������,����Ҫ�ж�
			else {

				//ջΪ�ջ�����������,��ֱ����ջ
				if (charstack.size() == 0 || str[i]=='(') {
					charstack.push(str[i]);
					i++;
				}
				//�����������,���������ȼ����
				else {
					//ջ����������ȼ�
					int indexfront = returnindex(charstack.front());
					//����ջ��������ȼ�
					int indextemp = returnindex(str[i]);
					//���������������ȼ�����ջ����������ȼ�,����ջ
					if (indextemp > indexfront) {
						charstack.push(str[i]);
						i++;
					}
					//����,��ջ��ջ��������,����ջ��ջһ�����Ž�������
					else {
						//�жϴ���ջ�������ջ����������ȼ�����-1,�򵯳�������
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
		//�ַ���ɨ�����,��ջ���������ݵ�������
		while (popcalculate());
		if (numstack.isEmpty()) {
			cout << "----------���ʽ����,����������!----------" << endl;
				return;
		}
		cout << "----------���ʽ���Ϊ----------" << endl;
		cout << numstack.front()<<endl;
	}
	
private:
	//�жϱ��ʽ�Ƿ�Ϸ�
	bool istrue(string str) {
		bool flag = true;
		//�ж��Ƿ��г��˿ո�,-+*/()֮��ķ���
		for (int i = 0; i < str.length(); i++) {
			if (returnindex(str[i]) == -4) {
				flag = false;
				cout << "---------------���ʽ���Ϸ�(�������Ϸ������������ĸ)---------------" << endl;	
			}
		}
		//ȥ���ո�,�ж������Ƿ���ȷ
		string tempstr;
		
		for (int i = 0; i < str.length(); i++) {
			if (str[i] != ' ' ) {
				tempstr.push_back(str[i]);
			}
		}
		//�����ַ���,�ж�()ǰ���Ƿ�Ϸ�
		for (int i = 0; i < tempstr.length(); i++) {
			//��������� �ұ��Ƿ��Ż���������
			if (tempstr[i]=='(') {
				if (i-1<0) {
					if (returnindex(tempstr[i+1])==0|| returnindex(tempstr[i + 1]) == 1 || tempstr[i+1] == ')' ) {
						flag = false;
						cout << "---------------���ʽ���Ϸ�(�������ұ������������������)---------------" << endl;
					
					}
				}
				else if (i + 1 >= tempstr.length()) {
						flag = false;
						cout << "---------------���ʽ���Ϸ�(�����������Ҷ�)---------------" << endl;
						
					
				}
				else {
					if (returnindex(tempstr[i + 1]) == 0 || returnindex(tempstr[i + 1]) == 1 || tempstr[i + 1] == ')') {
						flag = false;
						cout << "---------------���ʽ���Ϸ�(�������ұ������������������)---------------" << endl;
					
					}
					if (returnindex(tempstr[i - 1]) == -2 || tempstr[i - 1] == ')') {
						flag = false;
						cout << "---------------���ʽ���Ϸ�(��������������ֻ���������)---------------" << endl;

					}
				}

			}
			//�����������
			if (tempstr[i]==')') {
				if (i - 1 < 0) {
					cout << "---------------���ʽ���Ϸ�(�������������)---------------" << endl;
				}
				else if (i + 1 >= tempstr.length()) {
					if (returnindex(tempstr[i - 1]) == 0 || returnindex(tempstr[i - 1]) == 1 || tempstr[i - 1] == '(') {
						flag = false;
						cout << "---------------���ʽ���Ϸ�(��������������������������)---------------" << endl;
					}
				}
				else {
					if (returnindex(tempstr[i - 1]) == 0 || returnindex(tempstr[i - 1]) == 1 || tempstr[i - 1] == '(') {
						flag = false;
						cout << "---------------���ʽ���Ϸ�(��������������������������)---------------" << endl;

					}
					if (returnindex(tempstr[i + 1]) == -2 || tempstr[i  + 1] == '(') {
						flag = false;
						cout << "---------------���ʽ���Ϸ�(�������ұ������ֻ���������)---------------" << endl;

					}
				}
			}
		}
		//ȥ���ո������,�ж�������������Ƿ���ȷ
		tempstr = "";
		for (int i = 0; i < str.length(); i++) {
			if (str[i] != ' ' && str[i] != '(' && str[i] != ')') {
				tempstr.push_back(str[i]);
			}
		}
		
		for (int i = 0; i < tempstr.length(); i++) {
			//���str��������,��Ҫ�ж�ǰ�����������
			if (returnindex(tempstr[i]) != -2) {
				if (i - 1 < 0 || i + 1 >= tempstr.length()) {
					flag = false;
					cout << "---------------���ʽ���Ϸ�(���������û������)---------------" << endl;

				}
				else {
					if (returnindex(tempstr[i - 1]) != -2 || returnindex(tempstr[i + 1]) != -2) {
						flag = false;
						cout << "---------------���ʽ���Ϸ�(���������û������)---------------" << endl;

						
					}
				}
			}
		}
		//ֻ��������,�ж������Ƿ�Ϸ�
		stack<char> tmpstack;
		for (int i = 0; i < str.length(); i++) {
			if (str[i]=='(' || str[i]==')') {
				if (tmpstack.isEmpty()) {
					tmpstack.push(str[i]);
				}
				//������ֱ����ջ
				else if (str[i] == '(') {
					tmpstack.push(str[i]);
				}
				//���������ж�ջ���Ƿ���������,�����򵯳�ջ����������
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
			cout << "---------------���ʽ���Ϸ�(���Ų�ƥ��)---------------" << endl;
		}
		if (flag == false) {
			str = "";
		}
		return flag;
		
	}

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
	
	//���ز����������ȼ�,������ǲ������򷵻�-1,�Ȳ��ǲ�����Ҳ���ǲ���������-2
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
	cout <<"|       ���ʽ����ϵͳ         |" << endl;
	cout <<"|       (1).������ʽ         |" << endl
		<< "|       (2).������           |" << endl
		<< "|       (0).�˳�ϵͳ           |"  << endl;
	cout << " ------------------------------ " << endl;
	Expression expression;
	while (flag) {
		
		cout << "----------������Ҫ���еĲ���(1).������ʽ.(2).������.----------" << endl;
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
			cout << "�˳�!" << endl;
			break;
		default:
			break;
		}
	}
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
	return 0;
}







