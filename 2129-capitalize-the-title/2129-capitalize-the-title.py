class Solution:
    def capitalizeTitle(self, title: str) -> str:
        
        lower = "abcdefghijklmnopqrstuvwxyz"
        upper = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        
        wordList = title.split()
        answer = []
        
        for word in wordList:
            
            newWord = []
            
            if len(word) < 3:
                for alpha in word:
                    newWord.append(alpha if ord(alpha) > 96 else chr(ord(alpha) + 32))
            else:
                for i in range(len(word)):
                    if i == 0:
                        newWord.append(word[i] if ord(word[i]) < 96 else chr(ord(word[i]) - 32))
                    else:
                        newWord.append(word[i] if ord(word[i]) > 96 else chr(ord(word[i]) + 32))
                
            answer.append("".join(newWord))
                
        return " ".join(answer)