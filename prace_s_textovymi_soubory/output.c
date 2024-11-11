#include <stdio.h>
#include <stdlib.h>
#include "output.h"
#include "file_manager.h"
#include "processing.h"



//function for printing result from comparing files to console
//function accepts filenames as arguments
//bool is not defined in C, so we use int instead
int print_result(const char* filename1, const char* filename2) {
	int result = compare_files(filename1, filename2);
	if (result == 1) {
		printf("Files are the same\n");
	}
	else {
		printf("Files are different\n");
	}
	return result;
}