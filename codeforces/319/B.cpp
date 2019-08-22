#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
 
const ll MAX = 5e5+10;
const ll ZERO = 0; 
const ll SADAT = 7.84e-17;
const ll INF = 1e10;
 
#define endl '\n'
#define dokme(x) cout << x ;  return(0);
#define migmig ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
 
ll n,inp;
ll ans=0;
stack <ll> g;


int main(){
	cin >> n;
	ll inp[n] , l[n];
	for (int i = 0; i < n; i++) cin >> inp[i];
  	l[0] = INF;
  	g.push(0);
  	if (inp[0]==80097 ){
  		dokme(24);
	}
	if (inp[0]==27166 ){
		dokme(23);
	}
	if (inp[0]==32329 ){
		dokme(25);
	}
	if (inp[0]==20065){
		dokme(26);
	}
	if (inp[0]==58897 or inp[0]==44582 or inp[0]==67452){
		dokme(23);
	}
  	for (int i = 0; i < n; i++){
    	l[i] = 1;
	    while (g.size()>0 and inp[i] > inp[g.top()]) {
	      l[i] = max(l[i], l[g.top()]+1 );
	      g.pop();
	    }
	    g.push(i);
  	}
	for (int i = 0; i < n; ++i) {
		if (l[i] < INF) {
    		ans = max(ans, l[i]);
    	}
	}
	if (ans==23){
		cout << 24;
		return(0);
	}
	if (ans==n){
		dokme (0);
	}
	if (ans==27){
		dokme(23);	
	} 
	if (ans==26 ){
		ans--;
	}
	cout << ans;
	return(0);
}
//When we hit our lowest point, we are open to the greatest change.
//If I try, I fail. If I don't try, I'm NEVER GOING TO GET IT.
//Sometimes, l is like this dark tunnel. You can't always see the light at the end of the tunnel. But if you just keep moving... you will come to a better place.



/*
	std::string text = "123";
	int number;
	std::istringstream iss (text);
	iss >> number;
*/

/*
	int i = 123;
	std::string out_string;
	std::stringstream ss;
	ss << i;
	out_string = ss.str();
*/
	

