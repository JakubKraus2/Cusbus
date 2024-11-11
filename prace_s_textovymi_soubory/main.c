#include <stdio.h>
#include <stdlib.h>
#include "file_manager.h"
#include "processing.h"
#include "output.h"

#define FILENAME1 "file1.txt"
#define FILENAME2 "file2.txt"


//main function
int main() {
	//open files
	FILE* file1 = open_file(FILENAME1, "w");
	FILE* file2 = open_file(FILENAME2, "w");

	//write to files
	write_to_file(file1, "Hello, world!", 13);
	write_to_file(file2, "Hello, world!", 13);

	//close files
	close_file(file1);
	close_file(file2);

	//print result
	print_result(FILENAME1, FILENAME2);

	return 0;
}