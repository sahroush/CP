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

ld n;
string a , b;
ld all;
ld sum[27];
ld ans;

int main(){
    migmig
    cin >> n;
    cin >> a >> b;
    a="$" + a;
    b="$" + b;
    all = n * (n + 1) * (2*n + 1) / 6;
    for(int i = 1 ; i <= n ; i ++){
		sum[b[i] - 'A'] += (n - i + 1);
	}
	for(int i = 1 ; i <= n ; i ++){
		ans += sum[a[i] - 'A'] * (i);
		sum[b[i] - 'A'] -= (n - i + 1);
	}
	for(int i = 1 ; i <= n ; i ++){
		sum[b[i] - 'A'] += i;
	}
	for(int i = n ; i > 0 ; i --){
		sum[b[i] - 'A'] -= i;
		ans+= ((n - i + 1) * sum[a[i] - 'A']);
	}
	cout << fixed << (ans/all);
    return(0);
}

