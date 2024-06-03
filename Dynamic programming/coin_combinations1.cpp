#include<iostream>
#include<vector>
using namespace std;
const int mod = 1e9 + 7;
typedef long long ll;
int main(){
    int n, x;
    cin>>n>>x;
    vector<int> coins(n);
    for(int i=0;i<n;i++){
        cin>>coins[i];
    }
    //dp[sum] = no of ways to reach sum using the given n coins.
    vector<int> dp(1+x,0);
    dp[0] = 1;
    // 0 sum can be reached in exactly one way
    for(int i=0;i<=x;i++){
        for(int val : coins){
            if(i+val<=x) dp[i+val] = (ll)(dp[i+val] + dp[i]) % mod;
        }
 
    }
    cout<<dp[x]<<endl;
}
