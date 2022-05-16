class Solution:
    height = 0
    width = 0
    def floodFill(self, image: List[List[int]], sr: int, sc: int, newColor: int) -> List[List[int]]:
        
        self.height, self.width = len(image), len(image[0])
        
        def DFS(x: int, y: int, startColor: int, newColor: int): # no return
            
            if x < 0 or y < 0 or x >= self.height or y>= self.width:
                return
            if image[x][y] == newColor or image[x][y] != startColor:
                return
            
            image[x][y] = newColor
            
            DFS(x - 1, y, startColor, newColor)
            DFS(x, y + 1, startColor, newColor)
            DFS(x + 1, y, startColor, newColor)
            DFS(x, y - 1, startColor, newColor)
                
        DFS(sr, sc, image[sr][sc], newColor)
        
        return image
            
        
        
        
        