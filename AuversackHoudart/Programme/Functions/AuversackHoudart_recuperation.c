#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../Headers/AuversackHoudart_structures.h"

void recupTables() { //affiche la liste des tables
	
	int n=0, i;
	FILE *fdat;
	fdat = fopen("Data/AuversackHoudart_Table.dat", "r");

	Table *deb, *courant, *suivant;
	courant=malloc(sizeof(Table));
	deb=courant;

	// Lecture + Construction de ma liste chain�e
	while(!feof(fdat)) {
		
		strcpy(courant->nomMatin,"");
		courant->nbPersonneMatin=0;
		courant->numMenuMatin=0;
		
		strcpy(courant->nomSoir,"");
		courant->nbPersonneSoir=0;
		courant->numMenuSoir=0;
		
		fscanf(fdat,"%d",&courant->estReserveMatin);
		if(courant->estReserveMatin == 1) {
			fscanf(fdat,"%s",&courant->nomMatin);
			fscanf(fdat,"%d",&courant->nbPersonneMatin);
			fscanf(fdat,"%d",&courant->numMenuMatin);		
		}

		fscanf(fdat,"%d",&courant->estReserveSoir);
		if(courant->estReserveSoir == 1) {
			fscanf(fdat,"%s",&courant->nomSoir);
			fscanf(fdat,"%d",&courant->nbPersonneSoir);
			fscanf(fdat,"%d",&courant->numMenuSoir);
		}
		fscanf(fdat,"%d",&courant->nbPlaceMax);
		
		suivant=malloc(sizeof(Table));
		courant->suivant=suivant;
		n++;
		courant=suivant;
	}

	//Placer Null au suivant du derni�re �l�ment + lib�rer l'espace de suivant
	courant=deb;
	for(i=1;i<n;i++) {
		courant=courant->suivant;
	}
	courant->suivant=NULL;	
		
	courant=deb;	
	
	// Affichage
	printf("\n");
	printf("   |Midi|\n");	
	printf("   --------------------------------------------------------------------------------\n");
	printf("   | Num table | nb place max  |  Reserve  |     Nom      |  nb Pers.  | Num menu |\n");
	printf("   --------------------------------------------------------------------------------\n");
	
	if(compterTable()!=0) { 
		for(i=1;i<=n;i++) {
			printf("   |     %d     |      %2d       |    %-3s    |  %-12s|      %d     |     %d    |\n",i, courant->nbPlaceMax, (courant->estReserveMatin==1 ? "Oui":"Non"), courant->nomMatin, courant->nbPersonneMatin, courant->numMenuMatin);
			courant=courant->suivant;
		}
		printf("   --------------------------------------------------------------------------------\n");
		
	}
	printf("\n");
	
	courant=deb;	
	// Affichage
	
	printf("   |Soir|\n");	
	printf("   --------------------------------------------------------------------------------\n");
	printf("   | Num table | nb place max  |  Reserve  |     Nom      |  nb Pers.  | Num menu |\n");
	printf("   --------------------------------------------------------------------------------\n");
	if(compterTable()!=0) { 	
		for(i=1;i<=n;i++) {
			printf("   |     %d     |      %2d       |    %-3s    |  %-12s|      %d     |     %d    |\n",i,courant->nbPlaceMax, (courant->estReserveSoir==1) ? "Oui":"Non", courant->nomSoir, courant->nbPersonneSoir, courant->numMenuSoir);
			courant=courant->suivant;
		}
		printf("   --------------------------------------------------------------------------------\n");
		
	}
	printf("\n");
	
	free(courant);
	free(suivant);	
	fclose(fdat);	
	
}

