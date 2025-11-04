/**
 *    author:  sow72567555
**/
#include <bits/stdc++.h>
 
using namespace std;

using ll = long long;
 
#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 42
#endif
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin>>t;
  while(t--){
    int n;
    cin>>n;
    vector<ll> a(n), c(n);
    ll s=0;
    for(int i=0; i<n; i++) cin>>a[i];
    for(int i=0; i<n; i++) {
        cin>>c[i];
        s+=c[i];
    }
    vector<ll> dp(n+1, 0);
    dp[0]=c[0];
    ll maxdp=dp[0];
    for(int i=1; i<n; i++){
        ll best=0;
        for(int j=0; j<i; j++){
            if (a[j]<=a[i]) best = max(best, dp[j]);
        }
        dp[i]=c[i]+best;
        if (maxdp<dp[i]) maxdp=dp[i];
    }
    cout<<s-maxdp<<"\n";
  }
}