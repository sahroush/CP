#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll MAX = 5e5+10;
const ll ZERO = 0; 
const ll SADAT = 7.84e-17;

#define endl '\n'
#define dokme(x) cout << x ;  return(0);
#define migmig ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
 

 
ll n,x; 
int main(){
	cin >> n >> x;
  	ll res = 0;
	for (int i = 1; i <n+1; ++i) {
		if (x % i == 0 and x/i<=n){
	    	res++;
		}
	}
	cout << res;

	return(0);
}
//When we hit our lowest point, we are open to the greatest change.
//If I try, I fail. If I don't try, I'm NEVER GOING TO GET IT.
//Sometimes, life is like this dark tunnel. You can't always see the light at the end of the tunnel. But if you just keep moving... you will come to a better place.
