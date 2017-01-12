#include "CompareFunctions.h"
#include <string.h>

/*
Compares two names, checking last names first, then if they are equal it
compares first names, and returns an int signaling ascending order.
@param void pointer a
@param void pointer b
@return int temp is a code telling qsort how to swap the two values
*/
int asc_compare_name(const void* a, const void* b) {
	record *record_a = (record*)a;
	record *record_b = (record*)b;
	int temp = strcmp(record_a->name.last, record_b->name.last);
	if (temp == 0) temp = strcmp(record_a->name.first, record_b->name.first);
	return temp;
}

/*
Compares two names and returns an int signaling descending order.
@param void pointer a
@param void pointer b
@return int temp is a code telling qsort how to swap the two values
*/
int desc_compare_name(const void* a, const void* b) {
	record *record_a = (record*)a;
	record *record_b = (record*)b;
	int temp = strcmp(record_a->name.last, record_b->name.last) * -1;
	if (temp == 0) temp = strcmp(record_a->name.first, record_b->name.first) * -1;
	return temp;
}

/*
Compares two names for ascending order, if the names are equal it compares scores
for ascending order.
@param void pointer a
@param void pointer b
@return int temp is a code telling qsort how to swap the two values
*/
int acn_acs(const void* a, const void* b) {
	int temp = asc_compare_name(a, b);
	if (temp == 0) temp = asc_compare_score(a, b);
	return temp;
}

/*
Compares two names for ascending order, if the names are equal it compares scores
for descending order.
@param void pointer a
@param void pointer b
@return int temp is a code telling qsort how to swap the two values
*/
int acn_dcs(const void* a, const void* b) {
	int temp = asc_compare_name(a, b);
	if (temp == 0) temp = desc_compare_score(a, b);
	return temp;
}

/*
Compares two names for descending order, if the names are equal it compares scores
for ascending order.
@param void pointer a
@param void pointer b
@return int temp is a code telling qsort how to swap the two values
*/
int dcn_acs(const void* a, const void* b) {
	int temp = desc_compare_name(a, b);
	if (temp == 0) temp = asc_compare_score(a, b);
	return temp;
}

/*
Compares two names for descending order, if the names are equal it compares scores
for descending order.
@param void pointer a
@param void pointer b
@return int temp is a code telling qsort how to swap the two values
*/
int dcn_dcs(const void* a, const void* b) {
	int temp = desc_compare_name(a, b);
	if (temp == 0) temp = desc_compare_score(a, b);
	return temp;
}

/*
Compares two scores for ascending order.
@param void pointer a
@param void pointer b
@return int temp is a code telling qsort how to swap the two values
*/
int asc_compare_score(const void* a, const void* b) {
	record *record_a = (record*)a;
	record *record_b = (record*)b;
	return record_a->score - record_b->score;
}

/*
Compares two scores for descending order.
@param void pointer a
@param void pointer b
@return int temp is a code telling qsort how to swap the two values
*/
int desc_compare_score(const void* a, const void* b) {
	record *record_a = (record*)a;
	record *record_b = (record*)b;
	return (record_a->score - record_b->score) * -1;
}

/*
Compares two scores for ascending order, if the scores are equal it compares names
for ascending order.
@param void pointer a
@param void pointer b
@return int temp is a code telling qsort how to swap the two values
*/
int acs_acn(const void* a, const void* b) {
	int temp = asc_compare_score(a, b);
	if (temp == 0) temp = asc_compare_name(a, b);
	return temp;
}

/*
Compares two scores for ascending order, if the scores are equal it compares names
for descending order.
@param void pointer a
@param void pointer b
@return int temp is a code telling qsort how to swap the two values
*/
int acs_dcn(const void* a, const void* b) {
	int temp = asc_compare_score(a, b);
	if (temp == 0) temp = desc_compare_name(a, b);
	return temp;
}

/*
Compares two scores for descending order, if the scores are equal it compares names
for ascending order.
@param void pointer a
@param void pointer b
@return int temp is a code telling qsort how to swap the two values
*/
int dcs_acn(const void* a, const void* b) {
	int temp = desc_compare_score(a, b);
	if (temp == 0) temp = asc_compare_name(a, b);
	return temp;
}

/*
Compares two scores for descending order, if the scores are equal it compares names
for descending order.
@param void pointer a
@param void pointer b
@return int temp is a code telling qsort how to swap the two values
*/
int dcs_dcn(const void* a, const void* b) {
	int temp = desc_compare_score(a, b);
	if (temp == 0) temp = desc_compare_name(a, b);
	return temp;
}
