class Solution:
    def hasAllCodes(self, s: str, k: int) -> bool:
        num,cnt = 0,0
        mask = (1 << k ) - 1
        check = [False for x in range(1 << k)]
        
        for i, c in enumerate(s):
            num = mask & ((num << 1) + ord(c) - 0)
            if i >= k - 1 and check[num] == False:
                cnt += 1
                check[num] = True

        return True if cnt == 2 ** k else False
        