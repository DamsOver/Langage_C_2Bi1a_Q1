#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Table {
	int nbPlaceMax;
	
	int estReserveMatin;
	char nomMatin[21];
	int nbPersonneMatin;
	int numMenuMatin;
	
	int estReserveSoir;
	char nomSoir[21];
	int nbPersonneSoir;
	int numMenuSoir;
	
	struct Table *suivant;
}Table;

typedef struct Menu {
	char nom[21];
	float prix;
	char description[40];
	
	struct Menu *suivant;
}Menu;

void ajouterTable() {

	Table table;
	
	FILE *fdat;
	fdat = fopen("Data/Table.dat", "a");
	
	// Initialisation
	table.estReserveMatin = 0;
	strcpy(table.nomMatin, "");
	table.nbPersonneMatin = 0;
	table.numMenuMatin = 0;
	
	table.estReserveSoir = 0;
	strcpy(table.nomSoir, "");
	table.nbPersonneSoir = 0;
	table.numMenuSoir = 0;	
	
	// Ajout table
	system("cls");
	recupTables();
	printf("   Nombres de places a table : ");	
	scanf("%d", &table.nbPlaceMax);
		
	system("cls");
	recupTables();	
	printf("   Table reserve le matin(0/1) : ");	
	scanf("%d", &table.estReserveMatin);

	if(table.estReserveMatin==1) {
		
		system("cls");	
		recupTables();		
		printf("   Nom de la reservation : ");
		scanf("%s", &table.nomMatin);
		
		erreurNbPlaceMaxMatin:
		
		system("cls");		
		recupTables();		
		printf("   Nombre de personne a table : ");
		scanf("%d", &table.nbPersonneMatin);
		
		if(table.nbPersonneMatin > table.nbPlaceMax) {
			goto erreurNbPlaceMaxMatin;
		}
		
		erreurNumMenuMatin:
		
		system("cls");		
		recupTables();		
		printf("   Numero du menu choisi : ");
		scanf("%d", &table.numMenuMatin);
		
		if(table.numMenuMatin<=0 || table.numMenuMatin>compterMenu()) {
			goto erreurNumMenuMatin;
		}
	}
	
	system("cls");
	recupTables();
	printf("   Table reserve le soir(0/1) : ");
	scanf("%d", &table.estReserveSoir);
	
	if(table.estReserveSoir==1) {
		
		system("cls");	
		recupTables();		
		printf("   Nom de la reservation : ");
		scanf("%s", &table.nomSoir);
		
		erreurNbPlaceMaxSoir:
		
		system("cls");		
		recupTables();		
		printf("   Nombre de personne a table : ");
		scanf("%d", &table.nbPersonneSoir);
		
		if(table.nbPersonneSoir > table.nbPlaceMax) {
			goto erreurNbPlaceMaxSoir;
		}
		
		erreurNumMenuSoir:
			
		system("cls");		
		recupTables();
				
		printf("   Numero du menu choisi : ");
		scanf("%d", &table.numMenuSoir);
		
		if(table.numMenuSoir<=0 || table.numMenuSoir>compterMenu()) {
			goto erreurNumMenuSoir;
		}
		
	}
		
	fprintf(fdat, "\n%d ", table.estReserveMatin);
	if(table.estReserveMatin==1) {
		fprintf(fdat, "%s %d %d ", table.nomMatin, table.nbPersonneMatin, table.numMenuMatin);
	}
	
	fprintf(fdat, "%d", table.estReserveSoir);
	if(table.estReserveSoir==1) {
		fprintf(fdat, " %s %d %d", table.nomSoir, table.nbPersonneSoir, table.numMenuSoir);
	}
	fprintf(fdat, " %d", table.nbPlaceMax);
	fclose(fdat);	
}

void ajouterMenu() {
	int j;
	Menu menu;
	
	FILE *fdat;
	fdat = fopen("Data/Menu.dat", "a");
	
	recupMenu();
	
	printf("   Nom du Menu : ");
	scanf("%s", &menu.nom);
	
	system("cls");
	recupMenu();
	
	printf("   Prix du Menu : ");
	scanf("%5f", &menu.prix);
	
	system("cls");
	recupMenu();
	printf("   Description du Menu : ");
	fflush(stdin);
	fgets(menu.description, 40, stdin);
	//scanf("%s", &menu.description);
	
	for(j=0; j<strlen(menu.description); j++) {
		if(menu.description[j] == ' ') {
			menu.description[j] = '_';
		}
		if(menu.description[j] == '\n') {
			menu.description[j] = '\0';
		}
	}
	
	fprintf(fdat, "\n%s %5.2f %s", menu.nom, menu.prix, menu.description);
	
	fclose(fdat);	
}
