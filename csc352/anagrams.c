/*Author: Adam Cunningham
*
*assignment2 problem1
*anagrams.c
*this program will take any string of size 64 or less
*from the user's input in standard in
*it will take subsequent input and compare it to the original string
*if the word or words(split on whitespace) is an anagram of the first,
*it will print out the anagram(s)
*if it contains some non-alphabetical character it prints a warning
*
*anagrams are of the same length and contain the same letters in any order
*not case sensitive
*/



#include<stdio.h>
#include<math.h>
#include<ctype.h>
#include<string.h>


int isNumeric(char c){
	/*compares a character to the lowercase alphabet
	*returns true or false*/
	if ((c < 'a') || (c > 'z')){
		return 0;
	}
	return 1;
}

int checkInput(char word[]){
	/*takes a string aray, calls isnumeric on each
	*character in the array, returns true or false*/
	int i;
	for (i = 0; i < strlen(word); i++){
		if (!isNumeric(word[i])){
			return 0;
		}
	}return 1;
}

int convertToLower(char word[]){
	/*converts a char array to lowercase
	*/
	int i;
	for (i = 0; i < strlen(word); i++){
		word[i] = tolower(word[i]);
	}
	return 0;
}

int compareString(char word[], char wordToCompare[])
	{
	/*compares two char arrays to determine if they contain
	*the same letters*/ 
	int j;
	int i = 0;
	int matchCount = 0;
	while (word[i] != '\0')
	{
		j = 0;
		while (wordToCompare[j] != '\0')
		/*traverses two char arrays. If the a matched letter is found
		*it it is counted, and then removed from the array its being compared to*/
		{
			if (word[i] == wordToCompare[j])
			{
			matchCount += 1;
			wordToCompare[j] = '0';
			}
		j += 1;
		}
	i += 1;
	}
return (i == matchCount);
}

int main()
{
	/*initializes two char arrays, takes user input to fill one, and then
	*uses std in to repeatedly get the other. Each time one is recieved, a copy
	*is created for testing anagram purposes*/
	char word[65];
	char wordCopy[65];

	char wordToCompare[65];
	char wordToCompareCopy[65];

	scanf("%65s", word);
	printf("%s\n", word);
	strcpy(wordCopy, word);
	convertToLower(wordCopy);

	while (	scanf("%65s", wordToCompare) > 0 )
		{
		strcpy(wordToCompareCopy, wordToCompare);
		convertToLower(wordToCompareCopy);
		if (!checkInput(wordCopy) || !checkInput(wordToCompareCopy)){
			printf("%s\n", "Bad Input ... non-alphabetical character");
		}
		int isAnagram = compareString(wordCopy, wordToCompareCopy);
		if (isAnagram){
			printf("%s", wordToCompare);
			printf("%c", '\n');
		} 
	}
	return 0;

}
