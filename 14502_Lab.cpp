#include <cstdio>
#include <vector>
#include <queue>
#define MAX 9
using namespace std;

//1. 벽을 무작위로 세운다 단, 기존의 지도는 저장한다.
//2. 바이러스를 퍼뜨린다.
//3. 안전 구역을 센다
//4. 최대 값을 구한다.

int N,M;
int max_safe = 0;
vector<int> map[MAX];
vector<int> spreadMap[MAX];
vector<int> spreadBefore[MAX];
vector<pair<int,int>> virus_pos;

pair<int, int> moving[4] = {make_pair(1,0), make_pair(-1,0), make_pair(0,1), make_pair(0,-1)};

void map_copy(vector<int> OriginMap[], vector<int> copyMap[]){
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            copyMap[i][j] = OriginMap[i][j];
        }
    }
}

void virus_spread(int dx, int dy){//바이러스가 퍼져나가는 시뮬레이션
    int x = dx; int y = dy;
    queue<pair<int,int>> q;
    q.push(make_pair(x, y));
    while(!q.empty()){
        x = q.front().first;
        y = q.front().second;
        q.pop();
        for(int i = 0; i < 4; i++){
            if(x+moving[i].first>=0 && y+moving[i].second>=0 && x+moving[i].first<N && y+moving[i].second<M){
                if(spreadMap[x+moving[i].first][y+moving[i].second] == 0){
                    spreadMap[x+moving[i].first][y+moving[i].second] = 2;
                    q.push(make_pair(x+moving[i].first,y+moving[i].second));
                }
            }
        }
    }
}

void wall_maker(int cnt){
    if(cnt == 3){
        int cnt_safe = 0;
        map_copy(spreadMap, spreadBefore);
        for(int i = 0; i < virus_pos.size(); i++)//초기 바이러스 위치 적용
            virus_spread(virus_pos[i].first, virus_pos[i].second);

        for(int i = 0; i < N; i++){
            for(int j = 0; j < M; j++){
                if(spreadMap[i][j] == 0)
                    cnt_safe += 1;
            }
        }
        if(max_safe < cnt_safe)
            max_safe = cnt_safe;


        map_copy(spreadBefore, spreadMap);
    }
    else{
        for(int i = 0; i < N; i++){
            for(int j = 0; j < M; j++){
                if(spreadMap[i][j] == 0){//빈공간 사용했다면
                    spreadMap[i][j] = 1;
                    if(cnt < 3)
                        wall_maker(cnt+1);
                    spreadMap[i][j] = 0;
                }

            }
        }
    }
}


int main(){
    int tmp;

    scanf("%d %d", &N, &M);

    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            scanf("%d", &tmp);
            map[i].push_back(tmp);
            spreadMap[i].push_back(tmp);
            spreadBefore[i].push_back(tmp);
        }
    }

    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            if(map[i][j] == 2){
                virus_pos.push_back(make_pair(i,j));
            }
        }
    }
    //입력 구간

    wall_maker(0);

    printf("%d", max_safe);
}