#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
int mod = 1e9 + 7;
const int INF = 1e9 + 5;
int main(){
    int n, x;
    cin >> n >> x;
    vector<int> c(n);
    for(int i=0;i<n;i++){
        cin >> c[i];
    }
    vector<int> dp(1+x, INF);
    //dp[i] = min no of coins to achieve a sum of i, -1 if not possible
    dp[0] = 0;
    for(int i=0;i<=x;i++){
        for(int val : c){
            if(i-val>=0) dp[i] = std::min(dp[i] , 1 + dp[i-val]);
        }
    }
    int ans = (dp[x] == INF) ? -1 : dp[x];
    cout << ans << endl;
 
}
