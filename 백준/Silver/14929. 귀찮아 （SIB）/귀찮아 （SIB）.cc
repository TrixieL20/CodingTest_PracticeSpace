#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, sum_val = 0;
    long sum = 0;
	
	cin >> n;
	
	vector <int> arr(n + 1), psum(n + 1); 
	
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		sum_val += arr[i];
		psum[i + 1] = sum_val;
	}
	
	for (int i = 0; i < n; i++) {
		sum += arr[i] * (psum[n] - psum[i + 1]);
	}
	cout << sum;
}