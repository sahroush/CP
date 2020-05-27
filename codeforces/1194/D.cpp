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

ll q , n , k;

int main(){
    migmig
    cin >> q;
    while(q -- ){
		cin >> n >> k;
		//k=5
		// 0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 ...
		// L W W L W W L W W L  W  W  L  W  W  L  W  W  L  W  W
		//k=4
		// 0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 ...
		// L W W L W W L W W L  W  W  L  W  W  L  W  W  L  W  W
		//thonkery
		//k=3
		// 0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20...
		// L W W W L W W W L W  W
		//gcd(k , 3) ?? 
		//k%3 != 0 ==> state%3==0 : L
		if(k%3){
			cout << ((n%3)?"Alice":"Bob") << endl;
		}
		else{
			cout << (!((n%(k+1)!=k and (n%(k+1))%3 == 0))?"Alice":"Bob") << endl;
		}
	}
    return(0);
}