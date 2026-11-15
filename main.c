#include "functions.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
	char tab[3][3];
	tuto();
	reset_tab(tab);
	while(1)
	{
		aff_tab(tab);
		tour_joueur(tab);
		if (joueur_win(tab))
        {
            aff_tab(tab);
            printf("C'est gagné !\n");
            return 1;
        }
		if(match_nul(tab))
		{
	        aff_tab(tab);
            printf("Match nul !\n");
            return 1;
		}
		tour_ordi(tab);
		if(ordi_win(tab))
		{
			aff_tab(tab);
            printf("Perdu ! Vous ferez mieux la prochaine fois !\n");
            return 1;
		}
		if(match_nul(tab))
		{
			aff_tab(tab);
            printf("Match nul !\n");
            return 1;
		}
	}
	return 0;
}