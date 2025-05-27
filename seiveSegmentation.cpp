#include<bits/stdc++.h>
using namespace std;

#define int long long

vector<int> basePrimes(int b){
  int isPrime[1001000];
  for(int i = 2; i*i <= b; i++) isPrime[i] = 1;

  for(int i = 2; i*i <= b; i++){
    for(int j = i*i; j*j <= b; j+=i){
      isPrime[j] = 0;
    }
  }

  vector<int> ans;

  for(int i = 2; i*i <= b; i++){
    if(isPrime[i]) ans.push_back(i);
  }
  return ans;
}

vector<int> primeInRange(int a, int b){
  vector<int> basePrime = basePrimes(b);
  vector<int> isPrime(b - a + 1, 1);
  for(auto prime : basePrime){
    int curMul = ((a + prime - 1)/prime)*prime;
    while(curMul <= b){
      if(curMul != prime){
        isPrime[curMul - a] = 0;
      }
      curMul += prime;
    }
  }

  vector<int> ans;
  for(int i = 0; i < b - a + 1; i++){
    if(isPrime[i]){
      ans.push_back(i + a);
    }
  }
  return ans;
}

signed main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int a, b;
  cin >> a >> b;
  vector<int> ans = primeInRange(a, b);
  for(auto it : ans){
    cout << it << " ";
  }
}
