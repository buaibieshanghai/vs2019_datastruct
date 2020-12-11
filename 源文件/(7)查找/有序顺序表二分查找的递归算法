  //有序顺序表的二分查找的递归算法

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class OrderArray{
private:
		vector<int> vecs;
public:
	OrderArray(){
		int n;
		cout <<"请输入有序顺序表的长度:";
		cin >> n;
		cout << "请输入"<<n<<"个有序顺序表的元素:";
		int data;
		for(int i=0; i<n; i++){
			cin >> data;
			vecs.push_back(data);
		}
		sort(vecs.begin(),vecs.end());
	}
	void printArray(){
		for(auto it=vecs.begin(), E = vecs.end(); it!=E; it++){
			cout<< *it<<" ";
		}
	}
	
	void find(){
		while(true){
			int num;
			cout << "输入你要查找的数字";
			cin >>num;
			int index = BiFind(0,vecs.size()-1,num);
			if(index == -1){
				cout << "该数字不存在" <<endl;
			}else{
				cout <<"数字" <<vecs[index] <<"的下标为"<<index<<endl;
			}
		}
	

	}
	//二分递归查找
	int BiFind(int left, int right, int data){
	
		if(left > right){
			return -1;
		}
		int middle =( left + right) /2;
		// 相等则返回所在下标
		if(data == vecs[middle]){
			return middle;
		}
		else if(data < vecs[middle]){
			return BiFind(left,middle-1,data);
		}
		else {
			return BiFind(middle+1,right,data);
		}
	}
};


int main(){

	OrderArray orderarray;
	orderarray.printArray();
	orderarray.find();
	system("pause");
	return 0;
}

