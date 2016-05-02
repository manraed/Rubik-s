#include <stdio.h>



int main(void) {
	int test;
	char boven[9] = "RBWRWOOWW";
	char rechts[9] = "OROBRWBBR";
	char achter[9] = "YYGWBGWRG";
	char links[9] = "RGGOOYYBW";
	char voor[9] = "BORYGWBOG";
	char onder[9] = "YGBRYGYYO";
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
	//test = find_edgepiece('W','G', matrix);
	//printf("%d\n", test);
//	BCW(matrix);

//	draai_voor_naar_links(matrix);
	print_matrix(matrix);

	maak_wit_kruis(matrix);
	print_matrix(matrix);
	solve_corner_pieces(matrix);

	solve_middle_layer(matrix);
	maak_geel_kruis(matrix); // ok

	maak_geel_vlak(matrix);
	print_matrix(matrix);

	yellow_corner_correct(matrix);
	print_matrix(matrix);
    
	get_endstate(matrix);
	print_matrix(matrix);
	//test = find_edgepiece('W', 'G', matrix);
	//printf("%d\n", test);
	return 0;
}