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

ll n , p;
ll a[maxn] , b[maxn];
ll have , use;

int main(){
    migmig
    cin >> n >> p;
    for(int i = 0 ; i < n ; i ++)
		cin >> a[i] >> b[i];
	for(int i = 0 ; i < n ; i ++)
		have+=b[i] , use+=a[i];
	if(use-p <= 0)
		dokme(-1);
	ld l = 0 , r = 1e16;
	ld ans = 0;
	for(int i = 0 ; i < 100 ; i ++){
		ld mid = (l + r)/ld(2);
		ld sum = 0;
		for(int i = 0 ; i < n ; i ++){
			sum += max(ld(0) , mid*a[i] - b[i])/mid;
		}
		if(sum-p <= 1e-9){
			ans = mid;
			l = mid;
		}
		else{
			r = mid;
		}
	}
	cout << fixed << ans;
    return(0);
}