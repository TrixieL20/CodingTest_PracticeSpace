import java.util.*;

class Solution {

    public int solution(int coin, int[] cards) {

        int n = cards.length;

        // 현재 가지고 있는 카드
        Set<Integer> hand = new HashSet<>();

        // 이번 라운드에 뽑았지만 아직 가지고 있지 않은 카드
        Set<Integer> candidate = new HashSet<>();

        // 처음 n/3장
        for (int i = 0; i < n / 3; i++) {
            hand.add(cards[i]);
        }

        int round = 1;

        // 이후 카드 2장씩
        for (int i = n / 3; i < n; i += 2) {

            candidate.add(cards[i]);
            candidate.add(cards[i + 1]);

            /*
             * ① 코인 0개
             *
             * hand 안에서 pair 찾기
             */
            Integer a = null;
            Integer b = null;

            for (int card : hand) {
                int pair = n + 1 - card;

                if (hand.contains(pair)) {
                    a = card;
                    b = pair;
                    break;
                }
            }

            if (a != null) {
                hand.remove(a);
                hand.remove(b);

                round++;
                continue;
            }

            /*
             * ② 코인 1개
             *
             * hand + candidate
             */
            if (coin >= 1) {

                boolean found = false;

                for (int card : hand) {
                    int pair = n + 1 - card;

                    if (candidate.contains(pair)) {

                        hand.remove(card);
                        candidate.remove(pair);

                        coin--;
                        found = true;

                        break;
                    }
                }

                if (found) {
                    round++;
                    continue;
                }
            }

            /*
             * ③ 코인 2개
             *
             * candidate + candidate
             */
            if (coin >= 2) {

                Integer first = null;
                Integer second = null;

                for (int card : candidate) {
                    int pair = n + 1 - card;

                    if (candidate.contains(pair)) {
                        first = card;
                        second = pair;
                        break;
                    }
                }

                if (first != null) {

                    candidate.remove(first);
                    candidate.remove(second);

                    coin -= 2;

                    round++;
                    continue;
                }
            }

            /*
             * 세 가지 방법 모두 실패
             *
             * 이번 라운드를 넘길 수 없음
             */
            break;
        }

        return round;
    }
}