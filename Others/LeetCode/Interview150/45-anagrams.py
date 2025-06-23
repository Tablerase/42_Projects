class Solution(object):
    def groupAnagrams(self, strs: list[str]):
        """
        :type strs: List[str]
        :rtype: List[List[str]]
        """
        # groups: list[list[str]] = []
        dictOfStr = {}

        for to_gather in strs:
            # check for anagrams
            sortedKey = ''.join(sorted(to_gather))
            if dictOfStr.get(sortedKey) != None:
                dictOfStr[sortedKey].append(to_gather)
            # if none
            else:
                # groups.append([to_gather])
                dictOfStr[sortedKey] = [to_gather]
        return list(dictOfStr.values())


if __name__ == '__main__':
    Input = ["eat", "tea", "tan", "ate", "nat", "bat"]
    # Input = ["ddddddddddg", "dgggggggggg"]
    # Any order
    Output = [["bat"], ["nat", "tan"], ["ate", "eat", "tea"]]
    # Output = [["dgggggggggg"], ["ddddddddddg"]]
    test = Solution()
    print(test.groupAnagrams(Input))
