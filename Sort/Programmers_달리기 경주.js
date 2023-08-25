function solution(players, callings) {
    const playersObj = {};
    let tmp;
    for (let i = 0; i < players.length; i++) {
        playersObj[players[i]] = i;
    }
    callings.forEach((player) => {
        const calledIdx = playersObj[player];
        if (calledIdx === 0) return;
        tmp = players[calledIdx - 1];
        players[calledIdx - 1] = players[calledIdx];
        players[calledIdx] = tmp;
        playersObj[player]--;
        playersObj[players[calledIdx]]++;
    })
    return players;
}