#include <bits/stdc++.h>
using namespace std;

const int INF = 987654321;
int r, c, j_x, j_y, answer = INF;
vector<vector<char>> m;
queue<pair<int, int>> q;
vector<vector<int>> visited, fired;

const int dx[] = {0, 0, 1, -1}, dy[] = {1, -1, 0, 0};
 
void solution(int j_y, int j_x) {
	
	// 불 번짐 
	while (q.size() > 0) {
		int f_y, f_x;
		tie(f_y, f_x) = q.front(); q.pop();
		
		for (int i = 0; i < 4; i++) {
			int nfy = f_y + dy[i], nfx = f_x + dx[i];
			
			if (nfy < 0 || nfy >= r || nfx < 0 || nfx >= c) continue;
			if (m[nfy][nfx] == '#' || fired[nfy][nfx] != INF) continue;
			
			fired[nfy][nfx] = fired[f_y][f_x] + 1;
			q.push({nfy, nfx});
		}
	}
	
	// 지훈이의 이동
	q.push({j_y, j_x}); visited[j_y][j_x] = 1;
	while (q.size() > 0) {
		tie(j_y, j_x) = q.front(); q.pop();
		
		if (j_y == 0 || j_y == r - 1 || j_x == 0 || j_x == c - 1) {
			answer = visited[j_y][j_x];
			break;
		}
		
		for (int i = 0; i < 4; i++) {
			int njy = j_y + dy[i], njx = j_x + dx[i];
				
			if (m[njy][njx] == '#' || m[njy][njx] == 'F' || fired[njy][njx] <= visited[j_y][j_x] + 1 || visited[njy][njx] != INF) continue;
				
			visited[njy][njx] = visited[j_y][j_x] + 1;
			q.push({njy, njx});
		}
	}
}

int main() {
	cin >> r >> c;
	m.assign(r, vector<char>(c, ' '));
	visited.assign(r, vector<int>(c, INF));
	fired.assign(r, vector<int>(c, INF));
	
	for (int i = 0; i < r; i++) {
		vector<int> v;
		for (int j = 0; j < c; j++) {
			cin >> m[i][j];
			
			if(m[i][j] == 'J') {
				j_y = i;
				j_x = j;
			} else if(m[i][j] == 'F') {
				q.push({i, j});
				fired[i][j] = 1;
			}
		}
	}
	
	solution(j_y, j_x);
	
	if (answer == INF) {
		cout << "IMPOSSIBLE";
	} else {
		cout << answer;
	}
}