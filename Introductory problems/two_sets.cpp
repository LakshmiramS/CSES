//
// Created by lakshmiram  on 02/06/24.
//
#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
int main(){
    ll n;
    cin >> n;
    ll fullsum = n * (n + 1)/2;
    if(fullsum % 2){
        cout << "NO" << endl;
        return 0;
    }
    else{
        ll halfsum = fullsum / 2;
        vector<bool> a(n+1);
        for(int i=1;i<=n;i++){
            a[i] = false;

        }
        ll truecount = 0;
        ll i = n;
        while(halfsum){
            if(halfsum >= i){
                halfsum -= i;
                a[i] = true;
                truecount++;
                i--;
            }
            else{
                a[halfsum] = true;
                truecount++;
                halfsum = 0;
            }
        }
        cout << "YES" << endl;
        cout << truecount << endl;
        for(int i=1;i<=n;i++){
            if(a[i] == true){
                cout << i << " ";
            }
        }
        cout << endl;
        cout << n - truecount << endl;
        for(int i=1;i<=n;i++){
            if(a[i] != true){
                cout << i << " ";
            }
        }


    }
}