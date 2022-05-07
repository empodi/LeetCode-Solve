class Solution:
    def backspaceCompare(self, s: str, t: str) -> bool:
        
        s_stack = []
        t_stack = []
        
        def build_stack(string, stack):
            for s in string:
                if s == "#":
                    if not stack:
                        continue
                    else:
                        stack.pop()
                else:
                    stack.append(s)
                    
        build_stack(s, s_stack)
        build_stack(t, t_stack)
        
        if s_stack == t_stack:
            return True
        return False