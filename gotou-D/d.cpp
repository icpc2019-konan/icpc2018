#include <iostream>
#include <vector>

using namespace std;

struct Point{
    int t1,t2;
    Point(int t1,int t2){
        this->t1=t1;
        this->t2=t2;
    }
};
vector<vector<int>> v;
vector<Point> points;
int n;
int ans=0;

//将来的にプレーオフになる可能性があるか
bool will_playoff(int t1){
    int win=0,lose=0,not_match=0;
    for(int i=0;i<n;i++){
        if(t1==i)continue;
        if(v[t1][i]==1)win++;
        else if(v[t1][i]==0)lose++;
        else not_match++;
    }
    if(abs(win-lose)>not_match)return false;
    else return true;
}
//プレーオフであるかどうか
bool is_playoff(){
    for(int i=0;i<n;i++){
        int win=0,lose=0;
        for(int j=0;j<n;j++){
            if(i==j)continue;
            if(v[i][j]==1)win++;
            else if(v[i][j]==0)lose++;
        }
        if(win!=lose)return false;
    }
    return true;
}

void dfs(int idx){
    if(idx==points.size()){
        if(is_playoff())ans++;
        return;
    }
    //t1が勝ってt2が負ける
    Point point=points[idx];
    v[point.t1][point.t2]=1;
    v[point.t2][point.t1]=0;
    if(will_playoff(point.t1))dfs(idx+1);

    //t1が負けてt2が勝つ
    v[point.t1][point.t2]=0;
    v[point.t2][point.t1]=1;
    if(will_playoff(point.t1))dfs(idx+1);

    v[point.t1][point.t2]=v[point.t2][point.t1]=-1;
    return;
}

int main(){
    while(cin>>n){
        if(n==0)break;
        //なんか初期化
        v.clear();
        v.resize(10,vector<int>(10,-1));
        points.clear();
        ans=0;

        int m;cin>>m;
        for(int i=0;i<m;i++){
            int win,lose;
            cin>>win>>lose;
            win--; lose--;
            v[win][lose]=1;
            v[lose][win]=0;
        }
        //まだ戦っていないところを保存
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(v[i][j]==-1 and i!=j)points.push_back(Point{i,j});
            }
        }
        dfs(0);
        cout<<ans<<endl;

    }
}