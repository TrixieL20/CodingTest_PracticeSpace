#include <bits/stdc++.h>
using namespace std;

int h, w, visited[50][50], mx = -1;
char m[50][50];
const int dx[] = {0, 0, 1, -1}, dy[] = {1, -1, 0, 0};

void bfs(int y, int x) {
	memset(visited, 0, sizeof(visited));
	visited[y][x] = 1; 
	queue<pair<int, int>> q;
	q.push({y, x});
	
	while (q.size()) {
		tie(y, x) = q.front(); q.pop();
		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i], nx = x + dx[i];
			if (ny >= h || ny < 0 || nx >= w || nx < 0) continue;
			if (m[ny][nx] == 'W' || visited[ny][nx] > 0) continue;
			
			visited[ny][nx] = visited[y][x] + 1;
			q.push({ny, nx});
			mx = max(mx, visited[ny][nx]);
		}
	}
	return;
}

int main() {
	cin >> h >> w;
	
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			char a;
			cin >> a;
			m[i][j] = a;
		}
	}
	
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			if(m[i][j] == 'L') bfs(i, j);
		}
	}
	
	cout << mx - 1;
}