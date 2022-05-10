class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        
        myHash = dict()
        answer = []
        rIdx = 0
        
        def countingSortString(word: str) -> str:
            
            counter = [0] * 26
            ret = ""
            
            for alphabet in word:
                counter[ord(alphabet) - 97] += 1
                
            for i in range(26):
                ret += chr(i + 97) * counter[i]
            
            return ret
            
        
        for word in strs:
            tmp = countingSortString(word)

            if tmp not in myHash:
                myHash[tmp] = rIdx
                answer.append([word])
                rIdx += 1
            else:
                answer[myHash[tmp]].append(word)
            
        return answer
        