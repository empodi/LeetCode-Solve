class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        
        minBuy = 987654321
        maxProfit = 0
        
        for i, price in enumerate(prices):
            
            if price < minBuy:
                minBuy = price
                continue
            
            if price - minBuy > maxProfit:
                maxProfit = price - minBuy
                
        return maxProfit
            