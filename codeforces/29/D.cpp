#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const ll maxn = 320;
const ll ZERO = 0;
const ll SADAT = 7.84e-17;
const ll INF = 1e9;
const ll mod = 1e9+7;

#define endl '\n'
#define dokme(x) cout << x ;  return(0);
#define migmig ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_init freopen("input.txt", "r+", stdin); freopen("output.txt", "w+", stdout);

int n , k = 0 , pth[maxn] , cnt[maxn];
vector <int> vec[maxn] ;
bool mark[maxn] ;
map <pair <int , int> , int > mp;
map <pair <int , int> , vector <int> > path;

void dfs(int v ,  vector < int > ph , int source){
    mark[v] = 1;
    ph.push_back(v);
    path[make_pair(source , v)] = ph;
    for (int i = 0 ; i  < vec[v].size() ; i ++){
        int u = vec[v][i];
        if (!mark[u]){
            dfs(u , ph , source);
        }
    }
    if (vec[v].size() == 1 and v!=1){
        k++;
    }
}

int main (){
    //migmig
    cin >> n;
    for (int i = 1; i < n ; i ++){
        int x , y;
        cin >> x >> y;
        vec[x].push_back(y);
        vec[y].push_back(x);
        mp[make_pair(min(x , y) , max(x , y))] = i;
    }
    for (int  i =1 ; i <=n ; i ++){
        fill(mark , mark+maxn , 0);
        k = 0;
        vector <int> boz;
        dfs(i , boz , i);
    }
    for (int i = 0 ; i  < k ; i ++){
        cin >> pth[i];
    }
    int pos = 1;
    vector <int> ans;
    for (int i = 0 ; i < k ; i ++){
        vector <int> boz;
        boz = path[{pos , pth[i]}];
        pos = pth[i];
        for (int i = 0 ; i < boz.size() ; i ++){
            ans.push_back(boz[i]);
        }
        ans.pop_back();
        if (i == k-1){
            boz = path[{pos , 1}];
            for (int i = 0 ; i < boz.size() ; i ++){
                ans.push_back(boz[i]);
            }
        }
    }

    for (int i = 0 ; i < ans.size()-1 ; i ++){
        cnt[mp[{min(ans[i] , ans[i+1]) , max(ans[i] , ans[i+1])}]]++;
        if (cnt[mp[{min(ans[i] , ans[i+1]) , max(ans[i] , ans[i+1])}]] > 2){
            dokme(-1);
        }
    }
    for (int i = 0 ; i < ans.size() ; i ++){
        cout << ans[i] << '\t';
    }



    return(0);
}



//When we hit our lowest point, we are open to the greatest change.
//If I try, I fail. If I don't try, I'm NEVER GOING TO GET IT.
//Sometimes, life is like this dark tunnel. You can't always see the light at the end of the tunnel. But if you just keep moving... you will come to a better place.
//It is important to draw wisdom from diffrent places. If you take it from only one place it becomes rigid and stale.
