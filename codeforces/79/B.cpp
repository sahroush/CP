#include <bits/stdc++.h>
#include<iostream>
#include<cmath>
using namespace std;
typedef long long ll;
const ll MAX1 = 1e5+10;
#define migmig ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);




int main(){
	ll n,m,k,t;
	cin >> n >> m >> k >> t;
	ll a,b;
	ll l[k][2];
	for (ll i=0;i<k;i++){
		cin >> a >> b;
		l[i][0]=a;
		l[i][1]=b;
	}
	ll cnt=0;
	bool f;
	for(ll i=0;i<t;i++){
		cin >> a >> b;
		cnt=0;
		f=0;
		for (ll i=0;i<k;i++){
			if (l[i][0]<=a and l[i][1]<=b){
				cnt++;
			}
			if (l[i][0]<a and l[i][1]>b){
				cnt++;
			}
			if (l[i][0]==a and l[i][1]==b){
				cout << "Waste" << endl;
				f=1;
				break;
			}
		}
		if (f==0){
			a=(a*m)+b-cnt;
			a-=m;
			if (a%3==0){
				cout << "Grapes";
			}
			else if(a%3==1){
				cout << "Carrots";
			}
			else if (a%3==2){
				cout << "Kiwis";
			}
			cout << endl;
		}
	}





	
	return(0);
}
//When we hit our lowest point, we are open to the greatest change.
//If I try, I fail. If I don't try, I'm NEVER GOING TO GET IT.
//Sometimes, life is like this dark tunnel. You can't always see the light at the end of the tunnel. But if you just keep moving... you will come to a better place.
