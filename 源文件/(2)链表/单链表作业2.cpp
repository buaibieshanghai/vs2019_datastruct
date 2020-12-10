#include <iostream>
using namespace std;
class Node {
public:
	int data;   //数据
	Node* next;
	Node() {
		data = -1;
		next = 0;
	}
	Node(int data) {
		this->data = data;
		this->next = 0;
	}
	Node& operator= (Node& node) {
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
	void addList2(int data) {        //尾插
		Node* temp = &head;
		Node* tempnode = new Node(data);
		while (temp->next != 0) {
			temp = temp->next;
		}
		temp->next = tempnode;	
	}
	void showList() {
		for (Node* temp = &head; temp->next != 0; temp = temp->next) {
		
			cout  << temp->next->data << ' ';
		}
	}
	List& fanzhuan() {
		List newList;

		Node* temp = &head;
		Node* temp1 =&newList.head;
		while (temp->next != 0) {
			Node* tempnode = temp->next;
			head.next = tempnode->next;

			tempnode->next = temp1->next;
			temp1->next = tempnode;

		}
		return newList;
	}

	friend List&  hebingList(List & list1,List& list2 ) {
		Node* head1 =list1.head.next;
		Node* head2 = list2.head.next;
		List list;
		if (head1->data < head2->data) {
			list.head = list1.head;
			head1 = head1->next;
		}
		else {
			list.head = list2.head;
			head2 = head2->next;
		}
		Node* temp = list.head.next;
		while (head1!=0 && head2!=0 ) {
			if (head1->data <head2->data) {
				temp->next = head1;
				head1 = head1->next;
				
			}
			else {
				temp->next = head2;
				head2 = head2->next;
				
			}
			temp = temp->next;
		}
		if (head1!=0) {   //将最后一个数据加到合并的单链表最后
			temp->next = head1;
		}
		if (head2!=0) {
			temp->next = head2;
		}
		return list; 
		
	}
};

int main() {
	List list1;

	list1.addList2(0);
	list1.addList2(1);
	list1.addList2(3);
	list1.addList2(4);
	list1.addList2(7);
	list1.addList2(20);
	list1.addList2(40);
	List list2;
	list2.addList2(-1);
	list2.addList2(0);
	list2.addList2(5);
	list2.addList2(6);
	list2.addList2(10);
	list2.addList2(50);
	cout << "合并之前" << endl;
	list1.showList();
	cout << endl;
	list2.showList();
	cout << endl;
	cout << "合并之后" << endl;
	List list=  hebingList(list1,list2);
	list.showList();
	cout << "反转后" << endl;
	List listfanzhuan =  list.fanzhuan();
	listfanzhuan.showList();

	
	return 0;
}