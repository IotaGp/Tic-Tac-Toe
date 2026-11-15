#include "functions.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
	char tab[3][3]; //Création du tableau
	tuto(); //demande si le joueur veut avoir un tuto
	reset_tab(tab); //pour réinitialiser toutes les cases du tableau
	while(1) //boucle qui s'arrête seulement quand on return 1 donc lorsque la partie est terminée
	{
		aff_tab(tab); //affiche le tableau actuel à chaque tour 
		tour_joueur(tab);
		if (joueur_win(tab)) //vérifie si le joueur gagne
        {
            aff_tab(tab);
            printf("C'est gagné !\n");
            return 1;
        }
		if(match_nul(tab)) //vérifie s'il y a match nul
		{
	        aff_tab(tab);
            printf("Match nul !\n");
            return 1;
		}
		tour_ordi(tab);
		if(ordi_win(tab)) //vérifie si l'ordi gagne
		{
			aff_tab(tab);
            printf("Perdu ! Vous ferez mieux la prochaine fois !\n");
            return 1;
		}
		if(match_nul(tab)) //vérifie encore s'il y a match nul
		{
			aff_tab(tab);
            printf("Match nul !\n");
            return 1;
		}
	}
	return 0;
}