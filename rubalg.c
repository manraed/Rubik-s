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



*/
#include "rubalg.h"
//void draaikubus(vlak a, vlak b) { // draai kubus zodat vlak a op vlak b plek komt liggen
								  /*
								  if(a==0){ bovenvlak moet gedraaid worden
								  if(b==1){ naar rechts
								  * draairechts();
								  *  }
								  * if(b==2){ naar achter
								  * draaiachter();
								  * }
								  * if(b==3){ links draaien
								  * draailinks();
								  * }
								  * if(b==4){ naar beneden draaien
								  * draaionder();
								  * }
								  * if(b==5){
								  * dubbel naar beneden draaien
								  * }
								  * }
								  *
								  * if(a==1){
								  * if(b==0){ links draaien
								  * draailinks();
								  * }
								  * if(b==2){
								  * draairechtsnaarachter() ;
								  * }
								  * if(b==3){
								  * draaidubbelx();
								  * }
								  * if(b==4){
								  * draailinks();
								  * draaiboven();
								  * }
								  * if(b==5){
								  * draairechts();
								  * }
								  * }
								  * if(a==2){
								  * if(b==0){
								  * draaionder();
								  * }
								  * if(b==1){
								  * draaionder();
								  * draairechts();
								  * }
								  * if(b==3){
								  * draaionder();
								  * draailinks();
								  * }
								  * if(b==4){
								  * draaidubbely();
								  * }
								  * if(b==5){
								  * draaiboven();
								  * }
								  *  }
								  * if(a==3){
								  * if(b==0){
								  * draairechts();
								  * }
								  * if(b==1){
								  * draaioverx();
								  * }
								  * if(b==2){
								  * draairechts();
								  * draaiboven();
								  * }
								  * if(b==4){
								  * draairechts();
								  * draaionder();
								  * }
								  * if(b==5){
								  * draailinks();
								  * }
								  * }
								  * if(a==4){
								  * if(b==0){
								  * draaiboven();
								  * }
								  * if(b==1){
								  * draaiboven();
								  * draairechts();
								  * }
								  * if(b==2){
								  * draaiovery();
								  * }
								  * if(b==3){
								  * draaiboven();
								  * draailinks();
								  * }
								  * if(b==5){
								  * draaionder();
								  * }
								  * }
								  * if(a==5){
								  * if(b==0){
								  * draaioverx();
								  * }
								  * if(b==1){
								  * draailinks();
								  * }
								  * if(b==2){
								  * draaionder();
								  * }
								  * if(b==3){
								  * draairechts();
								  * }
								  * if(b==4){
								  * draaiboven();
								  * }
								  *
								  * }
								  *
								  */
//}

int find_edgepiece(char a, char b,char matrix[6][9]) { // geeft vlak en positie terug in een int[2], werkt!
	
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
		}

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
		if (b == 3) { {LCCW(matrix); }
		if (b == 5) { RCW(matrix); }
		if (b = 7) { BCW(matrix); BCW(matrix); }
		//  if(vlak==5) zit goed
		}

	}
}
/* alle handelingen zijn nu geimplementeerd als functies
Nu beginnen we aan begin algoritme:
Dit is een wit kruis krijgen in vlak wit
belangrijk: eerst hoekpunt met kleur aan blauw aan andere kant(zie:edge pieces), dan oranje,groen,rood */

void maak_wit_kruis(char matrix[6][9]) {
	int wb;
	
/*	zorg ervoor dat vlak wit vanboven staat!
	zorg dat wit-blauw edge piece in down-vlak ligt:
	zoek eerst wit-blauw edge piece met findedgepiece(w,b) */
	
	wb = find_edgepiece('W', 'B', matrix);
//	 wb/10 is vlak, wb%10 is positie
	if (wb / 10 != 0 || wb % 10 != 1) {
		bringdownedge(wb / 10, wb % 10, matrix);
		wb = find_edgepiece('W', 'B', matrix);
		if (wb/ 10 == 5) { // het witte van wb zit in ondervlak
			if (wb % 10 == 3) { DCW(matrix); } // juist draaien zodat gealligneerd is met blauwcenter
			if (wb % 10 == 5) { DCCW(matrix); }
			if (wb % 10 == 7) { DCW(matrix); DCW(matrix); }
			BCW(matrix); BCW(matrix); // naar boven draaien
		}
		else {
			if (find_edgepiece('W', 'B', matrix) / 10 == 1) {
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
		}
	}
	/*check of wit-blauw edge op vlak==w en pos==1 ligt, else
	zet wit-blauw beneden: bringdownedge
	draai wit-blauw naar blauw vlak:
	var[][] =
	kijk of wit in geel vlak ligt if(find_edgepiece(w,b)[i]==y){
	var[][] = find_edgepiece(w,b);
	if(pos==1){ DCW x 2
	if(pos==3){ DCCW
	if(pos==5){ DCW
	dan naar boven: BCW x 2
	draai kubus dan, zodat oranje rechts gaat staan
	} else{  dus als het blauw stuk in geel ligt, gaat kruis niet goed zitten:
	var[][] = findedgepiece(b,w)
	if(pos==1){ DCW x 2
	if(pos==3){ DCCW
	if(pos==5){ DCW
	BCW x 2
	draai kubus zodat blauw rechts zit, dan
	RCCW
	UCW
	FCCW
	UCCW
	}
	nu staat witblauw correct, volgende is oranje
	vind wit-oranje: findedgepiece(w,o)
	check of wit-oranje edge op vlak==w en pos==3 ligt, else
	bringdownedge(findedgepiece(w,o)))
	kijk of wit in geel vlak ligt if(findedgepiece(w,o)[i]==y){
	var[][] = findedgepiece(w,o);
	if(pos==1){ DCW x 2
	if(pos==3){ DCCW
	if(pos==5){ DCW
	controleer hier of de wit-blauw is verplaatst!! kan gebeuren !!

	} else  dus als het oranje stuk in geel ligt, werk met
	var[][] = findedgepiece(o,w)
	if(pos==1){ DCCW
	if(pos==3){ OK
	if(pos==5){ DCW x 2
	if(pos==7){ DCW

	}
	*/
}