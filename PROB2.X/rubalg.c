

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

void draairechtsnaarachter(){ // ietscomplexer
    draailinks();
    draaiachter();
    
}
void draaiachter(){ //bovenvlak wordt achtervlak
    
    /*
      M2 open doen
     * servo B clockwise 90, servor c counterclockwise 90
     * M2 toe doen
     * M1 open doen
     * servo terugplaatsen
     * M1 toe doen
     * 
     * matrix aanpassen: 
     * vlak 0 2 4 en 5 doorschuiven: 0 -> 2 2 -> 5 5 -> 4 4 -> 0, posities blijven zelfde
     * vlak 1 en 3 draaien de posities: godhalellujah, das hetzelfde als vorige!
     * vlak 1:
     * 0->2
     * 1->5
     * 2->8
     * 3->1
     * 4->4
     * 5->7
     * 6->0
     * 7->3
     * 8->6
     * 
     * vlak 2:
     * 0->6
     * 1->3
     * 2->0
     * 3->7
     * 4->4
     * 5->1
     * 6->8
     * 7->5
     * 8->2
     */
    
}
void draaionder(){ // bovenvlak wordt voorvlak
    
    /*
     
     naar beneden draaien
     *  M2 open doen
     * servo B counter clockwise 90, servor D clockwise 90
     * M2 toe doen
     * M1 open doen
     * servo terugplaatsen
     * M1 toe doen
     * 
     * matrix aanpassen: 
     * vlak 0 2 4 en 5 doorschuiven: 0 -> 4 4 -> 5 5 -> 2 2 -> 0, posities blijven zelfde
     * vlak 1 en 3 draaien de posities: godhalellujah, das hetzelfde als vorige!
     * vlak 3:
     * 0->2
     * 1->5
     * 2->8
     * 3->1
     * 4->4
     * 5->7
     * 6->0
     * 7->3
     * 8->6
     * vlak 1:
     * 0->6
     * 1->3
     * 2->0
     * 3->7
     * 4->4
     * 5->1
     * 6->8
     * 7->5
     * 8->2
     */
    
    
    
}
void draaidubbelx(){ // draai vlak naar overzijde over x as door kubus
    
    // nog effe schrijven
   
}
void draaidubbely(){ // draai vlak over y-as zijde
    // nog te schrijven
}
void draairechts(){ // bovenvlak wordt rechtsvlak
    
    /*
    M1 open doen 
     * servo A 90 clockwise en C 90 counter clockwise draaien
     * M1 toe doen
     * M2 open doen
     * servo A en C terugzetten
     * M2 toe doen
     * 
     * !!matrix aanpassen:
     * template maken
     * boven,onder,links en rechts vlak: [i] doorschuiven : 0 -> 1 1 -> 5 5 -> 3 3 -> 0
     * voor en achter: vlak blijft zelfde, posities veranderen wel!
     * front wordt:
     * 0->2
     * 1->5
     * 2->8
     * 3->1
     * 4->4
     * 5->7
     * 6->0
     * 7->3
     * 8->6
     * back wordt:
     * 0->6
     * 1->3
     * 2->0
     * 3->7
     * 4->4
     * 5->1
     * 6->8
     * 7->5
     * 8->2
     *  !! zie patroon, back is omgedraaide front <- ipv -> !! 
     
     */
       
}
void draailinks(){ // bovenvlak wordt linksvlak
    /*
     M1 open doen 
     * servo A 90 counter clockwise en C 90 clockwise draaien
     * M1 toe doen
     * M2 open doen
     * servo A en C terugzetten
     * M2 toe doen
     * !!matrix aanpassen:
     * template maken
     * boven,onder,links en rechts vlak: [i] doorschuiven : 0 -> 3 3 -> 5 5 -> 1 1 -> 0
     * voor en achter: vlak blijft zelfde, posities veranderen wel!
     * back wordt:
     * 0->2
     * 1->5
     * 2->8
     * 3->1
     * 4->4
     * 5->7
     * 6->0
     * 7->3
     * 8->6
     * front wordt:
     * 0->6
     * 1->3
     * 2->0
     * 3->7
     * 4->4
     * 5->1
     * 6->8
     * 7->5
     * 8->2
     * bemerk analogie met naar rechts draaien woohooow
     * 
     */
    
}

void draaikubus(vlak a, vlak b){ // draai kubus zodat vlak a op vlak b plek komt liggen
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
     * 
     * 
     
     
     
     
     
     */
    
    
    
    
}





void RCW() {
	// servoB 90 clockwise draaien

	//M1 open doen

	// servoB terug op 0 graden zetten
	// zorg dat veranderingen in matrix worden aangepast!!
	//M1 terug toe doen

}

void RCCW() {
	//servoB 90 counter clockwise draaien 

	//M1 open doen

	//servoB terug op 0 graden zetten
	// zorg dat veranderingen in matrix worden aangepast!!
	//M1 terug toe doen
}

void LCW() {
	//servoD 90 clockwise draaien

	//M1 open
	// zorg dat veranderingen in matrix worden aangepast!!
	//servoD terug op 0 graden zetten

	//M1 terug toe doen
}

void LCCW() {
	//servoD 90 counter clockwise draaien 

	//M1 open doen

	//servoD terug op 0 graden zetten
	// zorg dat veranderingen in matrix worden aangepast!!
	//M1 terug toe doen

}

