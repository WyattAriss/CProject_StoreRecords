#include "Commands.h"
#include <stdio.h>

/*
Adds the record specified by prec to the structure plist's array of records.
@param plist record_list pointer plist holds an array of records
@param record pointer prec is the record to be added to plist
@return 1 on success, 0 on failure
*/
int add(record_list* plist, const record* prec) {
	if (plist->nalloc == plist->nused) {
		record *temp = realloc(plist->data, (plist->nalloc + BLOCK) * sizeof(record));
		if (temp == NULL) {
			perror("error reallocating");
			return 0;
		}
		plist->data = temp;
		plist->nalloc += BLOCK;
		plist->data[plist->nused] = *prec;
		plist->nused++;
		#ifdef DEBUG
			printf("#\n");
		#endif
	} else {
		plist->data[plist->nused] = *prec;
		plist->nused++;
	}
	return 1;
}

/*
Sorts the data stored in plist.
@param record_list pointer plist points to a struct holding an array of records
@param int switch1 is the first switch code
@param int switch2 is the second switch code
@return return 1 on success, 0 on failure
*/
int sort(record_list* plist, int switch1, int switch2) {
	
	/* invalid switches */
	if (switch1 == 0 && switch2 == 0) return 2;
	/* -n || -n -n || -n +n */
	if (switch1 == 1 && (switch2 == 0 || switch2 == 1 || switch2 == 2)) {
		qsort(plist->data, plist->nused, sizeof(record), desc_compare_name);
		return 1;
	}
	/* -n -s */
	if (switch1 == 1 && switch2 == 3) {
		qsort(plist->data, plist->nused, sizeof(record), dcn_dcs);
		return 1;
	}
	/* -n +s */
	if (switch1 == 1 && switch2 == 4) {
		qsort(plist->data, plist->nused, sizeof(record), dcn_acs);
		return 1;
	}
	/* +n || +n -n || +n +n */
	if (switch1 == 2 && (switch2 == 0 || switch2 == 1 || switch2 == 2)) {
		qsort(plist->data, plist->nused, sizeof(record), asc_compare_name);
		return 1;
	}
	/* +n -s */
	if (switch1 == 2 && switch2 == 3) {
		qsort(plist->data, plist->nused, sizeof(record), acn_dcs);
		return 1;
	}
	/* +n +s */
	if (switch1 == 2 && switch2 == 4) {
		qsort(plist->data, plist->nused, sizeof(record), acn_acs);
		return 1;
	}
	/* -s || -s -s || -s +s */
	if (switch1 == 3 && (switch2 == 0 || switch2 == 3 || switch2 == 4)) {
		qsort(plist->data, plist->nused, sizeof(record), desc_compare_score);
		return 1;
	}
	/* -s -n */
	if (switch1 == 3 && switch2 == 1) {
		qsort(plist->data, plist->nused, sizeof(record), dcs_dcn);
		return 1;
	}
	/* -s +n */
	if (switch1 == 3 && switch2 == 2) {
		qsort(plist->data, plist->nused, sizeof(record), dcs_acn);
		return 1;
	}
	/* +s || +s -s || +s +s */
	if (switch1 == 4 && (switch2 == 0 || switch2 == 3 || switch2 == 4)) {
		qsort(plist->data, plist->nused, sizeof(record), asc_compare_score);
		return 1;
	}
	/* +s -n */
	if (switch1 == 4 && switch2 == 1) {
		qsort(plist->data, plist->nused, sizeof(record), acs_dcn);
		return 1;
	}
	/* +s +n */
	if (switch1 == 4 && switch2 == 2) {
		qsort(plist->data, plist->nused, sizeof(record), acs_acn);
		return 1;
	}

	return 0;
}
