
#include <iostream>
using namespace std;
class Array {
private:
	int* arr;   //指向动态数组
	int size;   //数组元素个数
	int caps;   //数组最大数量
public:
	Array() {
		caps = 10;
		arr = new int[caps];
		size = 0;
	}
	Array(int caps) {
		this->caps = caps;
		size = 0;
		arr = new int[caps];
	}
	//添加容量
	void addcaps() {
		caps = caps * 2;
		int* arrnew = new int[caps];
		for (int i = 0; i < size; i++) {
			arrnew[i] = arr[i];
		}
		arr = arrnew;
	}
	void deleteArray() {
		cout << "请输入你要删除的位置" << endl;
		int index;
		cin >> index;
		for (int i = index; i < size - 1; i++) {
			arr[i] = arr[i + 1];
		}
		size--;
		cout << "已删除" << endl;
	}
	void addArray() {
		cout << "请输入你要插入的位置和数据" << endl;
		int data;
		int index;
		cin >> index >> data;
		if (index < 0 || index > size) {
			cout << "位置输入有误" << endl;
			return;
		}
		//如果数组已达到最大容量则扩容
		if (size == caps) {
			addcaps();
		}
		//将index位置后的元素以此后移
		for (int i = size; i > index; i--) {
			arr[i] = arr[i - 1];
		}
		arr[index] = data;
		size++;

	}
	void showArray() {
		for (int i = 0; i < size; i++) {
			cout << "位置" << i << "数据" << arr[i] << endl;

		}
	}
};
int main() {
	Array array;
	bool flag = true;
	int a;
	cout << "顺序表基本操作" << endl;


	while (flag) {
		cout << "(1).添加元素" << endl
			<< "(2).删除元素" << endl
			<< "(3).显示元素" << endl
			<< "(0).退出" << endl;
		cout << "输入你要进行的操作:" << endl;
		cin >> a;
		switch (a)
		{
		case 1:
			array.addArray();
			break;
		case 2:
			array.deleteArray();
			break;
		case 3:
			array.showArray();

			break;
		case 0:
			flag = false;
			cout << "退出!" << endl;
			break;
		default:
			break;
		}
	}


	return 0;


}