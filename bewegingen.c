#include "bewegingen.h"

void draai_wijzerzin(int vlak, char matrix[6][9]) { 
	char temp[9];
	for (int i = 0; i < 9; i++) {
		temp[i] = matrix[vlak][i];
	}
	matrix[vlak][0] = temp[6];
	matrix[vlak][1] = temp[3];
	matrix[vlak][2] = temp[0];
	matrix[vlak][3] = temp[7];
	matrix[vlak][4] = temp[4];
	matrix[vlak][5] = temp[1];
	matrix[vlak][6] = temp[8];
	matrix[vlak][7] = temp[5];
	matrix[vlak][8] = temp[2];
}

void draai_tegenwijzerzin(int vlak, char matrix[6][9]) {
	char temp[9];
	for (int i = 0; i < 9; i++) {
		temp[i] = matrix[vlak][i];
	}
	matrix[vlak][0] = temp[2];
	matrix[vlak][1] = temp[5];
	matrix[vlak][2] = temp[8];
	matrix[vlak][3] = temp[1];
	matrix[vlak][4] = temp[4];
	matrix[vlak][5] = temp[7];
	matrix[vlak][6] = temp[0];
	matrix[vlak][7] = temp[3];
	matrix[vlak][8] = temp[6];
}

void draai_onder(char matrix[6][9]) {
	char temp[9];
	/**/
}

void draai_boven(char matrix[6][9]) {
	char temp[9];
	/*DC2 openen
	ServoB 90° */
}

void draai_rechts(char matrix[6][9]) {
	char temp[9];
	/*DC1 open
	ServoA 90° wijzerzin draaien en servoC 90° tegenwijzerzin
	DC1 sluiten
	DC2 openen
	ServoA en servoC terugzetten
	DC2 sluiten*/

	/*matrix aanpassen*/
	for (int i = 0; i < 9; i++) {
		temp[i] = matrix[0][i];
		matrix[0][i] = matrix[3][i];
		matrix[3][i] = matrix[5][i];
		matrix[5][i] = matrix[1][i];
		matrix[1][i] = temp[i];
	}
	draai_wijzerzin(4, matrix);
	draai_tegenwijzerzin(2, matrix);
}

void draai_links(char matrix[6][9]) {
	char temp[9];
	/*DC1 openen
	ServoA 90° tegenwijzerzin en servoC 90° wijzerzin draaien
	DC1 sluiten
	DC2 openen
	ServoA en C terugzetten
	DC2 sluiten*/

	/*matrix aanpassen*/
	for (int i = 0; i < 9; i++) {
		temp[i] = matrix[1][i];
		matrix[1][i] = matrix[5][i];
		matrix[5][i] = matrix[3][i];
		matrix[3][i] = matrix[0][i];
		matrix[0][i] = temp[i];
	}
	draai_wijzerzin(2, matrix);
	draai_tegenwijzerzin(4, matrix);
}

void RCW(char matrix[6][9]) {
	char temp[3];
	/*controleren of beide DC-motoren gesloten zijn
	ServoB 90° draaien in wijzerzin
	DC1 openen
	ServoB terugzetten
	DC1 sluiten*/
	
	/*matrix aanpassen*/
	temp[0] = matrix[5][6];
	temp[1] = matrix[5][3];
	temp[2] = matrix[5][0];
	matrix[5][0] = matrix[2][8];
	matrix[5][3] = matrix[2][5];
	matrix[5][6] = matrix[2][2];
	for (int i = 0; i < 3; i++) {
		matrix[2][2 + 3 * i] = matrix[0][2 + 3 * i];
		matrix[0][2 + 3 * i] = matrix[4][2 + 3 * i];
		matrix[4][2 + 3 * i] = temp[i];
	}
	draai_wijzerzin(1, matrix);
}

void RCCW(char matrix[6][9]) {
	char temp[3];
	/*controleren of beide DC-motoren gesloten zijn
	ServoB 90° draaien in tegenwijzerzin
	DC1 openen
	ServoB terugzetten
	DC1 sluiten*/

	/*matrix aanpassen*/
	temp[0] = matrix[5][6];
	temp[1] = matrix[5][3];
	temp[2] = matrix[5][0];
	matrix[5][6] = matrix[4][2];
	matrix[5][3] = matrix[4][5];
	matrix[5][0] = matrix[4][8];
	for (int i = 0; i < 3; i++) {
		matrix[4][2 + 3 * i] = matrix[0][2 + 3 * i];
		matrix[0][2 + 3 * i] = matrix[2][2 + 3 * i];
		matrix[2][2 + 3 * i] = temp[i];
	}
	draai_tegenwijzerzin(1, matrix);
}

