#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//###############################################################  struct section  ###################################################################
struct product{
	char code[20];
	char nom[20];
    float prix;
	int quantity;

};
//####################################################################  static variable  #############################################################


static struct product prd[200];                 //where we stock product
 int count=0;                              //how many product we added

//#################################################################  fuction section  ################################################################

 //------------------------------------------------------------------  Menu  -------------------------------------------------------------------------------
 
void menu(){            
	int choice , prodNmb , choiceNum;
	printf("#################################################################\n");
	printf("##                  pharmacy System Management                 ##\n");
	printf("#################################################################\n\n");
	printf("             choice one of the following options :\n\n");
	printf("                 __________________________________\n");
	printf("                | 1: ajouter des produit         : |\n");
	printf("                | 2: lister les produit          : |\n");
	printf("                | 3:enregistrer des vent         : |\n");
	printf("                | 4:rechercher les produit       : |\n");
	printf("                | 5:Etat de stock                : |\n");
	printf("                | 6:Alimenter le stock           : |\n");
	printf("                | 7:supprimer les produit        : |\n");
	printf("                | 8:Statistique de vente         : |\n");
	printf("------------------------------------------------------------------\n");
	printf("    saisir votre choix :\n");
	scanf("%d",&choice);
	switch(choice){
		case 1 :
 			// system("cls"); //to clear the terminal
			printf("      choice  what you want\n");
			printf("1: ajouter un produit.\n");
			printf("2: ajouter plusieur produit\n");
			scanf("%d",&choiceNum);
			if(choiceNum==1){
			  	addProd(1);
			}else if(choiceNum==2){
			printf("saisir le nomber de produit:\n");
			scanf("%d",&prodNmb);
			addProd(prodNmb);
			}else{
				menu();
			}
			afficher();
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
			}else{
				menu();
			}
			menu();
			break;
		case 3:
			acheterPrd();
			afficher();
			menu();
        case 4:
            	printf("      choice  what you want\n");
			printf("1: search by code\n");
			printf("2: search by quantity \n");
			scanf("%d",&choiceNum);
			if(choiceNum==1){
			    SearchByCode();
			}else if(choiceNum==2){
			    SearchByQuantity();
			}else{
				menu();
			}
            menu();
            break;
        case 5:
		    stockStatus();
		    menu();
		    break;
		case 6:
		stockSupply(); 
		menu();
		break;
		case 7 :
		deletProd();
		afficher();
		menu();
	}
}
//------------------------------------------------------------------------afficher function-------------------------------------------------------------------


void afficher(){
	int i;
		printf("-----------------------------------\n");
    printf("Code          |  Name        |  Price        |     Quantity\n");
    for(i=0; i<count; i++){
    
    printf("      %s     |  %s        |   %.2f        | %d     \n",prd[i].code,prd[i].nom,prd[i].prix,prd[i].quantity);
    
    }
}


//------------------------------------------------------------------listing by price----------------------------------------------------------------------------

void listParPrix(){                                                      
    struct product copy[count];
	int i, j;
	for(i = 0; i < count; i++){
		for(j = i+1; j < count; j++){
			if(prd[i].prix < prd[j].prix){
				copy[i]= prd[j];
				prd[j] = prd[i];
				prd[i] = copy[i];
			}
		}
	}
	printf("-----------------------------------\n");
    printf("Code          |  Name        |  Price        |     QuantitY\n");
    for(i=0; i<count; i++){
    
    printf("      %s     |  %s        |   %.2f        | %d     \n",prd[i].code,prd[i].nom,prd[i].prix,prd[i].quantity);
    
    }
	
}


 // ------------------------------------------------------------------ listing by name :---------------------------------------------------------------------
 
void listParNom(){                                                    
   struct product copy[count];
    int i,j;
    
    for(i=0;i<count;i++){
    	
        for(j=i+1;j<count;j++){
        if(strcmp(prd[i].nom,prd[j].nom)>0)
			{
              copy[i]=prd[i];
              prd[i]=prd[j];
              prd[j]=copy[i];
            }
    	}
	}
	printf("-----------------------------------\n");
    printf("Code       |  Name      |  Price      |    QuantitY\n");
    for(i=0; i <count; i++){
    printf("      %s     |  %s        |   %.2f        | %d     \n",prd[i].code,prd[i].nom,prd[i].prix,prd[i].quantity);
    
    }
}


// --------------------------------------------------------------------add product------------------------------------------------------------------------------//

