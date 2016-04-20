/*
we hebben een 6x9 matrix:
mat[i][j]:
i=0 --> boven
i=1 --> rechts
i=2 --> achter
i=3 --> links
i=4 --> voor
i=5 --> onder
om te weten welke kleur vlak het is, kijk mat[i][4] (middelste)

niet met delingen/module werken: beter met bitvlaggen, delingen duren 500 cycli in microcontroller, duurt op den duur wel lang

*/
#include "rubalg.h"
#include "bewegingen.h"

//#include <algorithm> // for std::find
//#include <iterator> // for std::begin, std::end

int find_edgepiece(char a, char b, char matrix[6][9]){ // geeft vlak en positie terug in een int[2], werkt!
	
	int result ; 
	//edge enkel op pos met oneven indexen zoeken
		for (int i = 0; i < 6; i++) {
			for (int j = 1; j < 8; j += 2) {
				if (matrix[i][j] == a) { // blokje is kleur a
					if (i == 0) {
						if (j == 1) {
							if (matrix[2][7] == b) {
								result = 10*i+j;
								return result;
							}
						}
						if (j == 3) {
							if (matrix[3][5] == b) {
								result = 10 * i + j;
								return result;
							}
						}
						if (j == 5) {
							if (matrix[1][3] == b) {
								result = 10 * i + j;
								return result;
							}
						}
						if (j == 7) {
							if (matrix[4][1] == b) {
								result = 10 * i + j;
								return result;
							}
						}
					}
					if (i == 1) {
						if (j == 1) {
							if (matrix[2][5] == b) {
								result = 10 * i + j;
								return result;
							}
						}
						if (j == 3) {
							if (matrix[0][5] == b) {
								result = 10 * i + j;
								return result;
							}
						}
						if (j == 5) {
							if (matrix[5][3] == b) {
								result = 10 * i + j;
								return result;
							}
						}
						if (j == 7) {
							if (matrix[4][5] == b) {
								result = 10 * i + j;
								return result;
							}
						}
					}
					if (i == 2) {
						if (j == 1) {
							if (matrix[5][1] == b) {
								result = 10 * i + j;
								return result;
							}
						}
						if (j == 3) {
							if (matrix[3][1] == b) {
								result = 10 * i + j;
								return result;
							}
						}
						if (j == 5) {
							if (matrix[1][1] == b) {
								result = 10 * i + j;
								return result;
							}
						}
						if (j == 7) {
							if (matrix[0][1] == b) {
								result = 10 * i + j;
								return result;
							}
						}
					}

					if(i==3){
						if (j == 1) {
							if (matrix[2][3] == b) {
								result = 10 * i + j;
								return result;
							}
						}
						if (j == 3) {
							if (matrix[5][5] == b) {
								result = 10 * i + j;
								return result;
							}
						}
						if (j == 5) {
							if (matrix[0][3] == b) {
								result = 10 * i + j;
								return result;
							}
						}
						if (j == 7) {
							if (matrix[4][3] == b) {
								result = 10 * i + j;
								return result;
							}
						}
					}
					if(i==4){
						if (j == 1) {
							if (matrix[0][7] == b) {
								result = 10 * i + j;
								return result;
							}
						}
						if (j == 3) {
							if (matrix[3][7] == b) {
								result = 10 * i + j;
								return result;
							}
						}
						if (j == 5) {
							if (matrix[1][7] == b) {
								result = 10 * i + j;
								return result;
							}
						}
						if (j == 7) {
							if (matrix[5][7] == b) {
								result = 10 * i + j;
								return result;
							}
						}
					}
					if(i==5){
						if (j == 1) {
							if (matrix[2][1] == b) {
								result = 10 * i + j;
								return result;
							}
						}
						if (j == 3) {
							if (matrix[1][5] == b) {
								result = 10 * i + j;
								return result;
							}
						}
						if (j == 5) {
							if (matrix[3][3] == b) {
								result = 10 * i + j;
								return result;
							}
						}
						if (j == 7) {
							if (matrix[4][7] == b) {
								result = 10 * i + j;
								return result;
							}
						}
					}
					}

				}
			}
		//	dan kijken in aanliggend vlak voor volgende kleur
		//		is correct-> return pos van a(dus vlak en pos)
			return result = 0;	}

