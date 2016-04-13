#include <stdio.h>

void print_matrix(char matrix[6][9]) {
	printf("\tKubus: \n");
	printf("* * *");
	for (int i = 0; i < 3; i++) {
		printf(" %c", matrix[2][i]);
	}
	printf(" * * * * * *\n");
	printf("* * *");
	for (int i = 3; i < 6; i++) {
		printf(" %c", matrix[2][i]);
	}
	printf(" * * * * * *\n");
	printf("* * *");
	for (int i = 6; i < 9; i++) {
		printf(" %c", matrix[2][i]);
	}
	printf(" * * * * * *\n");
	for (int i = 0; i < 3; i++) {
		if (i%3 == 0){
			printf("%c", matrix[3][i]);
		}
		else {
			printf(" %c", matrix[3][i]);
		}
	}
	for (int i = 0; i < 3; i++) {
		printf(" %c", matrix[0][i]);
	}
	for (int i = 0; i < 3; i++) {
		printf(" %c", matrix[1][i]);
	}
	for (int i = 0; i < 3; i++) {
		if (i % 3 == 2) {
			printf(" %c\n", matrix[5][i]);
		}
		else printf(" %c", matrix[5][i]);
	}
	for (int i = 3; i < 6; i++) {
		if (i % 3 == 0) {
			printf("%c", matrix[3][i]);
		}
		else {
			printf(" %c", matrix[3][i]);
		}
	}
	for (int i = 3; i < 6; i++) {
		printf(" %c", matrix[0][i]);
	}
	for (int i = 3; i < 6; i++) {
		printf(" %c", matrix[1][i]);
	}
	for (int i = 3; i < 6; i++) {
		if (i % 3 == 2) {
			printf(" %c\n", matrix[5][i]);
		}
		else printf(" %c", matrix[5][i]);
	}
	for (int i = 6; i < 9; i++) {
		if (i % 3 == 0) {
			printf("%c", matrix[3][i]);
		}
		else {
			printf(" %c", matrix[3][i]);
		}
	}
	for (int i = 6; i < 9; i++) {
		printf(" %c", matrix[0][i]);
	}
	for (int i = 6; i < 9; i++) {
		printf(" %c", matrix[1][i]);
	}
	for (int i = 6; i < 9; i++) {
		if (i % 3 == 2) {
			printf(" %c\n", matrix[5][i]);
		}
		else printf(" %c", matrix[5][i]);
	}
	printf("* * *");
	for (int i = 0; i < 3; i++) {
		printf(" %c", matrix[4][i]);
	}
	printf(" * * * * * *\n");
	printf("* * *");
	for (int i = 3; i < 6; i++) {
		printf(" %c", matrix[4][i]);
	}
	printf(" * * * * * *\n");
	printf("* * *");
	for (int i = 6; i < 9; i++) {
		printf(" %c", matrix[4][i]);
	}
	printf(" * * * * * *\n\n");
}

int main(void) {
	int test;
	char boven[9] = "WWGWWBOGB";
	char rechts[9] = "OWYYRGRRY";
	char achter[9] = "BOGRBBOGY";
	char links[9] = "OBGOOOWOW";
	char voor[9] = "BRWBGYRWB";
	char onder[9] = "RYYYYGRRG";
	char matrix[6][9];

	/*Matrix invullen*/
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 9; j++) {
			if (i == 0) {
				matrix[i][j] = boven[j];
			}
			if (i == 1) {
				matrix[i][j] = rechts[j];
			}
			if (i == 2) {
				matrix[i][j] = achter[j];
			}
			if (i == 3) {
				matrix[i][j] = links[j];
			}
			if (i == 4) {
				matrix[i][j] = voor[j];
			}
			if (i == 5) {
				matrix[i][j] = onder[j];
			}
		}
	}
	/*vanaf hier kan je aanpassen*/
	print_matrix(matrix);
	//test = find_edgepiece('W','G', matrix);
	//printf("%d\n", test);
//	BCW(matrix);

//	draai_voor_naar_links(matrix);
	print_matrix(matrix);
	maak_wit_kruis(matrix);
	
	print_matrix(matrix);
	test = find_edgepiece('W', 'G', matrix);
	printf("%d\n", test);
	return 0;
}