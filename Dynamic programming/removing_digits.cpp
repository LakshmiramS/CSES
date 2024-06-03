//
// Created by lakshmiram  on 10/12/23.
//
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
int mod = 1e9 + 7;
const int INF = 1e9 + 5;
int main(){
   int n;
   cin >> n;
   vector<int> dp(1+n, INF);
   dp[0] = 0;
   for(int i = 1;i<=n;i++){
       int num = i;
       while(num>0){
           int digit = num%10;
           dp[i] = min(dp[i], 1+dp[i-digit]);
           num /= 10;
       }
 
   }
   cout<<dp[n]<<endl;
}
