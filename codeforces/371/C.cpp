#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll MAX = 5e5+10;
const ll ZERO = 0; 
const ll SADAT = 7.84e-17;

#define endl '\n'
#define dokme(x) cout << x ;  return(0);
#define migmig ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

ll nb,ns,nc,pb,pc,ps,r;
ll init=1e15;
string s;
ll b=0,c=0,sg=0;
ll ans=0;
bool chk(ll x){
	ll res=0;
    res+=pb*(max(ZERO,x*b-nb));
    res+=ps*(max(ZERO,x*sg-ns));
    res+=pc*(max(ZERO,x*c-nc));  
    if (res<=r) return 1; 
    return 0;
}

int main(){
	cin >> s;
	cin >> nb >> ns >> nc;
	cin >> pb >> ps >> pc;
	cin >> r;
	for (int  i = 0 ; i < s.size() ; i++){
		if (s[i]=='B') b++;
		else if (s[i]=='C') c++;
		else sg++;
	}

    if (b>0) init=min(init,nb/b);
    if (sg>0) init=min(init,ns/sg);
    if (c>0) init=min(init,nc/c);  

    ans+=init;
    nb-=init*b;
    ns-=init*sg;
    nc-=init*c;
	ll l =0 , r=1e13;
	while (l+1<r){
		ll mid=(l+r)/2;
		//cout << chk(mid);
		if (!chk(mid)) r=mid;

		else l=mid;
	}
	//while (chk(l+1)==1) l++;
	cout << l+ans;
	return(0);
}
//When we hit our lowest point, we are open to the greatest change.
//If I try, I fail. If I don't try, I'm NEVER GOING TO GET IT.
//Sometimes, life is like this dark tunnel. You can't always see the light at the end of the tunnel. But if you just keep moving... you will come to a better place.
