class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        
        minBuy = 987654321
        maxProfit = 0
        
        for price in prices:
            
            if price < minBuy:
                minBuy = price
                continue
            
            maxProfit = maxProfit if price - minBuy < maxProfit else price - minBuy
                
        return maxProfit
            