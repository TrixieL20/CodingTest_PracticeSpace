import java.util.*;

class Solution {
    public int solution(int[] citations) {
        citations = Arrays.stream(citations).sorted().toArray();
        
        int len = citations.length;
        
        for (int i = citations[len - 1]; i > 0; i--) {
            int tHIndex = 0;
            
            for (int j = 0; j < len; j++) {
                if (i <= citations[j]) {
                    tHIndex++;
                }
            }
            
            if (tHIndex >= i) return i;
        }
        
        return 0;
    }
}