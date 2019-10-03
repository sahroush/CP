#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll maxn = 1e3+10;
const ll ZERO = 0;
const ll SADAT = 7.84e-17;
const ll INF = 1e10;
const ll mod = 1e9+7;

#define endl '\n'
#define dokme(x) cout << x ;  return(0);
#define migmig ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_init freopen("input.txt", "r+", stdin); freopen("output.txt", "w+", stdout);

int n , m;
int a[maxn][maxn];

bool chk(ll x){

	

	
	bool b[maxn][maxn];
	for (int i = 0 ; i < n ; i ++){
		for (int j = 0 ; j < m ; j ++){
			if (a[i][j] >=x){
				b[i][j] = 1;
			}
			else{
				b[i][j] = 0 ;
			}
		}
	}
	
	vector<int> vec[maxn];
	for (int i = 0 ; i < n ; i ++){
		for (int j = 0 ; j < m ; j ++){
			if (b[i][j]){
				vec[i].push_back(j);
			}
		}
	}
	int cnt[maxn][maxn];
	for (int i = 0 ; i < maxn ; i ++){
		fill(cnt[i] , cnt[i]+maxn , 0);
	}
	for (int i = 0 ; i < n ; i ++){
		for (int j = 0 ; j < vec[i] . size() ;  j++){
			for (int k = j+1 ;k<vec[i].size(); k++ ){
				cnt[vec[i][j]][vec[i][k]]++;
				if (cnt[vec[i][j]][vec[i][k]] == 2){
					return(1);
				}
			}
		}
	}
	return(0);
}

int main(){
    migmig

    cin >> n >> m;
    
    for (int  i = 0 ; i < n ; i ++){
    	for (int j = 0 ; j < m ; j++){
    		cin >> a[i][j];
		}
	}
	ll l = 0, r = 1e9+10;

	
	while (r-l>1){
	
		ll mid = (l+r) /2;
		
	
		if (chk(mid)){
			l = mid;
		}
		else{
			r = mid;
		}
		
	}
	while(!chk(r)){
	    r--;
	}
	cout << r;
 
    return(0);
}