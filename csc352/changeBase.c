/*Author: Adam Cunningham
*filename: changeBase.c
*the purpose of this program is to take a base from standard in
*then all subsequent numbers are converted to that base
*legal characters for base, 2-32
*legal characters for number to be converted
*0-9, a-z, (will be converted to lower)
*max converted number cardinality is 6
*if it contains non alphanumeric chars a warning will be printed
*/

#include<stdio.h>
#include<math.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>

int charToNum(char c, int base)
{
	/*parameters: a character from the stdin, and the base to be converted to
	*takes characters and converts to a corresponding number
	*if the translated char value is greater than or equal to
	*the base, or if its outside of the legal input, a warning is printed
	*
	*/
	
	if ((c >= 'a') && (c <= 'z'))
	{
		c -= 'a';
		c += 10;
	}
	else if ((c >= 'A') && (c <= 'Z'))
	{
		c -= 'A';
		c += 10;
	}
	else if ((c >= '0') && (c <= '9'))
	{
		c -= '0';
	}
	else 
	{
		printf("%s %d %s %c", "Not a", base, "number", '\n');
		return 0;
	}
	if (c >= base){
		printf("%s %d %s %c", "Not a", base, "number", '\n');
		return 0;
	}
	return (0 + c);
}

int changeBase(char toConvert[], int base)
{
	/*takes a char array to be converted to the base
	*takes a base to convert
	*/
	int sum;
	int i;
	int j;
	int currNum;
	j = 0;
	i = strlen(toConvert) -1;
	sum = 0;
	/*multiplies each element of the converted char array
	*by the base * arraylength - curr index+1
	*the sum is the converted number
	*/
	while (i <= 0)
	{
		currNum = charToNum(toConvert[j], base);
		if (currNum < 0){
			return currNum;
		}
		currNum = currNum * pow(base, i);
		sum += currNum;
		j++;
		i--;
	}
	printf("%d\n", sum);
	return 0;

}

int main()
{
	/*takes input from std in
	*does some basic input checking, and
	*converts the number to a new base
	*illegal bases exit the program
	*illegal numbers to be converted print a warning
	*/
	char toConvert[7];
	int base;
	scanf("%d", &base);
	
	if ((base <2) || (base > 32))
	{
		printf("%s", "Bad base input");
		exit(1);
	}
	while(scanf("%7s", toConvert))
	{
		changeBase(toConvert, base);	
	}
	
	return 0;
	
}
