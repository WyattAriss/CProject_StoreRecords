#include "DataStructures.h"

/*
Initializes a record_list
@param record_list pointer plist the list to initialize
*/
void list_init(record_list* plist) {
	plist->data = 0;
	plist->nalloc = 0;
	plist->nused = 0;
}

/*
Frees the memory used by plist
@param record_list pointer plist the list to free
*/
void list_destroy(record_list* plist) {
	free(plist->data);
	#ifdef DEBUG
		printf("@\n");
	#endif
}
