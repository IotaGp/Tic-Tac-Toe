#include <stdio.h>
#include <stdlib.h>

void tuto() //Si le joueur ne connaît pas les règles, il peut accéder à un tuto.
{
	int reponse;
	printf("Êtes-vous prêt(e) à jouer ?\n Si oui entrez '0', sinon entrez '1' pour avoir un tuto : ");
	scanf("%d", &reponse);
	if(reponse == 1) //si le joueur décide d'avoir le tuto
	{
		printf("Les cases sont :\n0  |1 |2  \n---------\n3  |4 |5\n---------\n6  |7 |8\n---------\n");
		printf("Pour jouer, il suffit d'entrer le numéro de la case choisie lorsque c'est à votre tour.\n");
		printf("Pour gagner, vous devez aligner trois symboles en ligne, en colone ou en diagonale tout en empêchant l'ordianteur de le faire.\n");
	}
		printf("Le jeu va commencer !\n");
}

void reset_tab(char tab[3][3]) //réinitialise les cases tout en affichant le numéro de chaque case
{
	int count = 0;
	int i = 0;
	int j;
	for(i; i < 3; i++) // parcourt toutes les lignes
	{
		for(j = 0; j < 3; j++) // parcourt toutes les lignes
		{	
			tab[i][j] = '0' + count;
			count++;
		}
	}
}

void aff_tab(char tab[3][3]) //Affiche le tableau avec les valeurs actuelles car il les prend directement dans le tableau. 
{
	printf("Le tableau actuel est :\n  %c |%c |%c\n---------\n  %c |%c |%c\n---------\n  %c |%c |%c\n", tab[0][0], tab[0][1], tab[0][2], tab[1][0], tab[1][1], tab[1][2], tab[2][0], tab[2][1], tab[2][2]);
}

int tour_joueur(char tab[3][3])
{
	int choix;
	int count = 0;
	int i;
	int j;
	while (count != 10)
	{
		printf("Choisissez où jouer : ");
		if(scanf("%d", &choix) != 1) // récupère le numéro de la case choisie et regarde si c'est bien un entier.
		{
			printf("Il faut entrer un chiffre compris entre 0 et 8\n");
			while(getchar() != '\n'); //supprimer le(s) mauvais choix jusqu'à la fin.
		}
		else if(choix >= 0 && choix <= 8) //si le chiffre est bien compris entre 0 et 8
		{
			i = choix / 3; //traduit le chiffre pour qu'il corresponde à la bonne case
			j = choix % 3; //idem
			if(tab[i][j] != 'X' && tab[i][j] != 'o') //s'il n'y a personne qui a déjà joué sur cette case
			{
				tab[i][j] = 'X'; //print le symbole dans la case
				printf("Votre tour est terminé.\n");
				count = 10; //ferme la boucle
			}
			else //si la case est occupée
			{
				printf("Cette case est occupée.\n");
			}
		}
		else //si c'est un autre entier
		{
			printf("Case inexistante. La triche est interdite !");
		}	
	}
	return 0;
}

void tour_ordi(char tab[3][3]) //Le fonctionnement de l'ordi
{
	int i;
	int j;
	for(i = 0; i < 3; i++) //parcourt toutes les lignes du tableau
	{
		for(j = 0; j < 3; j++) //parcourt toutes les colones du tableau
		{
			if(tab[i][j] != 'X' && tab[i][j] != 'o') //s'il n'y a personne qui a déjà joué sur cette case
			{
				tab[i][j] = 'o';
				printf("L'ordinateur joue en %d\n", i * 3 + j); //pour afficher le caractère dans la bonne case.
				return;
			}
		}
	}
}

int joueur_win(char tab[3][3]) //vérifie si le symbole du joueur est aligné trois fois donc s'il a gagné
{
	int i;
	for(i = 0; i < 3; i++)
	{
		if(tab[i][0] == 'X' && tab[i][1] == 'X' && tab[i][2] == 'X') //en ligne
		{
			return 1;
		}
		if(tab[0][i] == 'X' && tab[1][i] == 'X' && tab[2][i] == 'X') //en colone
		{
			return 1;
		}
		if(tab[0][0] == 'X' && tab[1][1] == 'X' && tab[2][2] == 'X') //première diagonale
		{
			return 1;
		}
		if(tab[0][2] == 'X' && tab[1][1] == 'X' && tab[2][0] == 'X') //deuxième diagonale
		{
			return 1;
		}
	}
	return 0;
}
int ordi_win(char tab[3][3]) //vérifie si l'ordi a gagné de la même manière
{
	int i;
	for(i = 0; i < 3; i++)
	{
		if(tab[i][0] == 'o' && tab[i][1] == 'o' && tab[i][2] == 'o')
		{
			return 1; //return 1 pour la condition du if dans le main.c
		}
		if(tab[0][i] == 'o' && tab[1][i] == 'o' && tab[2][i] == 'o')
		{
			return 1;
		}
		if(tab[0][0] == 'o' && tab[1][1] == 'o' && tab[2][2] == 'o')
		{
			return 1;
		}
		if(tab[0][2] == 'o' && tab[1][1] == 'o' && tab[2][0] == 'o')
		{
			return 1;
		}
	}
	return 0;
}

int match_nul(char tab[3][3]) //vérifie si toutes les cases sont remplies. Comme on a vérifié précédemment si quequ'un a gagné alors ça veut dire qu'il y a match nul.
{
	int i;
	int j;
	for(i = 0; i < 3; i++) //les boucles for sont utilisées de la même manière et pour les mêmes raisons que les précédentes.
	{
		for(j = 0; j < 3; j++)
		{
			if(tab[i][j] != 'X' && tab[i][j] != 'o') //s'il reste une case où personne n'a joué.
			{
				return 0;
			}
		}
	}
	return 1;
}