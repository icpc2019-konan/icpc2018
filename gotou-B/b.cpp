#include <iostream>
#include <vector>

using namespace std;
int main(){
    int w,h,t,p;
    while(cin>>w>>h>>t>>p){
        if(w+h+t+p==0)break;
        vector<vector<int>> v(1000,vector<int>(1000,0)); //適当に大きく取る
        for(int i=0;i<h;i++){
            for(int j=0;j<w;j++){
                v[1000-i-1][j]=1;
            }
        }
        int x0=0,y0=999; //現状の原点
        // デバッグ用
        // auto debug=[&](int y,int x){
        //     for(int i=0;i<y;i++){
        //         for(int j=0;j<x;j++){
        //             cout<<" "<<v[1000-i-1][j];
        //         }
        //         cout<<endl;
        //     }
        //     cout<<"x0,y0= "<<x0<<" "<<y0<<endl;
        // };
        for(int i=0;i<t;i++){
            int d,c;
            cin>>d>>c;
            if(d==1){ //横向きに折る
                for(int j=0;j<y0+1;j++){
                    int idx=x0+c;
                    //cout<<idx<<endl;
                    for(int k=0;k<c;k++){
                        v[j][idx+k]+=v[j][idx-k-1];
                    }
                }
                x0=x0+c;
            }else { //縦向きに折る
                for(int j=x0;j<1000;j++){
                    for(int k=0;k<c;k++){
                        int idx=y0-c;
                        v[idx-k][j]+=v[idx+k+1][j];
                    }
                }
                y0=y0-c;
            }
        }
        
        for(int i=0;i<p;i++){
            int x,y;
            cin>>x>>y;
            cout<<v[y0-y][x0+x]<<endl;
        }
    }

}