#include <iostream>
#include <vector>

using namespace std;
int main(){
    int b;
    while(cin>>b){
        if(b==0)break;
        int sum=0;
        int left=1;
        for(int right=0;right<1000000000;right++){ 
            sum+=right;
            while(sum>b){
                sum-=left;
                left++;
            }
            if(sum==b){
                cout<<left<<" "<<right-left+1<<endl;
                break;
            }
        }
    }
}