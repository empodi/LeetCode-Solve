class Solution:
    def canReach(self, arr: List[int], start: int) -> bool:
        if start < 0 or start >= len(arr) or arr[start] < 0:
            return False
        if arr[start] == 0:
            return True
        
        dist = arr[start]
        arr[start] = -1
        
        if self.canReach(arr, start - dist) or self.canReach(arr, start + dist):
            return True
        return False
        