void bringdownedge(int a, int b, char matrix[6][9]) { /* brengte edgepiece naar beneden, kijkt niet naar welke kleur echt in het geelvlak zit, en welke aan aanliggend*/
	// int a = vlak, int b = positie

	if (a == 0) { // wit
		if (b == 1) { BCW(matrix); BCW(matrix); } // let op, dubbel draaien moet nog geschreven worden
		if (b == 3) { LCW(matrix); LCW(matrix); }
		if (b == 5) { RCW(matrix); RCW(matrix); }
		if (b == 7) { FCW(matrix); FCW(matrix); }
	}
	if (a == 4) {//groen, dit aanpassen naar 0 tem 5 ( groen is dus voor)
		if (b == 3) { LCW(matrix); }
		if (b == 5) { RCCW(matrix); }
		if (b == 1) { FCW(matrix); FCW(matrix); }
		// if(pos==7) {niets
	}
	if (a == 3) { //oranje
		if (b == 1) { BCW(matrix); }
		// if(pos==3) niets, zit goed
		if (b == 5) { LCW(matrix); LCW(matrix); }
		if (b == 7) { LCW(matrix); }
	}
	if (a == 1) { // rood
		if (b == 3) { RCW(matrix); RCW(matrix); }
		if (b == 1) { RCW(matrix); }
		if (b == 7) { RCCW(matrix); }
		// if(pos==7) zit goed
	}
	if (a == 2) { // blauw
		//if(pos==1) zit goed
		if (b == 3) { LCCW(matrix); }
		if (b == 5) { RCW(matrix); }
		if (b = 7) { BCW(matrix); BCW(matrix); }
		//  if(vlak==5) zit goed
		}

	}

/* alle handelingen zijn nu geimplementeerd als functies
Nu beginnen we aan begin algoritme:
Dit is een wit kruis krijgen in vlak wit
belangrijk: eerst hoekpunt met kleur aan blauw aan andere kant(zie:edge pieces), dan oranje,groen,rood */

