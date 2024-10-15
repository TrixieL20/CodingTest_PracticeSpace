fun main() {
    val paper = Array(100) { BooleanArray(100) }  // 100x100 도화지
    val n = readln().toInt()  // 색종이의 수

    // 각 색종이의 왼쪽 아래 좌표 입력
    for (i in 0..n - 1) {  // 0부터 n-1까지 반복
        val (x, y) = readln().split(" ").map { it.toInt() }

        // 색종이 10x10 크기만큼 도화지에 표시
        for (dx in 0..9) {  // 0부터 9까지
            for (dy in 0..9) {  // 0부터 9까지
                paper[x + dx][y + dy] = true  // 색종이가 붙은 부분 true로 표시
            }
        }
    }

    // 색종이가 붙은 칸의 수를 세기
    var area = 0
    for (i in 0..99) {  // 0부터 99까지
        for (j in 0..99) {  // 0부터 99까지
            if (paper[i][j]) area++
        }
    }

    println(area)  // 색종이가 차지하는 총 면적 출력
}