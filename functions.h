#include <stdio.h>
#ifndef __FUNCTIONS_H__
#define __FUNCTIONS_H__
void tuto();
void aff_tab(char tab[3][3]);
void reset_tab(char tab[3][3]);
int tour_joueur(char tab[3][3]);
void tour_ordi(char tab[3][3]);
int joueur_win(char tab[3][3]);
int ordi_win(char tab[3][3]);
int match_nul(char tab[3][3]);
#endif