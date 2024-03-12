#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int box[1002][1002];

    int n,m, space=0, mx=1;
    int dx[4]={1,0,-1,0};
    int dy[4]={0,1,0,-1};

    cin>>n>>m;
    vector<queue<pair<int,int>>> Qs;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin>>box[i][j];
            if (box[i][j]==0) space++;
            else{
                queue<pair<int,int>> Q;
                Q.push({i,j});
                Qs.push_back(Q);
            }
        }
    }

    while (1){
        for (int qq = 0; qq < Qs.size(); ++qq) {
            if(Qs[qq].empty()) continue;
            pair<int,int> cur = Qs[qq].front(); Qs[qq].pop();
            int buf = box[cur.first][cur.second];
            for (int i = 0; i < 4; ++i) {
                int nx = cur.first+dx[i];
                int ny = cur.second+dy[i];
                if (nx<0 || nx>n || ny<0 || ny>m) continue;
                if (box[nx][ny]!=0) continue;
                box[nx][ny] = buf+1;
                mx = mx>buf+1?mx:buf+1;
                Qs[qq].push({nx,ny});
            }
        }
        int check=0;
        for (int i = 0; i < Qs.size(); ++i) {
            if(Qs[i].empty()) check++;
        }
        if(check==Qs.size()) break;
    }

    if(!space) cout<<"-1";
    else cout<<mx;

    return 0;
}
