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

int n , k;
ll a[maxn];
set < ll > st;

int main(){
    migmig
    cin >> n >> k;
    for(int i = 1; i  <= n ; i ++)
		cin >> a[i];
	for(int i = 1; i  <= n ; i ++)
		a[i]%=k;
	for(int i = 1; i  <= n ; i ++)
		if(a[i] == 0)a[i] = k;
	ll ans = a[1];
	for(int i = 2 ; i <= n ; i ++)
		ans = __gcd(ans , a[i]);
	ll boz = 0;
	for(int i = 0 ; i < k ; i  ++){
		st.insert(boz);
		boz = boz + ans;
		boz%=k;
	}
	cout << st.size() << endl;
		for(auto i : st)
			cout << i << ' ';
    
    
    
    return(0);
}