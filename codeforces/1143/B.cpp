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

int n;
ll ans = 0;
ll cur = 1;
ll a[40];
int len(int x){
	int cnt = 0;
	while(n){
		a[cnt] = n%10;
		cnt++;
		n/=10;
	}
	return(max(1 , cnt));
}

ll solve(int x){
	if(x < 10){
		return(max(1 , x));
	}
	return(max((x%10 * solve(x / 10)) , 9 * solve(x/10 - 1)));
}

int main(){
    migmig
    cin >> n;
    cout << solve(n);
    
    return(0);
}

