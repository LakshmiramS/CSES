#include<iostream>
using namespace std;
int main(){
    int n; cin>>n;
    int ans = 0;
    for(int i=1;i<=n;i++) ans = ans^i;
    for(int i=0;i<n-1;i++) {
        int temp; cin>>temp;
        ans = ans ^ temp;
    }
    cout<<ans<<endl;
}