#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int  ,int > pii;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const ll maxn  = 3e6;
const ll mod =1e9+7;
const ld PI = acos((ld)-1);

#define pb(x) push_back(x);
#define endl '\n'
#define dokme(x) return(cout << x , 0);
#define migmig ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ms(x , y) memset(x , y , sizeof x);
#define file_init freopen("input.txt", "r+", stdin); freopen("output.txt", "w+", stdout);
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}

ll n , d , k;
ll a[maxn];
ll boz[maxn];
ll sum = 0;

bool chk(ll x){
	ll cur = k , cnt = 0;
	for(ll i = 1;  i <= n ; i ++)
		boz[i] = a[i];
	for(ll i = 1 ; i <= d+1 ; i ++)
		cnt+=a[i];
	for(ll i = 1 ; i <= n ; i ++){
		if(i != 1 and i + d <= n)cnt+=boz[i + d];
		if(cnt < x){
			if(cur < x - cnt)return(0);
			cur-=(x - cnt);
			boz[min(n , i + d)] += (x - cnt);
			cnt = x;
		}
		if(i - d >= 1)cnt-=boz[i - d];
	}
	return(1);
}


int main(){
    migmig
    cin >> n >> d >> k;
    for(ll i = 1 ; i <= n ; i ++){
		cin >> a[i];
		sum += a[i];
	}
	sum += k;
	ll l = 0 , r = sum;
	while(r - l > 1  ){
		ll mid = (l + r) / 2;
		if(chk(mid))
			l = mid;
		else 
			r = mid;
	}
    if(chk(r))dokme(r);
    cout << l;
    return(0);
}

