#include <stdio.h>
#include <stdlib.h>
#include "std_type.h"
#include "parse_csv.h"

static void test_hook(s32_t argc, str_t *argv[])
{
	for(;argc > 0; argc--) {
		printf("%s,", *argv++);
	}
	printf("\n");

}

int main(int argc, char *argv[]) 
{
	
    if (argc != 2) {
		LOG_E("Usage:./parse_csv <input csv file>");
        exit(0);
    }
    
	parse_csv_file(argv[1], FALSE, test_hook);

	return 0;
}

