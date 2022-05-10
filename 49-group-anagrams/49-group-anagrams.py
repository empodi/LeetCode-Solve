class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        
        myHash = dict()
        answer = []
        rIdx = 0
        
        for word in strs:
            tmp = "".join(sorted(word))

            if tmp not in myHash:
                myHash[tmp] = rIdx
                answer.append([word])
                rIdx += 1
            else:
                answer[myHash[tmp]].append(word)
            
        return answer
        