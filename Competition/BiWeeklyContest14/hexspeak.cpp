//https://leetcode.com/contest/biweekly-contest-14/problems/hexspeak/


class Solution:
    def toHexspeak(self, num: str) -> str:
        s=hex(int(num))[2:]
        s=s.replace("0","O")
        s=s.replace("1", "I")
        s=s.upper()
        for x in s:
            if x not in {"A", "B", "C", "D", "E", "F", "I", "O"}:
                return "ERROR"
        return s
