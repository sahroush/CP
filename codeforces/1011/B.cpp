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

int n, m;
int a[maxn];

bool chk(int x){
	int sum = 0;
	for(int i = 0 ; i < 300 ; i ++){
		sum+=a[i]/x;
	}
	return(sum >= m);
}

int main(){
    migmig
    cin >> m >> n;
    for(int i = 0 ; i < n ; i ++){
		int x;
		cin >> x;
		a[x]++;
	}
	sort(a , a + 200);
	int l = 0 , r = 1e5;
	while(r - l > 1){
		int mid = (l+r)/2;
		if(chk(mid))
			l = mid;
		else 
			r = mid;
	}
    cout << l;
    return(0);
}