/**
 * To debug:
 * deno run --watch file.ts
 *
Given two strings ransomNote and magazine, return true if ransomNote can be constructed by using the letters from magazine and false otherwise.

Each letter in magazine can only be used once in ransomNote.

 

Example 1:

Input: ransomNote = "a", magazine = "b"
Output: false

Example 2:

Input: ransomNote = "aa", magazine = "ab"
Output: false

Example 3:

Input: ransomNote = "aa", magazine = "aab"
Output: true
 */

function createCharMap(toMap: string): Map<string, number> {
  const charMap = new Map<string, number>();

  for (const char of toMap) {
    charMap.set(char, (charMap.get(char) || 0) + 1)
  }

  return charMap;
}

function canConstruct(ransomNote: string, magazine: string): boolean {
  const ransomMap = createCharMap(ransomNote);
  const magazineMap = createCharMap(magazine);
  console.log(ransomMap);
  console.log(magazineMap);
  // Remove each letter of ransomNote till empty or till magazine end with removing all the ransomNote letters
  magazineMap.forEach((value, letter) => {
    for (let letters = value; letters > 0; letters--) {
      const ransomAmount = ransomMap.get(letter);
      if (ransomAmount != undefined) {
        if (ransomAmount <= 1) {
          ransomMap.delete(letter);
        } else {
          ransomMap.set(letter, ransomAmount - 1);
        }
      } else {
        break;
      }
      if (ransomMap.size == 0) {
        return true;
      }
    }
  })
  return ransomMap.size > 0 ? false : true;
};


function test(ransom: string, magazine: string) {
  console.log("ransomNote: ", ransom, "Magazine: ", magazine);
  console.log("canConstruct: ", canConstruct(ransom, magazine));
}

test("a", "b")
test("aa", "ab")
test("aa", "aab")

