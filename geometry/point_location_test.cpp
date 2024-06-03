//
// Created by lakshmiram  on 01/06/24.
//
#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
void solve(){
    ll a,b,c,d,e,f;
    cin >>a >> b >> c >> d >> e >> f;
    ll x1 = c-a;
    ll x2 = e - a;
    ll y1 = d - b;
    ll y2 = f - b;
    ll temp = x1 * y2 - x2 * y1;
    if(temp > 0){
        cout << "LEFT" << endl;
    }
    else if(temp == 0){
        cout << "TOUCH" << endl;
    }
    else{
        cout << "RIGHT" << endl;
    }
    return;
 
}
int main(){
    int tt;
     cin >> tt;
     while(tt--){
         solve();
     }
 
}