void maak_wit_kruis(char matrix[6][9]) { // WERKT!! stage 2 is in orde
	int wb; int wo; int wg; int wr;
	/*	zorg ervoor dat vlak wit vanboven staat!
		zorg dat wit-blauw edge piece in down-vlak ligt:
		zoek eerst wit-blauw edge piece met findedgepiece(w,b) */

	wb = find_edgepiece('W', 'B', matrix); // 57 
	//	 wb/10 is vlak, wb%10 is positie
	if (wb / 10 != 0 || wb % 10 != 1) {
		bringdownedge(wb / 10, wb % 10, matrix);
		wb = find_edgepiece('W', 'B', matrix);
		if (wb / 10 == 5) { // het witte van wb zit in ondervlak
			print_matrix(matrix);
			if (wb % 10 == 3) { DCW(matrix); print_matrix(matrix);
			} // juist draaien zodat gealligneerd is met blauwcenter
			if (wb % 10 == 5) { DCCW(matrix); }
			if (wb % 10 == 7) { DCW(matrix); DCW(matrix); }
			BCW(matrix); BCW(matrix); // naar boven draaien
			print_matrix(matrix);
			draai_voor_naar_links(matrix);
		}
		else {
			if (find_edgepiece('W', 'B', matrix) / 10 == 1) { // witte ligt in rechtervlak, blauw in onder
				DCW(matrix);
				BCW(matrix); BCW(matrix);
			}
			if (find_edgepiece('W', 'B', matrix) / 10 == 3) {
				DCCW(matrix);
				BCW(matrix); BCW(matrix);
			}
			if (find_edgepiece('W', 'B', matrix) / 10 == 4) {
				DCW(matrix); DCW(matrix);
				BCW(matrix); BCW(matrix);
			}
			if (find_edgepiece('W', 'B', matrix) / 10 == 2) {
				BCW(matrix); BCW(matrix);
			}
			draai_voor_naar_links(matrix); /* zet blauw rechts*/
			RCCW(matrix);
			UCW(matrix);
			FCCW(matrix);
			UCCW(matrix);
		} // let op: vlak blauw staat nu rechts!
	}
	/*	nu staat witblauw correct, volgende is oranje */
	print_matrix(matrix);
	wo = find_edgepiece('W', 'O', matrix);
	//	 wo/10 is vlak, wo%10 is positie
	//controleer dat blauw niet kapot gemaakt wordt

	//bringdown!
	if (wo / 10 == 1) {
		if (wo % 10 == 1) { BCCW(matrix); }// wit zit nu beneden
		if (wo % 10 == 7) { FCW(matrix); }// wit zit beneden
	}
	if (wo / 10 == 0) {
		if (wo % 10 == 3) { LCW(matrix); LCW(matrix); }
		if (wo % 10 == 7) { FCW(matrix); FCW(matrix); }
	}
	if (wo / 10 == 2) {
		// bij 1 zit hij goed
		if (wo % 10 == 3) { LCCW(matrix); }
		if (wo % 10 == 5) { BCCW(matrix); }
		if (wo % 10 == 7) { BCCW(matrix); BCCW(matrix); }
	}
	if (wo / 10 == 3) { bringdownedge(wo / 10, wo % 10, matrix); 
	}
	if (wo / 10 == 4) {
		if (wo % 10 == 1) { FCW(matrix); FCW(matrix); }
		if (wo % 10 == 3) { RCW(matrix); }
		if (wo % 10 == 5) { FCW(matrix); }
	}
	wo = find_edgepiece('W', 'O', matrix); // positie van wit-oranje in ondervlak
	if (wo / 10 != 0 || wo % 10 != 1) { // anders ligt oranje al goed
		if (wo / 10 == 5) { // het witte van wo zit in ondervlak
			print_matrix(matrix);
			if (wo % 10 == 5) { DCCW(matrix); } // juist draaien zodat gealligneerd is met blauwcenter
			if (wo % 10 == 7) { DCW(matrix); DCW(matrix); }
			if (wo % 10 == 3) { DCW(matrix); }
			print_matrix(matrix);
			BCW(matrix); BCW(matrix); // naar boven draaien
			draai_voor_naar_links(matrix); // zet rood naar rechts
		}
		else { // witte zit niet juist: Ri-U-Fi-Ui doen om goed te krijgen
			if (find_edgepiece('W', 'O', matrix) / 10 == 1) { // witte ligt in rechtervlak, oranje in onder
				DCW(matrix);
				BCW(matrix); BCW(matrix);
			}
			if (find_edgepiece('W', 'O', matrix) / 10 == 3) {
				DCCW(matrix);
				BCW(matrix); BCW(matrix);
			}
			if (find_edgepiece('W', 'O', matrix) / 10 == 4) {
				DCW(matrix); DCW(matrix);
				BCW(matrix); BCW(matrix);
			}
			if (find_edgepiece('W', 'O', matrix) / 10 == 2) {
				BCW(matrix); BCW(matrix);
			}
			draai_voor_naar_links(matrix); /* zet oranje rechts*/
			RCCW(matrix);
			UCW(matrix);
			FCCW(matrix);
			UCCW(matrix);
		} // let op: vlak oranje staat nu rechts

	}

	// blauw en oranje zitten goed: nu groen
	print_matrix(matrix);
	wg = find_edgepiece('W', 'G', matrix);
	if (wg / 10 == 1) {
		if (wg % 10 == 1) { BCCW(matrix); }// wit zit nu beneden
		if (wg % 10 == 7) { FCW(matrix); }// wit zit beneden
	}
	if (wg / 10 == 0) {
		if (wg % 10 == 3) { LCW(matrix); LCW(matrix); }
		if (wg % 10 == 7) { FCW(matrix); FCW(matrix); }
	}
	if (wg / 10 == 2) {
		// bij 1 zit hij goed
		if (wg % 10 == 3) { LCCW(matrix); }
		if (wg % 10 == 5) { BCCW(matrix); }
		if (wg % 10 == 7) { BCCW(matrix); BCCW(matrix); }
	}
	if (wg / 10 == 3) {
		bringdownedge(wg / 10, wg % 10, matrix);
	}
	if (wg / 10 == 4) {
		if (wg % 10 == 1) { FCW(matrix); FCW(matrix); }
		if (wg % 10 == 3) { RCW(matrix); }
		if (wg % 10 == 5) { FCW(matrix); }
	}
	//	bringdownedge(wg / 10, wg % 10, matrix); // let op: hierdoor kan blauw kapot gaan, zie hierboven
		wg = find_edgepiece('W', 'G', matrix);
		if (wg / 10 == 5) { // het witte van wg zit in ondervlak
			if (wg % 10 == 3) { DCW(matrix); } // juist draaien zodat gealligneerd is met blauwcenter
			if (wg % 10 == 5) { DCCW(matrix); }
			if (wg % 10 == 7) { DCW(matrix); DCW(matrix); }
			BCW(matrix); BCW(matrix); // naar boven draaien
			draai_voor_naar_links(matrix); // zet blauw rechts: uit handigheid
		}
		else { // witte zit niet juist: Ri-U-Fi-Ui doen om goed te krijgen
			if (find_edgepiece('W', 'G', matrix) / 10 == 1) { // witte ligt in rechtervlak, groene in onder
				DCW(matrix);
				BCW(matrix); BCW(matrix);
			}
			if (find_edgepiece('W', 'G', matrix) / 10 == 3) {
				DCCW(matrix);
				BCW(matrix); BCW(matrix);
			}
			if (find_edgepiece('W', 'G', matrix) / 10 == 4) {
				DCW(matrix); DCW(matrix);
				BCW(matrix); BCW(matrix);
			}
			if (find_edgepiece('W', 'G', matrix) / 10 == 2) {
				BCW(matrix); BCW(matrix);
			}
			draai_voor_naar_links(matrix); /* zet groen rechts*/
			RCCW(matrix);
			UCW(matrix);
			FCCW(matrix);
			UCCW(matrix);
		} // let op: vlak groen staat nu rechts
	

	// blauw,oranje en groen zitten goed: nu rood !!LET OP: vlak groen staat rechts
//	print_matrix(matrix);
	
	wr = find_edgepiece('W', 'R', matrix);
	//	 wb/10 is vlak, wb%10 is positie
	if (wr / 10 == 1) {
		if (wr % 10 == 1) { BCCW(matrix); }// wit zit nu beneden
		if (wr % 10 == 7) { FCW(matrix); }// wit zit beneden
	}
	if (wr / 10 == 0) {
		if (wr % 10 == 3) { LCW(matrix); LCW(matrix); }
		if (wr % 10 == 7) { FCW(matrix); FCW(matrix); }
	}
	if (wr / 10 == 2) {
		// bij 1 zit hij goed
		if (wr % 10 == 3) { LCCW(matrix); }
		if (wr % 10 == 5) { BCCW(matrix); }
		if (wr % 10 == 7) { BCCW(matrix); BCCW(matrix); }
	}
	if (wr / 10 == 3) {
		bringdownedge(wr / 10, wr% 10, matrix);
	}
	if (wr / 10 == 4) {
		if (wr % 10 == 1) { FCW(matrix); FCW(matrix); }
		if (wr % 10 == 3) { RCW(matrix); }
		if (wr % 10 == 5) { FCW(matrix); }
	}
	if (wr / 10 != 0 || wr % 10 != 1) { // 
		bringdownedge(wr / 10, wr % 10, matrix);
		wr = find_edgepiece('W', 'R', matrix);
		if (wr / 10 == 5) { // het witte van wg zit in ondervlak
			if (wr % 10 == 3) { DCW(matrix); } // juist draaien zodat gealligneerd is met blauwcenter
			if (wr % 10 == 5) { DCCW(matrix); }
			if (wr % 10 == 7) { DCW(matrix); DCW(matrix); }
			BCW(matrix); BCW(matrix); // naar boven draaien
			draai_voor_naar_links(matrix); // rood rechts zetten
		}
		else { // witte zit niet juist: Ri-U-Fi-Ui doen om goed te krijgen
			if (find_edgepiece('W', 'G', matrix) / 10 == 1) { // witte ligt in rechtervlak, rode in onder
				DCW(matrix);
				BCW(matrix); BCW(matrix);
			}
			if (find_edgepiece('W', 'G', matrix) / 10 == 3) {
				DCCW(matrix);
				BCW(matrix); BCW(matrix);
			}
			if (find_edgepiece('W', 'G', matrix) / 10 == 4) {
				DCW(matrix); DCW(matrix);
				BCW(matrix); BCW(matrix);
			}
			if (find_edgepiece('W', 'G', matrix) / 10 == 2) {
				BCW(matrix); BCW(matrix);
			}
			draai_voor_naar_links(matrix); /* zet rood rechts*/
			RCCW(matrix);
			UCW(matrix);
			FCCW(matrix);
			UCCW(matrix);
		} // let op: vlak rood staat nu rechts: zoals start 

	}
}




