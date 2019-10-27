#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const ll maxn = 1e6+10;
const ll ZERO = 0;
const ll SADAT = 7.84e-17;
const ll INF = 1e9;
const ll mod = 1e9+7;

#define endl '\n'
#define dokme(x) cout << x ;  return(0);
#define migmig ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_init freopen("input.txt", "r+", stdin); freopen("output.txt", "w+", stdout);


int n;
vector <pair <int , int> > vec;
bool mark [maxn];


void dfs(int v){
    mark[v] = 1;
    for (int i = 0 ; i < n ; i ++){
        if (vec[v].first == vec[i].first or vec[v].second== vec[i].second){
            if (!mark[i]){
                dfs(i);
            }
        }
    }
}

int main (){
    migmig;
    cin >> n;
    int x , y;
    for (int i = 0 ; i < n ; i ++){
        cin >> x >> y;
        vec.push_back(make_pair(x , y));
    }
    int cnt = 0;
    for (int i = 0 ; i < n ; i++){
        if (!mark[i]){
            dfs(i);
            cnt++;
        }
    }
    cout << --cnt;
    return (0);
}



//When we hit our lowest point, we are open to the greatest change.
//If I try, I fail. If I don't try, I'm NEVER GOING TO GET IT.
//Sometimes, life is like this dark tunnel. You can't always see the light at the end of the tunnel. But if you just keep moving... you will come to a better place.
//It is important to draw wisdom from diffrent places. If you take it from only one place it becomes rigid and stale.
