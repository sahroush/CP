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

int n;
ll a[maxn];
map <ll , int > cnt;

int main(){
    migmig
    cin >> n;
    ll sum = 0;
    for(int i = 0 ; i < n ; i ++)
		cin >> a[i];
	sort(a , a + n);
	if(a[n-1] == 0)dokme("cslnb");
	for(int i = 0 ; i < n ; i ++)
		sum+=a[i];
	for(int i = 0 ; i < n; i ++)
		cnt[a[i]]++;
	int mx=  0;
	int dick = 0;
	for(int i = 0 ; i < n ; i ++)
		mx= max(mx,cnt[a[i]]);
	if(mx > 2)dokme("cslnb");
	for(int i = 0 ; i < n;  i ++)
		if(cnt[a[i]] > 1)dick++;
	if(dick > 2)dokme("cslnb");
	for(int i = 0 ; i < n ; i ++)
		if(cnt[a[i]] > 1 and cnt[a[i] -1] > 0){dokme("cslnb")}
	
	if(n == 1) dokme(((a[0]%2)? "sjfnb": "cslnb"));
    if(a[1] == 0)dokme("cslnb");
    bool oke = 0;
    for(int i = 0 ; i < n ; i ++){
		if(a[i]){
			if(i){
				if(a[i]-1 != a[i-1])oke = 1;
			}
			else oke = 1;
		}
	}
    if(oke == 0)dokme("cslnb");
    ll boz = sum - n*(n - 1)/2;
    dokme(((boz%2)? "sjfnb": "cslnb"));
    return(0);
}