// STAGE 3: cornerpieces oplossen zodat volledig wit vlak is opgelost
// de vier cornerpieces juist plaatsen 
void solve_corner_pieces(char matrix[6][9]) {
	int cp1; int cp2; int cp3; int cp4;

	cp1 = find_corner_piece('W', 'B', 'R', matrix); 
	if (cp1 / 10 != 0 && cp1 != 10 && cp1 != 16 && cp1 != 26 && cp1 != 28 && cp1 != 32 && cp1 != 38 && cp1 != 40 && cp1 != 42) { // indien cornerpiece niet
		wit_blauw_rood_inschuiven(cp1, matrix);
	}
	else { // blok zit vanboven, eruit draaien, terug positie zoeken, juist draaien en invoegen
		if (cp1 == 10 || cp1 == 28 || cp1 == 2) { RCW(matrix); DCW(matrix); RCCW(matrix); } // 10 en 28 zelfde blokje
		if (cp1 == 16 || cp1 == 42 || cp1 == 8) { RCCW(matrix); DCW(matrix); RCW(matrix); }
		if (cp1 == 26 || cp1 == 32 || cp1 == 0) { LCCW(matrix); DCW(matrix); LCW(matrix); }
		if (cp1 == 38 || cp1 == 40 || cp1 == 6) { LCW(matrix); DCW(matrix); LCCW(matrix); }
		cp1 = find_corner_piece('W', 'B', 'R', matrix); // terug positie zoeken
		wit_blauw_rood_inschuiven(cp1, matrix);
	}
	print_matrix(matrix);
	cp2 = find_corner_piece('W', 'B', 'O', matrix);
	if (cp2 / 10 != 0 && cp2 != 10 && cp2 != 16 && cp2 != 26 && cp2 != 28 && cp2 != 32 && cp2 != 38 && cp2 != 40 && cp2 != 42) { // indien cornerpiece niet
		wit_blauw_oranje_inschuiven(cp2, matrix);
	}
	else { // blok zit vanboven, eruit draaien, terug positie zoeken, juist draaien en invoegen
		if (cp2 == 10 || cp2 == 28 || cp2 == 2) { RCW(matrix); DCW(matrix); RCCW(matrix); } // 10 en 28 zelfde blokje
		if (cp2 == 16 || cp2 == 42 || cp2 == 8) { RCCW(matrix); DCW(matrix); RCW(matrix); }
		if (cp2 == 26 || cp2 == 32 || cp2 == 0) { LCCW(matrix); DCW(matrix); LCW(matrix); }
		if (cp2 == 38 || cp2 == 40 || cp2 == 6) { LCW(matrix); DCW(matrix); LCCW(matrix); }
		print_matrix(matrix);
		cp2 = find_corner_piece('W', 'B', 'O', matrix); // terug positie zoeken
		wit_blauw_oranje_inschuiven(cp2, matrix);
	}
	print_matrix(matrix);
	cp2 = find_corner_piece('W', 'G', 'R', matrix); // noem cp2 ipv cp3, moet ik minder aanpassen
	if (cp2 / 10 != 0 && cp2 != 10 && cp2 != 16 && cp2 != 26 && cp2 != 28 && cp2 != 32 && cp2 != 38 && cp2 != 40 && cp2 != 42) { // indien cornerpiece niet
		wit_groen_rood_inschuiven(cp2, matrix);
	}
	else { // blok zit vanboven, eruit draaien, terug positie zoeken, juist draaien en invoegen
		if (cp2 == 10 || cp2 == 28 || cp2 == 2) { RCW(matrix); DCW(matrix); RCCW(matrix); } // 10 en 28 zelfde blokje
		if (cp2 == 16 || cp2 == 42 || cp2 == 8) { RCCW(matrix); DCW(matrix); RCW(matrix); }
		if (cp2 == 26 || cp2 == 32 || cp2 == 0) { LCCW(matrix); DCW(matrix); LCW(matrix); }
		if (cp2 == 38 || cp2 == 40 || cp2 == 6) { LCW(matrix); DCW(matrix); LCCW(matrix); }
		cp2 = find_corner_piece('W', 'G', 'R', matrix); // terug positie zoeken
		wit_groen_rood_inschuiven(cp2, matrix);
	}
	print_matrix(matrix);
	cp2 = find_corner_piece('W', 'G', 'O', matrix);
	if (cp2 / 10 != 0 && cp2 != 10 && cp2 != 16 && cp2 != 26 && cp2 != 28 && cp2 != 32 && cp2 != 38 && cp2 != 40 && cp2 != 42) { // indien cornerpiece niet
		wit_groen_oranje_inschuiven(cp2, matrix);
	}
	else { // blok zit vanboven, eruit draaien, terug positie zoeken, juist draaien en invoegen
		if (cp2 == 10 || cp2 == 28 || cp2 == 2) { RCW(matrix); DCW(matrix); RCCW(matrix); } // 10 en 28 zelfde blokje
		if (cp2 == 16 || cp2 == 42 || cp2 == 8) { RCCW(matrix); DCW(matrix); RCW(matrix); }
		if (cp2 == 26 || cp2 == 32 || cp2 == 0) { LCCW(matrix); DCW(matrix); LCW(matrix); }
		if (cp2 == 38 || cp2 == 40 || cp2 == 6) { LCW(matrix); DCW(matrix); LCCW(matrix); }
		cp2 = find_corner_piece('W', 'G', 'O', matrix); // terug positie zoeken
		wit_groen_oranje_inschuiven(cp2, matrix);
	}
}

