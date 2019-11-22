/* Libraries */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/* Structs */
typedef struct results {
    int acess_count;
    int read_hits;
    int read_misses;
    int write_hits;
    int write_misses;
} Results;

typedef struct desc {
    int line_size;                                   // Block size
    int number_of_lines;                             // Number of blocks
    int associativity;                               // Number of blocks per set
    char replacement_policy[5];                      // LRU or FIFO + \0
} Desc;

typedef struct cache {
    int    ** Cache_Data;  
    long unsigned ** Cache_Upper;
    long unsigned ** T_Access; 
    long unsigned ** T_Load;   
} Cache;

/* Prototypes of used functions */
int startCache(Cache *cache1, int number_of_sets, int associativity);
int make_upper(long unsigned address, int words_per_line, int bytes_per_word);
int make_index(int number_of_lines_of_cache, long unsigned upper);
int make_tag(int number_of_lines_of_cache, int associativity);
int getPosUpper (Cache *cache, int index, long unsigned line, int associativity);
int there_Are_Space_Set(Cache *cache1, int index1, int associativity);
int random_free_space_set (Cache *cache1, int index1, int associativity);
int findLessAccessTSset (Cache *cache1, int index1, int associativity);
void write_cache (Cache *cache1, Results *result1, int index1, long unsigned line1, int data1, int associativity, char *replacement_policy);
void read_cache (Cache *cache1, Results *result1, int index1, long unsigned line1, int data1, int associativity, char *replacement_policy);
void generate_output(Results cache_results, char *output_name);

