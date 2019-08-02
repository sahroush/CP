#include <bits/stdc++.h>
#include<iostream>
#include<cmath>

using namespace std;
typedef long long ll;
const ll MAX1 = 1e5+10;

#define abs(x) sqrt(x*x);
#define migmig ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
queue <int> q;
int main(){
	int n;
	string s;
	cin >> n;
	cin >> s;
	int cntm=0;
	int cnt=0;
	for (int i=0;i<s.size();i++){
		if (s[i]=='B'){
			cnt++;
		}
		else{
			if (cnt>0){
				cntm++;
				q.push(cnt);
				cnt=0;
				
			}
		}
	}
	if (cnt>0){
		cntm++;
		q.push(cnt);
	}
	cout << cntm << endl;
	for (int i=0;i<cntm;i++){
		cout << q.front() << '\t';
		q.pop();
	}
	
	return(0);
}
//When we hit our lowest point, we are open to the greatest change.
//If I try, I fail. If I don't try, I'm NEVER GOING TO GET IT.
//Sometimes, life is like this dark tunnel. You can't always see the light at the end of the tunnel. But if you just keep moving... you will come to a better place.
