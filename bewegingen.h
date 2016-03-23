#pragma once

/*Vlak in wijzerzin draaien*/
void draai_wijzerzin(int, char[6][9]);

/*Vlak in tegenwijzerzin draaien*/
void draai_tegenwijzerzin(int, char[6][9]);

/*Kubus naar voor draaien (bovenvlak wordt voorvlak)*/
void draai_onder(char[6][9]);

/*Kubus naar achter draaien (bovenvlak wordt achtervlak)*/
void draai_boven(char[6][9]);

/*Kubus naar rechts draaien (bovenvlak wordt rechtse vlak)*/
void draai_rechts(char[6][9]);

/*Kubus naar links draaien (bovenvlak wordt links vlak)*/
void draai_links(char[6][9]);

/*Rechterkant van de kubus in wijzerzin draaien*/
void RCW(char[6][9]);

/*Rechterkant van de kubus in tegenwijzerzin draaien*/
void RCCW(char[6][9]);

/*Linkerkant van de kubus in wijzerzin draaien*/
void LCW(char[6][9]);

/*Linkerkant van de kubus in tegenwijzerzin draaien*/
void LCCW(char[6][9]);

/*Voorkant van de kubus in wijzerzin draaien*/
void FCW(char[6][9]);

/*Voorkant van de kubus in tegenwijzerzin draaien*/
void FCCW(char[6][9]);

/*Achterkant van de kubus in wijzerzin draaien*/
void BCW(char[6][9]);

/*Achterkant van de kubus in tegenwijzerzin draaien*/
void BCCW(char[6][9]);

/*Bovenkant van de kubus in wijzerzin draaien*/
void UCW(char[6][9]);

/*Bovenkant van de kubus in tegenwijzerzin draaien*/
void UCCW(char[6][9]);

/*Onderkant van de kubus in wijzerzin draaien*/
void DCW(char[6][9]);

/*Onderkant van de kubus in tegenwijzerzin draaien*/
void DCCW(char[6][9]);