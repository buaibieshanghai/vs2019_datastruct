
#include <iostream>
using namespace std;
class Array {
private:
	int* arr;   //ָ��̬����
	int size;   //����Ԫ�ظ���
	int caps;   //�����������
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
	//�������
	void addcaps() {
		caps = caps * 2;
		int* arrnew = new int[caps];
		for (int i = 0; i < size; i++) {
			arrnew[i] = arr[i];
		}
		arr = arrnew;
	}
	void deleteArray() {
		cout << "��������Ҫɾ����λ��" << endl;
		int index;
		cin >> index;
		for (int i = index; i < size - 1; i++) {
			arr[i] = arr[i + 1];
		}
		size--;
		cout << "��ɾ��" << endl;
	}
	void addArray() {
		cout << "��������Ҫ�����λ�ú�����" << endl;
		int data;
		int index;
		cin >> index >> data;
		if (index < 0 || index > size) {
			cout << "λ����������" << endl;
			return;
		}
		//��������Ѵﵽ�������������
		if (size == caps) {
			addcaps();
		}
		//��indexλ�ú��Ԫ���Դ˺���
		for (int i = size; i > index; i--) {
			arr[i] = arr[i - 1];
		}
		arr[index] = data;
		size++;

	}
	void showArray() {
		for (int i = 0; i < size; i++) {
			cout << "λ��" << i << "����" << arr[i] << endl;

		}
	}
};
int main() {
	Array array;
	bool flag = true;
	int a;
	cout << "˳����������" << endl;


	while (flag) {
		cout << "(1).���Ԫ��" << endl
			<< "(2).ɾ��Ԫ��" << endl
			<< "(3).��ʾԪ��" << endl
			<< "(0).�˳�" << endl;
		cout << "������Ҫ���еĲ���:" << endl;
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
			cout << "�˳�!" << endl;
			break;
		default:
			break;
		}
	}


	return 0;


}