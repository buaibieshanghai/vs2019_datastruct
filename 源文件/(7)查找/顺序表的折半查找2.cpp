
#include <iostream>
#include <windows.h>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

//˳�����۰����



int main() {
	//��������
	time_t timer;





	vector<int> v;
	DWORD t_start, t_end;
	time(&timer);
	srand(timer);
	for (int i = 0; i < 10000000; i++) {
		v.push_back(i);
	}

	int num = rand() % 10000000;




	cout << "��һ��(˳�����)" << endl;
	t_start = GetTickCount();

	int index1 = 0;


	for (int i = 0; v[i] != num; i++) {
		index1++;
	}



	cout << "�Ƚϴ���:" << index1 << endl;




	t_end = GetTickCount();
	cout << "��������ʱ��:" << (double)(t_end - t_start) / 1000 << "��" << endl;







	cout << "�ڶ���(�۰����)" << endl;
	t_start = GetTickCount();
	int left = 0;
	int right = v.size() - 1;
	int zhong = (left + right) / 2;
	while (true) {
		if (num == v[zhong]) {
			break;
		}
		//���Ҫ����������������,���м����Ϊ�ұ߽�
		else  if (num < v[zhong]) {
			right = zhong;
		}
		//�������Ϊ��߽�
		else if (num > v[zhong]) {
			left = zhong;
		}
		int zhong = (left + right) / 2;
	}

	t_end = GetTickCount();
	cout << "��������ʱ��:" << (double)(t_end - t_start) / 1000 << "��" << endl;
	return 0;
}