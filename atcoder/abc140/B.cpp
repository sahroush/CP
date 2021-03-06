#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll maxn = 30;
const ll ZERO = 0;
const ll SADAT = 7.84e-17;
const ll INF = 1e10;
const ll mod = 1e9+7;

#define endl '\n'
#define dokme(x) cout << x ;  return(0);
#define migmig ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_init freopen("input.txt", "r+", stdin); freopen("output.txt", "w+", stdout);

int n ;
int a[maxn] , b[maxn] ,c[maxn];

int main(){
	cin >> n;
	for (int i = 0 ; i < n ; i ++){
		cin >> a[i];
	}
	for (int i =0 ; i < n ; i ++){
		cin >> b[i];
	}
	for (int i = 0 ; i < n-1 ; i ++){
		cin >> c[i];
	}
	ll ans = 0;
	for (int i = 0; i < n ; i++){
		ans += b[a[i]-1];
		if (i> 0){
			if (a[i-1] + 1 == a[i]){
				ans+=c[a[i-1]-1];
			}
		}
	}
	cout << ans;

	return(0);
}
//When we hit our lowest point, we are open to the greatest change.
//If I try, I fail. If I don't try, I'm NEVER GOING TO GET IT.
//Sometimes, l is like this dark tunnel. You can't always see the light at the end of the tunnel. But if you just keep moving... you will come to a better place.
