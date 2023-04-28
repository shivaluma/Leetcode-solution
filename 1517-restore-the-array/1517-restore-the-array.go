const mod = 1e9 + 7

func numberOfArrays(s string, k int) int {
    n := len(s)
    dp := make([]int, n+1)
    dp[0] = 1
    
    for i := 1; i <= n; i++ {
        for j := i-1; j >= 0 && i-j <= k; j-- {
            if s[j] == '0' {
                continue
            }
            num, _ := strconv.Atoi(s[j:i])
            if num > k {
                break
            }
            dp[i] = (dp[i] + dp[j]) % mod
        }
    }
    
    return dp[n]
}