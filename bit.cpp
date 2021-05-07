// x=x|(1<<k) -> sets the kth bit(from right) to zero
// x=x|~(1<<k) -> sets the kth bit to zero
// x=x^(1<<k)  -> invert the kth bit
//(0<=k && k<=n-1) for n bit number
// a number 'x' is a power of two iff -> x&(x-1)==0
// x|(x-1) inverts all the bits after last one bit

// SET USING BITS
#include <iostream>
using namespace std;
int main(){
  int x=0;
  x|=1<<1;   // setting the first bit from right (second last from left) to 1=> 1 is in the set
  x|=1<<3;     //=>3 is in the set
  x|=1<<8;
         //returns the no of 1 in binary(no of elements of the set)
  cout<<__builtin__popcount(x)<<endl;
  for(int i=0;i<=31;i++){
    if(x&(1<<i)){
      cout<<1<<" ";
    }
  }
  // set operation(set a and set b)
  //UNION => a|b
  // intersection =>a&b
  // a-b=>a&(~b)
  // complement=>~a
  // hamstring problem => no of different bits (int a and int b)=no of 1's in a^b

  // COUNTING SUBGRIDS
  // o(n^3)
  // int subgrids(int rowno,int colno,int graph[][100]){
  //   int count=0;
  //   int totalcount=0;
  //   for(int row1=0;row1<rowno;row1++){
  //     for(int row2=row1+1;row2<rowno;row2++){
  //       count=0;
  //       for(int col=0;col<colno;col++){
  //         if(graph[row1][col]==1 && graph[row2][col]==1){
  //           count++;
  //         }
  //       }
  //       totalcount+=(count)*(count-1)/2;
  //     }
  //   }
  //   return totalcount;
  // }
  //WE CAN SOLVE THE ABOVE PROBLEM BY o(n^3/N) time (where N is the no of partitions vertical partitions made to the grid)
  // using bitwise operations and __builtin__popcount()


return 0;
}
