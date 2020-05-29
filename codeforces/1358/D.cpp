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

ll n , x;
ll d[maxn];

ll fd(ll pos , ll x){
	ll mx = d[pos];
	if(x <= d[pos]){
		return((x)*(x+1)/2);
	}
	x-=d[pos];
	pos = (pos+1)%n;
	return(fd(pos , x) + mx*(mx + 1)/2 );
}

ll bk(ll pos , ll x){
	ll mx = d[pos];
	if(x <= d[pos]){
		return(mx*(mx + 1)/2 - (mx - x)*(mx - x + 1)/2);
	}
	x-=d[pos];
	pos = (pos-1+n)%n;
	return(bk(pos , x) + mx*(mx + 1)/2 );
}

int main(){
    migmig
    cin >> n >> x;
    for(int i = 0 ; i < n ; i ++)
		cin >> d[i];
	ll ans = 0 , ind = 0 , sum = 0 , mx = 0;
	for(int i = 0 ; i < 2 * n ; i ++){
		if(sum + d[i%n] <= x){
			sum+=d[i%n];
			mx += d[i%n] * (d[i%n]+1) / 2;
			ans = max(ans , mx);
		}
		else{
			ll ez = sum + d[i%n] - x;
			ans = max(ans , mx - ez * (ez + 1) / 2 +  d[i%n] * (d[i%n]+1) / 2);
			sum -= d[ind%n];
			mx -= d[ind%n] * (d[ind%n]+1) / 2;
			ind++ , i --;
		}
	}
    cout << ans;
    return(0);
}