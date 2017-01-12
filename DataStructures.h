#define NAMESIZE 20
#define BLOCK 2
#include <stdlib.h>
#include <stdio.h>

/*
Structure to store a name
char last[NAMESIZE]		stores a last name
char first[NAMESIZE]	stores a first name
*/
typedef struct {
	char last[NAMESIZE]; /* last name */
	char first[NAMESIZE]; /* first name */
} name;

/*
Structure to store a record
name name	stores a first and last name
int score	stores a score
*/
typedef struct {
	name name;
	int score;
} record;

/*
Structure to store an array of records and track size
record* data	pointer to dynamic array of records
size_t nalloc	number of records allocated
size_t nused	number of records used
*/
typedef struct {
	record* data;
	size_t nalloc;
	size_t nused;
} record_list;

/*
Initializes a record_list
@param record_list pointer plist the list to initialize
*/
void list_init(record_list* plist);

/*
Frees the memory used by plist
@param record_list pointer plist the list to free
*/
void list_destroy(record_list* plist);
