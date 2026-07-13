class Solution:
    def findRepeatedDnaSequences(self, s: str) -> List[str]:
        seen = set()
        output = set()

        for i in range(len(s) - 9):
            sub = s[i : i + 10]
            if sub in seen:
                output.add(sub)
            else:
                seen.add(sub)
        return list(output)

        
