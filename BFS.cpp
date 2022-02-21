#include <iostream>
#include <vector>
#include <queue>
#define N 9

using namespace std;

bool visited[N];
vector<int> graph[N];

void bfs(int start){
    queue<int> q; 
    q.push(start);
    visited[start] = true;

    while (!q.empty()){
        //큐에서 한개 뽑기
        int x = q.front();
        q.pop();
        cout << x << ' ';
        //아직 방문하지 않은 원소 큐에 삽입
        for(int i = 0; i< graph[x].size(); i++){
            int y = graph[x][i];
            if(!visited[y]){
                q.push(y);
                visited[y] = true;
            }
        }
    }
}

int main(void){

}