#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Headers/afficherEcranPrincipal.h"
#include "Headers/afficherGestionPersonnel.h"
#include "Headers/afficherMenu.h"
#include "Headers/afficherServices.h"
#include "Headers/afficherTables.h"

#include "Headers/ajouterMenu.h"
#include "Headers/ajouterTable.h"

#include "Headers/recupMenu.h"
#include "Headers/recupTables.h"

#include "Headers/supprimerMenu.h"
#include "Headers/supprimerTable.h"

main() {
	// Param�tre Fen�tre
		system("title Gestion Restaurant");	// D�fini un titre � ma fen�tre
		system("mode con: cols=110 lines=40"); // D�fini la taille de ma fen�tre	
	// Fin Param�tre Fen�tre
	
	int choix=0;
	int choixGestionPersonnel=0;
	int choixServices=0;
	int choixMenu=0;
	int choixTables=0;
	
	while(1) { // Ecran Principal
		system("cls");	
		afficherEcranPrincipal();	
		scanf("%d", &choix);			
		
		switch(choix) {
			case 1: // Gestion du personnel
				while(1) {
					system("cls");	
					afficherGestionPersonnel();
					scanf("%d", &choixGestionPersonnel);
					if(choixGestionPersonnel==0) break;
				}			
				break;
				
			case 2: // Services
				while(1) {
					system("cls");	
					afficherServices();
					scanf("%d", &choixServices);
					switch(choixServices) {
						case 1:
							break;
						case 2:
							break;
						case 3:
							break;
						case 4: // Services -> 4. Gestion des tables
							while(1) {
								system("cls");
								afficherTables();
								scanf("%d", &choixTables);
								switch(choixTables) {
									case 1: // ajouter Table
										system("cls");
										ajouterTable();
										break;
									case 2: // supprimer Table
										system("cls");
										supprimerTable();
										break;
								}
								if(choixTables==0) break;
							}
							break;
						case 5: // Services -> 5. Gestion du menu
							while(1) {
								system("cls");
								afficherMenu();
								scanf("%d", &choixMenu);
								switch(choixMenu) {
									case 1: // ajouter Menu
										system("cls");
										ajouterMenu();
										break;
									case 2: // supprimer Menu
										system("cls");
										supprimerMenu();
										break;
								}
								if(choixMenu==0) break;
							}						
							break;	
					}
					if(choixServices==0) break;
				}
				break;
		}
		if(choix==0) break;
	}
	
}