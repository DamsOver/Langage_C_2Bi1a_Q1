#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../Headers/structures.h"

int compterMenu() { //Compte le nombre de menus
	FILE *fdat;
	fdat = fopen("Data/Menu.dat", "r");	

	int n=0, i, j, fichierVide;	

	Menu *deb, *courant, *suivant;
	courant=malloc(sizeof(Menu));
	deb=courant;

	// Lecture + Construction de ma liste chain�e
	while(!feof(fdat)) {
		fichierVide = fscanf(fdat,"%s",&courant->nom);
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
	
	free(courant);
	free(suivant);	
	fclose(fdat);
	if(fichierVide==-1) {
		return 0;
	}
	return n;
}

int compterTable() { //compte le nombre de tables
	int n=0, i, fichierVide;
	FILE *fdat;
	fdat = fopen("Data/Table.dat", "r");

	Table *deb, *courant, *suivant;
	courant=malloc(sizeof(Table));
	deb=courant;

	// Lecture + Construction de ma liste chain�e
	while(!feof(fdat)) {
		
		fichierVide = fscanf(fdat,"%d",&courant->estReserveMatin);
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
	
	free(courant);
	free(suivant);	
	fclose(fdat);
	if(fichierVide==-1) {
		return 0;
	}
	
	return n;
}

int compterTableReservMatin() { //compte le nombre de tables
	int n=0, i, fichierVide, nMatin=0;
	FILE *fdat;
	fdat = fopen("Data/Table.dat", "r");

	Table *deb, *courant, *suivant;
	courant=malloc(sizeof(Table));
	deb=courant;

	// Lecture + Construction de ma liste chain�e
	while(!feof(fdat)) {
		
		fichierVide = fscanf(fdat,"%d",&courant->estReserveMatin);
		if(courant->estReserveMatin == 1) {
			fscanf(fdat,"%s",&courant->nomMatin);
			fscanf(fdat,"%d",&courant->nbPersonneMatin);
			fscanf(fdat,"%d",&courant->numMenuMatin);
			nMatin++;
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
	
	free(courant);
	free(suivant);	
	fclose(fdat);
	if(fichierVide==-1) {
		return 0;
	}
	
	return nMatin;
}

int compterTableReservSoir() { //compte le nombre de tables
	int n=0, i, fichierVide, nSoir=0;
	FILE *fdat;
	fdat = fopen("Data/Table.dat", "r");

	Table *deb, *courant, *suivant;
	courant=malloc(sizeof(Table));
	deb=courant;

	// Lecture + Construction de ma liste chain�e
	while(!feof(fdat)) {
		
		fichierVide = fscanf(fdat,"%d",&courant->estReserveMatin);
		if(courant->estReserveMatin == 1) {
			fscanf(fdat,"%s",&courant->nomMatin);
			fscanf(fdat,"%d",&courant->nbPersonneMatin);
			fscanf(fdat,"%d",&courant->numMenuMatin);
			nSoir++;
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
	
	free(courant);
	free(suivant);	
	fclose(fdat);
	if(fichierVide==-1) {
		return 0;
	}
	
	return nSoir;
}


int compterEmploye() {
	int n=0, i, j, fichierVide;
	FILE *fdat;
	fdat = fopen("Data/Employes.dat", "r");

	Employe *deb, *courant, *suivant;
	courant=malloc(sizeof(Employe));
	deb=courant;

	// Lecture + Construction de ma liste chain�e
	while(!feof(fdat)) {
		fichierVide = fscanf(fdat,"%s",&courant->nom);
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
	
	free(courant);
	free(suivant);	
	fclose(fdat);	
	if(fichierVide==-1) {
		return 0;
	}
	return n;
}
