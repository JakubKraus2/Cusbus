#pragma once


//function for opening file
FILE* open_file(const char* filename, const char* mode);

//function for closing file
void close_file(FILE* file);

//function for reading from file
int read_from_file(FILE* file, char* buffer, int buffer_size);

//function for writing to file
int write_to_file(FILE* file, const char* buffer, int buffer_size);
