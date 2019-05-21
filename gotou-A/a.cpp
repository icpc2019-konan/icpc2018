#include <iostream>
#include <vector>

using namespace std;
int main(){
    int n;
    while(cin>>n){
        if(n==0)break;
        vector<int> v(n);
        double ave=0;
        for(int i=0;i<n;i++){
            cin>>v[i];
            ave+=v[i];
        }
        ave/=n;
        int ans=0;
        for(int i=0;i<n;i++){
            if(ave>=v[i])ans++;
        }
        cout<<ans<<endl;
    }
}