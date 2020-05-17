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

const ll N = 1e6+100;

struct indexed_set {
	
	int sz = 0, bit[N];

	int size() {
		return sz;
	}

	void update(int k, int x) {
		while (k < N) {
			bit[k] += x;
			k += k & -k;
		}
		sz += x;
	}

	int find_by_order(int k) {
		int ans = 0, sum = 0;
		for (int j = 20; j >= 0; --j) {
			ans += 1 << j;
			if (ans < N && sum + bit[ans] < k) {
				sum += bit[ans];
			} else {
				ans -= 1 << j;
			}
		}
		return ans + 1;
	}
	
	int order_of_key(int k) {
		int ans = 0;
		while (k >= 1) {
			ans += bit[k];
			k -= k & -k;
		}
		return ans;
	}
	
} is;


int n , t;
int sz = 0;
int q , a;


int main(){
    migmig
    cin >> n >> t;
	sz = n;
	for(int i = 0 ; i < n ; i ++){
		cin >> a;
		is.update(a , 1);
	}
	for(int i = 0 ; i < t ; i ++){
		cin >> q;
		if(q > 0)
			is.update(q , 1) , sz++;
		else
			is.update(is.find_by_order(-q) , -1) , sz--;
	}
    if(sz == 0)
		dokme(0);
    cout << is.find_by_order(1);
    return(0);
}