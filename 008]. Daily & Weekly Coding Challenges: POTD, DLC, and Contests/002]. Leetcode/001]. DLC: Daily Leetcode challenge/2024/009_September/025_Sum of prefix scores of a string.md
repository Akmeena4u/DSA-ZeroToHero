### Problem: 2416. Sum of Prefix Scores of Strings


**Problem Description**:
You are given an array `words` of size `n` consisting of non-empty strings.

The score of a string `word` is defined as the number of strings in the `words` array such that `word` is a prefix of another string. A prefix means that the string starts with the given prefix.

For example:
- If `words = ["a", "ab", "abc", "cab"]`, the score of `"ab"` is 2 because `"ab"` is a prefix of both `"ab"` and `"abc"`.

The task is to return an array `answer` of size `n`, where `answer[i]` is the sum of the scores of every non-empty prefix of `words[i]`.

**Note**: A string is considered a prefix of itself.

---

### Example 1:
**Input**: 
```
words = ["abc","ab","bc","b"]
```

**Output**:
```
[5, 4, 3, 2]
```

**Explanation**:
1. For the word `"abc"`:
    - It has 3 prefixes: `"a"`, `"ab"`, and `"abc"`.
    - There are 2 words with the prefix `"a"`, 2 words with the prefix `"ab"`, and 1 word with the prefix `"abc"`.
    - So, the total score for `"abc"` = 2 (for `"a"`) + 2 (for `"ab"`) + 1 (for `"abc"`) = **5**.

2. For the word `"ab"`:
    - It has 2 prefixes: `"a"` and `"ab"`.
    - There are 2 words with the prefix `"a"`, and 2 words with the prefix `"ab"`.
    - So, the total score for `"ab"` = 2 (for `"a"`) + 2 (for `"ab"`) = **4**.

3. For the word `"bc"`:
    - It has 2 prefixes: `"b"` and `"bc"`.
    - There are 2 words with the prefix `"b"`, and 1 word with the prefix `"bc"`.
    - So, the total score for `"bc"` = 2 (for `"b"`) + 1 (for `"bc"`) = **3**.

4. For the word `"b"`:
    - It has 1 prefix: `"b"`.
    - There are 2 words with the prefix `"b"`.
    - So, the total score for `"b"` = 2 (for `"b"`) = **2**.

---

### Approach: Trie (Prefix Tree)
To efficiently calculate the sum of prefix scores for each word, we can use a **Trie (Prefix Tree)**. Here's the step-by-step approach:

1. **Insert words into Trie**:
   - For each word in the array, insert it into the trie.
   - As you insert, for each character of the word, keep track of how many words pass through that node (character), which represents how many words have that prefix.

2. **Calculate scores using Trie**:
   - After constructing the trie, for each word, traverse its prefixes and calculate the score.
   - The score for a word is the sum of the number of words that share each of its prefixes.

---

### Trie Structure:
A trie node will contain:
- `countP`: The number of words that pass through this node, i.e., how many words share this prefix.
- `children[26]`: An array of pointers to child nodes (one for each character 'a' to 'z').

### Code Implementation:

```cpp
struct trieNode {
    int countP = 0;             // Tracks how many words pass through this node (prefix count).
    trieNode* children[26];     // Array to store child nodes for each letter (a-z).
};

class Solution {
public:

    // Function to create a new trie node.
    trieNode* getTrieNode() {
        trieNode* newNode = new trieNode();
        for(int i = 0; i < 26; i++) {
            newNode->children[i] = nullptr; // Initialize all children as nullptr.
        }
        newNode->countP = 0; // Initialize prefix count to 0.
        return newNode;
    }

    // Function to insert a word into the trie.
    void insert(string& word, trieNode* root) {
        trieNode* crawl = root; // Start from the root node of the trie.

        // Traverse through each character in the word.
        for(char &ch : word) {
            int idx = ch - 'a'; // Calculate the index for the current character ('a' -> 0, ..., 'z' -> 25).

            // If the child node doesn't exist, create a new trie node.
            if(!crawl->children[idx]) {
                crawl->children[idx] = getTrieNode();
            }

            // Increment the prefix count for this node.
            crawl->children[idx]->countP += 1;

            // Move to the child node.
            crawl = crawl->children[idx];
        }
    }

    // Function to calculate the score of all prefixes of the given word.
    int getScore(string& word, trieNode* root) {
        trieNode* crawl = root; // Start from the root node.
        int score = 0;          // Initialize the score for the current word's prefixes.

        // Traverse through each character in the word.
        for(char &ch : word) {
            int idx = ch - 'a'; // Get the index for the current character.

            // Add the prefix count for the current node.
            score += crawl->children[idx]->countP;

            // Move to the next node in the trie.
            crawl = crawl->children[idx];
        }

        // Return the total score for the word's prefixes.
        return score;
    }

    // Main function to compute the sum of prefix scores for each word in the input vector.
    vector<int> sumPrefixScores(vector<string>& words) {
        int n = words.size(); // Get the number of words.

        trieNode* root = getTrieNode(); // Create the root of the trie.

        // Insert each word into the trie.
        for(string &word : words) {
            insert(word, root);
        }

        vector<int> result(n); // Array to store the sum of prefix scores for each word.

        // For each word, calculate the sum of its prefix scores.
        for(int i = 0; i < n; i++) {
            result[i] = getScore(words[i], root);
        }

        // Return the result array.
        return result;
    }
};
```

---

### Complexity Analysis:
- **Time Complexity**: 
  - **Insert operation**: O(n * l), where `n` is the number of words and `l` is the average length of each word. We insert each word into the trie, and for each character, we perform a constant-time operation.
  - **Query operation**: O(n * l), as we traverse the trie for each word to calculate the prefix score.
  - Overall time complexity: **O(n * l)**.

- **Space Complexity**:
  - The trie stores all the characters of the words, so the space complexity is **O(n * l)**.

---

### Key Points:
- **Trie (Prefix Tree)** is an efficient data structure for problems involving prefixes. It allows us to store and query prefix information in an optimal way.
- This solution efficiently handles the problem of calculating prefix scores by using a trie to count how many words share a given prefix.