void FCW() {
	//servoC 90  clockwise draaien 

	//M2 open doen

	//servoC terug op 0 graden zetten
	// zorg dat veranderingen in matrix worden aangepast!!
	//M2 terug toe doen
}

void FCCW() {
	//servoC 90 counter clockwise draaien 

	//M2 open doen

	//servoC terug op 0 graden zetten
	// zorg dat veranderingen in matrix worden aangepast!!
	//M2 terug toe doen
}

void BCW() {
	//servoA 90  clockwise draaien 

	//M2 open doen
	// zorg dat veranderingen in matrix worden aangepast!!
	//servoA terug op 0 graden zetten

	//M2 terug toe doen

}

void BCCW() {
	//servoA 90  counter clockwise draaien 

	//M2 open doen

	//servoA terug op 0 graden zetten
	// zorg dat veranderingen in matrix worden aangepast!!
	//M2 terug toe doen
}

void UCW() { // u=up, d=down
	// we maken van up eerst front
	//M2 open doen

	//tegelijk servoD 90 graden clockwise en servoB 90 graden counter clockwise

	//M2 toe doen
	// zorg dat veranderingen in matrix worden aangepast!!
	//M1 open doen

	// servoD en servoB terug op 0

	//M1 toe doen

	// gebruik FCW

	//M2 open doen

	//tegelijk servoD 90 graden counter clockwise en servoB 90 graden clockwise

	// M2 toe doen
}

void UCCW() {
	// we maken van up eerst front
	//M2 open doen

	//tegelijk servoD 90 graden clockwise en servoB 90 graden counter clockwise
	// zorg dat veranderingen in matrix worden aangepast!!
	//M2 toe doen

	//M1 open doen

	// servoD en servoB terug op 0

	//M1 toe doen

	// gebruik FCCW

	//M2 open doen

	//tegelijk servoD 90 graden counter clockwise en servoB 90 graden clockwise

	// M2 toe doen

}

void DCW() {
	// we maken van down eerst front
	//M2 open doen

	//tegelijk servoD 90 graden counter clockwise en servoB 90 graden clockwise

	//M2 toe doen
	// zorg dat veranderingen in matrix worden aangepast!!
	//M1 open doen

	// servoD en servoB terug op 0

	//M1 toe doen

	// gebruik FCW

	//M2 open doen

	//tegelijk servoD 90 graden clockwise en servoB 90 graden counter clockwise

	// M2 toe doen

}

void DCCW() {
	// we maken van down eerst front
	//M2 open doen

	//tegelijk servoD 90 graden counter clockwise en servoB 90 graden clockwise

	//M2 toe doen
	// zorg dat veranderingen in matrix worden aangepast!!
	//M1 open doen

	// servoD en servoB terug op 0

	//M1 toe doen

	// gebruik FCCW

	//M2 open doen

	//tegelijk servoD 90 graden clockwise en servoB 90 graden counter clockwise

	// M2 toe doen

}
void findedgepiece(char a, char b) {
	/* 
	 edge enkel op pos met oneven indexen zoeken
	 for(int i = 0 ; i < 5 ; i++)
	 for(int j = 1 ; j < 7 ; j+=2)
	 if(mat[i][j]== a){ 
	  if(j==
	 dan kijken in aanliggend vlak voor volgende kleur
	 is correct-> return pos van a ( dus vlak en pos)

	*/
}
void bringdownedge() { /* brengte edgepiece naar beneden, kijkt niet naar welke kleur echt in het geelvlak zit, en welke aan aanliggend*/
	
	/*
	if(vlak==w){ nog niet in orde als het in wit vlak ligt
	if(pos==3){ exit functie
	if(pos==
	}
	if(vlak==4){/*groen, dit aanpassen naar 0 tem 5 ( groen is dus voor)
	if(pos==3) LCW
	if(pos==5) RCW
	if(pos==1) FCW x 2 
	if(pos==7) niets
	if(vlak==3){ /*oranje
	if(pos==1) BCW
	if(pos==3) niets, zit goed
	if(pos==5) LCW x 2
	if(pos==7) LCW
	if(vlak==1){ /* rood
	if(pos==1) RCW x 2
	if(pos==3) RCW
	if(pos==5) RCCW
	if(pos==7) zit goed
	if(vlak==2){ /* blauw
	if(pos==1) zit goed
	if(pos==3) LCW
    if(pos==5) RCCW
	if(pos=7) BCW x 2
	if(vlak==5) zit goed
	*/
	
}
/* alle handelingen zijn nu geimplementeerd als functies
   Nu beginnen we aan begin algoritme:
   Dit is een wit kruis krijgen in vlak wit 
   belangrijk: eerst hoekpunt met kleur aan blauw aan andere kant(zie:edge pieces), dan oranje,groen,rood */

void maakwitkruis() {
	/*
	 zorg ervoor dat vlak wit vanboven staat!
	 zorg dat wit-blauw edge piece in down-vlak ligt:
	 zoek eerst wit-blauw edge piece met findedgepiece(w,b)
	 check of wit-blauw edge op vlak==w en pos==1 ligt, else
	 zet wit-blauw beneden: bringdownedge
	 draai wit-blauw naar blauw vlak:
	 var[][] = 
	 kijk of wit in geel vlak ligt if(findedgepiece(w,b)[i]==y){
	 var[][] = findedgepiece(w,b);
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
