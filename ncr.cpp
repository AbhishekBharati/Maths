// Approach :- 1 Instead of Dividing use Inverses :-
#include<bits/stdc++.h>

using namespace std;

#define int long long
int mod = 1e9 + 7;

int binexp(int a, int b, int mod){
  if(b == 0) return 1;
  if(b%2 == 1){
    return a*binexp(a, b - 1, mod)%mod;
  } else {
    int temp = (a*a)%mod;
    return binexp(temp, b/2, mod);
  }
}

int inverses(int a, int mod){
  return binexp(a, mod - 2, mod);
}

int fact[1000100] = {0};

int rec(int x){
  if(x == 0) return 1;
  if(fact[x]){
    return fact[x];
  }
  int ans = (x*rec(x-1))%mod;
  return fact[x] = ans;
}

signed main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  fact[0] = 1;
  int n, r;
  cin >> n >> r;
  int num;
  if(fact[n]){
    num = fact[n];
  } else {
    num = rec(n);
  }
  int den;
  if(fact[n - r]){
    den = fact[n - r];
  } else {
    den = rec(n - r);
  }
  if(fact[r]){
    den *= fact[r];
  } else {
    den *= rec(r);
  }
  den = inverses(den, mod);
  int ans = (num*den)%mod;
  cout << ans << "\n";
  return 0;
}
