#include "CompareFunctions.h"

/*
Adds the record specified by prec to the structure plist's array of records.
@param plist record_list pointer plist holds an array of records
@param record pointer prec is the record to be added to plist
@return 1 on success, 0 on failure
*/
int add(record_list* plist, const record* prec);

/*
Sorts the data stored in plist.
@param record_list pointer plist points to a struct holding an array of records
@param int switch1 is the first switch code
@param int switch2 is the second switch code
@return return 1 on success, 0 on failure
*/
int sort(record_list* plist, int switch1, int switch2);
