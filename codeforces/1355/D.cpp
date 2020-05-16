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

ll n , s;

int main(){
    migmig
    cin >> n >> s;
	if(n == 1){
		if(s == 1)
			dokme("NO");
		cout << "YES" << endl;
		cout << s << endl;
		dokme(1);
	}
	ll mid = s/n;
	ll max = s/n ;
	if(s%n)max++;
	ll nummax = s - mid*n;
	if(mid > 1){
		cout << "YES" << endl;
		for(int i = 0 ; i < n ; i ++)
			cout << mid + (i < nummax) << ' ';
		cout << endl;
		dokme(1);
	}
    // we have at least one 1
    //also s < 2*n
    
    
    
    cout << "NO";
    return(0);
}