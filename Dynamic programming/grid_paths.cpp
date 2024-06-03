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
    //dp[i][j] = no of ways to get to i,j from 0,0
    //dp[i][j] = dp[i-1][j] + dp[i][j-1]
    vector< vector<int> > dp(n, vector<int>(n,-1));
    dp[0][0] = 1;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            char c;
            cin >> c;
            if(c=='.'){
                int left =  j-1>=0 ? dp[i][j-1] : 0;
                int up = i-1>=0 ? dp[i-1][j] : 0;
                if(i==0 and j==0) dp[i][j] = 1;
                else dp[i][j] = (up + left) % mod;
            }
            else if(c=='*') dp[i][j] = 0;
 
        }
        cout<<endl;
    }
    cout << dp[n-1][n-1] % mod << endl;
 
}
