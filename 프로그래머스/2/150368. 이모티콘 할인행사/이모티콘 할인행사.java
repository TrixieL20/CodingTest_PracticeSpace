import java.util.ArrayList;


class Solution {
    static int[] answer = {0, 0};
    static int[] discountRate = {10, 20, 30, 40};
    private int [][] users;
    private int [] emoticons;

    public int[] solution(int[][] users, int[] emoticons) {
        this.users = users;
        this.emoticons = emoticons;
        
        getBestSell(new int[emoticons.length], 0);
        return answer;
    }

    private void getBestSell(int[] calculatedRates, int idx) {
        if (idx == emoticons.length) {
            calculateSell(calculatedRates);
            return;
        }

        for (int i = 0; i < discountRate.length; i++) {
                int rate = discountRate[i];
                calculatedRates[idx] = rate;
                getBestSell(calculatedRates, idx + 1);

        }

    }

    private void calculateSell(int[] calculatedRates) {
        int serviceMember = 0;
        int totalSell = 0;

        for (int[] user : users) {
            int personalSell = 0;

            for (int i = 0; i < emoticons.length; i++) {

                if (calculatedRates[i] >= user[0]) {

                    int price = (int) (emoticons[i] * (100 - calculatedRates[i]) / 100.0);
                    personalSell += price;
                }
            }
            
            if (personalSell >= user[1]) {
                serviceMember++;
            } else {
                totalSell += personalSell;
            }
            
            if (answer[0] < serviceMember) {
                answer[0] = serviceMember;
                answer[1] = totalSell;
            }
            
            if (answer[0] == serviceMember && answer[1] < totalSell) {
                answer[0] = serviceMember;
                answer[1] = totalSell;
            }
        }
    }
}