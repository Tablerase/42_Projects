class Solution:
    def romanToInt(self, s: str) -> int:
        value = {
            "I": 1,
            "V": 5,
            "X": 10,
            "L": 50,
            "C": 100,
            "D": 500,
            "M": 1000,
        }
        # Establish evaluation cascade
        result = 0
        for index, char in enumerate(s):
            # print("Current letter", index, char)
            next_char = s[index+1] if index + 1 < len(s) else None
            # print("Next letter", next_char)
            # Find operation
            if next_char == None or value[char] >= value[next_char]:
                result += value[char]
            else:
                result -= value[char]
            # print("Result:", result)
        return result


if __name__ == "__main__":
    v27 = "XXVII"
    s = Solution()
    print(f"{v27} result: {s.romanToInt(v27)}")
    v58 = "LVIII"
    print(f"{v58} result: {s.romanToInt(v58)}")
    v1994 = "MCMXCIV"
    print(f"{v1994} result: {s.romanToInt(v1994)}")
