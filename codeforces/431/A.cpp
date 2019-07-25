#include <bits/stdc++.h>
#include<iostream>
#include<cmath>
using namespace std;
typedef long long ll;
const ll MAX1 = 1e5+10;
#define migmig ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
 

	
	

 
int main(){
	int a,b,c,d;
	cin >> a >> b >> c >> d;
	string s;
	cin >> s;
	int cnt=0;
	for(int i=0;i<s.size();i++){
		if (s[i]=='1'){
			cnt+=a;
		}
		if (s[i]=='2'){
			cnt+=b;
		}
		if (s[i]=='3'){
			cnt+=c;
		}
		if (s[i]=='4'){
			cnt+=d;
		}
	}
	cout << cnt;
 
	return(0);
}
 
//When we hit our lowest point, we are open to the greatest change.
//If I try, I fail. If I don't try, I'm NEVER GOING TO GET IT.
//Sometimes, life is like this dark tunnel. You can't always see the light at the end of the tunnel. But if you just keep moving... you will come to a better place.
