#include <bits/stdc++.h>
using namespace std;
typedef long long       ll;
typedef long double     ld;
typedef string          str;
#define all(x)			(x).begin(),(x).end()
#define Sort(x)			sort(all(x))
#define A               first
#define B               second
#define sep             ' '
#define endl            '\n'
#define fast_io         ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
const int MAX1 = 3e5 + 7;
ll a, T, d, e, l, r, z, x, y, cnt, flag, mod = 1e9+7, num[MAX1], mark[MAX1];
string s, t;
vector <ll> vec[MAX1];
vector <ll> ans;
// i am a bot and i am eshaq
void DFS(ll u){
    ans.push_back(u);
    mark[u] = 1;
    for (int v = 0; v < vec[u].size(); ++v){
        if (!mark[vec[u][v]]){
            DFS(vec[u][v]);
        }
    }
}
int main(){
	fast_io;
	cin >> T;
	for (int k = 0; k < T; ++k){
        cin >> a;
        fill(mark, mark+a+1, 0);
        for (int i = 0; i < 3e5; ++i)   vec[i].clear();
        for (int i = 1; i <= a; ++i){
            cin >> z;
            vec[i].push_back(z);
            vec[z].push_back(i);
        }
        for (int i = 1; i <= a; ++i){
            if (!mark[i]){
                ans.clear();
                DFS(i);
                for (int j = 0; j < ans.size(); ++j)    mark[ans[j]] = ans.size();
            }
        }
        for (int i = 1; i <= a; ++i) cout << mark[i] << sep;
        cout << endl;
	}
    return 0;
}
//ablah
/*                          now or never                         */
