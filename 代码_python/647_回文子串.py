class Solution:
    def countSubstrings(self, s:str) -> int:
        n = len(s)
        cnt = 0
        for i in range(2*n-1):
            L = i//2
            R = i//2 + i%2
            while L>=0 and R<n and s[L] == s[R]:
                cnt += 1
                L -= 1
                R += 1
        return cnt

