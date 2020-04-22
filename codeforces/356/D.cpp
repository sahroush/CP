#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll  ,ll > pii;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const ll maxn  = 70100;
const ll mod =1e9+7;
const ld PI = acos((ld)-1);

#define pb(x) push_back(x);
#define endl '\n'
#define dokme(x) return(cout << x , 0);
#define migmig ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ms(x , y) memset(x , y , sizeof x);
#define file_init freopen("input.txt", "r+", stdin); freopen("output.txt", "w+", stdout);
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}

pii a[maxn];
ll n , s;
bitset < maxn > dp , dummy , nw;
ll par[maxn];
ll coin[maxn] , pr[maxn];
bool mark[maxn];
ll val[maxn];
vector < ll > num[maxn];

int main(){
    migmig
    cin >> n >> s;
    for(ll i = 0 ; i < n ; i ++){
		cin >> a[i].first;
		val[i] = a[i].first;
		a[i].second = i;
	}
	ms(par , -1);
	sort(a , a + n);
	reverse(a , a + n);
	for(ll  i = 0 ; i < n ; i ++)
		num[a[i].first].pb(a[i].second);
	if(a[0].first > s)
		dokme(-1);
	ll sum = 0;
	for(ll i = 0 ; i < n ; i ++)
		sum+=a[i].first;
	if(sum < s)	dokme(-1);
	dp[a[0].first] = 1;
	par[a[0].first] = a[0].first;
	dp[0] = 1;
	for(ll i = n-1; i >=0 ; i --){
		dummy = dp;
		dummy[a[i].first] = 1;
		nw = dp^(dummy|(dp << a[i].first));
		dp=dummy|(dp << a[i].first);
		ll cur = nw._Find_first();
		while(cur!=maxn){
			par[cur] = a[i].first;
			cur = nw._Find_next(cur);
		}
	}
    if(!dp[s])
		dokme(-1);
	s-=a[0].first;
	num[a[0].first].pop_back();
    while(s){
		if(par[s] == -1)dokme(-1);
		mark[num[par[s]].back()] = 1;
		num[par[s]].pop_back();
		s-=par[s];
	}
    ll cur = 0;
    ll prev = -1;
    ms(pr , -1);
    reverse(a , a + n);
    for(ll i = 0; i < n ; i ++){
		if(mark[a[i].second]){
			coin[a[i].second] = val[a[i].second];
			continue;
		}
		coin[a[i].second] = val[a[i].second] - cur;
		cur = val[a[i].second];
		if(prev!=-1){
			pr[a[i].second] = prev;
		}
		prev = a[i].second+1;
	}
	for(ll i = 0 ; i < n ; i ++){
		if(pr[i] == -1){
			cout << coin[i] << " 0 " << endl;
		}
		else{
			cout << coin[i] << " 1 " << pr[i] << endl;
		}
	}
		
		
		
    return(0);
}

//When we hit our lowest poll, we are open to the greatest change.
//If I try, I fail. If I don't try, I'm NEVER GOING TO GET IT.
//Sometimes, life is like this dark tunnel. You can't always see the light at the end of the tunnel. But if you just keep moving... you will come to a better place.
//It is important to draw wisdom from diffrent places. If you take it from only one place it becomes rigid and stale.
//kuxtal jach uts chuchul u u páajtal máak jach táaj meyajilo'ob le castigadas tumen ch'aik descansos.
