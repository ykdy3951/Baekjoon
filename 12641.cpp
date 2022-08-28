#include <bits/stdc++.h>
using namespace std;

bool chk[105];
bool lis[105];
int arr[105];
int ans;
int t, p, q;

void bt(int cnt, int val) {
    if (cnt == q) {
        ans=min(ans,val);
        return;
    }
    
    for(int i = 0; i < q; i++) {
        if (chk[i]) continue;
        chk[i]=true;
        int tmp=0;
        for(int j = arr[i]-1; !lis[j]; j--) {
            tmp++;
        }
        for(int j = arr[i]+1; !lis[j]; j++) {
            tmp++;
        }
        lis[arr[i]]=true;
        bt(cnt+1,val+tmp);
        lis[arr[i]]=false;
        chk[i]=false;
    }
}

int main(void){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    cin >> t;
    lis[0]=true;
    for(int i = 1; i <= t; i++)
    {
        cin >> p >> q;
        fill_n(chk,q,false);
        ans=987654321;
        for(int j = 0; j < q; j++)
        {
            cin >> arr[j];
        }
        lis[p+1]=true;
        bt(0,0);
        cout << "Case #" << i << ": " << ans << endl;
        lis[p+1]=false;
    }
    
    return 0;
}
