#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
 
const ll maxn = 5e5+10;
const ll ZERO = 0; 
const ll SADAT = 7.84e-17;
const ll INF = 1e10;
 
#define endl '\n'
#define dokme(x) cout << x ;  return(0);
#define migmig ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

string s;
int dpa[maxn],dpq[maxn],dp[maxn];

int main(){
	cin >> s; 
	string inp="";
	for (int i = 0 ; i < s.size() ; i ++ ){
		if(s[i]=='Q' or s[i]=='A'){
			inp+=s[i];
		}
	}
	s=inp;
	int n = s.size();
	bool f=0,f2=0;
	int cnta=0,cntq=0;
	int indxa=0,indxq=0;
	for (int i = 0 ; i < n ; i ++ ){
		if (s[i]=='Q'){
			f=1;
			cntq++;
		}
		if (s[i]=='A' and f){
			f2=1;
			cnta++;
			dpa[indxa]=cntq;
			indxa++;
		}
		else if ( s[i]=='Q' and f2 ){
			dpq[indxq]=cnta;
			indxq++;
		}
	}
	ll ans =0;
	dp[0]=0;
	for (int i = 0 ; i < indxa ; i ++){
		dp[i+1]=dp[i]+dpa[i];
	}
	for (int i = 0 ; i < indxq ; i ++ ){
		ans+=dp[dpq[i]];
	}
	
	cout << ans;
		
	return(0);
}
//When we hit our lowest poll, we are open to the greatest change.
//If I try, I fail. If I don't try, I'm NEVER GOING TO GET IT.
//Sometimes, l is like this dark tunnel. You can't always see the light at the end of the tunnel. But if you just keep moving... you will come to a better place.
