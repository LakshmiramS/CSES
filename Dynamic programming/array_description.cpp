////
//// Created by lakshmiram  on 10/12/23.
////
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
int mod = 1e9 + 7;
const int INF = 1e9 + 5;
int main(){
    int n, m;
    cin>>n>>m;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    vector<int> prev(1+m,0);
    int last = a[n-1];
    if(last){
        prev[last] = 1;
    }
    else{
        for(int k=1;k<=m;k++) prev[k] = 1;
    }
    for(int i=n-2;i>=0;i--){
        vector<int> cur(1+m,0);
        int temp = a[i];
        if(temp){
            for(int l = temp-1;l<=temp+1;l++){
                if(1<=l and l<=m) cur[temp] =( cur[temp] +  prev[l]) % mod;
            }
        }
        else{
            for(int k=1;k<=m;k++){
                for(int l=k-1;l<=k+1;l++){
                    if(1<=l and l<=m) cur[k] = (cur[k] + prev[l]) %mod;
                }
            }
        }
        prev = cur;
    }
    int ans = 0;
    for(int i=1;i<=m;i++){
        ans = (ans + prev[i]) %mod;
    }
    cout<<ans <<endl;
 
}
