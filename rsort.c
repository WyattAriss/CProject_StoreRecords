/*
Student Name    : Wyatt Ariss
Student Number  : A00980674
Course          : COMP2510
Assignment #    : 3

PROGRAM DESCRIPTION:
A program to store and sort records of names and scores using dynamically
allocated memory.
*/

#include <stdio.h>
#include <string.h>
#include "ValidationFunctions.h"
#include "Commands.h"

#define LINESIZE 512

/*
Creates a record to be stored.
@param const char firstname[] is the records first name
@param const char lastname[] is the records last name
@param const int score is the score
@param prec is a pointer to the record to store the data in
*/
void create_record(const char firstName[], const char lastName[], const int score, record* prec) {
	strcpy(prec->name.first, firstName);
	strcpy(prec->name.last, lastName);
	prec->score = score;
}

/*
Takes input from the user.
@param record_list pointer
@return error code:
	-1			fgets fail
	 0			invalid input
	 error_code	success	
*/
int input(record_list* precordList) {
	char user_input[LINESIZE];
	char command[LINESIZE];
	char first_name[LINESIZE];
	char last_name[LINESIZE];
	size_t i;
	char arg1[3];
	char arg2[3];
	int switch_code1 = 0, switch_code2 = 0;
	float score;
	int error_code = 0;
	record current_record;

	fprintf(stderr, "Please enter a command ('add' or 'sort') followed by data\n");

	if (!fgets(user_input, LINESIZE, stdin)) {
		return -1;
	}

	if (sscanf(user_input, "%s", command) != 1) {
		clearerr(stdin);
	}

	if ((strcmp(command, "add") == 0)
		&& (sscanf(user_input, "%s%s%s%f", command, first_name, last_name, &score) == 4)
		&& (is_valid(first_name))
		&& (is_valid(last_name))
		&& (!validate_score(score))
		&& (score >= 0 && score <= 100)) {

		to_lower(first_name);
		to_lower(last_name);

		create_record(first_name, last_name, score, &current_record);

		error_code = add(precordList, &current_record);
		printf("...OK\n");
		return error_code;
	}

	if (strcmp(command, "sort") == 0) {
		if (sscanf(user_input, "%s%s%s", command, arg1, arg2) == 3) {
			switch_code1 = switch_validation(arg1);
			switch_code2 = switch_validation(arg2);
			error_code = sort(precordList, switch_code1, switch_code2);
		} else if (sscanf(user_input, "%s%s", command, arg1) == 2) {
			switch_code1 = switch_validation(arg1);
			error_code = sort(precordList, switch_code1, switch_code2);
		} else if (sscanf(user_input, "%s", command) == 1) {
			error_code = sort(precordList, switch_code1, switch_code2);
		}

		for (i = 0; i < precordList->nused; i++) {
			printf("%s, %s: %d\n", precordList->data[i].name.last, precordList->data[i].name.first, precordList->data[i].score);
		}
		printf("...OK\n");
		return error_code;
	}
	return 0;
}

/*
Main function drives the program.
*/
int main(void) {

	record_list records;
	int result = 0;

	list_init(&records);

	while(result >= 0) {
		result = input(&records);
		if (result == 0) {
			fprintf(stderr, "Usage: add [firstname] [lastname] \n"); /* correct usage */
			fprintf(stderr, "Usage: sort [+ or -][n or s] [+ or -][n or s] \n");
		}
	}

	list_destroy(&records);

	return 1;

}
