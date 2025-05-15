function solution(answers) {
    let testNumbers = getFailerTestNumbers(answers.length);
    let answerCheckList = checkAnswer(answers, testNumbers);
    let highScore = Array.from(answerCheckList).sort((a, b) => b - a)[0];
    
    let answer = [];
    for(let i = 0; i < 3; i++) {
        if (answerCheckList[i] == highScore) answer.push(i + 1);
    }
    return answer;
}

function getFailerTestNumbers(testLength) {
    let failerTestNumbers = [[], [], []];
    
    while(failerTestNumbers[0].length < testLength) {
        failerTestNumbers[0].push(1, 2, 3, 4, 5);
        failerTestNumbers[1].push(2, 1, 2, 3, 2, 4, 2, 5);
        failerTestNumbers[2].push(3, 3, 1, 1, 2, 2, 4, 4, 5, 5);
    }
    
    failerTestNumbers[0].push(1, 2, 3, 4, 5);
    failerTestNumbers[1].push(2, 1, 2, 3, 2, 4, 2, 5);
    failerTestNumbers[2].push(3, 3, 1, 1, 2, 2, 4, 4, 5, 5);
    
    failerTestNumbers[0].splice(testLength);
    failerTestNumbers[1].splice(testLength);
    failerTestNumbers[2].splice(testLength);
    
    return failerTestNumbers;
}

function checkAnswer(answers, testNumbers) {
    let answerCheckList = new Array(3).fill(0);
    
    for(let i = 0; i < 3; i++) {
        for(let k = 0; k < answers.length; k++) {
            if (answers[k] == testNumbers[i][k]) answerCheckList[i] = answerCheckList[i] + 1;
        }
    }
    
    return answerCheckList;
}