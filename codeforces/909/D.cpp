#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int  ,int > pii;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const ll maxn  = 3e6;
const ll mod =1e9+7;
const ld PI = acos((ld)-1);

#define pb(x) push_back(x);
#define endl '\n'
#define dokme(x) return(cout << x , 0);
#define migmig ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ms(x , y) memset(x , y , sizeof x);
#define file_init freopen("input.txt", "r+", stdin); freopen("output.txt", "w+", stdout);
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}

string s;
vector < pii > vec;
vector < pii > boz;

bool chk(){
	int n = vec.size();
	if(n <= 1)
		return(0);
	for(int i = 0 ; i < n ; i ++){
		if(i == 0 or i == n - 1)vec[i].second--;
		else vec[i].second-=2;
	}
	boz.clear();
	for(auto j : vec){
		if(j.second > 0){
			if(boz.empty()){
				boz.pb(j);}
			else if (boz.back().first == j.first){
				boz.back().second+=j.second;}
			else{
				boz.pb(j);}
		}
	}
	swap(boz , vec);
	return(1);
}

int main(){
    migmig
    cin >> s;
    for(auto i : s){
		if(vec.empty()){
			vec.pb(pii(i - 'a' , 1));}
		else if (i-'a' == vec.back().first){
			vec.back().second++;}
		else{
			vec.pb(pii(i - 'a' , 1));}
	}
    int cnt = 0;
    while(1){
		if(chk()){
			cnt++;
		}
		else{
			dokme(cnt);
		}
	}
    return(0);
}

