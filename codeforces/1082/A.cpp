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

int q;
ll n , x , y , d; 

int main(){
    migmig
    cin >> q;
    while(q --){
		cin >> n >> x >> y >> d;
		//1 or n or normal
		ll mn = 1e10;
		if(abs(x - y)%d == 0){
			mn = min(mn , abs(x - y)/d);
		}
		if((y - 1)%d == 0){
			mn = min(mn , (x-1 + d - 1)/d + (y-1)/d);
		}
		if((n-y)%d == 0){
			mn = min(mn , (n-x + d - 1)/d + (n-y)/d);
		}
		if(mn == 1e10)
			cout << -1 << endl;
		else
		{
				cout << mn << endl;
		}
	}
    
    
    
    
    return(0);
}