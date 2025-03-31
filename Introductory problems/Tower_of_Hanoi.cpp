#include <bits/stdc++.h>
#define nl '\n'
#define ll long long
#define pii pair<int, int>
#define f(i, n) for (int i = 0; i < n; i++)
#define fastread() (ios_base::sync_with_stdio(false), cin.tie(NULL));
#define asort(a) sort(a.begin(), a.end());
#define dsort(a) sort(a.begin(), a.end(), greater<int>())
using namespace std;

vector<pii> moves;

void solve(int start, int end, int mid, int n){
	if(n==1){
		moves.push_back({start, end});
	}
	else{
		solve(start, mid, end, n-1);
		moves.push_back({start, end});
		solve(mid, end, start, n-1);
	}
}

int main(){
	int n;
	cin >> n;
	// vector<pii> moves;
	solve(1,3,2,n);
	cout << moves.size() << nl;
	for(auto move : moves){
		cout << move.first << " " << move.second << nl;
	}
	return 0;

}


