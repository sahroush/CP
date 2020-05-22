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

int n , m;
int x;
ll prt[maxn];
ll ans = 0;

int main(){
    migmig
    cin >> n >> m;
    int cur = -1;
    for(int i = 0 ; i < m ; i++){
		cin >> x;
		if(cur == -1){
			cur = x;
			continue;
		}
		int mn = cur , mx = x;
		if(mx < mn)swap(mx , mn);
		ans += mx - mn;
		cur = x;
		if(mx > mn){
			prt[mn]+=mn-1;
			prt[mn+1]-=mn-1;
			prt[mx]+=mn*2-mx;
			prt[mx+1]-=mn*2-mx;
			if(mx-mn-2 >= 0)
				prt[mn+1]-=1,prt[mx]+=1;
		}
	}
    for(int i = 1 ; i <= n ; i ++){ans+=prt[i];cout << ans << ' ';}
    return(0);
}