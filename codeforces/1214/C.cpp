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
 
int n;
string s;
stack < char > stk;
stack < char > els;
 
int main(){
	cin >> n;
	cin >> s;
	int flag=0, cnt=0;
	if ( n%2 == 1){
		dokme("No");
	}
	
	for (int i=n-1;i>=0;i--){
		if (s[i]==')'){
			flag++;
		}
		else if (flag!=0){
			cnt++;
			flag--;
		}
		else{
			//stk.push(s[i]);
		}
		
	}
	
	for (int i = 0 ; i < n ; i ++){
			
		if (s[i] == '('){
			stk.push('(');
		}
	
		else if (s[i] == ')' and stk.size() > 0 ){
			stk.pop();
			
		}
		else{
			els.push(')');
			
		}
	}
	if (n==cnt*2){
		dokme("Yes");
	}
	if (stk.size()==1  ){
		char a= stk.top();
		
		if (els.size()==1){
			char b = els.top();
			if (a==b){
				dokme("No");
			}
			else if(n-2==cnt*2){
				dokme("Yes");
			}
			else{
				dokme("No");
			}
		}
	}
	if(els.size()==2){
		char a = els.top();
		els.pop();
		char b= els.top();
		if (a!=b){
			dokme ( "yes");
		}
	}
	

	dokme("No");
	return(0);
}
	
	
 
 
 
//When we hit our lowest point, we are open to the greatest change.
//If I try, I fail. If I don't try, I'm NEVER GOING TO GET IT.
//Sometimes, l is like this dark tunnel. You can't always see the light at the end of the tunnel. But if you just keep moving... you will come to a better place.

