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

int q;
int x , y , tp;
bool mark[110];
vector <int> vec[110] ;
vector < pair <int , int> > pos;

void dfs(int v){
    mark[v] = 1;
    for (int  i = 0 ; i < vec[v].size() ; i ++){
        int u = vec[v][i];
        if (!mark[u]){
            dfs(u);
        }
    }

}



int main (){
    migmig;
    cin >> q;
    int cnt = 0;
    while(q--){
        cin >> tp;
        cin >> x >> y;
        if (tp == 1){
            for (int i = 1 ; i <= pos.size() ; i ++ ){
                int a = pos[i-1].first , b = pos[i-1].second;
                if ((a < x and x < b) or (a < y and y < b)){
                    vec[pos.size()+1].push_back(i);

                }
                if ((x < a and a < y) or (x < b and b < y)){
                    vec[i].push_back(pos.size() + 1);
                }
            }
            pos.push_back(make_pair(x , y));
        }
        else{
            fill(mark , mark +101 ,  0);
            dfs(x);
            if (mark[y]){
                cout << "YES" << endl;
            }
            else{
                cout << "NO" << endl;
            }
        }
    }

    return (0);
}



//When we hit our lowest point, we are open to the greatest change.
//If I try, I fail. If I don't try, I'm NEVER GOING TO GET IT.
//Sometimes, life is like this dark tunnel. You can't always see the light at the end of the tunnel. But if you just keep moving... you will come to a better place.
//It is important to draw wisdom from diffrent places. If you take it from only one place it becomes rigid and stale.
