#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int  ,int > pii;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const ll maxn  = 3e6;
const ll mod =1e9+7;
const ll mod2 =1e9+9;
const ld PI = acos((ld)-1);

#define pb(x) push_back(x);
#define endl '\n'
#define dokme(x) return(cout << x , 0);
#define migmig ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ms(x , y) memset(x , y , sizeof x);
#define file_init freopen("input.txt", "r+", stdin); freopen("output.txt", "w+", stdout);
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}

int n;
string s1 , s2;
ll h11 , h12 , h22 , h21;

int main(){
    migmig
    cin >> n;
    n-=2;
    cin >> s1;
    cin >> s2;
    for(int i = 0 ; i <= n ; i ++){
		ll a = 0;
		ll b = 0;
		if(s1[n - i] == 'N')a=0;
		if(s1[n - i] == 'S')a=1;
		if(s1[n - i] == 'E')a=2;
		if(s1[n - i] == 'W')a=3;
		if(s2[n - i] == 'N')b=1;
		if(s2[n - i] == 'S')b=0;
		if(s2[n - i] == 'E')b=3;
		if(s2[n - i] == 'W')b=2;
		h11 = (5 * h11 % mod + a)%mod;
		h12 = (7 * h12 % mod2 + a)%mod2;
		h21 = (h21 + b * pw(5 , i)%mod)%mod;
		h22 = (h22 + b * pw(7 , i , mod2) %mod2)%mod2;
		if(h11 == h21 and h12 == h22) dokme("NO");
	}
    cout << "YES";
    
    
    
    return(0);
}

