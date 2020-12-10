
#include <iostream>
#include <windows.h>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

//顺序表的时间复杂度为O(n)
//经过哨兵的优化可以把时间减少一半,但是时间复杂度不变 
//每个数据元素的查找次数 asl 为 n+1 / 2




int main() {
	//测试数组
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




		cout << "第二种" << endl;
		t_start = GetTickCount();

		int index1 = 0;


		for (int i = 0; v[i] != num; i++) {
			index1++;
		}
		cout << "比较次数:" << index1 << endl;

		t_end = GetTickCount();
		cout << "程序运行时间:" << (double)(t_end - t_start) / 1000 << "秒" << endl;






		cout << " 第一种" << endl;
		t_start = GetTickCount();//从操作系统启动所经过（elapsed）的毫秒数，它的返回值是DWORD。
		int index = 0;

		for (auto it_b = v.begin(), it_e = v.end(); it_b != it_e; it_b++) {
			//每比较一次,则标识符加一次
			index++;
			if ((*it_b) == num) {

				break;
			}

		}
		cout << "比较次数:" << index << endl;

		t_end = GetTickCount();
		cout << "程序运行时间:" << (double)(t_end - t_start) / 1000 << "秒" << endl;
	}

	return 0;
}