#include <stdio.h>
#include <stdlib.h>
#include "file_manager.h"



//function for opening file
FILE* open_file(const char* filename, const char* mode) {
	FILE* file = fopen(filename, mode);

	if (file == NULL) {
		fprintf(stderr, "Error: Unable to open file\n");
		exit(1);
	}

	return file;
}

//function for closing file
void close_file(FILE* file) {
	if (fclose(file) == EOF) {
		fprintf(stderr, "Error: Unable to close file\n");
		exit(1);
	}
}

//function for reading from file
int read_from_file(FILE* file, char* buffer, int buffer_size) {
	int read = fread(buffer, sizeof(char), buffer_size, file);

	if (read != buffer_size) {
		fprintf(stderr, "Error: Unable to read from file\n");
		exit(1);
	}

	return read;
}

//function for writing to file
int write_to_file(FILE* file, const char* buffer, int buffer_size) {
	int written = fwrite(buffer, sizeof(char), buffer_size, file);

	if (written != buffer_size) {
		fprintf(stderr, "Error: Unable to write to file\n");
		exit(1);
	}

	return written;
}