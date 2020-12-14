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
	Expression(string str) {
		this->str = str;
	}
	//������ʽ
	Expression(istream& is) {
		cout << "��������ʽ:" << endl;
		getline(is, str);
	}
	//������
	//��ջ��ջ��������,����ջ��ջһ�����Ž�������,
	//�����ɹ�����true
	//���ջ������������,���ٵ�������
	bool calculateone() {
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

	void calculateresult() {
		//����ǲ�������ֱ������ջ
		for (string::iterator it = str.begin(), E = str.end(); it != E; it++) {
			int index = returnindex(*it);
			if (index == -3) {

			}
			//����ǲ����� ֱ����ջ
			else if (index == -2) {
				numstack.push((*it) - '0');
			}
			//����������,����Ҫ�ж�
			else {

				//ջΪ�ջ�����������,��ֱ����ջ
				if (charstack.size() == 0 || (*it)=='(') {
					charstack.push(*it);
				}
				//�����������,���������ȼ����,
				
				else {
					//ջ����������ȼ�
					int indexfront = returnindex(charstack.front());
					//����ջ��������ȼ�
					int indextemp = returnindex(*it);
					//���������������ȼ�����ջ����������ȼ�,����ջ
					if (indextemp > indexfront) {
						charstack.push(*it);
					}
					//����,��ջ��ջ��������,����ջ��ջһ�����Ž�������
					else {
						//�жϴ���ջ�������ջ����������ȼ�����-1,�򵯳���������
						if (indexfront==-1 && indextemp == -1) {
							charstack.pop();
							
						}
						else {
							calculateone();
							it--;
						}
						
						
					}


				}
			}
		}

		while (calculateone());
	}





	//������
	/*
		����
		3*1+2-3*4/2+2*3-4*3 =
		3+2-6+6-12=
		-7

	*/
	void printresult() {

		cout << "������Ϊ:" << endl;
		for (int i = 0; i < numstack.size(); i++) {

			cout << numstack[i] << endl;
		}

		cout << "������Ϊ:" << endl;
		for (int i = 0; i < charstack.size(); i++) {

			cout << charstack[i] << endl;
		}

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
			return -2;
			break;
		default:
			return -3;
			break;

			break;
		}

	}
};
int main1() {
	Expression expression(cin);
	expression.calculateresult();
	expression.printresult();

	system("pause");
	return 0;
}







