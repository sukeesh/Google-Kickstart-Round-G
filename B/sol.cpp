#include <bits/stdc++.h>

using namespace std;

#define eps 1e-9
#define ll long long
#define INP freopen("input.txt","r",stdin);
#define OUT freopen("output.txt","w",stdout);

const long long inf = 1e18+5;
const int mod = (int) 1e9 + 7;

#define maxn 100010
ll r[maxn], b[maxn], n;
bool vis[maxn];

ll dfs(ll sum){
	
	ll i, j;
	ll ccnt = 0;
	for ( i = 0 ; i < n ; i ++ ) if ( vis[i] == false ) ccnt ++;

	if ( ccnt == 1 ) return sum;
	
	ll ans = inf;

	for ( i = 0 ; i < n ; i ++ ){
		for ( j = 0 ; j < n ; j ++ ){
			if ( i != j ){
				if ( vis[i] == false && vis[j] == false ){
					ll xxor = r[i]^b[j];

					vis[i] = true;
					ans = min(ans, dfs(sum + xxor));
					vis[i] = false;

					vis[j] = true;
					ans = min(ans, dfs(sum + xxor));
					vis[j] = false;

				}
			}
		}
	}

	return ans;
}

void solve(ll cas){
	memset(r, 0, sizeof(r));
	memset(b, 0, sizeof(b));
	memset(vis, 0, sizeof(vis));
	ll i;
	cin >> n;
	for ( i = 0 ; i < n ; i ++ )
		cin >> r[i];
	for ( i = 0 ; i < n ; i ++ )
		cin >> b[i];

	cout << "Case #" << cas << ": ";
	cout << dfs(0) << "\n";
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