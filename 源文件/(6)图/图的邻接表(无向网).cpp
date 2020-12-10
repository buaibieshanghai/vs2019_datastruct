//图的邻接表实现

#include <iostream>
#include <vector>
#include <list>
using namespace std;
//无向网节点
class UDNnode{
public:
	char data;  //存放节点的数据
	list<int>  list;
public:
	//初始化节点数据
	UDNnode(char data){
		this->data = data;
	}
};
//无向网类
class UDN {
private:
	vector<UDNnode*> vecs;
public:
	UDN() {
		cout << "请输入无向网节点的个数:";
		int num;
		cin >> num;
		cout << "请输入" << num << "个节点的数据:";
		char data;
		for (int i = 0; i < num; i++) {
			cin >> data;
			vecs.push_back(new UDNnode(data));
		}

	} 
	//显示
	void showdata() {
		for (auto it = vecs.begin(); it != vecs.end(); it++) {
			cout <<"节点:"<< (*it)->data<<"相临节点";
			for (auto i= (*it)->list.begin() ;i!=(*it)->list.end(); i++ ){
				cout << vecs[*i]->data  << "->";
			}
			cout << endl;

		}
	}
	//添加边
	void addallline() {
		for (auto it = vecs.begin(); it != vecs.end(); it++) {
			cout << "请输入节点" << (*it)->data << "的临边个数";
				int num;
			cin >> num;
			cout << "请输入" << num << "个相邻节点";

			for (int i = 0; i < num; i++) {
				char ch;
				cin >> ch;
				int index = returnindex(ch);
				(*it)->list.push_back(index);
			}
			cout << "已经成功添加节点"<< (*it)->data <<"的" << num << "个边" << endl;
		}
	}
	int returnindex(char ch){
		int index; 
		for (int i = 0; i<vecs.size(); i++) {
			if (vecs[i]->data == ch) {
				index = i;
			}
		}
		return index;
	}
	//析构
	~UDN(){
		for (auto it = vecs.begin(); it != vecs.end();it++) {
			delete (*it);
		}
	}
};
int main() {
	UDN udn;
	
	udn.addallline();
	udn.showdata();
	return 0;
}
