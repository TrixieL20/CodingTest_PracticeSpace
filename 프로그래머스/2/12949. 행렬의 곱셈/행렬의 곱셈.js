function solution(arr1, arr2) {
    var answer = [];
    
    for (let i = 0; i < arr1.length; i++) {
        let line = [];
        
        for (let j = 0; j < arr2[0].length; j++) {
            let value = 0;
            
            for (let k = 0; k < arr2.length; k++) {
                value += arr1[i][k] * arr2[k][j];
            }
            line.push(value);
        }
        answer.push(line);
    }
    
    return answer;
}