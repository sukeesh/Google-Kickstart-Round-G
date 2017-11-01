#include <bits/stdc++.h>

using namespace std;

#define eps 1e-9
#define ll long long
#define INP freopen("A-small-attempt0.in","r",stdin);
#define OUT freopen("output.txt","w",stdout);

const long long linf = 1e18+5;
const int inf = 1e9;

ll fpow(ll base,ll power, ll mod){
	ll result = 1;
	while (power > 0){
		if (power%2 == 1) result=((result % mod)*(base % mod)) % mod;
  		base = ((base % mod)*(base % mod)) % mod;
  		power /= 2;
  		while ( base < 0 ) base += mod;
  		while ( result < 0 ) result += mod;
  	}
	return result;
}

void solve(ll cas){
	ll a, n, p, i;
	cin >> a >> n >> p;
	ll ans = 1;
	for ( i = 1 ; i <= n ; i ++ ){
		ans = fpow(a, i, p) % p;
		a = ans;
	}
	cout << "Case #" << cas << ": ";
	cout << ans << "\n";
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