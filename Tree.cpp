#include <iostream>
#include <stack> 
using namespace std;

typedef struct TreeNode{
	char data;
	TreeNode * lc;
	TreeNode * rc;
}TreeNode;				//定义数结构体 

void CreateTreeNode(TreeNode *&t){		//先序创建二叉树 
	char c;
	cin>>c;
	if(c == '.')
		t = NULL;
	else
	{
		t = new TreeNode;
		t->data = c;
		CreateTreeNode(t->lc);
		CreateTreeNode(t->rc); 		
	}
			
}

int countLeaf(TreeNode * t){		//计算叶子数 
	if(t==NULL)
		return 0;
	int n = countLeaf(t->lc);
	int m = countLeaf(t->rc);
	if(n==0&&m==0)
		return 1;
	return n+m;
	
}

int countD(TreeNode *t){		//计算度为2的节点数 
	if(t==NULL)
		return 0;
	if(t->lc&&t->rc)
		return 1+countD(t->lc) + countD(t->rc);
	else{
		int n = countD(t->lc);
		int m = countD(t->rc);
		return n+m;
	}
	
}

void middle(TreeNode*t){		//中序遍历二叉树 
	if(!t){
		cout<<"BitTree is empty."<<endl;
	}
	stack<TreeNode*>st;

	TreeNode * p = t;
	while(p||!st.empty()){
		if(p){				//节点非空,入栈，访问左子树 
			st.push(p);
			p = p->lc;
		}
		else{				//左子树空，节点出栈，退回节点，访问右子树 
			p = st.top();
			st.pop();
			cout<<p->data<<' ';
				p = p->rc;
		}
	}
	cout<<endl; 
}

void InTraverse(TreeNode *t){
    TreeNode *p=t;
    stack<TreeNode*>s;
    while(p||!s.empty())
       if(p){  //根指针入栈，遍历左子树
           s.push(p);
           p=p->lc;
       }
       else{ //根指针退栈，访问结点，遍历右子树
           p=s.top();
		   s.pop();
           cout<<p->data;   //访问结点
           p=p->rc;
       }
}

int main(){
	TreeNode *root;
	CreateTreeNode(root);
	middle(root);
	cout<<countLeaf(root)<<endl;
	cout<<countD(root)<<endl;
	//test
	return 0;

	//注释test
}

