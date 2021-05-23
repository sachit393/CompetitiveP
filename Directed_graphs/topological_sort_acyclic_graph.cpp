#include <iostream>
#include <stack>
#include <vector>
using namespace std;

stack <int> s;

void topologicalSort(int a[100][100],int i,int n,int marked[]){
    if(marked[i]==2){
        return ;
    }
    if(marked[i]==1){
        cout<<"cycle"<<endl;
        return ;
    }

    marked[i]=1;
    for(int col=0;col<n;col++){
        if(a[i][col] && col!=i){

            topologicalSort(a,col,n,marked);

        }
    }
    marked[i]=2;
    s.push(i);

}

void findPath(vector<int> v,int paths[],int graph[][100],int n){
  paths[v[0]]=1;
  for(int  i=1;i<n;i++){
    for(int j=0;j<n;j++){
      if(graph[j][v[i]]){
        paths[v[i]]+=paths[j];
      }
    }
  }
  return ;
}

int main(){
    vector <int> v;
    int n;
    cin>>n;
    int graph[100][100]={0};
    int marked[10]={0};
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>graph[i][j];
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(graph[i][j]!=0 && !marked [i]){
                topologicalSort(graph,i,n,marked);
            }
        }
    }
    while(!s.empty()){
        v.push_back(s.top());
        s.pop();
    }
    int paths[n]={0};
    findPath(v,paths,graph,n);
    for(int i=0;i<n;i++){
      cout<<paths[i]<<" ";
    }
    return 0;
}
