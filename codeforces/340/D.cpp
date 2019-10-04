#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll maxn = 2e5+10;
const ll ZERO = 0;
const ll SADAT = 7.84e-17;
const ll INF = 1e10;
const ll mod = 1e9+7;

#define endl '\n'
#define dokme(x) cout << x ;  return(0);
#define migmig ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_init freopen("input.txt", "r+", stdin); freopen("output.txt", "w+", stdout);

int LIS(vector<int> v ){
    if (v.size() == 0){
        return (0);
    }
    std::vector<int> t(v.size(), 0);
    std::vector<int>::iterator it;
    int len = 1;
    t[0] = v[0];
    for (int i = 1; i < v.size(); i++) {
        if (v[i] > t[len - 1]){
            t[len++] = v[i];
        }
        else{
            it= find(t.begin(), t.begin() + len, v[i]);
            if (it != t.begin() + len){
                continue;
            }
        }
            it = upper_bound(t.begin(), t.begin() + len, v[i]);
            *it = v[i];
    }
    return (len);
}

int n , inp;
vector < int > vec;

int main(){
    migmig
    cin >> n;
    for (int i = 0 ; i < n ; i ++){
        cin >> inp;
        vec.push_back(inp);
    }
    cout << LIS(vec);

    return(0);
}


//When we hit our lowest point, we are open to the greatest change.
//If I try, I fail. If I don't try, I'm NEVER GOING TO GET IT.
//Sometimes, life is like this dark tunnel. You can't always see the light at the end of the tunnel. But if you just keep moving... you will come to a better place.
//It is important to draw wisdom from diffrent places. If you take it from only one place it becomes rigid and stale.
