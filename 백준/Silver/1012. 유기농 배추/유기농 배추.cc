#include <bits/stdc++.h>
using namespace std;

int m[50][50], visited[50][50];
int N, M;
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};
queue< pair<int, int> > q;

void initMap() {
	for (int i = 0; i < 50; i++) {
		for (int j = 0; j < 50; j++) {
			m[i][j] = 0;
			visited[i][j] = 0;
		}
	}
}

void DFS(int y, int x) {
	visited[y][x] = 1;
	m[y][x] = 0;
	
	for (int i = 0; i < 4; i++) {
		int cur_y = y + dy[i];
		int cur_x = x + dx[i];
		
		if (cur_y < 0 || cur_y >= N || cur_x < 0 || cur_x >= M) continue;
		if (visited[cur_y][cur_x] == 0 && m[cur_y][cur_x]) DFS(cur_y, cur_x);
	}
}

int main() {
	int T, K, x, y, sum;
	cin >> T;
	
	for (int i = 0; i < T; i++) {
		cin >> M >> N >> K;
		sum = 0;
		
		for (int j = 0; j < K; j++) {
			cin >> x >> y;
			m[y][x] = 1;
		}
		
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < M; k++) {
				if (visited[j][k] == 0 && m[j][k]) {
					sum++;
					DFS(j, k);
				}
			}
		}
		cout << sum << "\n";
		initMap();
	}
	
}