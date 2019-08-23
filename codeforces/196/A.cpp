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

int n,m;
int l[150];
string s;
int main(){
	cin >> s;
	string ans;
	int mx=0;
	
	for (int j = 26 ; j >=0;j--){
		for (int i=mx ; i<s.size() ; i ++){
			if (s[i]=='a'+j){
				mx=i;
				ans+=s[i];
			}
		}
	}
	cout << ans;
 
    return (0);
}
