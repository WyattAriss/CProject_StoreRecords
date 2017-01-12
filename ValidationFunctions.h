/*
Converts a string of characters to all lowercase
@param s as an array of characters
*/
void to_lower(char s[]);

/*
Checks whether the names entered are valid or not
@param character array
@return true or false, whether string is valid or not
*/
int is_valid(const char s[]);

/*
Checks whether the score is valid or not.
@param float score the score data as a float
@return true if invalid
*/
int validate_score(float score);

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
int switch_validation(char* switch_arg);
