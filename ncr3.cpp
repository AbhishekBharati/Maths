// What if n <= 10^9, & r <= 20. Here fact(n) won't work coz looping till 10^9 will give us a TLE. ao will use 
// Approach 3;

#include<bits/stdc++.h>
using namespace std;

#define int long long
int mod = 1e9 + 7;

int binexp(int a, int b){
  if(b==0) return 1;
  if(b%2 == 1) return a*binexp(a, b - 1)%mod;
  else {
    int temp = (a*a)%mod;
    return binexp(temp, b/2)%mod;
  }
}

int inverse(int a){
  return binexp(a, mod - 2);
}

signed main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int n, r;
  cin >> n >> r;
  int num = 1;
  int den = 1;
  for(int i = 0; i < r; i++){
    num *= (n - i)%mod;
    den *= (i + 1)%mod;
  }

  int ans = (num * inverse(den)%mod)%mod; 
  cout << ans << "\n";
  return 0;
}

