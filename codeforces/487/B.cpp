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
ll diff , sz;
ll a[maxn];
ll dp[maxn] , l[maxn];
deque < int > dq;

int main(){
    migmig
    cin >> n >> diff >> sz;
    ms(dp , 63);
    for(int i = 1 ; i <= n ; i ++)
		cin >> a[i];
	int pos = 1;
	for(int i = 1 ; i <= n ; i ++){
		while(dq.size() and a[i] - a[dq.front()] > diff)
			pos = dq.front()+1,dq.pop_front();
		l[i] = pos;
		while(dq.size() and a[i] < a[dq.back()])
			dq.pop_back();
		dq.pb(i);
	}
    dq.clear();
    pos = 1;
	for(int i = 1 ; i <= n ; i ++){
		while(dq.size() and a[dq.front()]-a[i] > diff)
			pos = dq.front()+1,dq.pop_front();
		l[i] = max((ll)pos,l[i]);
		while(dq.size() and a[i] > a[dq.back()])
			dq.pop_back();
		dq.pb(i);
	}
    dq.clear();
    dq.pb(0);
    dp[0] = 0;
    for(int i = 1 ; i <= n ; i ++){
		while(dq.size() and dq.front()+1 < l[i])
			dq.pop_front();
		if(dq.size())
			if(dq.front() <= i - sz)
				dp[i] = dp[dq.front()]+1;
		while(dq.size() and dp[i] < dp[dq.back()])
			dq.pop_back();
		dq.pb(i);
	}
    if(dp[n] > n)
		dokme(-1);
	dokme(dp[n]);
    return(0);
}