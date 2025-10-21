#include <bits/stdc++.h>
using namespace std;

const int INF = 987654321;
int r, c, j_x, j_y, answer = INF;
vector<vector<char>> m;
queue<pair<int, int>> q;
vector<vector<int>> visited, fired;

const int dx[] = {0, 0, 1, -1}, dy[] = {1, -1, 0, 0};
 
void solution(int j_y, int j_x) {
	
	// 🔥 불 번짐 BFS
	while (!q.empty()) {
		int f_y, f_x;
		tie(f_y, f_x) = q.front(); q.pop();
		
		for (int i = 0; i < 4; i++) {
			int nfy = f_y + dy[i], nfx = f_x + dx[i];
			
			if (nfy < 0 || nfy >= r || nfx < 0 || nfx >= c) continue;
			if (m[nfy][nfx] == '#' || fired[nfy][nfx] != INF) continue;  // ✅ 수정된 부분
			
			fired[nfy][nfx] = fired[f_y][f_x] + 1;
			q.push({nfy, nfx});
		}
	}
	
	// 👤 지훈이의 이동 BFS
	queue<pair<int,int>> jq;
	jq.push({j_y, j_x});
	visited[j_y][j_x] = 1;

	while (!jq.empty()) {
		tie(j_y, j_x) = jq.front(); jq.pop();
		
		// 탈출 조건: 가장자리에 도달
		if (j_y == 0 || j_y == r - 1 || j_x == 0 || j_x == c - 1) {
			answer = visited[j_y][j_x];
			return;
		}
		
		for (int i = 0; i < 4; i++) {
			int njy = j_y + dy[i], njx = j_x + dx[i];
				
			if (njy < 0 || njy >= r || njx < 0 || njx >= c) continue;
			if (m[njy][njx] == '#' || visited[njy][njx] != INF) continue;
			if (fired[njy][njx] <= visited[j_y][j_x] + 1) continue; // 🔥 불보다 빨리 가야함
				
			visited[njy][njx] = visited[j_y][j_x] + 1;
			jq.push({njy, njx});
		}
	}
}

int main() {
	cin >> r >> c;
	m.assign(r, vector<char>(c, ' '));
	visited.assign(r, vector<int>(c, INF));
	fired.assign(r, vector<int>(c, INF));
	
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> m[i][j];
			
			if (m[i][j] == 'J') {
				j_y = i;
				j_x = j;
			} else if (m[i][j] == 'F') {
				q.push({i, j});
				fired[i][j] = 1;
			}
		}
	}
	
	solution(j_y, j_x);
	
	if (answer == INF) cout << "IMPOSSIBLE\n";
	else cout << answer << "\n";
}
