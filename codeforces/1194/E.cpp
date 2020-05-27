#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll  ,ll > pii;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const ll maxn  = 3e4;
const ll mod =1e9+7;
const ld PI = acos((ld)-1);

#define pb push_back
#define endl '\n'
#define dokme(x) return(cout << x , 0);
#define migmig ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ms(x , y) memset(x , y , sizeof x);
#define file_init freopen("input.txt", "r+", stdin); freopen("output.txt", "w+", stdout);
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}

ll n;
vector < pii > hor[maxn] , ver[maxn];
ll fen[maxn];
vector< ll > vec[maxn];

void add(int pos , ll x){
	for(; pos < maxn ; pos += pos&-pos)
		fen[pos]+=x;
}

ll sum(int pos){
	ll ans = 0;
	for(;pos;pos-=pos&-pos)
		ans+=fen[pos];
	return(ans);
}

ll sum (ll l , ll r){
	return(sum(r) - sum(l-1));
}
int main(){
    migmig
    cin >> n;
    for(int i = 0 ; i < n ; i ++){
		int a , b , c , d;
		cin >> a >> b >> c >> d;
		a+=5002 , b += 5002 , c += 5002 , d += 5002;
		if(a == c){
			int mn = min(b , d);
			int mx = b+d - mn;
			ver[a].pb({mn , mx});
		}
		else{
			hor[b].pb({min(a , c) , a+c - min(a , c)});
		}
	}
    ll ans = 0;
    for(int i = 0 ; i < maxn ; i ++){
		for(auto [l , r] : hor[i]){
			ms(fen , 0);
			for(int i = 0 ; i < maxn ; i ++)
				vec[i].clear();
			for(int j = l ; j <= r ; j ++){
				for (auto [l2 , r2] : ver[j]){
					if(l2<=i and r2 > i)
						vec[r2].pb(j) , add(j , 1);
				}
			}
			for(int j = i+1 ; j < maxn ; j ++){
				for (auto [l2 , r2] : hor[j]){
					ll s = sum(l2 , r2);
					ans += s*(s-1)/2;
				}
				for(int i : vec[j])
					add(i , -1);
			}
		}
	}
    cout << ans << endl;
    return(0);
}