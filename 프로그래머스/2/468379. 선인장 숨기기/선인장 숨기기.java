import java.util.*;

class Solution {
    public int[] solution(int m, int n, int h, int w, int[][] drops) {
        int[][] desert = new int[m][n];
        int[][] minRows = new int[m][n - w + 1];
        int[][] windowMins = new int[m - h + 1][n - w + 1];
        
        for(int i = 0; i < m ; i++){
            Arrays.fill(desert[i], Integer.MAX_VALUE);
        }
        
        for (int i = 0; i < drops.length; i++) {
            int r = drops[i][0];
            int c = drops[i][1];
            
            desert[r][c] = i + 1;
        }
        
        for (int r = 0; r < m; r++) {
            int[] row = desert[r];
            Deque<Integer> dq = new ArrayDeque<>();
            
            for (int i = 0; i < n; i++) {
                while(!dq.isEmpty() && dq.peekFirst() <= i - w) {
                    dq.pollFirst();
                }
                
                while(!dq.isEmpty() && row[dq.peekLast()] >= row[i]) {
                    dq.pollLast();
                }
                
                dq.offerLast(i);
                
                if (i >= w - 1) {
                    minRows[r][i - w + 1] = row[dq.peekFirst()];
                }
            }
        }
        
        
        for (int r = 0; r < n - w + 1; r++) {
            Deque<Integer> dq = new ArrayDeque<>();
            
            for (int i = 0; i < m; i++) {
                while(!dq.isEmpty() && dq.peekFirst() <= i - h) {
                    dq.pollFirst();
                }
                
                while(!dq.isEmpty() && minRows[dq.peekLast()][r] >= minRows[i][r]) {
                    dq.pollLast();
                }
                
                dq.offerLast(i);
                
                if (i >= h - 1) {
                    windowMins[i - h + 1][r] = minRows[dq.peekFirst()][r];
                }
            }
        }
        
        int max = Integer.MIN_VALUE;
        int[] answer = new int[2];
        
        for (int r = 0; r < m - h + 1; r++) {
            for (int c = 0; c < n - w + 1; c++) {
                if (max < windowMins[r][c]) {
                    max = windowMins[r][c];
                    answer[0] = r;
                    answer[1] = c;
                }
            }
        }
        
        return answer;
    }
}