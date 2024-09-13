#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<vector<int>> board) {
    int risk[100][100];
    int dy[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
    int dx[8] = {0, 1, 1, 1, 0, -1, -1, -1};
    
    int answer = 0;
    int n = board.size();
    for (int i = 0; i < n; i ++) {
        for (int j = 0; j < n; j ++) {
            if (board[i][j] == 1) {
                risk[i][j] = 1;
                
                for (int k = 0; k < 8; k++) {
                    int cur_y = i + dy[k];
                    int cur_x = j + dx[k];
                    if (cur_y < n && cur_y >=0 && cur_x < n && cur_x >= 0) risk[cur_y][cur_x] = 1;
                }
            }
        }
    }
    
    for (int i = 0; i < n; i ++) {
        for (int j = 0; j < n; j ++) {
            if (risk[i][j] == 0) answer++;
        }
    }
    return answer;
}