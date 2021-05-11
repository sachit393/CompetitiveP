// GENERAL BINARY TREE
// a node can have 0,1,2 children
// height=level-1
// no of different(unlabelled) binary trees with 'n' nodes =>2nCn/(n+1)= T(n) =sigma(T(n-i)*T(i))  1<=i<=n-1
// no of different(unlabelled) binary trees with 'n' nodes =>(2nCn/(n+1))*n!

//Height vs Nodes

// for given height min no of nodes => h+1
// for given height max no of nodes =>2^(h+1)-1

// in general in coding log is always base 2

// for given no of nodes min height =>ceil(log(n+1)-1)
// for given no of nodes max height =>n-1
// log(n+1)-1<=h<=n-1
// h+1<=n<=2^(h+1)-1

// no of nodes with deg(2)+1=no of nodes with deg(0)  (for any binary tree)

//STRICT /PROPER BINARY tree
// a node can have 0 or 2 children

//Height vs nodes
// for a given height min no of nodes=>(2*h+1)
// for a given height max nodes =>2^(h+1)-1

// for given no of nodes min height =>ceil(log(n+1)-1)
// for a given no of nodes max height=>(n-1)/2

//  ceil(log(n+1)-1)<=h<=(n-1)/2

// for a strict binary tree
//e=i+1
//e-> external(leaf nodes)
//i->internal nodes

// FULL TREES(binary trees with max nodes for given height )
// n=2^(h+1)-1

//COMPLETE BINARY TREES(also called almost complete)

// if the tree is represented in an array using level order method their should be no blank
// spaces in middle of array
// IN other words =>
// a complete binary tree of height h is a full binary tree upto height h-1 AND in the last level, leaves are their starting from left to right

// Note-> all full binary trees are complete binary trees

// ARRAY REPRESENTATION OF BINARY TREES
// write elements of tree in array levele by level
// children of ith index is given by 2*i and 2*i+1
// parent of ith child is given by i/2 (integer division)
// ONly complete binary trees can be represented by this manner


// LINKED REPRESENTATION
// n nodes=> n+1 null pointers(for any general binary tree)

// BINARY TREE TRAVERSAL
//PREORDER->1. visit
//          2. preorder(lchild)
//          3. preorder(rchild)
//INORDER ->1. inorder(lchild)
//            2. visit(node)
//            3. inorder(rchild)
//POSTORDER ->1.postorder(lchild)
//            2.postorder(rchild)
//            3.visit(node)
//LEVELORDER


//PROGRAM FOR CREATION OF BINARY TREE

#include<iostream>
#include <queue>
#include <stack>
using namespace std;

class node{
  public:
  node* lchild;
  node* rchild;
  int value;
};
queue <node*> q;

void preorder(node* root){
	cout<<root->value<<" ";
	if(root->lchild){
		preorder(root->lchild);
	}
	if(root->rchild){
		preorder(root->rchild);
	}

}
void postorder(node* root){

	if(root->lchild){
		postorder(root->lchild);
	}

	if(root->rchild){
		postorder(root->rchild);
	}
	cout<<root->value<<" ";
}

void inorder(node* root){

	if(root->lchild){
		inorder(root->lchild);
	}
	cout<<root->value<<" ";
	if(root->rchild){
		inorder(root->rchild);
	}

}


node* createBinaryTree(){
  int temp=0;
  cout<<"ENTER ROOT VALUE"<<endl;
  cin>>temp;
  node* p=new node;
  node* root=p;
  node*t;
  p->value=temp;
  q.push(p);
  while(!q.empty()){
  	p=q.front();
  	q.pop();
  	cout<<"Enter left child of "<<p->value<<endl;
  	cin>>temp;
  	if(temp!=-1){
  		t=new node;
  		t->value=temp;
  		t->lchild=NULL;
  		t->rchild=NULL;
  		p->lchild=t;
  		q.push(t);
	  }
	cout<<"Enter right child of "<<p->value<<endl;
  	cin>>temp;
  	if(temp!=-1){
  		t=new node;
  		t->value=temp;
  		t->lchild=NULL;
  		t->rchild=NULL;
  		p->rchild=t;
  		q.push(t);
	  }
  }
  return root;
}
// iterative preorder
void iPreorder(node* root){
  stack <node*> s;
  node* p=root;
  while(p || !s.empty()){
    if(p){
      s.push(p);
      cout<<p->value<<endl;
      p=p->lchild;
    }
    else{
      p=s.top();
      s.pop();
      p=p->rchild;
    }
  }
}

void iInorder(node* root){
  node* p=root;
  stack <node*> s;
  while(p || !s.empty()){
    if(p){
      s.push(p);
      p=p->lchild;
    }
    else{
      p=s.top();
      s.pop();
      cout<<p->value<<endl;
      p=p->rchild;
    }
  }
}

void iPostorder(node* root){
  node* p=root;
  stack <int> s1;
  stack <int> s2;
  s.push(p);
  while(s1.empty()){
    p=s1.top();
    s2.push(p);
    s1.pop();
    if(p->rchild){
      s1.push(p->rchild);
    }
    if (p->lchild){
      s1.push(p->lchild);
    }
  }

  while(!s.empty()){
      cout<<s.top()->value<<" ";
      s.pop();
  }
}

void iPostorder(node* root){
    node* p=root;
    stack <node*> s1;
    stack <node*> s2;
    s1.push(p);
    while(!s1.empty()){
        p=s1.top();
        s2.push(p);
        s1.pop();

        if (p->lchild){
            s1.push(p->lchild);
        }
        if(p->rchild){
            s1.push(p->rchild);
        }
    }

    while(!s2.empty()){
        cout<<s2.top()->value<<" ";
        s2.pop();
    }
}

int main(){

  	node* root=createBinaryTree();
  	preorder(root);
  	cout<<endl;
  	inorder(root);
  	cout<<endl;
  	postorder(root);




  return 0;
}