void recupMenu() { //affiche la liste des menus
	int n=0, i, j;
	FILE *fdat;
	fdat = fopen("Data/AuversackHoudart_Menu.dat", "r");
	
	Menu *deb, *courant, *suivant;
	courant=malloc(sizeof(Menu));
	deb=courant;

	// Lecture + Construction de ma liste chain�e
	while(!feof(fdat)) {
		
		strcpy(courant->nom,"");
		courant->prix=0;
		strcpy(courant->description,"");
		
		fscanf(fdat,"%s",&courant->nom);
		fscanf(fdat,"%5f",&courant->prix);
		fscanf(fdat,"%s",&courant->description);
		suivant=malloc(sizeof(Menu));
		courant->suivant=suivant;
		n++;
		courant=suivant;
	}

	//Placer Null au suivant du derni�re �l�ment + lib�rer l'espace de suivant
	courant=deb;
	for(i=1;i<n;i++) {
		courant=courant->suivant;
	}
	courant->suivant=NULL;	
		
	courant=deb;
		
	// Affichage	
	printf("\n");	
	printf("   ----------------------------------------------------------------------------------------------------------\n");
	printf("   |  N  |         Nom          |     Prix (Euro)  |         Description                                    |\n");
	printf("   ----------------------------------------------------------------------------------------------------------\n");

	if(compterMenu()!=0) {	
		for(i=1;i<=n;i++) {			
			for(j=0; j<strlen(courant->nom); j++) {
				if(courant->nom[j] == '_') {
					courant->nom[j] = ' ';
				}
			}
			for(j=0; j<strlen(courant->description); j++) {
				if(courant->description[j] == '_') {
					courant->description[j] = ' ';
				}
			}		
			printf("   |  %d  |  %-20s|      %5.2f       |  %-54s|\n",i, courant->nom, courant->prix, courant->description);
			courant=courant->suivant;
		}
		printf("   ----------------------------------------------------------------------------------------------------------\n");
		printf("\n");
	}
	else {
		printf("\n");
	}
	
	free(courant);
	free(suivant);	
	fclose(fdat);	
}

void recupEmployes() { //affiche la liste des employes
	int n=0, i, j;
	FILE *fdat;
	fdat = fopen("Data/AuversackHoudart_Employes.dat", "r");

	Employe *deb, *courant, *suivant;
	courant=malloc(sizeof(Employe));
	deb=courant;

	// Lecture + Construction de ma liste chain�e
	while(!feof(fdat)) {
		
		strcpy(courant->nom,"");
		courant->service=0;
		strcpy(courant->fonction,"");
		
		fscanf(fdat,"%s",&courant->nom);
		fscanf(fdat,"%d",&courant->service);
		fscanf(fdat,"%s",&courant->fonction);
		
		suivant=malloc(sizeof(Employe));
		courant->suivant=suivant;
		n++;
		courant=suivant;
	}

	//Placer Null au suivant du derni�re �l�ment + lib�rer l'espace de suivant
	courant=deb;
	for(i=1;i<n;i++) {
		courant=courant->suivant;
	}
	courant->suivant=NULL;	
		
	courant=deb;
		
	// Affichage
	printf("\n");
	printf("   Service - Midi : 12h00-15h00 - Soir : 18h00-23h00");	
	printf("\n");
	printf("\n");
	printf("   |Employe|\n");	
	printf("   --------------------------------------------------------\n");
	printf("   |  N  |     Nom      |   Service   |      Fonction     |\n");
	printf("   --------------------------------------------------------\n");
	
	
	
	if(compterEmploye()!=0) {	
		
		for(i=1;i<=n;i++) {
			for(j=0; j<strlen(courant->fonction); j++) {
				if(courant->fonction[j] == '_') {
					courant->fonction[j] = ' ';
				}
			}
			
			printf("   |  %d  |   %-10s |    %-6s   |   %-16s|\n",i, courant->nom, (courant->service==1)?"Midi":(courant->service==2)?"Soir":"Aucun", courant->fonction);
			courant=courant->suivant;
		}
		printf("   --------------------------------------------------------\n");
	}
	
	printf("\n");
	
	free(courant);
	free(suivant);	
	fclose(fdat);
}

