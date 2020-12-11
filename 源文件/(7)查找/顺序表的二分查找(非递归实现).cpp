
#include <iostream>
#include <windows.h>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

//顺序表的折半查找



int main() {
	//测试数组
	time_t timer;





	vector<int> v;
	DWORD t_start, t_end;
	time(&timer);
	srand(timer);
	for (int i = 0; i < 10000000; i++) {
		v.push_back(i);
	}

	int num = rand() % 10000000;




	cout << "第一种(顺序查找)" << endl;
	t_start = GetTickCount();

	int index1 = 0;


	for (int i = 0; v[i] != num; i++) {
		index1++;
	}



	cout << "比较次数:" << index1 << endl;




	t_end = GetTickCount();
	cout << "程序运行时间:" << (double)(t_end - t_start) / 1000 << "秒" << endl;







	cout << "第二种(折半查找)" << endl;
	t_start = GetTickCount();
	int left = 0;
	int right = v.size() - 1;
	int zhong = (left + right) / 2;
	while (true) {
		if (num == v[zhong]) {
			break;
		}
		//如果要求的数字在左半区域,则中间更新为右边界
		else  if (num < v[zhong]) {
			right = zhong;
		}
		//否则更新为左边界
		else if (num > v[zhong]) {
			left = zhong;
		}
		int zhong = (left + right) / 2;
	}

	t_end = GetTickCount();
	cout << "程序运行时间:" << (double)(t_end - t_start) / 1000 << "秒" << endl;
	return 0;
}
