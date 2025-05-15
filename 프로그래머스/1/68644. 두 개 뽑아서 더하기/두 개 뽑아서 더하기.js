function solution(numbers) {
    let addedNumbers = addArrayNumbers(numbers);
    
    addedNumbers.sort((a, b) => a - b);
    let answer = [...new Set(addedNumbers)];
    return answer;
}

function addArrayNumbers(numbers) {
    let addedNumbers = [];
    for (let i = 0; i < numbers.length; i++) {
        for (let k = i + 1; k < numbers.length; k++) {
            addedNumbers.push(numbers[i] + numbers[k]);
        }
    }
    
    return addedNumbers;
}