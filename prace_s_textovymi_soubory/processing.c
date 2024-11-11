#include <stdio.h>
#include <stdlib.h>
#include "processing.h"
#include "file_manager.h"


//function for comparing to files if what was written to them is the same
//bool is not defined in C, so we use int instead
int compare_files(const char* filename1, const char* filename2) {
	FILE* file1 = open_file(filename1, "r");
	FILE* file2 = open_file(filename2, "r");

	if (file1 == NULL || file2 == NULL) {
		return -1;
	}

	char c1, c2;
	while (1) {
		c1 = fgetc(file1);
		c2 = fgetc(file2);

		if (c1 != c2) {
			close_file(file1);
			close_file(file2);
			return 0;
		}

		if (c1 == EOF || c2 == EOF) {
			break;
		}
	}

	close_file(file1);
	close_file(file2);
	return 1;
}