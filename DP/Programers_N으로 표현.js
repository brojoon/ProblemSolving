function solution(N, number) {
	const dp = new Array(9).fill(0).map((n) => new Set());
	for (let i = 1; i < 9; i++) {
			dp[i].add('1'.repeat(i) * N);
			for (let j = 1; j < i; j++) {
					for (const arg1 of dp[j]) {
							for (const arg2 of dp[i - j]) {
									dp[i].add(arg1 + arg2);
									dp[i].add(arg1 - arg2);
									dp[i].add(arg1 * arg2);
									dp[i].add(arg1 / arg2 >> 0);
							}
					}
			}
			if (dp[i].has(number)) return i;
	}
	return -1;
}