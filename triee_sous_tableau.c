
#include <stdlib.h>
#include <stdio.h>


int* triee(int D[100] ,int G[100] ,int tailleD , int tailleG )
{
  int i=0 ;
  int j=0 ;
  int  S=tailleD+tailleG ;
   int*T = (int*)malloc( S* sizeof(int));
   
  for(int x=0 ; x<S ;x++)
    {
     if(i<=tailleD && j<=tailleG)
        {        
      if (D[i]<=G[j])
        {
          T[x]=D[i] ;
          i++ ;       
        }
       else
        {
           T[x]=G[j] ;
           j++ ;
        } 
        }
     else if(i>tailleD)
     {
       T[x]=G[j] ;
       j++ ;
     }
    else if(j>tailleG)
     {
       T[x]=D[i] ;
       i++ ;
     }
        
        
    }
   return T ; 
  
}
// test 
int main()
 {
    int tailleD ,tailleG  ;
    int G[1000] ;
    int D[1000] ;
    printf("entre la taille du tableau gauche \n") ;
    scanf("%d",&tailleG) ;
    printf("entre la taille du tableau droite \n") ;
    scanf("%d",&tailleD) ;
    for ( int i = 0; i < tailleD ; i++)
    {
        D[i]=i ;
    }
    for (int  i = 0; i < tailleG; i++)
    {
        G[i]=i ;
    }
    
    int* monTableau = triee(D,G,tailleD,tailleG);
     for (int  i = 0; i < tailleD+tailleG; i++)
     {
        printf("|%d|",monTableau[i]) ;
     }
  return 0 ;   
 }


