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

vector < ll > kmp(string s){
    ll i = -1 ;
    vector < ll > f(s.size() + 1);
    f[0] = -1;
    for (ll j = 0 ; j < s.size() ; j ++){
        while(s[j]!=s[i] and i!=-1)
            i = f[i];
        f[j + 1] = ++i;
    }
    return(f);
}

ll n , k;
string s;
vector < ll > f;

bool chk(ll len){
	if(!f[len])return(0);
	ll ab = len - f[len];
	if(len%ab == 0 and (len / ab) % (k+1) == 0)
		return (1);
	ll cnt = len / (k * ab);
	if(cnt and len/(cnt*ab) == k)
		return(1);
	return(0);
}

int main(){
    migmig
    cin >> n >> k;
    cin >> s;
    f = kmp(s);
    if(k == 1){
		for(int i = 0 ; i < n ; i ++)
			cout << 1;
		return(0);
	}
    for(int i = 1 ; i <= n ; i ++){
		//k * AB + A
		cout << chk(i);
	}
    return(0);
}