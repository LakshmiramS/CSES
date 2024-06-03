//
// Created by lakshmiram  on 28/04/24.
//
#include<iostream>
#include<algorithm>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
 
void solve() {
    ll row, col;
    cin >> row >> col;
    ll layer = max(row, col);
    if (layer % 2 != 0) {
        if (row >= col) {
            cout << (layer - 1) * (layer - 1) + col;
        } else {
            cout << layer * layer - row + 1;
 
        }
    }
    else {
        if (col >= row) {
            cout << (layer - 1) * (layer - 1) + row;
        } else {
            cout << layer * layer - col + 1;
        }
    }
    cout << endl;
    return;
}
int main(){
    int tt;
    cin >> tt;
    while(tt--){
        solve();
    }
}
