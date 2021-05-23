#include <iostream>
#include <bits/stdc++.h>

#define ll long long
using namespace std;



ll nCr(ll n, ll r)
{

    // p holds the value of n*(n-1)*(n-2)...,
    // k holds the value of r*(r-1)...
    ll p = 1, k = 1;

    // C(n, r) == C(n, n-r),
    // choosing the smaller value
    if (n - r < r)
        r = n - r;

    if (r != 0) {
        while (r) {
            p *= n;
            k *= r;


            ll m = __gcd(p, k);

            p /= m;
            k /= m;

            n--;
            r--;
        }

    }

    else
        p = 1;


    return p;
}

int main()
{
  ll n;ll r;
  cin>>n>>r;
  cout<<nCr(n,r);



}
