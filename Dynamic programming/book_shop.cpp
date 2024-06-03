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
 
int main() {
    int n,x;
    cin >> n >> x;
    //dp[n][w] = greatest number of pages(val) you can get with n books and price constraint (wt limit) of w;
    //dp[n][w] = max(val[n] + dp[n-1][w-wt[i]], dp[n-1][w]);
    //dp[n][x]
    vector<int> val(n+1,0), wt(n+1,0);
    val[0] = 0;
    wt[0] = 0;
    for(int i=1;i<=n;i++){
        cin>>wt[i];
    }
    for(int i=1;i<=n;i++){
        cin>>val[i];
    }
    vector<int> dp(x+1,0);
    for(int item=1;item<=n;item++){
        for(int w=x;w>=0;w--){
            dp[w] = std::max((w-wt[item]>=0 ? (val[item] +  dp[w-wt[item]]) : 0), dp[w]);
        }
    }
    cout<< dp[x] << endl;
}
