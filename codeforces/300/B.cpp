#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll maxn = 2e4+10;
const ll ZERO = 0;
const ll SADAT = 7.84e-17;
const ll INF = 1e10;
const ll mod = 1e9+7;

#define endl '\n'
#define dokme(x) cout << x ;  return(0);
#define migmig ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_init freopen("input.txt", "r+", stdin); freopen("output.txt", "w+", stdout);

int n , m , a[maxn] , b[maxn] , cnt = 0;
vector  <int>  vec[30];
bool f [maxn];
int indx[maxn];


int main(){
    migmig
    fill(f , f+maxn , 0);
    fill(indx , indx +maxn , -1);
	cin >> n >> m;
	for (int i = 0 ; i < m ; i ++){
		cin >> a[i] >> b[i];
	}
	for (int i = 0 ; i < m ; i ++){
		if(indx[a[i]-1] == -1 and indx[b[i]-1] == -1){

			vec[cnt].push_back(a[i]);
			vec[cnt].push_back(b[i]);
            cnt++;
            if (cnt > n/3 ){
                dokme(-1);
            }

			if (vec[cnt-1].size() > 3){
				dokme(-1);
			}
			f[a[i]-1] = 1;
			f[b[i]-1] = 1;
			indx[a[i]-1] = cnt-1;
			indx[b[i]-1] = cnt-1;
		}
		else if (indx[b[i]-1] == -1){

			vec[indx[a[i]-1]].push_back(b[i]);
			if (vec[indx[a[i] - 1 ]] . size() > 3){
				dokme(-1);
			}
			f[b[i]-1] = 1;
			indx[b[i]-1] = indx[a[i]-1];
		}
		else if (indx[a[i]-1] == -1){
			vec[indx[b[i]-1]].push_back(a[i]);
			if (vec[indx[b[i] - 1 ]] . size() > 3){
				dokme(-1);
			}
			f[a[i]-1] = 1;
			indx[a[i]-1] = indx[b[i]-1];
		}
	}
	stack <int> stk;
	for (int i = 0 ; i < n ; i ++){
		if (!f[i]){
			stk.push(i+1);
		}
	}
	for (int i = 0 ; i < n/3 ; i ++){
		int d = 0;
		for (int j = 0 ;j < vec[i].size();j++ ){
			cout << vec[i][j] << '\t';
			d++;
		}
		for (int j = 0 ; j < 3-d ; j++){
			cout << stk.top() << '\t';
			stk.pop();
		}
		cout << endl;

	}



    return(0);
}
//When we hit our lowest point, we are open to the greatest change.
//If I try, I fail. If I don't try, I'm NEVER GOING TO GET IT.
//Sometimes, life is like this dark tunnel. You can't always see the light at the end of the tunnel. But if you just keep moving... you will come to a better place.
//It is important to draw wisdom from diffrent places. If you take it from only one place it becomes rigid and stale.
