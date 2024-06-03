#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
int mod = 1e9 + 7;
int main(){
    int n;
    cin >> n;
    vector<ll> dp(1+n);
    dp[0] = 1;
    for(int i=0;i<=n;i++){
        for(int j = 1;j<=6;j++){
            if(i+j<=n) dp[i+j] = (dp[i+j] + dp[i]) % mod;
        }
    }
    cout<<dp[n]<<endl;
}
