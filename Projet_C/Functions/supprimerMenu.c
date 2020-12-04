#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Menu {
	char nom[21];
	struct Menu *suivant;
}Menu;

void supprimerMenu() {
	int n=0, i;
	char menu[21];
	
	FILE *fdat, *fdatTmp;
	fdat = fopen("Data/Menu.dat", "r");
	fdatTmp = fopen("Data/Menu.tmp", "w");
	
	printf("Supprimer un Menu : ");
	scanf("%s", &menu);
		
	Menu *deb, *courant, *suivant;
	courant=malloc(sizeof(Menu));
	deb=courant;

	// Lecture + Construction de ma liste chain�e
	while(!feof(fdat)) {
		fscanf(fdat,"%s",&courant->nom);
		if(strcasecmp(courant->nom,menu) != 0) {
			suivant=malloc(sizeof(Menu));
			courant->suivant=suivant;
			n++;
			courant=suivant;
		}		
	}
	
	//Placer Null au suivant du derni�re �l�ment + lib�rer l'espace de suivant
	courant=deb;
	for(i=1;i<n;i++) {
		courant=courant->suivant;
	}
	courant->suivant=NULL;	
		
	courant=deb;	
		
	// Ecriture
	for(i=1;i<=n;i++) {		
		fprintf(fdatTmp, "%s", courant->nom);
		if(i!=n) {
			fprintf(fdatTmp, "\n");
		}
		courant=courant->suivant;
	}
		
	fclose(fdat);
	fclose(fdatTmp);
	remove("Data/Menu.dat");		
	rename("Data/Menu.tmp", "Data/Menu.dat");
}
