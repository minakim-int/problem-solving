//from paiza.jp skill check
#include <bits/stdc++.h>

using namespace std;

int s[200001];
int main()
{
    cin.tie(0); ios::sync_with_stdio(false);
    int n; cin>>n;
    int a, b; cin>>a>>b; // 登れるステップ数
    for(int i=1; i<=n; i++)
    {
        s[i]=1;　// 階段初期化
    }
    for(int i=1; i<=n; i++){
        if((i%a==0||i%b==0)) // aまたはｂステップで登れる階段は０にする
            s[i]=0;
        else if(i%(a+b)==0) // a＋ｂステップで登れる階段は０にする
            s[i]=0;
        if(s[i]==0) // 上の段階で既に０になった階段からaまたはｂステップで登れる階段も０にする
        { 
            s[i+a]=0;
            s[i+b]=0;
        }
    }
    s[n]=0;
    cout<<accumulate(s+1, s+n, 0);
  
    return 0;
}
