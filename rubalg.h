#pragma once

/*Zoekt een 'edgepiece' met kleur a en b, geeft de positie van kleur a terug (in decimaal getal)
Daarbij is tiental het vlak, en eenheid de positie op dat vlak*/
int  find_edgepiece(char, char, char[6][9]);
int find_corner_piece(char a, char b, char c, char[6][9]);

void wit_blauw_rood_inschuiven(int cp1, char[6][9]);
void wit_blauw_oranje_inschuiven(int cp2, char[6][9]);
void wit_groen_rood_inschuiven(int cp2, char[6][9]);
void wit_groen_oranje_inschuiven(int cp2, char[6][9]);

void solve_middle_layer(char[6][9]);
void recht_midden_plaatsen(char[6][9]);
void links_midden_plaatsen(char[6][9]);
void midden_indraaien(char[6][9]);

void maak_geel_kruis(char[6][9]);
int maak_geel_tussenstap(char[6][9]);
void omsingelde_hoek(char[6][9]);
void horizontale_lijn(char[6][9]);

void maak_geel_vlak(char[6][9]);
void geel_vlak_beweging(char[6][9]);

char alle_hoeken_juist(char[6][9]);
void verwissel_edgepieces_vooraan(char[6][9]);
char achterste_hoeken_juist(char[6][9]);
void yellow_corner_correct(char[6][9]);

void get_endstate(char[6][9]);
void yellow_edges_clockwise(char[6][9]);
void yellow_edges_counter_clockwise(char[6][9]);

void maak_wit_kruis(char[6][9]);
void solve_corner_pieces(char[6][9]);