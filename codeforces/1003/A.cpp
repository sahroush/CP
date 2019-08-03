#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll MAX1 = 1e5+10;

#define migmig ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);


int main(){
	int n;
	cin  >> n;
	int l[100];
	for (int i = 0 ; i < n; i++ ){
		cin >> l[i];
	}
	sort(l,l+n);
	int cnt=1,mx=-100;
	for (int i=1;i<n;i++){
		if (l[i]==l[i-1]){
			cnt++;
		}
		else{
			mx=max(mx,cnt);
			cnt=1;
		}
	}
	mx=max(cnt,mx);
	cout << mx;
	
	return(0);
}
//When we hit our lowest point, we are open to the greatest change.
//If I try, I fail. If I don't try, I'm NEVER GOING TO GET IT.
//Sometimes, life is like this dark tunnel. You can't always see the light at the end of the tunnel. But if you just keep moving... you will come to a better place.
