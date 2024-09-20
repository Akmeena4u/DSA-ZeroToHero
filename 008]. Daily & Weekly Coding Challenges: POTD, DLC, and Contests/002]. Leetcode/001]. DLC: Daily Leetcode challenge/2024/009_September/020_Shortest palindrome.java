

public String shortestPalindrome(String s) {
    // Get the length of the input string
    int length = s.length();
    
    // Create the reversed version of the input string
    String reversedString = new StringBuilder(s).reverse().toString();

    // Iterate through the string to find the longest palindromic prefix
    for (int i = 0; i < length; i++) {
        // Check if the prefix of the original string (0 to length - i)
        // matches the suffix of the reversed string (from i to end).
        // This ensures the longest prefix that forms a palindrome
        // is identified.
        if (s.substring(0, length - i).equals(reversedString.substring(i))) {
            // If found, append the remaining part of the reversed string
            // (the non-palindromic portion) to the start of the original string
            // and return the result.
            return new StringBuilder(reversedString.substring(0, i))
                    .append(s)  // Append the original string
                    .toString();
        }
    }

    // Return an empty string if no palindrome is found, though this case
    // is unlikely to occur since the entire string itself is always a palindrome.
    return "";
}
