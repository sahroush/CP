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

int n;
vector < pii > ans;
vector < pii > vec;
vector < int > one;

int main(){
    migmig
    cin >> n;
    int sum= 0;
    int cnt = 0;
    for(int i = 1 ; i <= n ; i ++){
		int d;
		cin >> d;
		sum+=d;
		if(d > 1)vec.pb({d, i});
		else
			one.pb(i);
		cnt+=(d == 1);
	}
    if(sum < 2*n-2)
		dokme("NO");
	cnt = n - cnt - 1 + min(2 , cnt);
	cout << "YES" << ' ' << cnt << endl << n-1 << endl;
	sort(vec.begin() , vec.end());
	reverse(vec.begin() , vec.end());
	int s = -1 , t = -1;
	for(int i = 1 ; i < (int)vec.size() ; i ++){
		ans.pb({vec[i].second , vec[i-1].second});
		if(s == -1) s = vec[i].second;
		t = vec[i].second;
		vec[i].first--;
		vec[i-1].first--;
	}
	s = vec[0].second;
	t = vec.back().second;
	if(one.size()){
		ans.pb({s , one.back()});
		one.pop_back();
		vec[0].first--;
	}
	if(one.size()){
		ans.pb({t , one.back()});
		one.pop_back();
		vec.back().first--;
	}
	int i = 0;
	while(one.size()){
		int cur = one.back();
		one.pop_back();
		while(vec[i].first<=0)i++;
		vec[i].first--;
		ans.pb({vec[i].second , cur});
	}
	for(auto [u , v] : ans)
		cout << u << ' ' << v << endl;
    return(0);
}