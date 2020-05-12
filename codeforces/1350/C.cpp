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
int a[maxn];
ll ans = 1;
vector < int > cnt;
vector < int > boz;
map < int , int > ct;

int main(){
    migmig
    cin >> n;
    for(int i = 0 ; i < n ; i ++)
		cin >> a[i];
	if(n == 1)
		dokme(a[0])
	if(n == 2){
		dokme(ll(a[0]) * ll(a[1]) / __gcd((ll)a[0] , (ll)a[1]));
	}
	for(int i = 2 ; i < 450 ; i ++){
		cnt.clear();
		for(int j = 0 ; j < n ; j ++){
			int cn = 0;
			while(a[j]%i == 0){
				a[j]/=i;
				cn++;
			}
			cnt.pb(cn);
		}
		sort(cnt.begin() , cnt.end());
		ans*=pw(i , cnt[1] , 1e18);
	}
	for(int i = 0 ; i < n ; i ++)
	if(a[i] > 1){
			boz.pb(a[i]);
		}
    if(boz.size() > n-2){
		sort(boz.begin() , boz.end());
		for(int i : boz){
			ct[i]++;
			if(ct[i] == n-1){ans*=i;break;}
		}
	}
    
    cout << ans;
    
    return(0);
}