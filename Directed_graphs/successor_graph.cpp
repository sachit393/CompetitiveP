//GRAPHS in which each vertices has outdegree exactly once
//contains one or more components
//THEY ALWAYS CONTAIN ONE CYCLE
#include <iostream>
#include <map>
#include <bits/stdc++.h>
using namespace std;

int successor(int graph[][100],int size,int n,int steps){
    if(steps==0){
        return n;
    }
    for(int col=0;col<size;col++){
        if(graph[n][col]){
            return successor(graph,size,col,steps-1);
        }
    }
    return -1;
}

void cycleDetector(int graph[][100],int n,int start){
    map <int,int> vertices;
    int i=start;
    int x=0;
    while(1){
        if(vertices.count(i)){
            cout<<i<<endl;
            cout<<x-vertices[i];
            return ;
        }
        vertices[i]=x;
        x++;
        i= successor(graph,n,i,1);
    }
}

int main(){
    int n;
    cin>>n;
    int graph[100][100];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>graph[i][j];
        }
    }
    //CONSIDERING INPUT TO BE SUCCESSOR GRAPH
    cycleDetector(graph,n,1);
    //detect the first cycle and its length starting from vertex 'start'



    return 0;
}
