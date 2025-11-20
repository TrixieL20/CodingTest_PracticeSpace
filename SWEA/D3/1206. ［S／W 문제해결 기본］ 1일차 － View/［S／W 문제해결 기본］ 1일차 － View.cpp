#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> b) {
	int answer = 0;
	for (int i = 2; i < b.size() - 2; i++) {
		int preMaxFloor = max(b[i - 2], b[i - 1]);
		int postMaxFloor = max(b[i + 2], b[i + 1]);
		int maxFloor = max(preMaxFloor, postMaxFloor);
		
		if (b[i] - maxFloor > 0) answer += (b[i] - maxFloor);
	}
	
	return answer;
}

int main() {
	int bNum, t = 10;
	
	for (int i = 0; i < 10; i++) {
		vector <int> buildings;
		cin >> bNum;
		for (int j = 0; j < bNum; j++) {
			int floor;
			cin >> floor;
			buildings.push_back(floor);
		}
		
		cout << '#' << i + 1 << ' ' << solution(buildings) << '\n';
	}
}