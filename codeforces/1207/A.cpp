#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
 
const ll maxn = 1e5+100;
const ll ZERO = 0; 
const ll SADAT = 7.84e-17;
const ll INF = 1000100000;
 
#define endl '\n'
#define dokme(x) cout << x ;  return(0);
#define migmig ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
 
ll b,p,f,h,c;
int q;
 
int main(){
	cin >> q;
	for (int i = 0 ; i < q ; i ++ ){
		cin >> b >> p >> f;
		cin >> h >> c;
		ll cnt = 0 ;
		if (h>c and b>1){
 
			if (p>0){
				cnt+=min(p,(b/2))*h;
				b=b/2-min(p,b/2);
				b*=2;
			}
			if (b>1){
				cnt+=c*min(f,(b/2));
			}
		}
		
		else{
			
			if (c>0 and b>1){
				cnt+=min(f,(b/2))*c;
				
				b=b/2-min(f,b/2);
				b*=2;
			}
			if (b>1 ){
				cnt+=h*min(p,(b/2));
			}
		}
		cout << cnt << endl;
	}
	
	
	
    
	return(0);
}
//When we hit our lowest point, we are open to the greatest change.
//If I try, I fail. If I don't try, I'm NEVER GOING TO GET IT.
//Sometimes, life is like this dark tunnel. You can't always see the light at the end of the tunnel. But if you just keep moving... you will come to a better place.