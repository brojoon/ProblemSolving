function solution(s) {
	let answer = "";
	
	answer = s[0].toUpperCase();
	for (let i = 1; i < s.length; i++) {
			answer[i - 1] === ' ' ? answer += s[i].toUpperCase() : answer += s[i].toLowerCase();
	}
	return answer
}