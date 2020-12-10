//无向图的邻接表实现
#include <iostream>
#include <vector>  //顺序表
#include <list>		//链表
#include <queue>    //队列
using namespace std;
//无向图节点
class UGN {
public:
	char data;  //存放节点的数据
	list<int>  list; //节点的邻接表
	int index;   //标识符,1代表没有输出过,0代表已经输出过
	//初始化节点数据
	UGN(char data) {
		this->data = data;
		index = 1;
	}
};
//无向网类
class UG {
private:
	//存放节点指针的数组
	vector<UGN*> vecs;
	//返回对应字符在数组里面的下标
	int returnindex(char ch) {
		int index = 0;
		for (int i = 0; i < vecs.size(); i++) {
			if (vecs[i]->data == ch) {
				index = i;
				break;
			}
		}
		return index;
	}
	//添加每个节点的相邻边
	void addside() {
		for (auto it = vecs.begin(), E = vecs.end(); it != E; it++) {
			cout << "请输入节点" << (*it)->data << "的临边个数";
			int num;
			cin >> num;
			cout << "请输入" << num << "个相邻节点";

			for (int i = 0; i < num; i++) {
				char ch;
				cin >> ch;
				int index = returnindex(ch);
				//把节点的每个相邻的节点下标存入链表
				(*it)->list.push_back(index);
			}
			cout << "已经成功添加节点" << (*it)->data << "的" << num << "边" << endl;
		}
	}
	
public:
	//创建无向图的动态节点并且将地址赋值给指针数组vecs
	UG() {
		cout << "请输入无向图节点的个数:";
		int num;
		cin >> num;
		cout << "请输入" << num << "个节点的数据:";
		char data;
		for (int i = 0; i < num; i++) {
			cin >> data;
			vecs.push_back(new UGN(data));
		}
		addside();
	}
	//广度优先遍历
	//利用队列实现广度优先遍历
	void BFS() {
		//队列存放每个节点指针
		queue<UGN*> que;
		que.push(vecs[0]);
		vecs[0]->index = 0;
		//队列不为空,则继续出队
		while (!que.empty()) {
			list<int>& templist = que.front()->list;
			//遍历队头节点的邻接表,并把邻接表对应的没有输出过的节点地址加入队列尾部
			for (auto it = templist.begin(), E = templist.end(); it != E; it++) {
				if (vecs[*it]->index) {
					que.push(vecs[*it]);
					vecs[*it]->index = 0;
				}
			}
			//输出对头节点的数据,然后出队
			cout << que.front()->data;
			
			que.pop();
		}
		//每次输出完毕要把所有的index恢复1,以便后续再次输出
		for (auto it = vecs.begin(), E = vecs.end(); it != E; it++) {
			(*it)->index = 1;
		}
	}
	//析构
	~UG() {
		for (auto it = vecs.begin(), E = vecs.begin(); it != E; it++) {
			delete (*it);
		}
	}
};
int main() {
	UG UG;
	UG.BFS();
	return 0;
}
