
#include <stdlib.h>
#include <stdio.h>

void triee( int indice_debut , int indice_fin , int T[1000])
{
  
 int indice ;   
 int Min=T[indice_debut] ; 
  for(int x=indice_debut ; x <indice_fin+1 ;x++)
   {
    
     for (int i = x; i < indice_fin+1; i++)
     {
        
        if(T[i]<=Min)
        { 
         Min=T[i] ;
         indice=i ;

         } 
    
   }
    int C ; 
    C=T[indice];
   T[indice]=T[x] ;
   T[x]=Min ;
   
   Min=T[x+1] ;
}   
}
int main()
 {
    int tailleD ,tailleG  ;
    int T[1000] ;
    int n=10;
    printf("entre la taille de l indice gauche \n") ;
    scanf("%d",&tailleG) ;
    printf("entre la taille de l indice droite \n") ;
    scanf("%d",&tailleD) ;
    for ( int i = 0; i < n ; i++)
    {
        T[i]=10-i ;
    }

     triee(tailleG,tailleD,T);
     for (int  i = 0; i < n; i++)
     {
        printf("|%d|",T[i]) ;
     }
  return 0 ;   
 }
