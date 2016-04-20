#pragma once

/*Zoekt een 'edgepiece' met kleur a en b, geeft de positie van kleur a terug (in decimaal getal)
Daarbij is tiental het vlak, en eenheid de positie op dat vlak*/
int  find_edgepiece(char, char, char[6][9]);
int find_corner_piece(char a, char b, char c, char[6][9]);

void wit_blauw_rood_inschuiven(int cp1, char[6][9]);
void wit_blauw_oranje_inschuiven(int cp2, char[6][9]);
void wit_groen_rood_inschuiven(int cp2, char[6][9]);
void wit_groen_oranje_inschuiven(int cp2, char[6][9]);

void maak_wit_kruis(char[6][9]);
void solve_corner_pieces(char[6][9]);