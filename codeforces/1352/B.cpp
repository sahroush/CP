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
		if(k > n){
			cout << "NO" << endl;
			continue;
		}
		if((n - k + 1)%2){
			cout << "YES" << endl;
			for(int i = 0 ; i < k -1 ; i ++){
				cout << 1 << ' ';
			}
			cout << n - k + 1 << endl;
			continue;
		}
		if((n - ( k - 1) * 2 ) > 0 and (n - ( k - 1) * 2 )%2 == 0){
			cout << "YES" << endl;
			for(int i = 0 ; i < k -1 ; i ++){
				cout << 2 << ' ';
			}
			cout << n - k - k  + 2 << endl;
			continue;
		}
		cout << "NO" << endl;
	}
    
    
    
    
    return(0);
}