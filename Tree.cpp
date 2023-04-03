#include <iostream>
#include <stack> 
using namespace std;

typedef struct TreeNode{
	char data;
	TreeNode * lc;
	TreeNode * rc;
}TreeNode;				//�������ṹ�� 

void CreateTreeNode(TreeNode *&t){		//���򴴽������� 
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

int countLeaf(TreeNode * t){		//����Ҷ���� 
	if(t==NULL)
		return 0;
	int n = countLeaf(t->lc);
	int m = countLeaf(t->rc);
	if(n==0&&m==0)
		return 1;
	return n+m;
	
}

int countD(TreeNode *t){		//�����Ϊ2�Ľڵ��� 
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

void middle(TreeNode*t){		//������������� 
	if(!t){
		cout<<"BitTree is empty."<<endl;
	}
	stack<TreeNode*>st;

	TreeNode * p = t;
	while(p||!st.empty()){
		if(p){				//�ڵ�ǿ�,��ջ������������ 
			st.push(p);
			p = p->lc;
		}
		else{				//�������գ��ڵ��ջ���˻ؽڵ㣬���������� 
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
       if(p){  //��ָ����ջ������������
           s.push(p);
           p=p->lc;
       }
       else{ //��ָ����ջ�����ʽ�㣬����������
           p=s.top();
		   s.pop();
           cout<<p->data;   //���ʽ��
           p=p->rc;
       }
}

int main(){
	TreeNode *root;
	CreateTreeNode(root);
	middle(root);
	cout<<countLeaf(root)<<endl;
	cout<<countD(root)<<endl;
	return 0;
}

