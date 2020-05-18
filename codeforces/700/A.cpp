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

ld n , d , v1 , v2 , k , gp;

bool chk(ld x){
	ld a = (d - (v1*x))/(v2 - v1);
	ld b = (d - (v1*x))/(v2 + v1);
	return(a*gp + (gp-1)*b >=x);
}

int main(){
    migmig
    cin >> n >> d >> v1 >> v2 >> k;
    ld l = 0 , r = 1e9 , mid;
    gp = ceil((n)/k);
    for(int i=0 ; i < 100000 ; i ++){
		mid = (l+r)/2;
		if(chk(mid))
			l = mid;
		else
			r = mid;
	}
    cout << fixed << setprecision(10) << mid;
    return(0);
}