void LCW(char matrix[6][9]) {
	char temp[3];
	/*Controleren of beide DC-motoren gesloten zijn
	ServoD 90° draaien
	DC1 openen
	Servo terugzetten
	DC1 sluiten*/

	/*matrix aanpassen*/
	temp[0] = matrix[5][8];
	temp[1] = matrix[5][5];
	temp[2] = matrix[5][2];
	matrix[5][8] = matrix[4][0];
	matrix[5][5] = matrix[4][3];
	matrix[5][2] = matrix[4][6];
	for (int i = 0; i < 3; i++) {
		matrix[4][3 * i] = matrix[0][3 * i];
		matrix[0][3 * i] = matrix[2][3 * i];
		matrix[2][3 * i] = temp[i];
	}
	draai_wijzerzin(3, matrix);
}

void LCCW(char matrix[6][9]) {
	char temp[3];
	/*Controleren of beide DC-motoren gesloten zijn
	ServoD 90° draaien in tegenwijzerzin
	DC1 openen
	Servo terugzetten
	DC1 sluiten*/

	/*matrix aanpassen*/
	temp[0] = matrix[5][8];
	temp[1] = matrix[5][5];
	temp[2] = matrix[5][2];
	matrix[5][8] = matrix[2][0];
	matrix[5][5] = matrix[2][3];
	matrix[5][2] = matrix[2][6];
	for (int i = 0; i < 3; i++) {
		matrix[2][3 * i] = matrix[0][3 * i];
		matrix[0][3 * i] = matrix[4][3 * i];
		matrix[4][3 * i] = temp[i];
	}
	draai_tegenwijzerzin(3, matrix);
}

void FCW(char matrix[6][9]) {
	char temp[3];
	/*Controleren of beide DC-motoren gesloten zijn
	ServoC 90° draaien in wijzerzin
	DC1 openen
	ServoC terugzetten
	D1 sluiten
	*/

	/*matrix aanpassen*/
	for (int i = 6; i < 9; i++) {
		temp[i - 6] = matrix[3][i];
		matrix[3][i] = matrix[5][i];
		matrix[5][i] = matrix[1][i];
		matrix[1][i] = matrix[0][i];
		matrix[0][i] = temp[i - 6];
	}
	draai_wijzerzin(4, matrix);
}

void FCCW(char matrix[6][9]) {
	char temp[3];
	/*Controleren of beide DC-motoren gesloten zijn
	ServoC 90° draaien in tegenwijzerzin
	DC1 openen
	ServoC terugzetten
	D1 sluiten
	*/

	/*matrix aanpassen*/
	for (int i = 6; i < 9; i++) {
		temp[i - 6] = matrix[0][i];
		matrix[0][i] = matrix[1][i];
		matrix[1][i] = matrix[5][i];
		matrix[5][i] = matrix[3][i];
		matrix[3][i] = temp[i - 6];
	}
	draai_tegenwijzerzin(4, matrix);
}

void BCW(char matrix[6][9]) {
	char temp[3];
	/*Controleren of DC-motoren gesloten zijn
	ServoA 90° in wijzerzin draaien
	DC2 openen
	ServoA terugzetten
	DC2 terug sluiten
	*/

	/*matrix aanpassen*/
	for (int i = 0; i < 3; i++) {
		temp[i] = matrix[0][i];
		matrix[0][i] = matrix[1][i];
		matrix[1][i] = matrix[5][i];
		matrix[5][i] = matrix[3][i];
		matrix[3][i] = temp[i];
	}
	draai_wijzerzin(2, matrix);
}

void BCCW(char matrix[6][9]) {
	char temp[3];
	/*Controleren of de DC-motoren gesloten zijn
	ServoA 90° in tegenwijzerzin draaien
	DC2 openen
	ServoA terugzetten
	DC2 sluiten*/

	/*matrix aanpassen*/
	for (int i = 0; i < 3; i++) {
		temp[i] = matrix[3][i];
		matrix[3][i] = matrix[5][i];
		matrix[5][i] = matrix[1][i];
		matrix[1][i] = matrix[0][i];
		matrix[0][i] = temp[i];
	}
	draai_tegenwijzerzin(2, matrix);
}

void UCW(char matrix[6][9]) {
	draai_onder(matrix);
	FCW(matrix);
	draai_boven(matrix);
}

void UCCW(char matrix[6][9]) {
	draai_onder(matrix);
	FCCW(matrix);
	draai_boven(matrix);
}

void DCW(char matrix[6][9]) {
	draai_boven(matrix);
	FCW(matrix);
	draai_onder(matrix);
}

void DCCW(char matrix[6][9]) {
	draai_boven(matrix);
	FCCW(matrix);
	draai_onder(matrix);
}

