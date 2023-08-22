function solution(k, tangerine) {
    const obj = {};
    let sum = 0;
    let kind = 0;
    tangerine.forEach((v) => {
        obj[v] = obj[v] ? ++obj[v] : 1
    })
    
    const sortedKind = Object.values(obj).sort((a, b) => b - a);
    
    for (let i = 0; i < sortedKind.length; i++) {
        sum += sortedKind[i];
        kind++;
        if (sum >= k) break;
    }

    return kind;
}