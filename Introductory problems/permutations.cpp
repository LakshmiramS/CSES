//
// Created by lakshmiram  on 16/02/24.
//
#include<iostream>
using namespace std;
int main(){
    int n; cin >> n;
    if(n <= 3){
        cout << "NO SOLUTION" << endl;
        return 0;
    }
    int N = n/2;
    vector<int> a(n);
    for(int i=N;i>0;i--){
        a[i] = 2 * i;
    }
    int m = (n%2 ==0) ? n-1 : n;
    for(int i=1;i<=m;i++){

    }


}