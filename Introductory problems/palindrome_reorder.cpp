//
// Created by lakshmiram  on 02/06/24.
//
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    string s;
    cin >> s;
    vector<int> alpha(26,0);
    for(char x : s){
       alpha[int(x)-65]++;

    }
    int oddcount = 0;
    for(int i=0;i<26;i++){
        if(alpha[i] % 2 == 1){
            oddcount++;
        }
    }
    string X = "";
    if(oddcount > 1){
        cout << "NO SOLUTION" << endl;
        return 0;
    }
    else{
        for(int i=0;i<26;i++){
            if(alpha[i] % 2 == 1){
                X = char(i + 65);
                break;

            }
        }

    }
    string str = "";
    for(int i=0;i<26;i++){
        for(int j=0;j<alpha[i]/2;j++){
            str += char(i + 65);
        }
    }
    string temp = str;
    reverse(str.begin(), str.end());
    cout << temp + X + str << endl;
}
