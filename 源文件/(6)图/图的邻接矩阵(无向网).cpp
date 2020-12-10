#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
//卑恋卑恋卑恋卑恋
#define MaxInt 32767		//表示极大值
#define MVNum 100			//最大最大顶点数
class UDN {			//无向网
private:
	vector<char> vexs;   //存放每个节点的数据char
	int vexnum;         //当前存放的节点个数
	vector<vector<int>> arcs;		//存放权值(类型为整形)
	int arcnum;          //当前存放的边数
public:
	UDN(){
		vexnum = 0;
		arcnum = 0;
		//初始化节点数据
		vexs.resize(MVNum);
		arcs.resize(MVNum);
		for (auto it = arcs.begin(); it != arcs.end(); it++) {
			(*it).resize(MVNum);
		}
		//赋值
		for (auto it = arcs.begin(); it!=arcs.end(); it++ ){
			for (auto it1 = it->begin(); it1 != it->end(); it1++) {
				(*it1) = MaxInt;
			}
		}
		
	}
	//输入总顶点数,总边数
	UDN(int vexnum,int arcnum) {
		vexs.resize(MVNum);
		arcs.resize(MVNum);
		//初始化节点数据
		this->vexnum = vexnum;
		this->arcnum = arcnum;
		cout << "请输入" <<vexnum<< "个顶点信息" << endl;
		char zimu[10] = {'a','b','c','d','e','f','g','h','i','j'};
		for (int i = 0; i < vexnum;i++) {
			 vexs[i]= zimu[i];
		}
		for (auto it = arcs.begin(); it != arcs.end(); it++) {
			(*it).resize(MVNum);
		}
		//赋值
		for (auto it = arcs.begin(); it != arcs.end(); it++) {
			for (auto it1 = it->begin(); it1 != it->end(); it1++) {
				(*it1) = MaxInt;
			}
		}
	}
	//添加两个节点之间的边
	void addline() {
		char ch1;
		char ch2;
		cout << "请输入两个节点的名字和权值" << endl;
	
		int index1;  //存放第一个节点的位置
		int index2;  //存放第二个节点的位置 
		int quanzhi;  //权值
		cin >> ch1 >> ch2>>quanzhi;
		bool flag1 = false;
		bool flag2 = false;

		for (int it = 0; it < vexnum; it++) {
			if (vexs[it]==ch1) {
				index1 = it;
				flag1 = true;
			}
			if (vexs[it]==ch2) {
				index2 = it;
				flag2 = true;
			}
		}
		if (!flag1 || !flag2 ) {
			cout << "错误数据" << endl;
			return;
		}
		else {
			arcs[index1][index2] = quanzhi;
			arcs[index2][index1] = quanzhi;
		}
	}
	void show() {
		cout << "  ";
		for (int it = 0; it != vexnum; it++) {
			cout << vexs[it] << " ";
		}
		cout << endl;
		for (int  it = 0; it != vexnum; it++) {
			cout << vexs[it]<<" ";
			for (int  it1 = 0; it1 != vexnum; it1++) {
				if (arcs[it][it1]==MaxInt) {
					cout << ' ' << " ";
				}
				else {
					cout << arcs[it][it1] << " ";
				}	
			}
			cout << endl;
		}
	}
};
int main() {
	UDN udn(5,0);
	while (1) {
		udn.addline();
		udn.show();
	}
	return 0;
}

