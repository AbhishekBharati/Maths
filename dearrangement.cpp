#include <bits/stdc++.h>
using namespace std;

#define int long long
int MOD = 1e9 + 7;
int dearrange[1000100];

void computeDearrangement(int n){
  dearrange[2] = 1;
  dearrange[1] = 0;
  for(int i = 3 ; i <= n; i++){
    dearrange[i] = ((i - 1)*(dearrange[i - 1] + dearrange[i - 2]))%MOD;
  }
}

signed main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int n; cin >> n;
  computeDearrangement(n);
  cout << dearrange[n] << "\n";
}
