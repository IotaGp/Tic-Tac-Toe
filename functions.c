#include <stdio.h>

void tuto() //Si le joueur ne connaît pas les règles, il peut accéder à un tuto.
{
	int reponse;
	printf("Êtes-vous prêt(e) à jouer ?\n Si oui entrez '0', sinon entrez '1' pour avoir un tuto : ");
	scanf("%d", &reponse);
	if(reponse == 1)
	{
		printf("Les cases sont :\n0  |1 |2  \n---------\n3  |4 |5\n---------\n6  |7 |8\n---------\n");
		printf("Pour jouer, il suffit d'entrer le numéro de la case choisie lorsque c'est à votre tour.\n");
		printf("Pour gagner, vous devez aligner.\n");
	}
		printf("Le jeu va commencer !\n");
}

void start()
{

}

int emplacement()
{
	int emp;
	printf("Où voulez-vous jouer ?");
	scanf("%d", &emp);
	if(emp >= 0 && emp <= 8)
	{

	}
	else
	{
		printf("Les cases vont de 0 à 8. Choisissez un chiffre compris dedans : ");
		scanf("%d", &emp);
	}
}