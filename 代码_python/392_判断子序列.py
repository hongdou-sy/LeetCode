class Solution:
    def isSubsequence(self, s: str, t: str) -> bool:
        m = len(s)
        n = len(t)
        dp = [[-1]*26 for _ in range(n+1)] # 创建二维数组dp,共n+1行,每一行有26个-1

        # 开始维护dp数组
        for i in range(n-1, -1, -1):
            for j in range(26):
                # 注意:python无法将字符自动转换成ACII码,需要使用函数ord
                if ord(t[i]) == ord('a') + j :
                    dp[i][j] = i
                else:
                    dp[i][j] = dp[i+1][j]
        
        # 开始匹配s和t
        pos = 0
        for i in range(m):
            if dp[pos][ord(s[i]) - ord('a')] == -1:
                return False
            else:
                pos = dp[pos][ord(s[i]) - ord('a')] + 1
        return True