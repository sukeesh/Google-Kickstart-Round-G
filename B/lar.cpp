#include <bits/stdc++.h>

using namespace std;

#define eps 1e-9
#define ll long long
#define INP freopen("input.txt","r",stdin);
#define OUT freopen("output.txt","w",stdout);

const long long linf = 1e18+5;
const int mod = (int) 1e9 + 7;
const int inf = 1e9;


#define maxn 123

ll Parent[maxn], rankk[maxn];

void make_set(){
	for(ll i=0;i<maxn;i++){
		Parent[i]=i;
		rankk[i]=0;
	}
}

ll find(ll x){	
	if(x!=Parent[x]){
		Parent[x]=find(Parent[x]);
	}
    return Parent[x];
}

void uunion(ll x,ll y){
    ll PX=find(x),PY=find(y);
    if(PX==PY){ 
    	return;
    }
    if(rankk[PX]>rankk[PY]){
        Parent[PY]=PX;
    }
    else{
        Parent[PX]=PY;
        if(rankk[PX]==rankk[PY]){
            rankk[PY]++;
        }
    }
}

#define maxn1 111
ll n, r[maxn1], b[maxn1];
vector < pair<ll, pair<ll, ll> > > v;
ll wt[maxn1][maxn1];

void solve(ll cas){

	cout << "Case #" << cas << ": ";

	make_set();
	v.clear();

	memset(r, 0, sizeof(r));
	memset(b, 0, sizeof(b));

	cin >> n;

	ll i, j;

	for ( i = 0 ; i < n ; i ++ ) for ( j = 0 ; j < n ; j ++ ){
		if ( i == j ){
			wt[i][j] = 0;
		}
		else{
			wt[i][j] = inf;
		}
	}

	for ( i = 0 ; i < n ; i ++ ){
		cin >> r[i];
	}
	for ( i = 0 ; i < n ; i ++ ){
		cin >> b[i];
	}

	for ( i = 0 ; i < n ; i ++ ) for ( j = 0 ; j < n ; j ++ ) if ( i != j ){
		wt[i][j] = min(r[i]^b[j], r[j]^b[i]);
	}

	for ( i = 0 ; i < n ; i ++ ){
		for ( j = i + 1 ; j < n ; j ++ ){
			if ( i != j ){
				v.push_back(make_pair(wt[i][j], make_pair(i, j)));
			}
		}
	}

	sort(v.begin(), v.end());

	ll ans = 0;

	for ( i = 0 ; i < v.size() ; i ++ ){
		if ( find(v[i].second.first) != find(v[i].second.second) ){
			uunion(v[i].second.first, v[i].second.second);
			ans += v[i].first;
		}
	}

	cout << ans << "\n";
}

int main(){
	// INP;
	// OUT;
	int t = 1;
	cin >> t;
	ll cntt = 1;
	while ( t -- ){
		solve(cntt);
		cntt ++;
	}
	return 0;	
}