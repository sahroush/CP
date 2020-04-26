#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int  ,int > pii;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const ll maxn  = 3e6;
const ll mod =998244353;
const ld PI = acos((ld)-1);

#define pb(x) push_back(x);
#define endl '\n'
#define dokme(x) return(cout << x , 0);
#define migmig ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ms(x , y) memset(x , y , sizeof x);
#define file_init freopen("input.txt", "r+", stdin); freopen("output.txt", "w+", stdout);
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}

int n;
ll p[maxn];
ll sum = 1;
ll prod = 1;

int main(){
    migmig
    cin >> n;
    for(int  i = 0 ; i < n ; i ++)
		cin >> p[i];
	for(int i = 0 ; i < n ; i ++)
		p[i] = (p[i] * pw(100 , mod - 2))%mod;
    for(int i = 0 ; i < n ; i ++){
		prod = (prod * p[i])%mod;
		if(i+1 < n)sum = (sum + prod)%mod;
	}
    cout << (sum * pw(prod , mod - 2))%mod;
    return(0);
}
