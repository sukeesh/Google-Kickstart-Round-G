#include <bits/stdc++.h>

using namespace std;

#define eps 1e-9
#define ll long long
#define INP freopen("input.txt","r",stdin);
#define OUT freopen("output.txt","w",stdout);

const long long linf = 1e18+5;
const int mod = (int) 1e9 + 7;
const int inf = 1e9;

ll n, m;

ll mat[51][51];

ll func(ll left, ll right){
	ll i, ret = linf;
	for ( i = left ; i <= right ; i ++ ){
		ret = min(ret, mat[0][i]);
	}
	return ret;
}

ll dfs(ll left, ll right){

	if ( left >= right ) return 0;

	ll val = func(left, right);

	ll ans = 0;

	for ( ll i = left ; i <= right ; i ++ ){

		if ( i + 1 <= right && i >= 0 ) ans = max(ans,  dfs(left, i) + dfs(i + 1, right));
	
	}

	return ans + val;
}

void solve(ll cas){
	
	cin >> n >> m;
	memset(mat, 0, sizeof(mat));

	ll i;


	for ( i = 0 ; i < m ; i ++ ){
		cin >> mat[0][i];
	}

	cout << "Case #" << cas << ": ";

	cout << dfs(0, m - 1) << "\n";
}

int main(){
	// INP;
	// OUT;
	int t = 1;
	cin >> t;
	int cnt = 1;
	while ( t -- ){
		solve(cnt);
		cnt ++;
	}
	return 0;	
}