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

int n , a[maxn];
int par[maxn];

int main(){
    migmig
    cin >> n;
    for(int i = 0 ; i < n-1 ; i ++){
		cin >> a[i];
	}
	par[a[0]] = a[0];
    int cur = a[0];
    int lst = n+1;
    for(int i = 1 ;i < n - 1 ; i ++){
		//cout << a[i] << ' '; 		
		if(par[a[i]]){
			while(par[--lst])continue;par[lst] = cur;
		}
		else{
			par[a[i]] = cur;
		}
		cur =a[i];
	}
	//dokme(par[4])
    while(par[--lst])continue;
    par[lst] = cur;
    cout << a[0] << endl;
    for(int i = 1 ; i <= n ; i ++){
		if(i!=a[0]){
			cout << i << ' ' << par[i] << endl;
		}
	}
    return(0);
}