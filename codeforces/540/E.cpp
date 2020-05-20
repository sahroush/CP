#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int  ,int > pii;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const ll maxn  = 3e6;
const ll mod =1e9+7;
const ld PI = acos((ld)-1);

#define pb push_back
#define endl '\n'
#define dokme(x) return(cout << x , 0);
#define migmig ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ms(x , y) memset(x , y , sizeof x);
#define file_init freopen("input.txt", "r+", stdin); freopen("output.txt", "w+", stdout);
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}

vector < pii > vec;
ll fen[maxn];
int n , q;
int a[maxn] , b[maxn];
int pos[maxn];

void add(int pos , ll val){
	for(;pos <= n;pos += pos&-pos)
		fen[pos]+=val;
}

ll sum(int pos){
	ll ans = 0;
	for(;pos;pos-=pos&-pos)
		ans+=fen[pos];
	return(ans);
}

int main(){
    migmig
    cin >> q;
    for(int i = 0 ; i < q ; i ++){
		cin >> a[i] >> b[i];
		vec.pb({a[i],1});
		vec.pb({b[i],1});
	}
	sort(vec.begin() , vec.end());
	n = unique(vec.begin() , vec.end())-vec.begin();
	for(int i = 0 ; i < n-1 ; i ++){
		int v = vec[i].first;
		if(v+1 == vec[i+1].first)continue;
		vec.pb({v+1 ,vec[i+1].first-v-1});
	}
	sort(vec.begin() , vec.end());
	n = unique(vec.begin() , vec.end())-vec.begin();
	for(int i = 1 ; i <= n ; i ++)
		pos[i] = i;
	for(int i = 0; i< q ; i ++){
		a[i] = lower_bound(vec.begin(), vec.begin()+n, pii(a[i] , 0)) - vec.begin() + 1;
		b[i] = lower_bound(vec.begin(), vec.begin()+n, pii(b[i] , 0)) - vec.begin() + 1;
		swap(pos[a[i]] , pos[b[i]]);
	}
	ll ans = 0;
	for(int i = n ; i ;i --){
		ll boz = sum(pos[i]);
		ll cof = vec[pos[i]-1].second;
		ans+=boz*cof;
		add(pos[i] , cof);
	}
    cout << ans;
    return(0);
}