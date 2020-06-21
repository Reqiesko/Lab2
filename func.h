#pragma once
#include "ui.h"



void fill_mas(double** array, int m, int n);

void print(double** array, int m, int n);

void print_in_file(string inpath, string outpath, double** array, int m, int n);

void print_source(string& inpath, double** array, int m, int n);

void save_source(string inpath, double** array, int modout, int m, int n);

void save_result(string path, double** array, int modout, int m, int n);

bool error_check();

bool file_check_size(string pFile);

int number_check();

bool check_read_only(string filename);

bool file_exist(string path);

bool file_name_check(string filename);