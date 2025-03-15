#include <bits/stdc++.h>
using namespace std;

int main() {
	priority_queue<int, vector<int>, greater<int>> pq;
	vector<pair<int, int>> lectures;
	int n;
	
	cin >> n;
	
	int p, d;
	for (int i = 0; i < n; i++) {
		cin >> p >> d;
		lectures.push_back({d, p});
	}
	sort(lectures.begin(), lectures.end());
	
	for (int i = 0; i < n; i++) {
		pq.push(lectures[i].second);
		if (pq.size() > lectures[i].first) {
			pq.pop();
		}
	}
	
	int answer = 0;
	while (pq.size()) {
		answer += pq.top(); pq.pop();
	}
	cout << answer;
}