#include <iostream>
using namespace std;


// heap => Complete(almost complete) Binary tree(generally)
//max heap =>every node should have elements greater than or equal to its descendants
//min heap =>every node should have element less than or equal to its descendants
// height=>ceil(log(n))

//insertion takes o(logn) time per insertion
// for creation call insertion funcion repeatedly
// in place heap creation
void heapInsert(int a[],int n){
  int i=n;
  int temp=a[n];
  while(i>1 && temp>a[i/2]){
    a[i]=a[i/2];
    i=i/2;
  }
  a[i]=temp;
}
//                   n->index of last element of array
//              size of array should be at least 2+n
void heapCreate(int a[],int n){
  for(int i=2;i<=n;i++){
    heapInsert(a,i);
  }
}
// only largest element (root ) is to deleted in a heap
int heapDelete(int a[],int n){
  int temp,i=1,j=2*i;
  temp=a[n];
  swap(a[1],a[n]);
  //size of heap becomes n-1
  while(j<=n-1){
    if(a[j]<a[j+1] && j<n-1 ){
      j=j+1;
    }
    if(a[i]<a[j]){
      swap(a[i],a[j]);
      i=j;
      j=2*j;
    }
    else{
      break;
    }
  }
  return a[n];
}
void heapSort(int a[],int n){
    for(int i=0;i<=n-2;i++){
        heapDelete(a,n-i);
    }
    return;

}
// IMP-> if we go on deleting elements from a heap then the elements will be sorted(in increasing order)
// HEAP sort (o(nlogn))
// 1.create an heap from the array which is to be sorted
// 2. delete all elements from the heap
int main()
{
  //insertion in max heap
  // int array in which our tree(ADT) will be stored in 2*i and 2*i+1 manner
  int a[10]={0,1,2,12,3,5,67,7,0,0};
  //elements are no there=>0
  //size of heap is 7
  // for inserting first insert after last non zero index of array
  // call insert function with a,n=>index of a at which new element is inserted

  heapCreate(a,7);
  heapSort(a,7);
  for(int i=1;i<=7;i++){
    cout<<a[i]<<" ";
  }
  return 0;
}

//PRIORITY queue using heap
// create an heap in o(nlogn) or o(n)
// delete elements whenever needed to be removed in o(nlogn)


// create heap according to the PRIORITY
// always keep higher value element at root and decreasing PRIORITY element at lower levels
// if larger value means higher PRIORITY => use  a max heap
// else use min heap
