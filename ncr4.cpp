// Approach :- 4
// Calculate ncr with modulo 10^9, Here modulo isn't a prime number so we can't do invereses. But we can use
// ncr = n-1cr-1 + n-1cr; -> This will lead to pascal's triangle which we'll be using.

#include<bits/stdc++.h>
using namespace std;

#define int long long

int ncr[1001][1001]; // For storing Pascal's triangle.
int mod = 1e9;

signed main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int n, r;
  cin >> n >> r;
  ncr[0][0] = 1;
  
  for(int i = 1; i <= n; i++){
    for(int j = 0; j <= n; j++){
      if(j == 0) ncr[i][j] = ncr[i-1][j] % mod;
      else ncr[i][j] = (ncr[i - 1][j - 1] + ncr[i - 1][j]) % mod;
    }
  }

  cout << ncr[n][r] << "\n";
  return 0;
}
