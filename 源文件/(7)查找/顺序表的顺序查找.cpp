
#include <iostream>
#include <windows.h>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

//˳����ʱ�临�Ӷ�ΪO(n)
//�����ڱ����Ż����԰�ʱ�����һ��,����ʱ�临�ӶȲ��� 
//ÿ������Ԫ�صĲ��Ҵ��� asl Ϊ n+1 / 2




int main() {
	//��������
	time_t timer;


	while (1) {
		vector<int> v;
		DWORD t_start, t_end;
		time(&timer);
		srand(timer);
		for (int i = 0; i < 10000000; i++) {
			v.push_back(rand());
		}
		v.push_back(-1);
		int num = -1;




		cout << "�ڶ���" << endl;
		t_start = GetTickCount();

		int index1 = 0;


		for (int i = 0; v[i] != num; i++) {
			index1++;
		}
		cout << "�Ƚϴ���:" << index1 << endl;

		t_end = GetTickCount();
		cout << "��������ʱ��:" << (double)(t_end - t_start) / 1000 << "��" << endl;






		cout << " ��һ��" << endl;
		t_start = GetTickCount();//�Ӳ���ϵͳ������������elapsed���ĺ����������ķ���ֵ��DWORD��
		int index = 0;

		for (auto it_b = v.begin(), it_e = v.end(); it_b != it_e; it_b++) {
			//ÿ�Ƚ�һ��,���ʶ����һ��
			index++;
			if ((*it_b) == num) {

				break;
			}

		}
		cout << "�Ƚϴ���:" << index << endl;

		t_end = GetTickCount();
		cout << "��������ʱ��:" << (double)(t_end - t_start) / 1000 << "��" << endl;
	}

	return 0;
}