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

ll n , m;

int main(){
    migmig
    cin >> n >> m;
    if(n>=4 and m>=4)dokme(n*m/2*2);
    if(n > m)swap(n , m);
    if(n == 1){
		if(m < 4)
			dokme(0);
		ll ans = m - m%6;
		ans += max(0LL , m%6-3)*2;
		dokme(ans);
	}
    if(n == 2){
		if(m%5 == 0)dokme(m*n);
		if(m%4 == 0)dokme(n*m);
		if(m%6 == 0)dokme(n*m);
		if(m <= 2)dokme(0);
		if(m==3)dokme(4);
		if(m==4)dokme(8);
		if(m == 7)dokme(12);
		dokme(n*m);
	}
    dokme(n*m/2*2);
    return(0);
}

