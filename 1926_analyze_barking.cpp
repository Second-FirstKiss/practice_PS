#include <iostream>
#include <queue>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int board[502][502];
    bool vis[502][502];
    int n,m;
    int dx[4]={1,0,-1,0};
    int dy[4]={0,1,0,-1};

    cin>>n>>m; // 보드 사이즈 입력
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin>>board[i][j];
        }
    } // 보드 입력
    int mx=0; // 최대 그림 넓이
    int num=0; // 그림 개수

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if(board[i][j]==0 || vis[i][j]) continue; // 보드의 해당 위치에 그림이 없거나 방문 했었다면 넘기기
            num++; // if문을 넘었다면 해당 위치에 새 그림이 있는 것이므로 그림 개수 추가
            queue<pair<int,int>> Q; // bfs 를 실행할 큐 정의
            vis[i][j]=1; // 시작 위치에 방문했음 표시
            Q.push({i,j}); // 큐에 시작 위치 삽입
            int area=0; // 카운트할 넓이 변수 정의
            while(!Q.empty()){
                area++; // 넓이 하나 카운트
                pair<int,int> cur = Q.front(); Q.pop(); // 큐에 있는 위치 저장후 삭제(큐에서 꺼내기)
                for (int dir=0;dir<4;dir++) {
                    int nx = cur.first + dx[dir]; // 탐색할 위치를 저장할 행의 좌표 저장
                    int ny = cur.second + dy[dir]; // 탐색할 위치를 저장할 열의 좌표 저장
                    if(nx<0 || nx>=n || ny < 0 || ny >= m) continue; //만약 탐색할 위치가 범위를 벗어날 경우 넘기기
                    if(vis[nx][ny] || board[nx][ny] != 1) continue; // 탐색할 위치가 이미 방문했던 곳이거나, 그림이 없다면 넘기기
                    vis[nx][ny]=1; // 탐색한 위치를 방문했다고 표시하기
                    Q.push({nx,ny}); // 탐색한 위치를 큐에 넣기
                }
            }
            mx=max(mx,area); // 넓이 변수와 기존의 제일 큰 넓이 비교후 최대 그림 넓이 저장
        }
    }
    cout<<num<<'\n'<<mx;
    return 0;
}
