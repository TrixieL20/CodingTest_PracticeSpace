fun main() {
    val ml = MutableList(5, {""})
    for (i in 0..4) run {
        var s: String = readln()
        ml[i] = s
    }

    var answer : String = ""
    for (i in 0..14) {
        for (j in 0..4) {
            if (ml[j].length > i) answer += ml[j][i]
        }
    }
    println(answer)
}