void wit_blauw_rood_inschuiven(int cp1,char matrix[6][9]) { // WERKT!!!!
	if (cp1 == 12 || cp1 == 22 || cp1 == 50) { // rechtsboven vanonder
		while (cp1 != 2 || matrix[0][2] != 'W') { // moet 1x 2x of 3x gebeuren tot goed zit
			BCCW(matrix); // ipv rcw!!
			DCCW(matrix);
			BCW(matrix); // ipv rccw
			DCW(matrix);
			cp1 = find_corner_piece('W', 'B', 'R', matrix);
		}
	}
	if (cp1 == 18 || cp1 == 48 || cp1 == 56) { // rechtsonder vanonder
		DCW(matrix);
		print_matrix(matrix);
		while (cp1 != 2 || matrix[0][2] != 'W') {  // moet 1x 2x of 3x gebeuren tot goed zit
			BCCW(matrix); // ipv rcw!!
			DCCW(matrix);
			BCW(matrix); // ipv rccw
			DCW(matrix);
			print_matrix(matrix);
			cp1 = find_corner_piece('W', 'B', 'R', matrix);
		}
	}
	if (cp1 == 36 || cp1 == 46 || cp1 == 58) { // linksonder vanonder
		DCW(matrix); DCW(matrix);
		while (cp1 != 2 || matrix[0][2] != 'W') {  // moet 1x 2x of 3x gebeuren tot goed zit
			BCCW(matrix); // ipv rcw!!
			DCCW(matrix);
			BCW(matrix); // ipv rccw
			DCW(matrix);
			cp1 = find_corner_piece('W', 'B', 'R', matrix);
		}
	}
	if (cp1 == 20 || cp1 == 30 || cp1 == 52) { // linksboven vanonder
		DCCW(matrix);
		while (cp1 != 2 || matrix[0][2] != 'W') {  // moet 1x 2x of 3x gebeuren tot goed zit
			BCCW(matrix); // ipv rcw!!
			DCCW(matrix);
			BCW(matrix); // ipv rccw
			DCW(matrix);
			cp1 = find_corner_piece('W', 'B', 'R', matrix);
		}
	}
}
void wit_blauw_oranje_inschuiven(int cp2, char matrix[6][9]) {
	if (cp2 == 12 || cp2 == 22 || cp2 == 50) { // rechtsboven vanonder
		DCW(matrix);
		while ( cp2 != 0  || matrix[0][0] != 'W') { // moet 1x 2x of 3x gebeuren tot goed zit
			LCCW(matrix); // ipv rcw!!
			DCCW(matrix);
			LCW(matrix); // ipv rccw
			DCW(matrix);
			cp2 = find_corner_piece('W', 'B', 'O', matrix);
		}
	}
	if (cp2 == 18 || cp2 == 48 || cp2 == 56) { // rechtsonder vanonder
		DCW(matrix); DCW(matrix);
		while (cp2 != 0 || matrix[0][0] != 'W') {
			 // moet 1x 2x of 3x gebeuren tot goed zit
			LCCW(matrix); // ipv rcw!!
			DCCW(matrix);
			LCW(matrix); // ipv rccw
			DCW(matrix);
			cp2 = find_corner_piece('W', 'B', 'O', matrix);
		}
	}
	if (cp2 == 36 || cp2 == 46 || cp2 == 58) { // linksonder vanonder
		DCCW(matrix);
		while (cp2 != 0 || matrix[0][0] != 'W') { // moet 1x 2x of 3x gebeuren tot goed zit
			LCCW(matrix); // ipv rcw!!
			DCCW(matrix);
			LCW(matrix); // ipv rccw
			DCW(matrix);
			cp2 = find_corner_piece('W', 'B', 'O', matrix);
		}
	}
	if (cp2 == 20 || cp2 == 30 || cp2 == 52) { // rechtsboven vanonder
		while (cp2 != 0 || matrix[0][0] != 'W') { // moet 1x 2x of 3x gebeuren tot goed zit
			LCCW(matrix); // ipv rcw!!
			DCCW(matrix);
			LCW(matrix); // ipv rccw
			DCW(matrix);
			cp2 = find_corner_piece('W', 'B', 'O', matrix);
		}
	}
	print_matrix(matrix);
}
void wit_groen_oranje_inschuiven(int cp2, char matrix[6][9]) {
	if (cp2 == 12 || cp2 == 22 || cp2 == 50) { // rechtsboven vanonder
		DCW(matrix); DCW(matrix);
		while (cp2 != 6 || matrix[0][6] != 'W') { // moet 1x 2x of 3x gebeuren tot goed zit
			FCCW(matrix); // ipv rcw!!
			DCCW(matrix);
			FCW(matrix); // ipv rccw
			DCW(matrix);
			print_matrix(matrix);
			cp2 = find_corner_piece('W', 'G', 'O', matrix);
		}
	}
	if (cp2 == 18 || cp2 == 48 || cp2 == 56) { // rechtsonder vanonder
		DCCW(matrix);
		while (cp2 != 6 || matrix[0][6] != 'W') { // moet 1x 2x of 3x gebeuren tot goed zit
			FCCW(matrix); // ipv rcw!!
			DCCW(matrix);
			FCW(matrix); // ipv rccw
			DCW(matrix);
			cp2 = find_corner_piece('W', 'G', 'O', matrix);
		}
	}
	if (cp2 == 36 || cp2 == 46 || cp2 == 58) { // linksonder vanonder
		while (cp2 != 6 || matrix[0][6] != 'W') { // moet 1x 2x of 3x gebeuren tot goed zit
			FCCW(matrix); // ipv rcw!!
			DCCW(matrix);
			FCW(matrix); // ipv rccw
			DCW(matrix);
			cp2 = find_corner_piece('W', 'G', 'O', matrix);
		}
	}
	if (cp2 == 20 || cp2 == 30 || cp2 == 52) { // rechtsboven 
		DCW(matrix);
		while (cp2 != 6 || matrix[0][6] != 'W') { // moet 1x 2x of 3x gebeuren tot goed zit
			FCCW(matrix); // ipv rcw!!
		    DCCW(matrix);
			FCW(matrix); // ipv rccw
			DCW(matrix);
			cp2 = find_corner_piece('W', 'G', 'O', matrix);
		}
	}
	print_matrix(matrix);
}
void wit_groen_rood_inschuiven(int cp2, char matrix[6][9]) {
	if (cp2 == 12 || cp2 == 22 || cp2 == 50) { // rechtsboven vanonder
		DCCW(matrix); 
		while (cp2 != 8 || matrix[0][8] != 'W') { // moet 1x 2x of 3x gebeuren tot goed zit
			RCCW(matrix); // ipv rcw!!
			DCCW(matrix);
			RCW(matrix); // ipv rccw
			DCW(matrix);
			cp2 = find_corner_piece('W', 'G', 'R', matrix);
		}
	}
	if (cp2 == 18 || cp2 == 48 || cp2 == 56) { // rechtsonder vanonder
		while (cp2 != 8 || matrix[0][8] != 'W') { // moet 1x 2x of 3x gebeuren tot goed zit
			RCCW(matrix); // ipv rcw!!
			DCCW(matrix);
			RCW(matrix); // ipv rccw
			DCW(matrix);
			cp2 = find_corner_piece('W', 'G', 'R', matrix);
		}
	}
	if (cp2 == 36 || cp2 == 46 || cp2 == 58) { // linksonder vanonder
		DCW(matrix);
		while (cp2 != 8 || matrix[0][8] != 'W') { // moet 1x 2x of 3x gebeuren tot goed zit
			RCCW(matrix); // ipv rcw!!
			DCCW(matrix);
			RCW(matrix); // ipv rccw
			DCW(matrix);
			cp2 = find_corner_piece('W', 'G', 'R', matrix);
		}
	}
	if (cp2 == 20 || cp2 == 30 || cp2 == 52) { // rechtsboven 
		DCW(matrix); DCW(matrix);
		while (cp2 != 8 || matrix[0][8] != 'W') { // moet 1x 2x of 3x gebeuren tot goed zit
			RCCW(matrix); // ipv rcw!!
			DCCW(matrix);
			RCW(matrix); // ipv rccw
			UCW(matrix);
			cp2 = find_corner_piece('W', 'G', 'R', matrix);
		}
	}
	print_matrix(matrix);
}


