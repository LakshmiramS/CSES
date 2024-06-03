//
// Created by lakshmiram  on 02/06/24.
//
#include<iostream>
using namespace std;
typedef long long ll;
int main(){
    ll n;
    cin >>n;
    ll ans = 0;
    ll temp = n;
    while(temp > 0){
        ans += temp / 5;
        temp = temp / 5;
    }
    cout << ans << endl;
}