function solution(scores) {
    let wanhoRank = 1;
    let SecondScoreMax = 0;
    const wanhoScoreSum = scores[0][0] + scores[0][1];
    const wanhoScore = scores[0];
    scores.sort((a, b) => a[0] === b[0] ? a[1] - b[1] : b[0] - a[0]);
    
    for (score of scores) {
        if (score[1] < SecondScoreMax) {
            if (wanhoScore === score) return -1;
        } else {
            SecondScoreMax = score[1];
            if (score[0] + score[1] > wanhoScoreSum) wanhoRank++;
        }
    }
    
    return wanhoRank;
}