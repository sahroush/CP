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

int n , m , a[maxn];
int odd,even;
bool mark[maxn];
map < int , int > cnt;

int main(){
    migmig
    cin >> n >> m;
    for(int i = 0;  i < n ; i ++){
		cin >> a[i];   
		if(cnt[a[i]] == 0){
			if(a[i]%2 and odd < n/2){
				mark[i] = 1;
				cnt[a[i]] = 1;
				odd++;
			}
			if(a[i]%2==0 and even < n/2){
				mark[i] = 1;
				cnt[a[i]] = 1;
				even++;
			}
		}
	}
	int o =1 , e = 2;
	int ans = 0;
	for(int i = 0 ; i < n ; i ++){
		if(mark[i])continue;
		ans++;
		while(cnt[o])o+=2;
		while(cnt[e])e+=2;
		if(odd < even){
			if(o > m)
				dokme(-1)
			cnt[o]=1;
			odd++;
			a[i] = o;
		}
		else{
			if(e > m)
				dokme(-1)
			cnt[e]=1;
			even++;
			a[i] = e;
		}
	}
	cout << ans << endl;
	for(int i = 0 ; i < n; i ++)
		cout << a[i] << ' ';
    return(0);
}