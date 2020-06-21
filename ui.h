#pragma once
#include <iostream>
#include <Windows.h>
#include <filesystem>
#include <string>
#include <istream>
#include <fstream>

using namespace std;

void greeting();

void Menu();

int save_result_q();

int wtdw_file(string& pFile);


enum fill_mat {
	keyboard = 1,
	from_file = 2,
	random = 3,
	test = 4,
	out = 5
};

enum saveinfile {
	yes = 1,
	no = 2
};


enum clearfile {
	rewrite = 1,
	add = 2,
	newfile
};