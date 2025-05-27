// What if n <= 40, and r <= 40.  THis code will only work for n == 40;
// Approach 2 :-
#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int n, r;
  cin >> n >> r;
  int ans = 1;
  for(int i = 0; i < r; i++){
    ans *= n - i;
    ans /= i + 1;
  }
  cout << ans << "\n";
}
