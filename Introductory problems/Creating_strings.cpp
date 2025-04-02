#include <bits/stdc++.h>
#define nl '\n'
#define ll long long
#define pii pair<int, int>
#define f(i, n) for (int i = 0; i < n; i++)
#define fastread() (ios_base::sync_with_stdio(false), cin.tie(NULL));
#define asort(a) sort(a.begin(), a.end());
#define dsort(a) sort(a.begin(), a.end(), greater<int>())
using namespace std;

vector<string> permutations;

void solve(string str){
	do{
		permutations.push_back(str);
	}while(next_permutation(str.begin(), str.end()));
}

int main(){
	string s;
	cin >> s;
	asort(s);
	solve(s);
	cout << permutations.size() << nl;
	for(auto element : permutations){
		cout << element << nl;
	}
	return 0;
}

