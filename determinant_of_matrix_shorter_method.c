#include <stdio.h>
//o(n^2)
int main(){
  int n;
  scanf("%d", &n);
  int matrix[100][100];
  int ans=0;
  int product=1;
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      scanf("%d",&matrix[i][j]);
    }
  }
  for(int col=0;col<n;col++){
    product=1;
    for(int i=0;i<n;i++){
      product*=matrix[i][(col+i)%n];
    }
    ans+=product;
  }
  for(int col=0;col<n;col++){
    product=1;
    for(int i=0;i<n;i++){
      product*=matrix[n-1-i][(col+i)%n];
    }
    ans-=product;
  }
  printf("%d",ans);
}
