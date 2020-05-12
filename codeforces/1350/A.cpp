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

int q;
ll n , k;

int main(){
    migmig
    cin >> q;
    while(q -- ){
		cin >> n >> k;
		if(n%2 == 0){
			cout << n+2LL*k << endl;
			continue;
		}
		ll cur = 0;
		for(int i = 2 ; i * i <= n ; i ++){
			if(n%i == 0){
				cur = i;
				break;
			}
		}
		if(cur == 0)cur = n;
		k--;
		cout << n + k*2 + cur << endl;
	}
    
    
    
    
    return(0);
}