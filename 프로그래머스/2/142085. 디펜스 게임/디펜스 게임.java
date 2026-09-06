import java.util.*;

class Solution {
    public int solution(int n, int k, int[] enemy) {
        Queue<Integer> pq = new PriorityQueue<>();
        
        for (int i = 0; i < Math.min(enemy.length, k); i++) {
            pq.add(enemy[i]);
        }
        
        int idx = k, answer = 0;
        
        while (true) {
            if (pq.isEmpty()) break;
            
            if (idx < enemy.length) {
                pq.add(enemy[idx++]);
            }
            
            int enemyCnt = pq.poll();
            
            if (n - enemyCnt < 0) {
                pq.add(enemyCnt);
                break;
            }
            
            n -= enemyCnt;
            answer++;
        }
        
        if (!pq.isEmpty()) {
            answer += Math.min(pq.size(), k);
        }
        
        return answer;
    }
}