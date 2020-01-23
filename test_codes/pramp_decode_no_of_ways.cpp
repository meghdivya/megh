#include<iostream>
using namespace std;
//12
//AB //L
//138   dp[0] = 1, dp[1] = dp[0] +1 /2, dp[2] = dp[1]     A, AC, M
int helper_dp(const string& S) {
  int dp[S.size() +1];
  dp[0] = 0;
  dp[1] = 1;
  for(int i=1; i<S.size(); i++) {
    if (S[i] == '0') {
      if(S[i-1] > '2') {
        dp[i+1] = 0;
      }
      else {
        dp[i+1] = dp[i];
      }
    }
    else if(S[i] < '7' && S[i-1] < '3') {
      dp[i+1] = dp[i] + dp[i-1];
    }
    else {
      dp[i+1] = dp[i];
    }
  }
  return dp[S.size()];
}
int main() {
    string S;
    cin>>S;
    cout<<helper_dp(S)<<endl;
    return 0;
}
