/*
#pragma GCC optimize("O2")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,fma")
*/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int , int> pii;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int maxn = 3e6;
const ll mod = 1e9+7;
const ld PI = acos((ld)-1);

#define pb push_back
#define endl '\n'
#define dokme(x) cout << x , exit(0)
#define migmig ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define ms(x , y) memset(x , y , sizeof x)
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}

int q;
int n;
string s[maxn];
int cnt[2];

vector < int > vec;

int32_t main(){
	migmig;
	cin >> q;
	while(q -- ){
		cin >> n;
		ms(cnt , 0);
		for(int i = 0 ; i < n ; i ++){
			cin >> s[i];
			for(int j = 0 ; j < (int)s[i].size() ; j ++)
				cnt[s[i][j] == '1'] ++;
		}
		int ans = 0;
		vec.clear();
		for(int i = 0 ; i < n ; i ++)if((int)s[i].size() % 2)ans++;	
		else vec.pb((int)s[i].size());
		sort(vec.begin() , vec.end());
		reverse(vec.begin() , vec.end());
		while(vec.size()){
			int x = vec.back();
			vec.pop_back();
			sort(cnt , cnt + 2);
			if(cnt[1] >= x){
				cnt[1] -= x;
				ans++;
				continue;
			}
			if(cnt[0] % 2 == 0 and x - cnt[0] <= cnt[1]){
				ans ++;
				x -= cnt[0];
				cnt[0] = 0;
				cnt[1] -= x;
				continue;
			}
			if(cnt[0] % 2 and x - cnt[0] + 1 <= cnt[1]){
				ans ++;
				x -= cnt[0]-1;
				cnt[0] = 1;
				cnt[1] -= x;
				continue;
			}
		}
		cout << ans << endl;
	}
	return(0);
}
