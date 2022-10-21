class Solution:
    def containsNearbyDuplicate(self, nums: List[int], k: int) -> bool:
        dict = {}
        for i,e in enumerate(nums):
            if e in dict:
                if i - dict[e][-1] <= k:
                    return True
                dict[e].append(i)
            else:
                dict[e] = [i]
        return False
            