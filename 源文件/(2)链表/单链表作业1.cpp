#include <iostream>
using namespace std;
class Node {
public:
	int data;   //数据
	int index;		//编号
	Node* next;
	Node() {
		data = -1;
		index = -1;
		next = 0;
	}
	Node(int data, int index) {
		this->data = data;
		this->index = index;
		this->next = 0;
	}
	Node& operator= (Node& node) {
		this->index = node.index;
		this->data = node.data;
		this->next = node.next;
		return *this;

	}
};

class List {
private:
	Node head;          //头结点 
public:

	List() {}
	bool isEmpty() {
		return head.next == 0;
	}//指定位置插入
	void addList() {       
		// 插入的数据 和 要插入的 位置
		int data;
		int index;
		cout << "输入要插入的数据 和 位置" << endl;
		cin >> data;
		cin >> index;

		Node * temp = &head;    //临时指针temp
		Node *tempnode= new Node(data, index);
		while (temp->next!=0 && temp->next->index < index) {
			temp = temp->next;
		}
		tempnode->next = temp->next;
		temp->next = tempnode;
	}
	void deleteList() {
		int index = -1;
		cout << "请输入要删除的数据位置:" << endl;
		cin >> index;
		Node* temp = &head;
		bool flag = false;
		while (temp->next != 0) {
			if (temp->next->index==index ) {
				flag = true;
				break;
			}
			temp = temp->next;
		}if (flag) {
			Node* tempdeletenode = temp->next;
			temp->next = temp->next->next;
			delete tempdeletenode;
			cout << "已删除" << endl;
		}
		else {
			cout << "该位置没有数据!" << endl;
		}

	}
	void showList() {
		for (Node* temp = &head; temp->next != 0; temp = temp->next) {
			cout << "位置:" << temp->next->index;
			cout << "数据:" << temp->next->data << endl;	
		}
	}
};

int main() {
	List list;
	bool flag = true;
	int a;
	cout << "单链表基本操作" << endl;
	
	while(flag) {
		cout << "(1).添加元素" << endl
			<< "(2).删除元素" << endl
			<< "(3).显示元素" << endl
			<< "(0).退出" << endl;
		cout << "输入你要进行的操作:" << endl;
		cin >> a;
		switch (a)
		{
		case 1:
			list.addList();
			break;
		case 2:
			list.deleteList();
			break;
		case 3:
			list.showList();

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