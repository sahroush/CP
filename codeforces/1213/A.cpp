#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
 
const ll maxn = 1e5+10;
const ll ZERO = 0; 
const ll SADAT = 7.84e-17;
const ll INF = 1e10;
 
#define endl '\n'
#define dokme(x) cout << x ;  return(0);
#define migmig ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int n;
int l[100];
int main(){
	cin >> n;
	for (int i = 0 ; i < n ; i ++){
		cin >> l[i];
	}
	int cnt,mx=1e9;
	for (int  i = 0 ; i < n ; i ++){
		cnt=0;
		for (int j = 0 ; j <  n ; j ++){
			cnt+=abs(l[i]-l[j])%2;
		}
		mx=min(cnt,mx);
	}
	cout << mx;

	
	return(0);
}
//When we hit our lowest poll, we are open to the greatest change.
//If I try, I fail. If I don't try, I'm NEVER GOING TO GET IT.
//Sometimes, l is like this dark tunnel. You can't always see the light at the end of the tunnel. But if you just keep moving... you will come to a better place.