void recupAdditionMidi() { //affiche l'addition d'une table pour le service du midi
		
	int n=0, i;
	FILE *fdat;
	fdat = fopen("Data/AuversackHoudart_Table.dat", "r");

	Table *deb, *courant, *suivant;
	courant=malloc(sizeof(Table));
	deb=courant;
	
	// Lecture + Construction de ma liste chain�e
	while(!feof(fdat)) {
		
		// Initialisation
		courant->nbPlaceMax=0;
		strcpy(courant->nomMatin, "");
		courant->nbPersonneMatin = 0;
		courant->numMenuMatin = 0;
		
		strcpy(courant->nomSoir, "");
		courant->nbPersonneSoir = 0;
		courant->numMenuSoir = 0;
		
		fscanf(fdat,"%d",&courant->estReserveMatin);
		if(courant->estReserveMatin == 1) {
			fscanf(fdat,"%s",&courant->nomMatin);
			fscanf(fdat,"%d",&courant->nbPersonneMatin);
			fscanf(fdat,"%d",&courant->numMenuMatin);			
		}

		fscanf(fdat,"%d",&courant->estReserveSoir);
		if(courant->estReserveSoir == 1) {
			fscanf(fdat,"%s",&courant->nomSoir);
			fscanf(fdat,"%d",&courant->nbPersonneSoir);
			fscanf(fdat,"%d",&courant->numMenuSoir);
		}
		fscanf(fdat,"%d",&courant->nbPlaceMax);
		
		suivant=malloc(sizeof(Table));
		courant->suivant=suivant;
		n++;
		courant=suivant;
	}

	//Placer Null au suivant du derni�re �l�ment + lib�rer l'espace de suivant
	courant=deb;
	for(i=1;i<n;i++) {
		courant=courant->suivant;
	}
	courant->suivant=NULL;	
		
	courant=deb;	
	// Affichage
	printf("\n");
	printf("   |Midi|\n");	
	printf("   --------------------------------------------------------------------------------\n");
	printf("   | Num table | nb place max  |  Reserve  |     Nom      |  nb Pers.  | Num menu |\n");
	printf("   --------------------------------------------------------------------------------\n");
	for(i=1;i<=n;i++) {
		printf("   |     %d     |      %2d       |    %-3s    |  %-12s|      %d     |     %d    |\n",i, courant->nbPlaceMax, (courant->estReserveMatin==1 ? "Oui":"Non"), courant->nomMatin, courant->nbPersonneMatin, courant->numMenuMatin);
		courant=courant->suivant;
	}
	printf("   --------------------------------------------------------------------------------\n");
	printf("\n");
	
	free(courant);
	free(suivant);	
	fclose(fdat);	
	
}

void recupAdditionSoir() { //affiche l'addition d'une table du service du soir
		
	int n=0, i;
	FILE *fdat;
	fdat = fopen("Data/AuversackHoudart_Table.dat", "r");

	Table *deb, *courant, *suivant;
	courant=malloc(sizeof(Table));
	deb=courant;

	// Lecture + Construction de ma liste chain�e
	while(!feof(fdat)) {
		
		courant->nbPlaceMax=0;
		strcpy(courant->nomMatin, "");
		courant->nbPersonneMatin = 0;
		courant->numMenuMatin = 0;
		
		strcpy(courant->nomSoir, "");
		courant->nbPersonneSoir = 0;
		courant->numMenuSoir = 0;
		
		fscanf(fdat,"%d",&courant->estReserveMatin);
		if(courant->estReserveMatin == 1) {
			fscanf(fdat,"%s",&courant->nomMatin);
			fscanf(fdat,"%d",&courant->nbPersonneMatin);
			fscanf(fdat,"%d",&courant->numMenuMatin);		
		}

		fscanf(fdat,"%d",&courant->estReserveSoir);
		if(courant->estReserveSoir == 1) {
			fscanf(fdat,"%s",&courant->nomSoir);
			fscanf(fdat,"%d",&courant->nbPersonneSoir);
			fscanf(fdat,"%d",&courant->numMenuSoir);
		}
		fscanf(fdat,"%d",&courant->nbPlaceMax);
		
		suivant=malloc(sizeof(Table));
		courant->suivant=suivant;
		n++;
		courant=suivant;
	}

	//Placer Null au suivant du derni�re �l�ment + lib�rer l'espace de suivant
	courant=deb;
	for(i=1;i<n;i++) {
		courant=courant->suivant;
	}
	courant->suivant=NULL;	
	
	courant=deb;	
	// Affichage
	
	printf("   |Soir|\n");	
	printf("   --------------------------------------------------------------------------------\n");
	printf("   | Num table | nb place max  |  Reserve  |     Nom      |  nb Pers.  | Num menu |\n");
	printf("   --------------------------------------------------------------------------------\n");
	for(i=1;i<=n;i++) {
		printf("   |     %d     |      %2d       |    %-3s    |  %-12s|      %d     |     %d    |\n",i,courant->nbPlaceMax, (courant->estReserveSoir==1) ? "Oui":"Non", courant->nomSoir, courant->nbPersonneSoir, courant->numMenuSoir);
		courant=courant->suivant;
	}
	printf("   --------------------------------------------------------------------------------\n");
	printf("\n");
	
	free(courant);
	free(suivant);	
	fclose(fdat);	
}

