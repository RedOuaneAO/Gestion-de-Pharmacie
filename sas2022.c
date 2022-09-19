#include <stdio.h>
#include <stdlib.h>
struct product {
	char prodName[30];
	char prodCode[20];
	int prodQuantity;
	float price;
};


static int nbr;
static struct product prd[200];
static int i;
void insertInto(int n){
     printf("saisir nomber de produit:");
     scanf("%d",&n);
	for (i=0;i<n;i++){
	    printf("le produit nomber %d :\n",i+1);
		printf("saisir le nome de produit :");
		scanf("%s",&prd[nbr].prodName);
		printf("saisir le code de produit :");
		scanf("%s",&prd[nbr].prodCode);
		printf("saisir la quantite de produit :");
		scanf("%d",&prd[nbr].prodQuantity);
		printf("saisir le prix de produit :");
		scanf("%f",&prd[nbr].price);
		nbr++;
	}
}
void printProd(){
	for(i=0;i<nbr;i++){
	    printf("le produit nomber %d :\n",i+1);
		printf("nome de produit :%s\n",prd[i].prodName);
		printf("code de produit :%s\n",prd[i].prodCode);
		printf("quantite de produit :%d\n",prd[i].prodQuantity);
		printf("prix de produit :%.3f\n",prd[i].price);
	}
}
void listProdby(){
    
}
int main(){

			insertInto(1);
			printProd();
	
	


}
