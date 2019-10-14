#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>

int** allocate();
int getInt(char c);
bool solve(int** matrix);
void print(int** matrix);
void freeMatrix(int** matrix);

int** allocate() {
	int** arr = malloc(16 * sizeof(int*));
	for (int i = 0; i < 16; i++) {
		arr[i] = malloc(16 * sizeof(int));
	}

	return arr;
}

int getInt(char c) {
	int result;
	if(c == 'A') {
		result = 10;
	} else if (c == 'B') {
		result = 11;
	} else if (c == 'C') {
		result = 12;
	} else if (c == 'D') {
		result = 13;
	} else if (c == 'E') {
		result = 14;
	} else if (c == 'F') {
		result = 15;
	} else {
		result = c - '0';
	}
	return result;
}

bool valid(int** matrix) {
	bool result = true;
	for(int num = 0; num < 16; num++) {
		for(int i = 0; i < 16; i++) {
			int count = 0;
			int count2 = 0;
			int sum = 0;
			int sum2 = 0;
			for(int j = 0; j < 16; j++){
				if(matrix[i][j] == num) {
					count++;
				}
				if(matrix[i][j] != -1) {
					sum += matrix[i][j];
				}
				if(matrix[j][i] == num) {
					count2++;
				}
				if(matrix[j][i] != -1) {
					sum2 += matrix[j][i];
				}
			}
			if(count > 1 || count2 > 1 || sum > 120 || sum2 > 120) {
				return false;
			}
		}

		for(int rows = 0; rows < 16; rows+=4) {
			for(int cols = 0; cols < 16; cols+=4) {
				int x = cols - (cols%4);
				int y = rows - (rows%4);
				int count = 0;
				int sum = 0;
				for(int i = y; i < y+4; i++) {
					for(int j = x; j < x+4; j++) {
						if(matrix[i][j] == num) {
							count++;
						}
						if(matrix[i][j] != -1) {
							sum += matrix[i][j];
						}
					}
				}
				if(count > 1 || sum > 120) {
					return false;
				}
			}
		}
	}

	return result;
}

bool solve(int** matrix) {
	if(valid(matrix) == false) {
		return false;
	}

	int rows = -1;
	int cols = -1;
	bool found = false;
	for(int i = 0; i < 16; i++) {
		for(int j = 0; j < 16; j++) {
			if(matrix[i][j] == -1) {
				rows = i;
				cols = j;
				found = true;
				break;
			}
		}
		if(found == true) {
			break;
		}
	}
	if(found == false) {
		return true;
	} else {
		for(int num = 0; num < 16; num++) {
			matrix[rows][cols] = num;
			if(solve(matrix)) {
				return true;
			} else {
				matrix[rows][cols] = -1;
			}
		}
		return false;
	}
}

void print(int** matrix) {
	for(int i = 0; i < 16; i++) {
		if(i != 0) {
			printf("\n");
		}
	
		for(int j = 0; j < 16; j++) {
			if(matrix[i][j] == -1) {
				printf("%d	", matrix[i][j]);
			} else {
				printf("%X	", matrix[i][j]);
			}
		}
	}
}

void freeMatrix(int** matrix) {
	for (int i = 0; i < 16; i++) {
		free(matrix[i]);
	}
	free(matrix);
}
		

int main(int argc, char** argv) {
	
	if (argc != 2) {
		printf("insufficient arguments\n");
		exit(0);
	}

	FILE* fp = fopen(argv[1], "r");

	if (fp == NULL) {
		printf("error\n");
		exit(0);
	}

	int** matrix = allocate();

	char a;

	for(int i = 0; i < 16; i++) {
		for(int j = 0; j < 16; j++) {

			if(fscanf(fp, "%c", &a) == EOF) {
				exit(0);
			}

			if (a == '	') {
				fscanf(fp, "%c\n", &a);
			}
			
			if (a != '-') {
				int x = getInt(a);
				matrix[i][j] = x;
			} else {
				matrix[i][j] = -1;
			}


		}
	}
	
	if(solve(matrix) == true) {
		print(matrix);
	} else {
		printf("no-solution\n");
	}

	freeMatrix(matrix);
	return 0;

}
