#include <bits/stdc++.h>

using namespace std;

int n , q , a[110];

int32_t main(){
    cin >> q;
    while(q --){
        cin >> n;
        for(int i = 1 ; i <= n ; i ++)cin >> a[i];
        int mj = 1 , cnt = 1;
        for(int i = 2 ; i <= n ; i ++){
            if(a[i] != a[mj])cnt--;
            if(cnt == 0)mj = i;
            if(a[i] == a[mj])cnt++;
        }
        int ans;
        for(int i = 1 ; i <= n ; i ++)if(a[i] ^ a[mj])ans = i;
        cout << ans << endl;
    }
    return 0;
}