class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        
        pLen = len(prices)
        globalMin = prices[0]
        maxProfit = 0
        
        i = 0
        while i < pLen:
            
            price = prices[i]
            
            if price < globalMin:
                globalMin = price
            
            if i == 0 or (i > 0 and price < prices[i - 1]):
                localMin = price 
                i += 1
                
                while i < pLen and prices[i] >= prices[i - 1]:
                    i += 1
                
                maxProfit = max(prices[i - 1] - globalMin, maxProfit + prices[i - 1] - localMin)
            else:
                i += 1

            
        return maxProfit
               