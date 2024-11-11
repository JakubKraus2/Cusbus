#pragma once


//function for printing result from comparing files to console
//function accepts filenames as arguments
//bool is not defined in C, so we use int instead
int print_result(const char* filename1, const char* filename2);