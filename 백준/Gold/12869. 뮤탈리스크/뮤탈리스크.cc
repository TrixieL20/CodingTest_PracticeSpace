#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
int n, answer = INF;
int visited[64][64][64];
int scvs[3], attack[6][3] = {
	{1, 3, 9},
	{1, 9, 3},
	{3, 1, 9},
	{3, 9, 1},
	{9, 1, 3},
	{9, 3, 1}
};

struct A {
	int a1, a2, a3;
};

queue<A> q;

int solution(int a1, int a2, int a3) {
	visited[a1][a2][a3] = 1;
	q.push({a1, a2, a3});
	
	while(q.size()) {
		if (visited[0][0][0]) break;
		
		int a = q.front().a1;
		int b = q.front().a2;
		int c = q.front().a3;
		
		q.pop();
		
		for (int i = 0; i < 6; i++) {
			int na = max(0, a - attack[i][0]);
			int nb = max(0, b - attack[i][1]);
			int nc = max(0, c - attack[i][2]);
			
			if (visited[na][nb][nc]) continue;
			
			visited[na][nb][nc] = visited[a][b][c] + 1;
			q.push({na, nb, nc});
			
		}
	}
	
	return visited[0][0][0] - 1;
}

int main() {
	cin >> n;
	
	for (int i = 0; i < n; i++) {
		cin >> scvs[i];
	}
	
	cout << solution(scvs[0], scvs[1], scvs[2]);	
}