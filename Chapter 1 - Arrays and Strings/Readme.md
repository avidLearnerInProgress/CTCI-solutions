## Condensed Summary

### Is Unique

* **Problem Statement** **&rarr;** Implement an algorithm to determine if a string has all unique characters. What if you cannot use additional data structures?

	* **Key points** :-

		1. Clarify if the string has ASCII or Unicode character encoding.

		2.  ASCII encoding has 128 characters and extended ASCII has 256 characters.
		3. [ASCII character codes table](https://www.petefreitag.com/cheatsheets/ascii-codes/)

		4. When you encounter count/unique element problems in string; it is highly likely that hash table data will be required.

	* **Approach** :-
		1. Create array of boolean values where each value indicates if character is contained in string. If we encounter any character twice, return false.

		2. Use bit-vector instead of boolean array to reduce space.

		3. Sort string and linearly check neighbouring characters.

### Check Permutation

* **Problem Statement** **&rarr;** Given two stirngs, write a method to decide if one is a permutation of the other

	* **Key points** :-
		1. Clarify if permutation is case sensitive, if whitespace is significant and are repeated characters allowed.

		2. Two strings of different length cannot be permutations of each other.

		3. Permutation - Two strings with same character counts

	* **Approach** :-
		1. Sort both the strings.

		2. Hash the count of characters in string one. Now, iterate over string two and decrement the value in hashtable.

### URLify

* **Problem Statement** **&rarr;** Write a method to replace all spaces in string with "%20". You may assume that string has sufficient space at the end to hold additional characters.

	* **Key points** :-
		1. Clairfy whether you are allowed to modify string inplace.

		2. Think of additional space counts.

		3. For string manipulation problems(having extra spaces), editing the string backwards from end to start is preferred.

	* **Approach** :-
		1. Get space count, triple the count to suffice space for additional characters. Scan from right to left; if you encounter space, insert 3 characters, else insert normal character.  
        _Snippet_:-
            ```
                int extendedLen = len + 2 * space_count;
                i = extendedLen - 1;
                FORD (j, len - 1, 0) {
                    if (str[j] != ' ') {
                        str[i--] = str[j];
                    } else {
                        str[i--] = '0';
                        str[i--] = '2';
                        str[i--] = '%';
                    }
                }
            ```

### Palindrome Permutation

* **Problem Statement** **&rarr;** Given a string, write a function to check if a string is a permutation of palindrome.

	* **Key points** :-
		1. Palindrome is a string that is same when read backwards and forwards. The aim is to find a permutation/variant of string that is a palindrome.

		2. Even length palindrome strings have even count of all characters within string. Odd length palindrome strings have even count of all characters except one character within string.

		3. For permutation of palindrome, a string cannot have more than one character whose count is odd(or specifically > 1)

	* **Approach** :-
		1. Use hashtable, count occurences of each character within string. Now check for number of odd count characters. If its > 1, then return false.

		2. Instead of checking number of odd count characters in the end, check for number of odd counts while scanning string L-R itself.
   
### One Away

* **Problem Statement** **&rarr;** There are 3 types of edit taht can be performed. Insert, remove or replace a character. Given two strings, write a function to check if both of them are 1/0 edits away.

	* **Key points** :-
		1. Replacement in this problem explicitly means that two strings differ only in one place.
   
		2. Removal and Insertion also imply that one string is smaller than other

		3. If two strings differ in length > 1, they aren't one/zero edits away.

	* **Approach** :-
		1. Use hashtable, count occurences of each character within *the longer* string. Now scan through smaller string and decrement the count of occurences for characters encountered in hashtable. If final difference in count is <= 1, both the strings are one/zero edit away.
   
		2. Find longer string. Take two pointers (i and j) each for long and short string. If s1[i] != s2[j] and len(s1) == len(s2) increment shorter pointer. Increment longer pointer always while scanning.  
        _Snippet_:-
            ```
                int i = 0, j = 0;
                    bool found = false; //calculate difference - one away
                    while(i < s1.length() && j < s2.length()){
                        if(s1[i] != s2[j]){
                            if(found) return false; // testcase --> "tail" "pale" will break this loop
                            found = true;
                            //replace operation
                            if(s1.length() == s2.length())j++; //move shorter pointer only when both strings are of same length. 
                            //If they are moved when they are of unequal lengths; it will be big problem
                            /*
                            Example: bale and pal
                            b != p:- and len(bale) != len(pal) So increment only i here.
                            i.e. increment only longer pointer to bring the [b + len(ale)] and len(pal) in sync for next iteration
                            */
                        }
                        else
                            j++; //move shorter pointer ahead when both chars in s1 and s3 are ruqal
                        i++; //increment longer pointer always while scanning.
                    }
                    return true;
                }
            ```

### String Compression

* **Problem Statement** **&rarr;** Implement a method to perform basic string compression using the counts of repeated characters. If compressed string doesn't become smaller than the original string, your method should return original string. Assume string has only uppercase and lowercase letters. (a-zA-Z)

	* **Key points** :-
		1. Clarify how the characters are placed in string. Take an example in this case. Are they sorted/un-sorted/spread randomly within the string.
   
		2. When consecutive characters are placed next to each other, we can use look ahead comparison of characters at position i and i+1 within string.

	* **Approach** :-
        1. Use hashing. Each occurence of character can be hashed and then the count can be appended in the string from backwards Similar to technique that was used in _problem URLify_. This takes O(n) space.
   
        2. Lookahead comparison: When extra space is not allowed, use a global counter to count occurences of same character. Since same characters are placed next to each other(assumption), then this counter can be reset as and when charAt(i) != charAt(i+1).  
        _Snippet_:-
            ```
                FOR(i, 0, x.length() - 1){
                    count_compression++;
                    if(i+1 >= x.length() || x[i] != x[i+1]){
                        length_compression += 1 + count_compression;
                        count_compression = 0;
                    }
                }
            ```

### Rotate Matrix

* **Problem Statement** **&rarr;** Given an image represented by matrix NxN matrix, where each pixel in the image is 4 bytes, write a method to rotate image by 90 degrees. Can you do this inplace?

	* **Key points** :-
		1. Look for patterns in the given sample testcase. Matrix rotation highly involves dealing with transpose of matrix.
   
		2. Look at the 4 corners of input matrix and output matrix for the sample testcase.

	* **Approach** :-
        1. Transpose matrix and then perform transformations(row-wise/column-wise) to bring the input matrix in desired output state.  _My workaround_:-
        ```
        //clockwise :- transpose + rowwise transformation
        /*
        1 2 3      1 4 7      7 4 1 
        4 5 6  --> 2 5 8  --> 8 5 2 
        7 8 9      3 6 9      9 6 3
        */

        //anticlockwise :- transpose + rowwise + columnwise + rowwise transformation
        /*
        1 2 3      1 4 7      7 4 1     9 6 3     3 6 9 
        4 5 6  --> 2 5 8  --> 8 5 2 --> 8 5 2 --> 2 5 8 
        7 8 9      3 6 9      9 6 3     7 4 1     1 4 7
        */
        ```
        2. Perform circular rotation on each layer, moving corner edges. Top to right, right to bottom, bottom to left and left to top. (Or vice versa) 

        
