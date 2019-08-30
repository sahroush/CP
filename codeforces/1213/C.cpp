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

ll n,q;
ll m;
ll sum=0;
vector < ll > vec;

int main(){
	cin >> q;
	for(ll i = 0 ; i < q ; i ++){
		cin >> n >> m;
		ll cnt=2;
		sum=0;
		vec.push_back(m%10);
		while (m*cnt%10!=vec[0]){
			vec.push_back(m*cnt%10);
			cnt++;
		}
		ll mod = n/m;
		//cout << mod;
		ll sz=vec.size();
		for (ll j = 0 ; j < sz ; j++){
			sum+=vec[j]*(mod/sz);
		}
		mod =mod%sz;
		
		for (ll j = 0 ; j < mod ; j ++){
			sum+=vec[j];
		}
		cout << sum << endl;
		sz=vec.size();
		for (ll j = 0 ; j < sz ; j++) vec.pop_back();
	}
	



	return(0);
}
//When we hit our lowest poll, we are open to the greatest change.
//If I try, I fail. If I don't try, I'm NEVER GOING TO GET IT.
//Sometimes, l is like this dark tunnel. You can't always see the light at the end of the tunnel. But if you just keep moving... you will come to a better place.
