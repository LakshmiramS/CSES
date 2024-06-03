//
// Created by lakshmiram  on 02/06/24.
//
#include<iostream>
#include<utility>
#include<algorithm>
using namespace std;
typedef long long ll;
void solve(){
    ll a; ll b;
    cin >> a >> b;
    if((a+b)%3!=0){
        cout << "NO" << endl;
    }
    else {

        while (a > 0 && b > 0) {
            if (a > b)
                swap(a, b);
            ll temp = min(a, b / 2);
            a = a - temp;
            b = b - 2 * temp;
        }
        if (a == 0 && b == 0) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
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
