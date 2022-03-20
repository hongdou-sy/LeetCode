class Solution:
    def expandAroundCenter(self, s, left, right):
        while left>=0 and right<len(s) and s[left] == s[right]:
            left -= 1
            right +=1
        return left + 1, right - 1
    
    def longestPalindrome(self, s:str) -> str:
        maxL, maxR = 0,0
        for i in range(2*len(s)-1):
            L = i/2
            R = i/2 + i%2
            left, right = self.expandAroundCenter(s, L, R)
            if right-left > maxR-maxL:
                maxL = left
                maxR = right
        return s[maxL:maxR+1] #字符串切片,左闭右开[maxL,maxR)

# 时间击败8%,空间击败15%
class Solution:
    def longestPalindrome(self, s:str) -> str:
        n = len(s)
        if n==1:
            return s
        
        dp = [[False] * n for _ in range(n)] # 定义dp数组,每一行是n个False,一共n行
        maxLen = 1
        maxL = 0
        for i in range(n):
            dp[i][i] = True

        for L in range(2,n+1):
            for i in range(n):
                j = i+L-1
                if j>=n:
                    break

                if s[i]!=s[j]:
                    dp[i][j] = False
                else:
                    if L==2:
                        dp[i][j] =True
                    else:
                        dp[i][j] = dp[i+1][j-1]

                if dp[i][j] and L>maxLen:
                    maxLen = L
                    maxL = i
        
        return s[maxL:maxL+maxLen]