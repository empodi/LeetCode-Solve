class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        
        strLen = len(strs)
        
        if strLen == 1: return [strs]
        
        myHash = dict()
        retArray = []
        
        for word in strs:
            tmp = "".join(sorted(word))

            if tmp not in myHash:
                myHash[tmp] = [word]
            else:
                myHash[tmp].append(word)
                
        for key in myHash:
            retArray.append(myHash[key])
            
        return retArray
        