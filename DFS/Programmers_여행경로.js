const visited = new Array(10001).fill(false);
let ans_str = "";

function dfs(tickets, cur, path, depth) {
    if (depth === tickets.length) {
        if (ans_str == "" || ans_str > path) ans_str = path;
        return;
    }
    for (let i = 0; i < tickets.length; i++) {
        if (tickets[i][0] === cur && !visited[i]) {
          
            visited[i] = true;
            dfs(tickets, tickets[i][1], path + tickets[i][1], depth + 1);
            visited[i] = false;
        }
    }
}

function solution(tickets) {
    const answer = [];
    dfs(tickets, "ICN", "ICN", 0);
    for (let i = 0; i < ans_str.length; i += 3) {
        answer.push(ans_str.slice(i, i + 3));
    }
    return answer;
}