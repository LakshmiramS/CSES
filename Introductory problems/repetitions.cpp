//
// Created by lakshmiram  on 16/02/24.
//
#include<iostream>
#include<string>
using namespace std;
int main(){
    string s;
    cin >> s;
    s += 'B';
    int ans = 0;
    char curr = ' ';
    int curr_count = 0;
    for(char c : s){
        if(c != curr){
            curr = c;
            ans = max(ans, curr_count);
            curr_count = 1;
        }
        else{
            curr_count++;
        }
    }
    cout << ans << endl;



}
