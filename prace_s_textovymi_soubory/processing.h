#pragma once


//function for comparing to files if what was written to them is the 
//bool is not defined in C, so we use int instead
int compare_files(const char* filename1, const char* filename2);