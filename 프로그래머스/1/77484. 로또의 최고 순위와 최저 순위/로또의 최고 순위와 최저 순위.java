import java.util.*;

class Solution {
    public int[] solution(int[] lottos, int[] win_nums) {
        int zeroCnt = 0, correctCnt = 0;
        
        
        for (int i = 0; i < lottos.length; i++) {
            if (lottos[i] == 0) {
                zeroCnt++;
            }
        }
        
        for (int i = 0; i < lottos.length; i++) {
            for (int j = 0; j < win_nums.length; j++) {
                if (lottos[i] == win_nums[j]) {
                    correctCnt++;
                }
            }
        }
        
        int[] answer = new int[2];
        
        answer[1] = 7 - correctCnt;
        answer[0] = 7 - correctCnt - zeroCnt;
        
        for (int i = 0; i < answer.length; i++) {
            if (answer[i] == 7) answer[i] = 6;
        }

        return answer;
    }
}