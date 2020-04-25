#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int , ll > pii;

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

int n;
ll a[maxn];
ll ans = 1;
ll g[maxn];
ll num[maxn];
int cnt[maxn];

void solve(ll x){
	for(int i = 0 ; i < n ; i ++){
		g[i] = __gcd(a[i] , x);
	}
	sort(g , g + n);
	int cur= 0;
	for(int  i = 0 ; i < n ; ){
		num[cur] = g[i];
		cnt[cur] = 1;
		int pos = i+1;
		while(pos < n and g[pos] == num[cur]){
			cnt[cur] ++;
			pos++;
		}
		i = pos;
		cur++;
	}
	for(int i = 0 ; i < cur ; i ++){
		if(num[i] <= ans)continue;
		int all = cnt[i];
		for(int j = i + 1 ; j < cur ; j ++){
			if(num[j] % num[i] == 0)all += cnt[j];
			
		}
		if(all*2 >= n){ans = num[i];}
	}
}



int main(){
    migmig
    cin >> n;
    for(int i = 0 ; i < n ; i ++ ) cin >> a[i];
    int cur = rng()%n;
    for(int i = 0 ; i < 13 ; i ++){
		solve(a[cur]);
		cur = rng()%n;
	}
    cout << ans;
    return(0);
}



