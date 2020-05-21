#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int  ,int > pii;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const ll maxn  = 2020; //:weary:
const ll mod =1e9+7;
const ld PI = acos((ld)-1);

#define pb push_back
#define endl '\n'
#define dokme(x) return(cout << x , 0);
#define migmig ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ms(x , y) memset(x , y , sizeof x);
#define file_init freopen("input.txt", "r+", stdin); freopen("output.txt", "w+", stdout);
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}

int n;
ll x[maxn] , y[maxn] , c[maxn] , k[maxn] , ans[maxn] , sum;
int mark[maxn] , g[maxn];
vector < int > gr;
vector < pii > nrm;

int main(){
    migmig
    cin >> n;
    for(int i = 1 ; i <= n ; i ++)
		cin >> x[i] >> y[i];
	for(int i = 1 ; i <= n ; i ++)
		cin >> c[i] , ans[i] = c[i];
	for(int i = 1 ; i <= n ; i ++)
		cin >> k[i];
    for(int i = 1 ; i <= n ; i ++){
		ll mn = 3e18;
		int ind = 0;
		for(int j = 1; j <= n ; j ++)
			if(!mark[j])if(mn > ans[j])mn = ans[j] , ind = j;
		mark[ind]=1;
		sum+=ans[ind];
		if(!g[ind])gr.pb(ind);
		else nrm.pb({ind , g[ind]});
		for(int j = 1 ; j <= n ; j ++){
			if(mark[j])continue;
			ll cst = ((k[j] + k[ind])*(abs(x[ind] - x[j])+abs(y[ind] - y[j])));
			if(cst < ans[j]){
				ans[j] = cst;
				g[j] = ind;
			}
		}
	}
	cout << sum << endl << gr.size() << endl;
	for(int i : gr)
		cout << i << ' ';
	cout << endl;
	cout << nrm.size() << endl;
	for(auto [i , j] : nrm)
		cout << i << ' ' << j << endl;
    return(0);
 }