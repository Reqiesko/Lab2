#include "test.h"



const int count_of_tests = 33;
const int r1 = 2, c1 = 2, r2 = 3, c2 = 2, r3 = 2, c3 = 3, r4 = 3, c4 = 3, r5 = 4, c5 = 2;
void module_tests() {
	system("cls");
	int count = 0, i, j;
	

	double** source_mat1 = create_mat(r1, c1);
	source_mat1[0][0] = 4; source_mat1[0][1] = 5;
	source_mat1[1][0] = 5; source_mat1[1][1] = 4.5;
									         
	double** source_mat2 = create_mat(r2, c2);
	source_mat2[0][0] = 2;		source_mat2[0][1] = 9;
	source_mat2[1][0] = 9;		source_mat2[1][1] = 5.5;
	source_mat2[2][0] = 7.25; source_mat2[2][1] = 4.625;

	double** source_mat3 = create_mat(r3, c3);
	source_mat3[0][0] = -5;		source_mat3[0][1] = 2;    source_mat3[0][2] = -3.9;
	source_mat3[1][0] = 3.9;	source_mat3[1][1] = 0.55;  source_mat3[1][2] = 1.275;

	double** source_mat4 = create_mat(r4, c4);
	source_mat4[0][0] = 5;		source_mat4[0][1] = 4;		source_mat4[0][2] = 3;
	source_mat4[1][0] = 3;		source_mat4[1][1] = 4;		source_mat4[1][2] = 4;
	source_mat4[2][0] = 3.5;  source_mat4[2][1] = 4.25;	source_mat4[2][2] = 4.125;

	double** source_mat5 = create_mat(r5, c5);
	source_mat5[0][0] = 40;		 source_mat5[0][1] = -20;
	source_mat5[1][0] = 20;    source_mat5[1][1] = 30;
	source_mat5[2][0] = 5;		 source_mat5[2][1] = 22.5;
	source_mat5[3][0] = 1.25;  source_mat5[3][1] = 20.625;

	double** result_mat1 = create_mat(r1, c1);
	result_mat1[0][0] = 4;	result_mat1[0][1] = 5;
	fill_mat(result_mat1, r1, c1);


	double** result_mat2 = create_mat(r2, c2);
	result_mat2[0][0] = 2;	result_mat2[0][1] = 9;
	fill_mat(result_mat2, r2, c2);


	double** result_mat3 = create_mat(r3, c3);
	result_mat3[0][0] = -5;	result_mat3[0][1] = 2;	result_mat3[0][2] = -3.9;
	fill_mat(result_mat3, r3, c3);


	double** result_mat4 = create_mat(r4, c4);
	result_mat4[0][0] = 5;	result_mat4[0][1] = 4;	result_mat4[0][2] = 3;
	fill_mat(result_mat4, r4, c4);


	double** result_mat5 = create_mat(r5, c5);
	result_mat5[0][0] = 40;	result_mat5[0][1] = -20;
	fill_mat(result_mat5, r5, c5);
	
	
	for (i = 0; i < r1; i++) {	
		for (j = 0; j < c1; j++) {
			if (source_mat1[i][j] == result_mat1[i][j]) {				
				count++;
			}
			else {
				cout << "В массиве №1" << endl;
				cout << "Ожидался элемент " << "U" << "[" << i << "]" << "," << "[" << j << "] = " << source_mat1[i][j] << endl;
				cout << "А получен элемент " << "U" << "[" << i << "]" << "," << "[" << j << "] = " << result_mat1[i][j] << endl;
			}
		}
	}


	for (i = 0; i < r2; i++) {
		for (j = 0; j < c2; j++) {
			if (source_mat2[i][j] == result_mat2[i][j]) {
				count++;
			}
			else {
				cout << "В массиве №2" << endl;
				cout << "Ожидался элемент " << "U" << "[" << i << "]" << "," << "[" << j << "] = " << source_mat2[i][j] << endl;
				cout << "А получен элемент " << "U" << "[" << i << "]" << "," << "[" << j << "] = " << result_mat2[i][j] << endl;
			}
		}
	}


	for (i = 0; i < r3; i++) {
		for (j = 0; j < c3; j++) {
			if (source_mat3[i][j] == result_mat3[i][j]) {
				count++;
			}
			else {
				cout << "В массиве №4" << endl;
				cout << "Ожидался элемент " << "U" << "[" << i << "]" << "," << "[" << j << "] = " << source_mat3[i][j] << endl;
				cout << "А получен элемент " << "U" << "[" << i << "]" << "," << "[" << j << "] = " << result_mat3[i][j] << endl;
			}
		}
	}


	for (i = 0; i < r4; i++) {
		for (j = 0; j < c4; j++) {
			if (source_mat4[i][j] == result_mat4[i][j]) {
				count++;
			}
			else {
				cout << "В массиве №4" << endl;
				cout << "Ожидался элемент " << "U" << "[" << i << "]" << "," << "[" << j << "] = " << source_mat4[i][j] << endl;
				cout << "А получен элемент " << "U" << "[" << i << "]" << "," << "[" << j << "] = " << result_mat4[i][j] << endl;
			}
		}
	}

	for (i = 0; i < r5; i++) {
		for (j = 0; j < c5; j++) {
			if (source_mat5[i][j] == result_mat5[i][j]) {
				count++;
			}
			else {
				cout << "В массиве №5" << endl;
				cout << "Ожидался элемент " << "U" << "[" << i << "]" << "," << "[" << j << "] = " << source_mat5[i][j] << endl;
				cout << "А получен элемент " << "U" << "[" << i << "]" << "," << "[" << j << "] = " << result_mat5[i][j] << endl;
			}
		}
	}
	

	if (count == count_of_tests) {
		cout << "Тест успешно пройден!" << endl;
	}
	else {
		cout << "Тест провален!" << endl;
	}
	
	for (i = 0; i < r1; i++) {
		delete[] source_mat1[i];	
	}	
	for (i = 0; i < r2; i++) {
		delete[] source_mat2[i];
	}
	
	for (i = 0; i < r3; i++) {
		delete[] source_mat3[i];
	}
	
	for (i = 0; i < r4; i++) {
		delete[] source_mat4[i];
	}
	
	for (i = 0; i < r5; i++) {
		delete[] source_mat5[i];
	}
	for (i = 0; i < r1; i++) {
		delete[] result_mat1[i];
	}

	for (i = 0; i < r2; i++) {
		delete[] result_mat2[i];
	}

	for (i = 0; i < r3; i++) {
		delete[] result_mat3[i];
	}

	for (i = 0; i < r4; i++) {
		delete[] result_mat4[i];
	}

	for (i = 0; i < r5; i++) {
		delete[] result_mat5[i];
	}

	delete[] source_mat1;
	delete[] source_mat2;
	delete[] source_mat3;
	delete[] source_mat4;
	delete[] source_mat5;
	delete[] result_mat1;
	delete[] result_mat2;
	delete[] result_mat3;
	delete[] result_mat4;
	delete[] result_mat5;
}

