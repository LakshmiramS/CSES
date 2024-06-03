//
// Created by lakshmiram  on 01/06/24.
//
#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
int main(){
    ll k ;
    cin >> k;
    vector<ll> ans(k+1);
    ans[1] = 0;
    ans[2] = 6;
    for(ll i=3;i<=k;i++){
        ans[i]  = (ll)(i*i)*(i*i - 1)/2 - (ll)2*2*(i-3+1)*(i-2+1);
    }
    for(int i=1;i<=k;i++){
        cout << ans[i] << endl;
    }
}
