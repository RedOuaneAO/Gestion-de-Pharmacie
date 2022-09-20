#include <stdio.h>
#include <stdlib.h>

//struct section
struct product{
	char code[20];
	char nom[20];
    float prix;
	int quantity;

};
//static variable
static struct product prd[200];
static int count=0;
//fuction section
void menu(){             //menu
	int choix , prodNmb , choiceNum;
	printf("#################################################################\n");
	printf("##                  pharmacy System Management                 ##\n");
	printf("#################################################################\n\n");
	printf("             choice one of the following options :\n\n");
	printf("1: ajouter des produit         :\n");
	printf("2: lister les produit          :\n");
	printf("3:enregistrer des vent         :\n");
	printf("4:rechercher les produit       :\n");
	printf("5:Etat de stock                :\n");
	printf("6:Alimenter le stock           :\n");
	printf("7:supprimer les produit        :\n");
	printf("8:Statistique de vente         :\n");
	printf("------------------------------------------------------------------\n");
	printf("    saisir votre choix :\n");
	scanf("%d",&choix);
	switch(choix){
		case 1 :
 			// system("cls"); //to clear the terminal
			printf("      choice  what you want\n");
			printf("1: ajouter un produit.\n");
			printf("2: ajouter plusieur produiut\n");
			scanf("%d",&choiceNum);
			if(choiceNum==1){
			  	ajoutProd(1);
			}else if(choiceNum>1){
			printf("saisir le nomber de produit:\n");
			scanf("%d",&prodNmb);
			ajoutProd(prodNmb);
			}
			menu();
			break;
		case 2:
			printf("      choice  what you want\n");
			printf("1: lister par prix.\n");
			printf("2: lister par alphabe\n");
			scanf("%d",&choiceNum);
			if(choiceNum==1){
			    listParPrix();
			}else if(choiceNum==2){
			    listParNom();
			}
		

	}
}
void listParPrix(){         //listing by price
    int i, j, tmp;
    struct product copy[count];
    for(i=0;i<count;i++){
        for(j= i + 1;j<count;j++){
            if(prd[i].prix<prd[j].prix){
                //NAME
                strcpy(copy[i].nom,prd[i].nom);
                strcpy(prd[i].nom,prd[j].nom);
                strcpy(prd[j].nom,copy[i].nom);
                //code
                strcpy(copy[i].code,prd[i].code);
                strcpy(prd[i].code,prd[j].code);
                strcpy(prd[j].code,copy[i].code);
            // QUANTITY
                copy[i].quantity=prd[i].quantity;
                prd[i].quantity=prd[j].quantity;
                prd[j].quantity=copy[i].quantity;
                
                tmp=prd[i].prix;
                prd[i].prix=prd[j].prix;
                prd[j].prix=tmp;
            
            }
        }
    }
    printf("-----------------------------------\n");
    printf("Code       |  Name      |  Price      |    QuantitY\n");
    for(i=0; i <count; i++){
    
    printf("      %s     |  %s        |   %.2f        | %d     \n",prd[i].code,prd[i].nom,prd[i].prix,prd[i].quantity);
    
    }
    }

void listParNom(){
    struct product copy[count];
    int i,j;
    for(i=0;i<count;i++){
        for(j=i+1;j<count;j++){
            if(strcmp(prd[i].nom,prd[j].nom)>0){
                //NOM
                strcpy(copy[i].nom,prd[i].nom);
                strcpy(prd[i].nom,prd[j].nom);
                strcpy(prd[j].nom,copy[i].nom);
                 //code
                strcpy(copy[i].code,prd[i].code);
                strcpy(prd[i].code,prd[j].code);
                strcpy(prd[j].code,copy[i].code);
                // QUANTITY
                copy[i].quantity=prd[i].quantity;
                prd[i].quantity=prd[j].quantity;
                prd[j].quantity=copy[i].quantity;
                //PRICE
                copy[i].prix=prd[i].prix;
                prd[i].prix=prd[j].prix;
                prd[j].prix=copy[i].prix;
            }
        }
    }
      printf("-----------------------------------\n");
    printf("Code       |  Name      |  Price      |    QuantitY\n");
    for(i=0; i <count; i++){
    
    printf("      %s     |  %s        |   %.2f        | %d     \n",prd[i].code,prd[i].nom,prd[i].prix,prd[i].quantity);
    
    }
  }


void ajoutProd(int prodNum){  //ajouter produit
//  	system("cls");
	int i;
	for(i=0;i<prodNum;i++){
		printf("product nomber %d\n",i+1);
		printf("enter the code of the product: \n");
		scanf("%s",&prd[count].code);
		printf("enter the name of the product: \n");
		scanf("%s",&prd[count].nom);
		printf("enter the quantity of the product: \n");
		scanf("%d",&prd[count].quantity);
		printf("enter the price of the product: \n");
		scanf("%f",&prd[count].prix);
		count++;
	}
}

int main(int argc, char *argv[]) {
	menu();
	return 0;
}
