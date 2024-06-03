#include<iostream>
typedef long long ll;
ll collatz(ll n){
    if(n==1) return -1;
    if(n%2 == 0) return n/2;
    else return 3*n+1;
}
using namespace std;

int main(){
    ll n; cin>>n;
    cout<<n<<"\t";
    ll temp = collatz(n);
    while(temp != -1){
        cout<<temp<<"\t";
        temp = collatz(temp);
    }

}
