class Solution:
    def repeatedCharacter(self, s: str) -> str:
        seen = set() 
        i = 0
        for i in s:
            if i in seen: 
                return i
            else:
                seen.add(i)
            