void recupTableReserveMidi() { //affiche les tables reservees pour le midi
	
	int n=0, i;
	FILE *fdat;
	fdat = fopen("Data/AuversackHoudart_Table.dat", "r");

	Table *deb, *courant, *suivant;
	courant=malloc(sizeof(Table));
	deb=courant;

	// Lecture + Construction de ma liste chain�e
	while(!feof(fdat)) {		
		
		courant->nbPlaceMax=0;
		strcpy(courant->nomMatin, "");
		courant->nbPersonneMatin = 0;
		courant->numMenuMatin = 0;
		
		strcpy(courant->nomSoir, "");
		courant->nbPersonneSoir = 0;
		courant->numMenuSoir = 0;
	
		fscanf(fdat,"%d",&courant->estReserveMatin);
		if(courant->estReserveMatin == 1) {
			fscanf(fdat,"%s",&courant->nomMatin);
			fscanf(fdat,"%d",&courant->nbPersonneMatin);
			fscanf(fdat,"%d",&courant->numMenuMatin);			
		}

		fscanf(fdat,"%d",&courant->estReserveSoir);
		if(courant->estReserveSoir == 1) {
			fscanf(fdat,"%s",&courant->nomSoir);
			fscanf(fdat,"%d",&courant->nbPersonneSoir);
			fscanf(fdat,"%d",&courant->numMenuSoir);
		}
		fscanf(fdat,"%d",&courant->nbPlaceMax);
		
		suivant=malloc(sizeof(Table));
		courant->suivant=suivant;
		n++;
		courant=suivant;
	}

	//Placer Null au suivant du derni�re �l�ment + lib�rer l'espace de suivant
	courant=deb;
	for(i=1;i<n;i++) {
		courant=courant->suivant;
	}
	courant->suivant=NULL;	
		
	courant=deb;	
	// Affichage
	printf("\n");
	printf("   |Midi|\n");	
	printf("   --------------------------------------------------------------------------------\n");
	printf("   | Num table | nb place max  |  Reserve  |     Nom      |  nb Pers.  | Num menu |\n");
	printf("   --------------------------------------------------------------------------------\n");
	if(compterTableReservMatin()!=0) {		
		for(i=1;i<=n;i++) {
			if(courant->estReserveMatin==1) {
				printf("   |     %d     |      %2d       |    %-3s    |  %-12s|      %d     |     %d    |\n",i, courant->nbPlaceMax, (courant->estReserveMatin==1 ? "Oui":"Non"), courant->nomMatin, courant->nbPersonneMatin, courant->numMenuMatin);			
			}
			courant=courant->suivant;
		}	
		printf("   --------------------------------------------------------------------------------\n");	
	}
	printf("\n");
	free(courant);
	free(suivant);	
	fclose(fdat);	
}

