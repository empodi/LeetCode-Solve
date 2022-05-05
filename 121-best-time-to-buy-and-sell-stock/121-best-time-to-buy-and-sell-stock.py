class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        
        minBuy = prices[0]
        maxProfit = 0
        
        for price in prices:
            
            if price < minBuy:
                minBuy = price
            else:            
                maxProfit = maxProfit if price - minBuy < maxProfit else price - minBuy
                
        return maxProfit
            