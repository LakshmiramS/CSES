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
    int n, x;
    cin >> n >> x;
    vector<int> coins(n);
    for(int i=0;i<n;i++){
        cin>>coins[i];
    }
    vector<int> prev(1+x,0);
    prev[0] = 1;
    for(int j=n-1;j>=0;j--){
        prev[0] = 1;
        for(int sum=1;sum<=x;sum++){
            ll one = prev[sum];
            ll two = sum-coins[j] >= 0 ? prev[sum-coins[j]] : 0 ;
            ll ssum = one + two;
            prev[sum] = ssum >= mod ? ssum-=mod: ssum;
        }
    }
    cout<<prev[x] <<endl;
}