void recupTableReserveSoir() { //affiche les tables reservees pour le soir
	
	int n=0, i;
	FILE *fdat;
	fdat = fopen("Data/AuversackHoudart_Table.dat", "r");

	Table *deb, *courant, *suivant;
	courant=malloc(sizeof(Table));
	deb=courant;

	// Lecture + Construction de ma liste chain�e
	while(!feof(fdat)) {			
	
		courant->nbPlaceMax=0;
		strcpy(courant->nomMatin, "");
		courant->nbPersonneMatin = 0;
		courant->numMenuMatin = 0;
		
		strcpy(courant->nomSoir, "");
		courant->nbPersonneSoir = 0;
		courant->numMenuSoir = 0;
	
		fscanf(fdat,"%d",&courant->estReserveMatin);
		if(courant->estReserveMatin == 1) {
			fscanf(fdat,"%s",&courant->nomMatin);
			fscanf(fdat,"%d",&courant->nbPersonneMatin);
			fscanf(fdat,"%d",&courant->numMenuMatin);	
		}

		fscanf(fdat,"%d",&courant->estReserveSoir);
		if(courant->estReserveSoir == 1) {
			fscanf(fdat,"%s",&courant->nomSoir);
			fscanf(fdat,"%d",&courant->nbPersonneSoir);
			fscanf(fdat,"%d",&courant->numMenuSoir);
		}
		fscanf(fdat,"%d",&courant->nbPlaceMax);
		
		suivant=malloc(sizeof(Table));
		courant->suivant=suivant;
		n++;
		courant=suivant;
	}

	//Placer Null au suivant du derni�re �l�ment + lib�rer l'espace de suivant
	courant=deb;
	for(i=1;i<n;i++) {
		courant=courant->suivant;
	}
	courant->suivant=NULL;	
	
	courant=deb;	
	// Affichage
	printf("\n");
	printf("   |Soir|\n");	
	printf("   --------------------------------------------------------------------------------\n");
	printf("   | Num table | nb place max  |  Reserve  |     Nom      |  nb Pers.  | Num menu |\n");
	printf("   --------------------------------------------------------------------------------\n");
	if(compterTableReservSoir()!=0) {
		for(i=1;i<=n;i++) {
			if(courant->estReserveSoir==1) {
				printf("   |     %d     |      %2d       |    %-3s    |  %-12s|      %d     |     %d    |\n",i,courant->nbPlaceMax, (courant->estReserveSoir==1) ? "Oui":"Non", courant->nomSoir, courant->nbPersonneSoir, courant->numMenuSoir);
			
			}
			courant=courant->suivant;
		}
		printf("   --------------------------------------------------------------------------------\n");
		
	}
	printf("\n");
	free(courant);
	free(suivant);	
	fclose(fdat);	
}

void recupTableLibreMidi() { //affiche les tables libres du midi
	
	int n=0, i;
	FILE *fdat;
	fdat = fopen("Data/AuversackHoudart_Table.dat", "r");

	Table *deb, *courant, *suivant;
	courant=malloc(sizeof(Table));
	deb=courant;

	// Lecture + Construction de ma liste chain�e
	while(!feof(fdat)) {	
	
		courant->nbPlaceMax=0;
		strcpy(courant->nomMatin, "");
		courant->nbPersonneMatin = 0;
		courant->numMenuMatin = 0;
		
		strcpy(courant->nomSoir, "");
		courant->nbPersonneSoir = 0;
		courant->numMenuSoir = 0;
		
		fscanf(fdat,"%d",&courant->estReserveMatin);
		if(courant->estReserveMatin == 1) {
			fscanf(fdat,"%s",&courant->nomMatin);
			fscanf(fdat,"%d",&courant->nbPersonneMatin);
			fscanf(fdat,"%d",&courant->numMenuMatin);			
		}

		fscanf(fdat,"%d",&courant->estReserveSoir);
		if(courant->estReserveSoir == 1) {
			fscanf(fdat,"%s",&courant->nomSoir);
			fscanf(fdat,"%d",&courant->nbPersonneSoir);
			fscanf(fdat,"%d",&courant->numMenuSoir);
		}
		fscanf(fdat,"%d",&courant->nbPlaceMax);
		
		suivant=malloc(sizeof(Table));
		courant->suivant=suivant;
		n++;
		courant=suivant;
	}

	//Placer Null au suivant du derni�re �l�ment + lib�rer l'espace de suivant
	courant=deb;
	for(i=1;i<n;i++) {
		courant=courant->suivant;
	}
	courant->suivant=NULL;	
		
	courant=deb;	
	// Affichage
	printf("\n");
	printf("   |Midi|\n");	
	printf("   --------------------------------------------------------------------------------\n");
	printf("   | Num table | nb place max  |  Reserve  |     Nom      |  nb Pers.  | Num menu |\n");
	printf("   --------------------------------------------------------------------------------\n");
	if(compterTable()!=0) {
		for(i=1;i<=n;i++) {
			if(courant->estReserveMatin==0) {
				printf("   |     %d     |      %2d       |    %-3s    |  %-12s|      %d     |     %d    |\n",i, courant->nbPlaceMax, (courant->estReserveMatin==1 ? "Oui":"Non"), courant->nomMatin, courant->nbPersonneMatin, courant->numMenuMatin);			
			}
			courant=courant->suivant;
		}
		printf("   --------------------------------------------------------------------------------\n");
	}
	printf("\n");
	
	free(courant);
	free(suivant);	
	fclose(fdat);	
}

