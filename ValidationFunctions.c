#include "ValidationFunctions.h"
#include <ctype.h>

/*
Converts a string of characters to all lowercase
@param s as an array of characters
*/
void to_lower(char s[]) {
	size_t i;

	for (i = 0; s[i] != '\0'; i++) {
		s[i] = tolower(s[i]);
	}
}

/*
Checks whether the names entered are valid or not
@param character array
@return true or false, whether string is valid or not
*/
int is_valid(const char s[]) {
	int i;
	int cnt = 0;

	if (s[0] == '-') return 0;

	for (i = 0; s[i] != '\0'; i++) {
		if (s[i] != '-' && !isalpha(s[i])) {
			return 0;
		}
		cnt++;
	}

	if (cnt < 2 || cnt > 19 || s[cnt - 1] == '-') return 0;

	return 1;
}

/*
Checks whether the score is valid or not.
@param float score the score data as a float
@return true if invalid
*/
int validate_score(float score) {
	int temp = (int)score;
	float temp2 = temp;
	return temp2 < score;
}

/*
Validate the switch argument.
@param char pointer to the switch argument to validate
@return validation code:
	0	invalid argument
	1	-n
	2	+n
	3	-s
	4	+s
*/
int switch_validation(char* switch_arg) {
	int switch_char = switch_arg[1];
	int switch_mod = switch_arg[0];
	if (switch_arg[2] != '\0') return 0;
	if (switch_char == 'n') {
		if (switch_mod == '-') return 1;
		if (switch_mod == '+') return 2;
	} else if (switch_char == 's') {
		if (switch_mod == '-') return 3;
		if (switch_mod == '+') return 4;
	}
	
	return 0;
}
