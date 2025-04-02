#include <bits/stdc++.h>
#define nl '\n'
#define ll long long
#define pii pair<int, int>
#define f(i, n) for (int i = 0; i < n; i++)
#define fastread() (ios_base::sync_with_stdio(false), cin.tie(NULL));
#define asort(a) sort(a.begin(), a.end());
#define dsort(a) sort(a.begin(), a.end(), greater<int>())
using namespace std;

bool takencols[8], takendiag1[15], takendiag2[15];
int ans = 0;

void solve(vector<string> &board, int r, int &ans){
	if(r==8){
		ans++;
		return;
	}
	f(c,8){
		if(board[r][c]=='.'){
			if(!takencols[c] && !takendiag1[r+7-c] && !takendiag2[r+c]){
				takencols[c] = takendiag1[r+7-c] = takendiag2[r+c] = true;
				solve(board, r+1, ans);
				takencols[c] = takendiag1[r+7-c] = takendiag2[r+c] = false;

			}
		}
	}

}

int main(){
	vector<string> board(8);
	f(i,8) cin >> board[i];
	solve(board, 0 , ans);
	cout << ans << nl;
	return 0;

}
