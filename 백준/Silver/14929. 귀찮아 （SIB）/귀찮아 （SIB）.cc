#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
    long sum = 0;
	
	cin >> n;
	
	vector <int> arr(n + 1), psum(n + 1); 
	
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
		psum[i] = psum[i - 1] + arr[i];
	}
	
	for (int i = 1; i < n; i++) {
		sum += arr[i] * (psum[n] - psum[i]);
	}
	cout << sum;
}