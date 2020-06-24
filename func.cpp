#include "func.h"


const int f_row = 1;

void fill_mas(double **array, int m, int n) {
	for (int i = 1; i < m; i++) {
		for (int j = 0; j < n; j++) {		
			if (i % 2 == 0) {
				if (j == 0) {
					array[i][j] = (array[i - 1][n - 1] + array[0][n - 1]) / 2;
				}
				else {
					array[i][j] = (array[i][j - 1] + array[0][j - 1]) / 2;
				}
			}
			if (i % 2 == 1) {
				if (j == 0) {
					array[i][j] = abs(array[i - 1][n - 1] + array[0][n - 1]) / 2;
				}
				else {
					array[i][j] = abs(array[i][j - 1] + array[0][j - 1]) / 2;
				}
			}
		}
	}
}


void print(double** array, int m, int n) {
	for (int i = 0; i < m; i++) {
		if (i == 0) {
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
		}
		for (int j = 0; j < n; j++) {
			cout << "U" << "[" << i + 1 << "]" << "[" << j + 1 << "]" << " = ";
			cout << array[i][j] << " ";
		}
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
		cout << endl;
	}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
}

void print_in_file(string inpath, string outpath, double** array, int m, int n) {
	cin >> outpath;
	ifstream fcheck;
	while (inpath == outpath) {
		cout << "Адреса файлов совпадают. Введите путь к файлу: " << endl;
		cin >> outpath;
	}
	fcheck.open(outpath);
	while (!check_read_only(outpath)) {
		fcheck.close();
		cout << "Введите путь к файлу: " << endl;
		cin >> outpath;
		while (inpath == outpath) {
			cout << "Адреса файлов совпадают. Введите путь к файлу: " << endl;
			cin >> outpath;
		}
		fcheck.open(outpath);
	}
	while (file_name_check(outpath)) {
		fcheck.close();
		cout << "Ошибка! Некорректное путь или имя файла." << endl;
		cout << "Введите путь к файлу: " << endl;
		cin >> outpath;
		while (inpath == outpath) {
			cout << "Адреса файлов совпадают. Введите путь к файлу: " << endl;
			cin >> outpath;
		}
		fcheck.open(outpath, ios::in);
	}
	if (file_exist(outpath) == false) {
		fcheck.close();
		save_result(outpath, array, rewrite, m, n);
	}
	else {
		fcheck.close();
		if (file_check_size(outpath) == true) {
			save_result(outpath, array, rewrite, m, n);
		}
		else {
			save_result(outpath, array, wtdw_file(outpath), m, n);
		}
	}
}

void print_source(string& inpath, double** array, int m, int n) {
	cin >> inpath;
	ifstream fcheck;
	fcheck.open(inpath);
	while (!check_read_only(inpath)) {
		fcheck.close();
		cout << "Введите путь к файлу: " << endl;
		cin >> inpath;
		fcheck.open(inpath);
	}
	while (file_name_check(inpath)) {
		fcheck.close();
		cout << "Ошибка! Некорректное путь или имя файла." << endl;
		cout << "Введите путь к файлу: " << endl;
		cin >> inpath;
		fcheck.open(inpath, ios::in);
	}
	if (file_exist(inpath) == false) {
		fcheck.close();
		save_source(inpath, array, rewrite, m, n);
	}
	else {
		fcheck.close();
		if (file_check_size(inpath) == true) {
			save_source(inpath, array, rewrite, m, n);
		}
		else {
			save_source(inpath, array, wtdw_file(inpath), m, n);
		}
	}
}
void save_source(string inpath, double** array, int modout, int m, int n) {
	ofstream fout;
	if (modout == 1) {
		fout.open(inpath, ios::out);
		fout << " " << endl;
	}
	if (modout == 2) {
		fout.open(inpath, ios::app);
		fout << " " << endl;
	}
	fout << m << " " << n << endl;
	for (int i = 0; i < f_row; i++) {
		for (int j = 0; j < n; j++) {
			fout << array[i][j] << " ";
		}
		fout << endl;
	}
	cout << "Исходные данные успешно сохранены! " << endl;
}

double** create(int m, int n) {
	double** array = new double* [m];
	for (int i = 0; i < m; i++) {
		array[i] = new double[n];
	}
	return array;
}

void save_result(string path, double** array, int modout, int m, int n) {
	ofstream fout;
	if (modout == 1) {
		fout.open(path, ios::out);
		fout << " " << endl;
	}
	if (modout == 2) {
		fout.open(path, ios::app);
		fout << " " << endl;
	}
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			fout << "U" << "[" << i + 1 << "]" << "[" << j + 1 << "]" << " = ";
			fout << array[i][j] << " ";
		}
		fout << endl;
	}
	cout << "Массив успешно сохранен! " << endl;
}

bool file_name_check(string filename) {
	size_t found = filename.find_last_of("\\");
	size_t point = filename.find_last_of(".");
	size_t base = point - found - 1;
	string basefilenameStr = filename.substr(found + 1, base);
	const char* basefilenameChar = basefilenameStr.c_str();
	ofstream file(filename, ios::app);
	if (!_strcmpi(basefilenameChar, "con")) return true;
	if (!std::filesystem::is_regular_file(filename)) return true;
	file.close();
	return false;
}


bool error_check() {
	if (cin.fail())
	{
		cin.clear();
		cin.ignore(32767, '\n');
		cout << "Пожалуйста введите цифру из выше указанных! " << endl;
		return 0;
	}
	return 1;
}

bool file_check_size(string pFile) {
	ifstream file_check_size;
	file_check_size.open(pFile, ios::in);
	file_check_size.seekg(0, ios::end);
	if (file_check_size.tellg() == 0) {
		file_check_size.close();
		return true;
	}
	else {
		file_check_size.close();
		return false;
	}
}

int number_check() {
	int a;
	while (!(cin >> a) || (cin.peek() != '\n'))
	{
		cin.clear();
		while (cin.get() != '\n');
		cout << "Ошибка! Пожалуйста введите число! " << endl;
	}
	return a;
}

double numb_check() {
	double a;
	while (!(cin >> a) || (cin.peek() != '\n'))
	{
		cin.clear();
		while (cin.get() != '\n');
		cout << "Ошибка! Пожалуйста введите число! " << endl;
	}
	return a;
}
bool check_read_only(string filename) {
	ofstream file(filename, ios::in);
	LPCSTR name = filename.c_str();
	WIN32_FIND_DATAA findData;
	FindFirstFileA(name, &findData);
	if (findData.dwFileAttributes & FILE_ATTRIBUTE_READONLY) {
		cerr << "Ошибка! Невозможно сохранить данные в файл, предназначенный только для чтения! " << endl;
		return false;
	}
	else {
		return true;
	}
}


bool file_exist(string path) {
	ifstream file(path);
	file.open(path, ios::in);
	if (file.is_open())
		return true;
	else
		return false;
}