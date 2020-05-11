#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int  ,int > pii;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const ll maxn  = 1e7+100;
const ll mod =1e9+7;
const ld PI = acos((ld)-1);

#define pb(x) push_back(x);
#define endl '\n'
#define dokme(x) return(cout << x , 0);
#define migmig ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ms(x , y) memset(x , y , sizeof x);
#define file_init freopen("input.txt", "r+", stdin); freopen("output.txt", "w+", stdout);
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}

int n , m;
int a[maxn] , b[maxn];
int dv[maxn];
int prma[maxn] , prmb[maxn];

int main(){
    migmig
    cin >> n >> m;
    for(int i = 0 ; i < n ; i ++)
		cin >> a[i];
	for(int i = 0 ; i < m ; i ++)
		cin >> b[i];
	for(int i = 2 ; i * i < maxn ; i ++)
		if(dv[i] == 0)
			for(int j = i * i ; j < maxn ; j += i)
				dv[j] = i;
    for(int i = 2 ; i < maxn ; i ++)
		if(dv[i] == 0)
			dv[i] = i;
	for(int i = 0 ; i < m ; i ++)
		for(int j = b[i] ; j > 1 ; j /= dv[j])
			prmb[dv[j]]++;
    cout << n << ' ' << m << endl;
    for(int i = 0 ; i < n ; i ++){
		int ans = 1;
		for(int j = a[i] ; j > 1 ; j /= dv[j])
			if(prmb[dv[j]])prmb[dv[j]]--;
			else ans*=dv[j];
		cout << ans << ' ';
	}
	cout << endl;
	    for(int i = 0 ; i < m ; i ++){
		int ans = 1;
		for(int j = b[i] ; j > 1 ; j /= dv[j])
			if(prmb[dv[j]]){prmb[dv[j]]--;
			ans*=dv[j];}
		cout << ans << ' ';
	}
    
    return(0);
}