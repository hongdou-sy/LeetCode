class Solution:
    def minDistinct(self, word1:str, word2:str) -> int:
        m = len(word1);
        n = len(word2)
        dp = [[0]*(n+1) for _ in range(m+1)]

        # 初始化dp数组
        for j in range(n+1):
            dp[0][j] = j
        for i in range(m+1):
            dp[i][0] = i
        
        # 维护dp数组
        for i in range(1, m+1):
            for j in range(1, n+1):
                if word1[i-1] == word2[j-1]:
                    dp[i][j] = dp[i-1][j-1]
                else:
                    dp[i][j] = min(dp[i-1][j] + 1, dp[i][j-1] + 1)
        return dp[m][n] 