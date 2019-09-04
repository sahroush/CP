#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
 
const ll maxn = 2e5+10;
const ll ZERO = 0;
const ll SADAT = 7.84e-17;
const ll INF = 1e10;
const ll mod = 1e9+7;
 
#define endl '\n'
#define dokme(x) cout << x ;  return(0);
#define migmig ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_init     freopen("input.txt", "r+", stdin); freopen("output.txt", "w+", stdout);
 
int n , b , g;
pair <int ,  int >  l[300+10];

bool cnt1[400]  , cnt2[400];
 
 
int main(){
	
	cin >> b >> g >> n;
	int cnt = 0 ;
	int minb=0 , ming=0;
	if (n-b > 0){
		ming = n-b;
	}
	if (n-g > 0){
		minb = n-g;
	}
	ll ans  = 0 ;
	for (int i = 0 ; i <= n ; i ++){
		if (n-i >= ming and i >= minb and n-i <= g and i <= b  ){
			ans++;
		}
	}
	cout << ans;
	
	
	
	return(0);
}
	
	
 
 
 
//When we hit our lowest point, we are open to the greatest change.
//If I try, I fail. If I don't try, I'm NEVER GOING TO GET IT.
//Sometimes, l is like this dark tunnel. You can't always see the light at the end of the tunnel. But if you just keep moving... you will come to a better place.
