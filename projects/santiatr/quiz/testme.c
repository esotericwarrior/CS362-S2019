/**********************************************************
* Name: Tristan Santiago
* Date: May 8, 2019
* Description: This program implements a random tester to
* generate the error message with the specified coverage.
***********************************************************/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
/**********************************************************
* Function: char inputChar()
* Parameters: No parameters.
* Description: This function generates a random character
* within the specified ASCII range and returns in.
***********************************************************/
char inputChar() {
	char random = (rand() % 94) + 32;	// #32 - 125.
    return random;	// Return randomly generated character.
}
/**********************************************************
* Function: char* inputString()
* Parameters: No parameters.
* Description: This function is responsible for populating
* the random string using a randomly generated character.
***********************************************************/
char *inputString() {
	int i = 0;
	/* Define array to store the random string. */
	static char randomString[6];
	/* Define a string that contains the target characters. */
	char targetString[] = "reset";
	/* Clear the random string before populating. */
	memset(randomString, '\0', sizeof(randomString));
	while (i < 5) { 
		/* Populate the string using random characters. */
		randomString[i] = targetString[rand() % 5];
		i++;
	}
    return randomString;
}

void testme() {
	int tcCount = 0;
	char *s;
	char c;
	int state = 0;
	
	while (1) {
		tcCount++;
		c = inputChar();
		s = inputString();
		printf("Iteration %d: c = %c, s = %s, state = %d\n", tcCount, c, s, state);
		if (c == '[' && state == 0) state = 1;
		if (c == '(' && state == 1) state = 2;
		if (c == '{' && state == 2) state = 3;
		if (c == ' '&& state == 3) state = 4;
		if (c == 'a' && state == 4) state = 5;
		if (c == 'x' && state == 5) state = 6;
		if (c == '}' && state == 6) state = 7;
		if (c == ')' && state == 7) state = 8;
		if (c == ']' && state == 8) state = 9;
		if (s[0] == 'r' && s[1] == 'e'
			&& s[2] == 's' && s[3] == 'e'
			&& s[4] == 't' && s[5] == '\0'
			&& state == 9) {
				printf("error ");
				exit(200);
		}
	}
}

int main(int argc, char *argv[]) {
	srand(time(NULL));
	testme();
	return 0;
}
