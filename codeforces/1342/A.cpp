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
ll n , a , b , x , y;

int main(){
    migmig
    cin >> q;
    while(q -- ){
		cin >> x >> y >> a >> b;
		ll ans =0;
		if(min(x , y) * b < min(x , y) * a * 2){
			ans = min(x , y);
			x-=min(x , y);
			y-=ans;
			ans*=b;
		}
		cout << ans + a * (x + y) << endl;
		
	}
    
    
    
    
    return(0);
}

