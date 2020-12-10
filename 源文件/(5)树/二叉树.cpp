#include <iostream>
#include <vector>//顺序表
using namespace std;
struct TreeNode //二叉树节点类
{
    char data;
    TreeNode* left;
    TreeNode* right;
    int index=1;   //标识每个节点是否可输出,1为可以输出,0为不能输出
    TreeNode(char data) : data(data), left(NULL), right(NULL) {}
};
class BiTree {
private:
    TreeNode* root;
public:
    //将一个数组实现的二叉树变成链表实现的二叉树
    BiTree(istream& is) {
        int maxSize;
        cout << "输入二叉树的长度" << endl;
        is >> maxSize ;
        vector<char> v1(maxSize, '#');
        cout << "请输入" << maxSize << "个节点元素(元素用空格隔开,不存在的元素输入#)" << endl;
        for (int i = 0; i < maxSize; i++) {
            cin >> v1[i];
        }
        root = CreateBiTree(v1);
    }
    ~BiTree()
    {
        postorderTraversaldelete(root);
    }
    void show() {
        cout << "先序遍历:";
        preorderTraversal(root);
        cout << endl;
        cout << "中序遍历:";
        inorderTraversal(root);
        cout << endl;
        cout << "后序遍历:";
        postorderTraversal(root);
        cout << endl;
        int i = 1;     
        while (root->index!=0) {
            cout << "第" << i << "条路径:";
            i++;       
            showpath(root);
            cout << endl;
        }     
    }
     //二叉树的先序遍历
     void preorderTraversal(TreeNode*root) {
        if (root==NULL) {
            return;
        }
        cout << root->data;
        preorderTraversal(root->left);
        preorderTraversal(root->right);      
    }
    //二叉树的中序遍历
     void inorderTraversal(TreeNode*root ) {
        if (root == NULL) {
            return;
        }
        inorderTraversal(root->left);
        cout << "->" << root->data;
        inorderTraversal(root->right);
    }
    //二叉树的后序遍历
    void postorderTraversal(TreeNode*root){
        if (root == NULL) {
            return;
        }
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        cout << "->" << root->data;
    } 
     // 利用递归创建二叉树
     TreeNode* CreateBiTree(vector<char>& v, int n = 0) {
            TreeNode* root;
            TreeNode* lefttree;
            TreeNode* righttree;
            if (n >= v.size() || v[n] == '#') {
                root = NULL;
                return root;
            }  
                lefttree = CreateBiTree(v, 2 * n + 1);
                righttree = CreateBiTree(v, 2 * n + 2);
                root = new TreeNode(v[n]);
                root->left = lefttree;
                root->right = righttree;       
            return root;
        }
     //后续遍历销毁二叉树
     void postorderTraversaldelete(TreeNode*& root) {
            if (root == NULL) {
                return;
            }
            postorderTraversaldelete(root->left);
            postorderTraversaldelete(root->right);
            delete root;
            root = NULL;
            return;
        }
     //输出路径
     int   showpath(TreeNode* root) {
         //如果根节点为空或者不可输出,则返回0
         if (root == NULL || root->index == 0) {
             return 0;
         }
         //输出该节点数据
         cout << "->" << root->data;
         //输出左子节点,如果左子节点为空或者不能输出,则判断右子节点是否为空或者不能输出,
          //如果右子节点也为空或者不能输出 则根节点也设置为不可输出
         if (showpath(root->left) == 0) {
             if (showpath(root->right) == 0) {
                 root->index = 0;
             }
             //右子节点成功输出,则判断右子节点是否是不可输出,如果是,则根节点也设置为不可输出
             else if (root->right->index == 0) {
                 root->index = 0;
             }
         }//左子节点成功输出,则判断左子节点是否是不可输出
         else if (root->left->index == 0) {
             // 如果是, 则根节点也设置为不可输出
             if (root->right == NULL || root->right->index == 0) {
                 root->index = 0;
             }
         }
         return 1;
     } 
};
int main() {
    while (1) {
        BiTree bi(cin);
        bi.show();
    }
}





