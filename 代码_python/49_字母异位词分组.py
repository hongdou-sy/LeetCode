from ast import List
import collections

class Solution:
    # strs为字符串组成的列表,该函数的返回值为List[List[str]],即由字符串列表组成的列表
    def groupAnagrams(self, strs:List[str]) -> List[List[str]]:
        #先创建哈希表
        mp = collections.defaultdict(list) #collections.defaultdict将键值对序列list转换为列表字典
        
        # 遍历字符串列表中的每个字符串
        for str in strs:
            #sorted对str进行排序,但并不修改str的内容;
            #对字符串排序:先将字符串转换成列表,进行排序,然后再合并成字符串
            temp = "".join(sorted(str)) 
            mp[temp].append(str)

        return list(mp.values) #mp.values不是列表,需要使用list()将其转换为列表

class Solution:
    # strs为字符串组成的列表,该函数的返回值为List[List[str]],即由字符串列表组成的列表
    def groupAnagrams(self, strs:List[str]) -> List[List[str]]:
        mp = collections.defaultdict(list)

        for st in strs:
            counts = [0]*26 #新建一个列表,里面含有26个0
            #记录字符串st中每一个字母出现的次数
            for ch in st:
                counts[ord(ch)-ord('a')] +=1
            #字典的键可以是元组但不能是列表,因此需要将列表list转换成元组tuple
            mp[tuple(counts)].append(st)
        
        return list(mp.values)
            
