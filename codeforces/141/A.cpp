#include <bits/stdc++.h>
#include<iostream>
#include<cmath>

using namespace std;
typedef long long ll;
const ll MAX1 = 1e5+10;

#define abs(x) sqrt(x*x);
#define migmig ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int main(){
	string a,b,c;
	cin >> a>>b>>c;
	a=a+b;
	bool l[a.size()],l2[c.size()];
	memset(l,0,a.size());
	memset(l2,0,c.size());
	for (int i=0;i<a.size();i++){
		for (int j=0;j<c.size();j++){
			if (a[i]== c[j] and l[i]==0 and l2[j]==0){
				l[i]=1;
				l2[j]=1;
			}	
		}
	}
	for (int i=0;i<a.size();i++){
		if (l[i]==0){
			cout << "NO";
			return(0);
		}
	}
	for (int i=0;i<c.size();i++){
		if (l2[i]==0){
			cout << "NO";
			return(0);
		}
	}
	cout << "YES";
	
	return(0);
}
//When we hit our lowest point, we are open to the greatest change.
//If I try, I fail. If I don't try, I'm NEVER GOING TO GET IT.
//Sometimes, life is like this dark tunnel. You can't always see the light at the end of the tunnel. But if you just keep moving... you will come to a better place.