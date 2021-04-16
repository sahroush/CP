//曇り空 のぞいた予感
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int , int> pii;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int maxn = 3e6;
const ll mod = 1e9+7;

#define pb push_back
#define endl '\n'
#define dokme(x) cout << x , exit(0)
#define ms(x , y) memset(x , y , sizeof x)
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}

int qu;
int n;
string s;
int cnt[3];

queue < int > q;

int32_t main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin >> qu;
	while(qu--){
		cin >> n;
		cin >> s;
		ms(cnt , 0);
		for(int i = 0 ; i < n ; i ++)cnt[(s[i] == 'M')] ++;
		if(cnt[1] * 2 != cnt[0]){
			cout << "NO" << endl;
			continue;
		}
		ms(cnt , 0);
		bool ok = 1;
		for(int i = 0 ; i < n ; i ++){
			if(s[i] == 'T'){
				q.push(i);
			}
			if(s[i] == 'M'){
				if(!q.size()){
					ok = 0 ;
					break;
				}
				int v = q.front();
				q.pop();
				s[v] = 'F';
			}
		}
		while(q.size())q.pop();
		reverse(s.begin() , s.end());
		for(int i = 0 ; i < n ; i ++){
			if(s[i] == 'T'){
				q.push(i);
			}
			if(s[i] == 'M'){
				if(!q.size()){
					ok = 0 ;
					break;
				}
				int v = q.front();
				q.pop();
				s[v] = 'F';
			}
		}
		while(q.size())q.pop();
		cout << ((ok) ? "YES" : "NO") << endl;
	}

	return(0);
}