void addProd(int prodNum){  
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
//------------------------------------------------------------------acheterPrd-------------------------------------------------------------------------------------//


void acheterPrd(){
//    system("cls");
    printf("#=#=#=#=#=#=#=#=#=#=# sell a new product #=#=#=#=#=#=#=#=#=#=#\n");
    int i;
    int test =0;
    char Code[20];
    printf("Enter the code of the product: ");
    scanf("%s",Code);
    for (i = 0; i < count; i++)
	{
        if ( strcmp(prd[i].code,Code) == 0 )
		{
		test=1;
                printf("name : %s \t code : %s\t quantity : %d \n", prd[i].nom,prd[i].code ,prd[i].quantity);
                int nmbQantity = 0;
                printf("Give the quantity you want to buy: ");
                scanf("%d", &nmbQantity);
                if ( nmbQantity <= prd[i].quantity)
				{
                    prd[i].quantity -= nmbQantity;    
				 	printf("name : %s \t code : %s\t quantity : %d \n", prd[i].nom,prd[i].code ,prd[i].quantity);
				 	
				 	
                }else{
                    printf("Quantity not avalaible\n");
                    
				}				
		}

    }
    
    if(test==0){
    		printf("The code you entered doesn't match any product\n");
	}
    	
	
    
}




// ----------------------------------------------------------------------- search for product-----------------------------------------------------------------//


void SearchByCode(){
    char pro_code[15];
    int i;
    printf("Enter the code of the product you want to search for:\t");
    scanf("%s",pro_code);
    for(i=0;i<count;i++){
    	
        if (strcmp(prd[i].code,pro_code)==0)
            {
                // system("cls");
                printf("exist\n");
                printf(" Code : %s \tName: %s\t Quantity : %d Price : \t %.2f Dh  PriceTVA : %.2f Dh\n",prd[i].code,prd[i].nom,prd[i].quantity,prd[i].prix,(prd[i].prix+(prd[i].prix*0.15)));
                return;
            }
        }
        printf("This product doesn't exist'\n");
}



void SearchByQuantity(){
int	prdQuant , i;
printf("Enter the Quantity of the Product :\t");
scanf("%d",&prdQuant);
for(i=0;i<count;i++){
	if(prd[i].quantity==prdQuant){
		printf("name :%s\t code :%s\t quantity :%d\t price : %.2f",prd[i].nom,prd[i].code,prd[i].quantity,prd[i].prix);
		
	}else{
		printf("there is no product match");
	}
  }
}
//----------------------------------------------------------------statusOfTheStock------------------------------------------------------------------------------//

 void stockStatus(){
     int i;
     for(i=0;i<count;i++){
         if(prd[i].quantity<3)
         printf(" Code : %s \tName: %s\t Quantity : %d Price : \t %.2f Dh \n",prd[i].code,prd[i].nom,prd[i].quantity,prd[i].prix);
     }
}

//----------------------------------------------------  supply the stock ---------------------------------------------------------------//

void stockSupply(){
	    int i;
         char prdCodeAdd[15];
         int prdQuantityAdd;
         int test =0;
         printf("enter the code of the product :\t");
         scanf("%s",prdCodeAdd);
         
         for(i=0;i<count;i++){
         	
             if (strcmp(prd[i].code,prdCodeAdd)==0){
             	test=1;
                 printf("existe\n");
                 printf(" Code : %s \tName: %s\t Quantity : %d Price : \t %.2f Dh \n",prd[i].code,prd[i].nom,prd[i].quantity,prd[i].prix);
                 printf("enter the quantity of the product:\t");
                 scanf("%d",&prdQuantityAdd);
                 
                 prd[i].quantity += prdQuantityAdd;
                 printf(" Code : %s \tName: %s\t Quantity : %d Price : \t %.2f Dh \n",prd[i].code,prd[i].nom,prd[i].quantity,prd[i].prix);
             }
            
         }
         if(test==0)
          printf("the product doesn't exist\n");
 }
 
 //-----------------------------------------------------------delet a product -----------------------------------------------//
 
 void deletProd(){
 	char prdCode[20];
 	int i;
 	printf("enter the code of the product :\t");
 	scanf("%s",&prdCode);
 	for(i=0;i<count;i++){
 		if(strcmp(prd[i].code,prdCode)==0){
 			prd[i]=prd[i+1];
 			count--;
		 }
	 }
 }
 
 
int main(int argc, char *argv[]) {
	menu();
	return 0;
}

