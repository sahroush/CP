#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int  ,int > pii;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const ll maxn  = 3e6;
const ll mod = 1e9+7;
const ld PI = acos((ld)-1);

#define pb(x) push_back(x);
#define endl '\n'
#define dokme(x) return(cout << x , 0);
#define migmig ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ms(x , y) memset(x , y , sizeof x);
#define file_init freopen("input.txt", "r+", stdin); freopen("output.txt", "w+", stdout);
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}

string s , t;
int n , m , sum;
int ans = 0;
ll th[maxn];
ll pww[maxn] , inv[maxn];
ll p = 31;

ll geth(ll l , ll r){
	return((th[r] - th[l - 1] + mod)%mod*inv[l-1]%mod)%mod;
}

int solve(ll sz1 ,ll sz0){
	ll val1 = -1;
	ll val0 = -1;
	ll pos = 1;
	for(int i = 0 ; i < n ; i ++){
		if(s[i] == '0'){
			if(val0 == -1){
				val0 = geth(pos , pos + sz0-1);
			}
			if(val0!=geth(pos , pos + sz0-1))return(0);
			pos+=sz0;
		}
		else{
			if(val1 == -1){
				val1 = geth(pos , pos + sz1-1);
			}
			if(val1!=geth(pos , pos + sz1-1))return(0);
			pos+=sz1;
		}
	}
	if(val1 == val0)
		return(0);
	return(1);
}

int main(){
    migmig
    cin >> s >> t;
    for(auto i : s)
		sum+=i - '0';
	n = s.size() , m = t.size();
	ll cnt = 1;
    if(sum < n-sum){
		for(auto &i : s)
			if(i=='0')
				i = '1';
			else
				i = '0';
		sum = n-sum;
	}
	pww[0] = inv[0] = 1;
	ll in = pw(p , mod-2);
	for(int i = 1; i < 1000020 ; i ++){
		pww[i] = pww[i-1]*p %mod ;
		inv[i] = inv[i-1]*in%mod;
	}
	for(cnt ; cnt <= m; cnt ++){
		th[cnt] = (th[cnt - 1] + pww[cnt] * (t[cnt-1] - 'a' + 1))%mod;
	}
	ll cnt1 = sum , cnt0 = n-sum;
	for(int i = 1 ; i ; i ++){
		ll sum1= i * cnt1;
		ll sum0 = m - sum1;
		if(sum0 <= 0)break;
		if(sum0%cnt0)continue;
		if(sum0 < cnt0)break;
		ans+=solve(i , sum0 / cnt0);
	}
	cout << ans;
    return(0);
}