#include <vector>
#include <iostream>
#include <stack>
#include <queue>
#include <cmath>
#include <algorithm>
#include <string>
#include <set>
#include <climits>
#define forloop(n) for(int i=0;i<n;i++)
#define MOD 1000000007
#define long long ll
using namespace std;
void inputArray(int a[],int n){
  for(int i=0;i<n;i++){
  cin>>a[i];
  }
}
//used for finding union of two sets(tree form set use in kruskals algortihm ) with parent v,u
void myUnion(int a[],int v,int u){
  if(a[v]<a[u]){
    a[v]=a[u]+a[v];
    a[u]=v;
  }
  else{
    a[u]=a[u]+a[v];
    a[v]=u;
  }
  return ;
}
void floydWarshall(int a[][1000],int n){
  for(int k=0;k<n;k++){
    for(int i=0;i<n;i++){
      for(int j=0;j<n;j++){
        a[i][j]=min(a[i][j],a[i][k]+a[k][j]);
      }
    }
  }
}

int edgeno(int graph[][1000],int n){
  int edges=0;
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      if(graph[i][j]!=0){
        edges++;
      }
    }
  }
  return edges;
}
// void dijkstra(int a[],int start )
// bellmanFord using adjancy matrix and assuming directed graph
// the graph    n->no of vertices cost[]->for storing the cost of path from start to an edge  start-> the starting index
void bellmanFord(int graph[][1000],int n,int cost[],int start){
  int e=edgeno(graph,n);
  int edges[e][2]={0};
  int x=0;
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      if(graph[i][j]!=0){
        edges[x][0]=i;
        edges[x][1]=j;
        x++;
      }
    }
  }
  for(int i=0;i<n;i++){
    if(i==start){
      cost[i]=0;
    }
    else{
      cost[i]=10000000;
    }
  }
  for(int i=0;i<n-1;i++){
  for(int i=0;i<e;i++){
    cost[edges[i][1]]=min(cost[edges[i][1]],cost[edges[i][0]]+graph[edges[i][0]][edges[i][1]]);
  }
}



}
// for finding parent of a given element of a set in kruskals algorithm
int myFind(int a[],int v){
  while(a[v]>0){
    v=a[v];
  }
  return v;
}

void printArray(int a[],int n){
  for(int i=0;i<n;i++){
    cout<<a[i]<<" ";
  }
  cout<<endl;
}


void modified_dfs(int a[][1000],int i,int j,int n,int marked[][1000]){

	for(int col=0;col<n;col++){
		if(a[i][col] && marked[i][col]==0){
			marked[i][col]=1;
			modified_dfs(a,col,i,n,marked);
		}
	}
}

void print2Darray(int a[][1000],int rowno,int colno){
	for(int i=0;i<rowno;i++){
		for(int j=0;j<colno;j++){
			cout<<a[i][j]<<" ";
		}
		cout<<endl;
	}
}
void input2Darray(int a[][1000],int rowno,int colno){
	for(int i=0;i<rowno;i++){
		for(int j=0;j<colno;j++){
			cin>>a[i][j];
		}
	}
}
//SEGMENT tree
//size 4*n+1(n->no of elements in array)
  //array for which tree is needed  ;tree->array on which tree is stored; start->starting index of a,treeIndex->index of tree at which sum of a form start to end is stored
void buildTreeSum(int a[],int tree[],int start,int end,int treeIndex){
  if(start==end){
    tree[treeIndex]=a[start];
    return ;
  }
  int mid=(start+end)/2;
  buildTreeSum(a,tree,start,mid,2*treeIndex);
  buildTreeSum(a,tree,mid+1,end,2*treeIndex+1);
  tree[treeIndex]=tree[2*treeIndex]+tree[2*treeIndex+1];
}
// o(n)
void buildTreeMin(int a[],int tree[],int start,int end,int treeIndex){
  if(start==end){
    tree[treeIndex]=a[start];
    return ;
  }
  int mid=(start+end)/2;
  buildTreeMin(a,tree,start,mid,2*treeIndex);
  buildTreeMin(a,tree,mid+1,end,2*treeIndex+1);
  tree[treeIndex]=min(tree[2*treeIndex],tree[2*treeIndex+1]);
}
// Return min element of array a(tree as the corresponding tree) from index l to r
//o (log n)
int queryMin(int tree[],int treeIndex,int s,int e,int l,int r){
  //No overlap
  if(r<s || l>e){
    return INT_MAX-1;
  }
  // Complete overlap (query set is superset of [s,e])
  else if(l<=s && r>=e){
    return tree[treeIndex];
  }
  //Partial overlap
  int mid=(s+e)/2;
  int left=queryMin(tree,2*treeIndex,s,mid,l,r);
  int right=queryMin(tree,2*treeIndex+1,mid+1,e,l,r);
  return min(left,right);

}

//                                                         i->index of array a(for which tree is updated) at which update is to done
//                                                          value->value to which the update is to be done
// o(log n)
void updateNode(int tree[],int treeIndex,int start,int end,int i,int value){
  // i is not in this range(subtree)
  if(s>i || e<i){
    return ;
  }
  // s==e==i(reach the node at which update is to be done)
  if(s==e==i){
    tree[treeIndex]=value;
    return ;
  }
  //Partial overlap calling left and right subtree
  int mid=(start+end)/2;
  updateNode(tree,treeIndex,start,mid,i,value);
  updateNode(tree,treeIndex,mid+1,end,i,value);
  tree[treeIndex]=min(tree[2*treeIndex],tree[2*treeIndex+1]);
  return;


}
// o(n)
void updateRange(int tree[],int treeIndex,int start,int end,int l,int r,int value){
  // no overlap
  if(r<s || l>e){
    return ;
  }
  // we get to a particular node of the range(l,r)
  if(s==e){
    tree[treeIndex]+=value;
    return;
  }
  //partial and complete overlap (call both sides)
  int mid=(start+end)/2;
  updateRange(tree,2*treeIndex,start,mid,l,r,value);
  updateRange(tree,2*treeIndex+1,mid+1,end,l,r,value);
  tree[treeIndex]=min(tree[2*treeIndex],tree[2*treeIndex+1]);
  return;
}

int count2=0;
void floodFill(char graph[][100],int i,int j,int n){
	if(i<0 || i>=n || j<0 || j>=n){
		return;
	}
	if(graph[i][j]=='1'){

	graph[i][j]='0';
	count2++;
	floodFill(graph,i+1,j,n);
	floodFill(graph,i-1,j,n);
	floodFill(graph,i,j-1,n);
	floodFill(graph,i,j+1,n);
	}
	else{
		return;
	}


	}

int main(){

	 // int t;
	 // cin>>t;
	 // for(int x=0;x<t;x++){
   //


		// int n;
		// cin>>n;
   //
	 // }




  return 0;
}
