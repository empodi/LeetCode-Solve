class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        
        minBuy = prices[0]
        maxProfit = 0
        
        for price in prices:
            
            if price < minBuy:
                minBuy = price
            else:        
                diff = price - minBuy
                maxProfit = maxProfit if diff < maxProfit else diff
                
        return maxProfit
            