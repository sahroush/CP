#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll MAX1 = 1e5+10;

#define migmig ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);


int main(){
	int n;
	cin  >> n;
	int v1,v2,p1,p2;
	cin >> v1 >> v2 >> p1 >> p2;
	int a=v1*n+2*p1;
	int b=v2*n + 2 * p2;
	swap(a,b);
	if (a>b){
		cout << "First";
	}
	else if ( b>a){
		cout << "Second";
	}
	else{
		cout << "Friendship";
	}
	
	return(0);
}
//When we hit our lowest point, we are open to the greatest change.
//If I try, I fail. If I don't try, I'm NEVER GOING TO GET IT.
//Sometimes, life is like this dark tunnel. You can't always see the light at the end of the tunnel. But if you just keep moving... you will come to a better place.
