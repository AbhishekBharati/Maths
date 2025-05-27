#include <bits/stdc++.h>
using namespace std;

#define int long long

int fact[1000100];

int rec(int x){
  if(x == 0) return 1;
  if(fact[x]){
    return fact[x];
  }
  int ans = x*rec(x-1);
  return fact[x] = ans;
}

signed main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int x;
  cin >> x;
  if(fact[x]){
    cout << fact[x] << "\n";
    return 0;
  }
  cout << rec(x) << "\n";
  return 0;
}
