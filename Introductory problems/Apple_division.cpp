#include <bits/stdc++.h>
#define nl '\n'
#define ll long long
#define pii pair<int, int>
#define f(i, n) for (int i = 0; i < n; i++)
#define fastread() (ios_base::sync_with_stdio(false), cin.tie(NULL));
#define asort(a) sort(a.begin(), a.end());
#define dsort(a) sort(a.begin(), a.end(), greater<int>())
using namespace std;

int main(){
	int n;
	cin >> n;
	vector<ll> v(n);
	ll total = 0;
	f(i,n){
		cin >> v[i];
		total += v[i];
	}
	//iterate through all possible subsets and find mindiff
	ll mindiff = INT_MAX;
	f(i, 1<<n){
		ll temp_sum = 0;
		f(j,n){
			if(i & 1<<j) temp_sum += v[j];
		}
		mindiff = min(mindiff, abs(total - 2*temp_sum));
	}
	cout << mindiff << nl;
	return 0;
}

