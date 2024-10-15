fun main() {
    val i : Int = readln().toInt()

    // 각 줄 입력 받기
    for (j in 1..i) {
        val s: String = readln()
        var cnt : Int = 0
        var answer : Int = 0

        for (k in 0 .. s.length - 1) {
            if (s[k] == 'O') {
                cnt++
                answer += cnt
            } else cnt = 0
        }
        println(answer)
    }
}