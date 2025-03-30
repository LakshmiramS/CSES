#include <bits/stdc++.h>
#define nl '\n'
#define ll long long
#define f(i, n) for (int i = 0; i < n; i++)
#define fastread() (ios_base::sync_with_stdio(false), cin.tie(NULL));
#define asort(a) sort(a.begin(), a.end());
#define dsort(a) sort(a.begin(), a.end(), greater<int>())
using namespace std;

int main(){
	int n;
	cin >> n;
	vector<string> v(65550);
	v[0] = '0';
	v[1] = '1';
	if(n>1){
		for(int i=2;i<=n;i++){
			int temp = pow(2,i-1);
			int p = temp -1;
			int q = temp;
			while(p>=0){
				v[q] = v[p];
				q++;
				p--;
			}
			f(j,temp){
				v[j] = '0' + v[j];
				v[j+temp] = '1' + v[j+temp];
			}
		}
	}
	f(i, pow(2,n)){
		cout << v[i] << nl;
	}
	return 0;

}


