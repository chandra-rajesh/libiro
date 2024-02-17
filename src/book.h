#include <stdio.h>
#include <stdlib.h>

#define u32 unsigned int

// IDK HOW TO USE THIS

/*TODO*/

void add_books(FILE *lib_appender, FILE *lib_reader, char *book_name,
               char *author_name);

u32 get_book_ID(FILE *lib_appender, FILE *lib_reader, char *book_name);

u32 generate_ID(FILE *lib_reader);
