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
pii d[maxn];
int ch[maxn];

int main(){
    migmig
    cin >> n;
    for(int i = 1 ; i <= n ; i ++)
		cin >> d[i].first, d[i].second = i;
	sort(d+1 , d+n+1);
	reverse(d+1 , d+n+1);
    for(int  i = 1 ; i <= n ; i ++)
		ch[i] = d[i].second*2-1;
    for(int  i = 1 ; i < n ; i ++)
		cout << ch[i] << ' ' << ch[i+1] << endl;
	int sz = n;
	for(int i = 1 ; i <= n ; i ++){
		if(i + d[i].first - 1 < sz)
			cout << ch[i + d[i].first - 1] << ' ' << d[i].second * 2 << endl;
		else{
			cout << ch[sz++] << ' ' << d[i].second*2 << endl;
			ch[sz]=d[i].second*2;
		}
	}
    return(0);
}