void recupTableLibreSoir() { //affiche les tables libres du soir
	
	int n=0, i;
	FILE *fdat;
	fdat = fopen("Data/AuversackHoudart_Table.dat", "r");

	Table *deb, *courant, *suivant;
	courant=malloc(sizeof(Table));
	deb=courant;

	// Lecture + Construction de ma liste chain�e
	while(!feof(fdat)) {	
	
		courant->nbPlaceMax=0;
		strcpy(courant->nomMatin, "");
		courant->nbPersonneMatin = 0;
		courant->numMenuMatin = 0;
		
		strcpy(courant->nomSoir, "");
		courant->nbPersonneSoir = 0;
		courant->numMenuSoir = 0;
	
		fscanf(fdat,"%d",&courant->estReserveMatin);
		if(courant->estReserveMatin == 1) {
			fscanf(fdat,"%s",&courant->nomMatin);
			fscanf(fdat,"%d",&courant->nbPersonneMatin);
			fscanf(fdat,"%d",&courant->numMenuMatin);
			
		}

		fscanf(fdat,"%d",&courant->estReserveSoir);
		if(courant->estReserveSoir == 1) {
			fscanf(fdat,"%s",&courant->nomSoir);
			fscanf(fdat,"%d",&courant->nbPersonneSoir);
			fscanf(fdat,"%d",&courant->numMenuSoir);
		}
		fscanf(fdat,"%d",&courant->nbPlaceMax);
		
		suivant=malloc(sizeof(Table));
		courant->suivant=suivant;
		n++;
		courant=suivant;
	}

	//Placer Null au suivant du derni�re �l�ment + lib�rer l'espace de suivant
	courant=deb;
	for(i=1;i<n;i++) {
		courant=courant->suivant;
	}
	courant->suivant=NULL;	
	
	courant=deb;	
	// Affichage
	printf("\n");
	printf("   |Soir|\n");	
	printf("   --------------------------------------------------------------------------------\n");
	printf("   | Num table | nb place max  |  Reserve  |     Nom      |  nb Pers.  | Num menu |\n");
	printf("   --------------------------------------------------------------------------------\n");
	if(compterTable()!=0) {	
		for(i=1;i<=n;i++) {
			if(courant->estReserveSoir==0) {
				printf("   |     %d     |      %2d       |    %-3s    |  %-12s|      %d     |     %d    |\n",i,courant->nbPlaceMax, (courant->estReserveSoir==1) ? "Oui":"Non", courant->nomSoir, courant->nbPersonneSoir, courant->numMenuSoir);
			
			}
			courant=courant->suivant;
		}
		printf("   --------------------------------------------------------------------------------\n");
	}
	printf("\n");
	
	free(courant);
	free(suivant);	
	fclose(fdat);	
}