int find_corner_piece(char a, char b, char c, char matrix[6][9]) { // geeft positie van a terug, cornerpiece met kleuren a,b,c
	int result = 0; // tiental is vlak, eenheid is positie
	for(int i = 0; i < 6; i++) {
		for (int j = 0; j < 9; j += 2) { // 4 en 6 iteratie zijn overbodig: corners zijn enkel 0 2 6 8 
			if (matrix[i][j] == 'W' && j!=4) {

				if (i == 0) { // wit ligt in vlak 0
					if (j == 0) { // wit ligt op positie 0 in vlak 1
						if ((matrix[2][6] == b && matrix[3][2] == c) || (matrix[2][6] == c && matrix[3][2] == b)) {
							return i * 10 + j;
						}
					}
					if (j == 2) { // op positie 2
						if ((matrix[2][8] == b && matrix[1][0] == c) || (matrix[2][8] == c && matrix[1][0] == b)) {
							return i * 10 + j;
						}
					}
					if (j == 6) {
						if ((matrix[3][8] == b && matrix[4][0] == c) || (matrix[3][8] == c && matrix[4][0] == b)) {
							return i * 10 + j;
						}
					}
					if (j == 8) {
						if ((matrix[1][6] == b && matrix[4][2] == c) || (matrix[1][6] == c && matrix[4][2] == b)) {
							return i * 10 + j;
						}
					}
				}

				if (i == 1) { // wit ligt in vlak 1
					if (j == 0) { // wit ligt op positie 0 in vlak 1
						if ((matrix[0][2] == b && matrix[2][8] == c) || (matrix[0][2] == c && matrix[2][8] == b)) {
							return i * 10 + j;
						}
					}
					if (j == 2) { // op positie 2
						if ((matrix[2][2] == b && matrix[5][0] == c) || (matrix[2][2] == c && matrix[5][0] == b)) {
							return i * 10 + j;
						}
					}
					if (j == 6) {
						if ((matrix[0][8] == b && matrix[4][2] == c) || (matrix[0][8] == c && matrix[4][2] == b)) {
							return i * 10 + j;
						}
					}
					if (j == 8) {
						if ((matrix[4][8] == b && matrix[5][6] == c) || (matrix[4][8] == c && matrix[5][6] == b)) {
							return i * 10 + j;
						}
					}
				}
				if (i == 2) { // wit ligt in vlak 1
					if (j == 0) { // wit ligt op positie 0 in vlak 1
						if ((matrix[3][0] == b && matrix[5][2] == c) || (matrix[3][0] == c && matrix[5][2] == b)) {
							return i * 10 + j;
						}
					}
					if (j == 2) { // op positie 2
						if ((matrix[1][2] == b && matrix[5][0] == c) || (matrix[1][2] == c && matrix[5][0] == b)) {
							return i * 10 + j;
						}
					}
					if (j == 6) {
						if ((matrix[0][0] == b && matrix[3][2] == c) || (matrix[0][0] == c && matrix[3][2] == b)) {
							return i * 10 + j;
						}
					}
					if (j == 8) {
						if ((matrix[0][2] == b && matrix[1][0] == c) || (matrix[0][2] == c && matrix[1][0] == b)) {
							return i * 10 + j;
						}
					}
				}
				if (i == 3) { // wit ligt in vlak 1
					if (j == 0) { // wit ligt op positie 0 in vlak 1
						if ((matrix[2][0] == b && matrix[5][2] == c) || (matrix[2][0] == c && matrix[5][2] == b)) {
							return i * 10 + j;
						}
					}
					if (j == 2) { // op positie 2
						if ((matrix[0][0] == b && matrix[2][6] == c) || (matrix[0][0] == c && matrix[2][6] == b)) {
							return i * 10 + j;
						}
					}
					if (j == 6) {
						if ((matrix[4][6] == b && matrix[5][8] == c) || (matrix[4][6] == c && matrix[5][8] == b)) {
							return i * 10 + j;
						}
					}
					if (j == 8) {
						if ((matrix[0][6] == b && matrix[4][0] == c) || (matrix[0][6] == c && matrix[4][0] == b)) {
							return i * 10 + j;
						}
					}
				}
				if (i == 4) { // wit ligt in vlak 1
					if (j == 0) { // wit ligt op positie 0 in vlak 1
						if ((matrix[0][6] == b && matrix[3][8] == c) || (matrix[0][6] == c && matrix[3][8] == b)) {
							return i * 10 + j;
						}
					}
					if (j == 2) { // op positie 2
						if ((matrix[0][8] == b && matrix[1][6] == c) || (matrix[0][8] == c && matrix[1][6] == b)) {
							return i * 10 + j;
						}
					}
					if (j == 6) {
						if ((matrix[3][6] == b && matrix[5][8] == c) || (matrix[3][6] == c && matrix[5][8] == b)) {
							return i * 10 + j;
						}
					}
					if (j == 8) {
						if ((matrix[1][8] == b && matrix[5][6] == c) || (matrix[1][8] == c && matrix[5][6] == b)) {
							return i * 10 + j;
						}
					}
				}
				if (i == 5) { // wit ligt in vlak 1
					if (j == 0) { // wit ligt op positie 0 in vlak 1
						if ((matrix[1][2] == b && matrix[2][2] == c) || (matrix[1][2] == c && matrix[2][2] == b)) {
							return i * 10 + j;
						}
					}
					if (j == 2) { // op positie 2
						if ((matrix[2][0] == b && matrix[3][0] == c) || (matrix[2][0] == c && matrix[3][0] == b)) {
							return i * 10 + j;
						}
					}
					if (j == 6) {
						if ((matrix[1][8] == b && matrix[4][8] == c) || (matrix[1][8] == c && matrix[4][8] == b)) {
							return i * 10 + j;
						}
					}
					if (j == 8) {
						if ((matrix[3][6] == b && matrix[4][6] == c) || (matrix[3][6] == c && matrix[4][6] == b)) {
							return i * 10 + j;
						}
					}
				}

			}


		}
	}
}