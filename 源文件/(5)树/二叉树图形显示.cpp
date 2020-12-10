#include <iostream>
#include <vector>//顺序表
#include <queue>//队列
#include <cmath>
#include <cstdlib>
#include <ctime>
using namespace std;
struct TreeNode //二叉树节点类
{
    char val;
    int x, y;
    int index=1;//为0则是叶子结点 为1则不是
    TreeNode* left;
    TreeNode* right;
    TreeNode(char v) : val(v), left(0), right(0), x(0), y(0) {}

};
class BiTree {
    class PrintArray //存放二叉树图形的数组
    {
    public:
        char** array;  //指向二维数组
        int length;
        int height;
        //提供长与宽
        PrintArray(TreeNode* root) { //通过一个二叉树给输出数组赋值
            //初始化数组长度和高度
            this->length = 0;
            BiTree::return_lenght(root, this->length);
            BiTree::return_height(root, this->height);
            array = new char* [height];    //动态创建一个二维数组 默认元素都为空格
            for (int i = 0; i < height; i++) {
                array[i] = new char[length];
            }
            for (int i = 0; i < height; i++) {
                for (int j = 0; j < length; j++) {
                    array[i][j] = ' ';
                }
            }


            //层次遍历给数组赋值

            queue<TreeNode*> queue;
            if (root == NULL) {
                return;
            }
            queue.push(root);
            while (!queue.empty()) {
                if (queue.front() == NULL) {
                    queue.pop();
                    continue;
                }
                queue.push(queue.front()->left);
                queue.push(queue.front()->right);
                array[queue.front()->x][queue.front()->y] = queue.front()->val;



                if (queue.front()->left != NULL) {
                    array[queue.front()->x + 1][queue.front()->y - 1] = '/';
                }
                if (queue.front()->right != NULL) {
                    array[queue.front()->x + 1][queue.front()->y + 1] = '\\';
                }

                queue.pop();
            }

        }

        ~PrintArray()
        {
            for (int i = 0; i < height; i++)
                delete[] array[i];
            delete[] array;

        }
        void show() {
            for (int i = 0; i < height; i++) {
                cout << "            ";
                for (int j = 0; j < length; j++) {
                    cout << array[i][j];
                }
                cout << endl;
            }
        }

    };

public:
    //默认初始化一个空的二叉树
    BiTree() :root(NULL) {}
    //将一个数组实现的二叉树变成链表实现的二叉树
    BiTree(vector<char>& v) {
        root = CreateBiTree(v);
    }

    BiTree(istream& is) {
        int maxSize;
        cout << "输入二叉树的长度" << endl;
        is >> maxSize;
        //  int maxSize = pow(2, n ) - 1;
        vector<char> v1(100, '#');
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

    TreeNode* returnroot() {
        return root;
    }


    //二叉树的先序遍历
    static void preorderTraversal(TreeNode* root) {
        if (root == NULL) {
            return;
        }
        cout << "->" << root->val;
        preorderTraversal(root->left);
        preorderTraversal(root->right);


    }
    //二叉树的中序遍历
    static void inorderTraversal(TreeNode* root) {
        if (root == NULL) {
            return;
        }
        inorderTraversal(root->left);
cout << "->" << root->val;
inorderTraversal(root->right);


    }
    //二叉树的后序遍历
    static void postorderTraversal(TreeNode* root) {
        if (root == NULL) {
            return;
        }
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        cout << "->" << root->val;
    }



    //二叉树的图形化输出

    void showDraw() {
        PrintArray pa(root);
        cout << "图形输出为:" << endl;



        pa.show();
    }

private:
    // 创建二叉树
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
    //层次遍历赋给每个元素x坐标 
    static void return_height(TreeNode* root, int& t) {
        typedef  pair<TreeNode*, int>  node_Y;
        queue<node_Y> queue;

        if (root == NULL) {
            return;
        }
        queue.push(node_Y(root, 0));

        while (!queue.empty()) {
            if (queue.front().first == NULL) {

                queue.pop();
                continue;
            }
            queue.push(node_Y(queue.front().first->left, queue.front().second + 1));
            queue.push(node_Y(queue.front().first->right, queue.front().second + 1));
            t = queue.front().first->x = queue.front().second * 2;

            queue.pop();

        }
        t++;
    }
    //中序遍历赋给每个元素x坐标 
    static void return_lenght(TreeNode* root, int& i) {

        if (root == NULL) {
            return;
        }
        //遍历左子树
        return_lenght(root->left, i);

        root->y = i;
        i++;
        //遍历右子树
        return_lenght(root->right, i);


    }
    TreeNode* root;
   


    
    
     public:
   
    
    static void preorderTraversal2(TreeNode* root) {
        
        if (root == NULL) {
            return;
        }
        cout << "->" << root->index;
        preorderTraversal2(root->left);
        preorderTraversal2(root->right);


    }

    public: 
     //先序遍历输出一个最左边根到叶子节点的路径
     //当遇到叶子节点,说明输出结束,返回0,
     static  int   printleff(TreeNode* root) {
         //如果根节点为空或者不可输出,则返回0
        if (root == NULL || root->index == 0) {
             return 0;
         }
         //输出该节点数据
         cout << "->" << root->val;
     //输出左子节点,如果左子节点为空或者不能输出,则判断右子节点是否为空或者不能输出,
      //如果右子节点也为空或者不能输出 则根节点也设置为不可输出
         if (printleff(root->left) == 0) {      
             if (printleff(root->right) == 0) {
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
    vector<char> all = {
      'A','B','C','D','E','F','G','H','I','J',
      'K','L','M','N','O','P','Q','R','S','T',
      'U','V','W','X','Y','Z','#','#','#','#',
      '#','#','#','#','#','#','#','#','#','#' };
    char a = 'y';
    int i = 9;
    while (a != 'n') {
        srand(time(0));
        int maxSize = rand() % 10 + 4;
        vector<char> v;
        for (int i = 0; i < maxSize; i++) {
            if (i == 0) {
                int t = rand() % 40;
                while (all[t] == '#') {
                    t = rand() % 40;
                }
                v.push_back(all[t]);
            }
            else {
                v.push_back(all[rand() % 40]);
            }

        }
        for (int i = 0; i < v.size(); i++) {
            if (v[i] == '#') {
                if (2 * i + 1 < v.size()) {
                    v[2 * i + 1] = '#';
                }
                if (2 * i + 2 < v.size()) {
                    v[2 * i + 2] = '#';
                }


            }
        }

        BiTree bi(v);
        bi.showDraw();
        





        while (BiTree::printleff(bi.returnroot())) {
            cout << endl;
        }

        cout << "先序遍历:";
        BiTree::preorderTraversal(bi.returnroot());
        cout << endl;
        cout << "中序遍历:";
        BiTree::inorderTraversal(bi.returnroot());
        cout << endl;
        cout << "后序遍历:";
        BiTree::postorderTraversal(bi.returnroot());
        cout << endl;
        cout << "输出叶子:";
        
        BiTree::preorderTraversal2(bi.returnroot());

        cout << endl << "刷新?(y/n)" << endl;
        cin >> a;

    }
}

