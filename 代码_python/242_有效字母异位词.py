class Solution:
    def isAnagram(slef, s:str, t:str)->bool:
        if(len(s)!=len(t)):
            return False
        counts = [0]*26
        for i in range(len(s)):
            counts[ord(s[i])-ord("a")] +=1
            counts[ord(t[i])-ord("a")] -=1
        for i in counts: #对于列表counts中的每一个元素i
            if(i!=0): 
                return False
        return True

'''python3的写法'''
# 时间击败10%,空间击败94%
class Solution:
    def isAnagram(slef, s:str, t:str)->bool:
        if(len(s)!=len(t)):
            return False
        counts = [0]*26
        for i in s:
            counts[ord(i)-ord("a")] +=1
        for i in t:
            counts[ord[i]-ord("a")] -=1
            if counts[ord[i]-ord("a")]<0:
                return False
        return True