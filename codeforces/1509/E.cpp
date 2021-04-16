//曇り空 のぞいた予感
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int , int> pii;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int maxn = 3e6;
const ll mod = 1e9+7;

#define pb push_back
#define endl '\n'
#define dokme(x) cout << x , exit(0)
#define ms(x , y) memset(x , y , sizeof x)
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}

ll n , k , q;

int32_t main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin >> q;
	while(q --){
		cin >> n >> k;
		if(n <= 62){
			if((1ll << (n - 1)) < k){
				cout << -1 << endl;
				continue;
			}
		}
		vector < ll > p;
		p.clear();
		ll x = n;
		ll sum = 0;
		while(x){
		
			if(x == 1){
				p.pb(1);
				x--;
			}
			for(int i = 1 ; i <= x ; i ++){
				if(x - i - 1 > 60){
					p.pb(1);
					x--;
					break;
				}
				ll val = x - i - 1;
				if(val == -1)val = 1;
				else val = (1LL << val);
				sum += val;
				if(sum == k){
					p.pb(i);
					sum -= val;
					x-=i;
					break;
				}
				if(sum > k){
					p.pb(i);
					sum -= val;
					x -= i;
					break;
				}
			}
		}
		ll cur = 0;
		ll mx = 0;
		for(auto x : p){
			cur += x;
			while(cur != mx){
				cout << cur << ' ';
				cur--;
			}
			cur = mx + x;
			mx = cur;
		}
		cout << endl;
	}

	return(0);
}
