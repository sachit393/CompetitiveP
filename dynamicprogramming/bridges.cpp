#include <iostream>
#include <algorithm>
using namespace std;
bool isValid(int i,int j,int a[],int b[]){
  if((a[i]<=a[j] && b[i]<=b[j]) || a[i]>=a[j] && b[i]>=b[j]){
    return true;
  }
  return false;
}


int main(){
  int t;
  cin>>t;
  for(int i=0;i<t;i++){
    int n;
    cin >> n;
    int a[n+1];
    for (int i=1;i<=n;i++){
      cin>>a[i];
    }
    int b[n+1];
    for(int j=1;j<=n;j++){
      cin>>b[j];
    }

    int dp[n+1]={0};
    dp[1]=1;
    for(int i=1;i<=n;i++){
    	for(int j=1;j<n-i+1;j++){
    		if(a[j]>a[j+1]){
    			swap(a[j],a[j+1]);
    			swap(b[j],b[j+1]);
			}
			else if(a[j+1]==a[j]){
				if(b[j]>b[j+1]){
					swap(b[j],b[j+1]);
				}
			}
		}
	}
    for (int i=2; i <=n; i++) {
      for(int j=i-1;j>0;j--){
        if(isValid(j,i,a,b)){
          dp[i]=dp[j]+1;
          break;
        }
        else{
          dp[i]=1;
        }
      }
    }
    sort(dp+1,dp+n+1);
    cout<<dp[n]<<endl;


  }
  return 0;
}




  return 0;
}
