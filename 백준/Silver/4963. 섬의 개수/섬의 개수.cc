#include <bits/stdc++.h>
using namespace std;

int dy[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dx[8] = {0, 1, 1, 1, 0, -1, -1, -1};
int m[50][50];
int w, h;

void DFS(int y, int x) {
	m[y][x] = 0;
	
	for (int i = 0; i < 8; i++) {
		int cur_y = y + dy[i];
		int cur_x = x + dx[i];
		
		if (cur_y < 0 || cur_y >= h || cur_x < 0 || cur_x >= w) continue;
		if (m[cur_y][cur_x]) DFS(cur_y, cur_x);
	}
}

int main() {
	while(true) {
		cin >> w >> h;
		if (w == 0 && h == 0) break;
		
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				cin >> m[i][j];
			}
		}
		
		int sum = 0;
		
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				if (m[i][j]) {
					sum++;
					DFS(i, j);
				}
			}
		}
		cout << sum << "\n";
	}
}