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
		1. Get space count, triple the count to suffice space for additional characters. Scan from right to left; if you encounter space, insert 3 characters, else insert normal character. _Snippet_:-
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

* **Problem Statement** **&rarr;** Given a string, write a function to check if a string is  a permutation of palindrome.

	* **Key points** :-
		1. Palindrome is a string that is same when read backwards and forwards. The aim is to find a permutation/variant of string that is a palindrome.

		2. Even length palindrome strings have even count of all characters within string. Odd length palindrome strings have even count of all characters except one character within string.

		3. For permutation of palindrome, a string cannot have more than one character whose count is odd(or specifically > 1)

	* **Approach** :-
		1. Use hashtable, count occurences of each character within string. Now check for number of odd count characters. If its > 1, then return false.
		2. Instead of checking number of odd count characters in the end, check for number of odd counts while scanning string L-R itself.