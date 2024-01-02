#include "raylib.h"
#include <stdio.h>
#include <math.h>
  
int main(int argc, char* argv[]) {
    // Initialization
    const int screenWidth = 1280;
    const int screenHeight = 720;
    int i=5;
    int x=0;
    char text[20];
    //int poscx; //position case en x
    //sprintf(text, "%d", number); pour convertir d'un entier a une chaine de caractere
    int sizec,sizetext,poscx,poscy;
    InitWindow(screenWidth, screenHeight, "Hello, Raylib!");
    //on fait un tableau 
int n=15;
typedef struct ncase{
int val;
Rectangle box;
int speedx;
int speedy;
bool existe;
int ligne;
}ncase;
ncase C[n];



//Tableau Gauche
int mglo=n/2;
int  m;
int NbrDeSousTableau;
if(n%2==0) NbrDeSousTableau=log2(n);
else{NbrDeSousTableau=log2(n)+1;}
ncase G[NbrDeSousTableau][mglo];
ncase D[NbrDeSousTableau][n-mglo];

void Afficher(int LeIDebut,int Taille,int Milleu,int index,ncase D[index][Milleu]){
for(int i=LeIDebut ; i<Taille ; i++){
     int sizec=D[index][i-LeIDebut].box.height;
 DrawRectangleRec(D[index][i-LeIDebut].box,RED); //une case 
 sprintf(text, "%d", D[index][i-LeIDebut].val);
 DrawText(text,D[index][i-LeIDebut].box.x  + MeasureText(text,sizetext),D[index][i-LeIDebut].box.y + sizec/2 - sizetext/2 ,sizetext, WHITE);}}

for(int j=0 ; j<n ; j++){
    C[j].box.height=50;
    C[j].box.width=50;
    C[j].box.x=(screenWidth/(n))*(j+1)-(C[j].box.width+C[j].box.width/4);
    C[j].box.y=screenHeight/2-C[j].box.height;
    C[j].val=j;
    C[j].existe=false;
    C[j].ligne=0;
    printf(" | %d | ",C[j].val);
    }
  SetTargetFPS(60);  



int index=0;
for(index = 0 ; index<NbrDeSousTableau ; index++ )
{       for(int z=0; z<mglo ; z++){
    G[index][z]=C[z];
if(index==0) {G[index][z].box.y=50;}
else{G[index][z].box.y=50*((index+1)*2);}
}
        for(int z=mglo; z<n ; z++){
    D[index][z-mglo]=C[z];
 if(index==0)  {D[index][z-mglo].box.y=50;}
 else{D[index][z-mglo].box.y=50*(index*3)+50;}
 }}
index = 1;
int indexvar =1;

bool Animation=false;
bool Animation2=false;
bool Animation3=false;
bool Replacement=false;
bool Affichage=false;
bool Text=false;

    // Main game loop
    while (!WindowShouldClose()) {

  
// Draw -----------------------------------------------------------------------------------------------------------
// Draw -----------------------------------------------------------------------------------------------------------
// Draw -----------------------------------------------------------------------------------------------------------
// Draw -----------------------------------------------------------------------------------------------------------
// Draw
        BeginDrawing();
        ClearBackground(BLACK);
   for(int j=0 ; j<n ; j++){
    poscx= C[j].box.x;
    poscy=C[j].box.y;
    sizec=C[j].box.height;
    sizetext=20;          
        DrawRectangleRec(C[j].box,BLUE); //une case 
        sprintf(text, "%d", C[j].val);
    DrawText(text,poscx + MeasureText(text,sizetext) ,poscy + sizec/2 - sizetext/2 ,sizetext, WHITE);}
//FIRST SPLIT-----------------------------------------------------------------------------------------------
for(int j=0 ; j<mglo;j++){
if(G[0][j].existe) {
//Afficher(0,mglo,mglo,0,G);
 DrawRectangleRec(G[0][j].box,RED); //une case 
        sprintf(text, "%d", G[0][j].val);
    DrawText(text,G[0][j].box.x + MeasureText(text,sizetext) ,G[0][j].box.y + sizec/2 - sizetext/2 ,sizetext, WHITE);}

for(int j=mglo; j<n ; j++){
 if(D[0][j-mglo].existe) {
//Afficher(mglo,n,mglo,0,D); 
DrawRectangleRec(D[0][j-mglo].box,RED); //une case 
        sprintf(text, "%d", D[0][j-mglo].val);
    DrawText(text,D[0][j-mglo].box.x + MeasureText(text,sizetext) ,D[0][j-mglo].box.y + sizec/2 - sizetext/2 ,sizetext, WHITE);}  }
}
//SECOND SPLIT---------------------------------------------
for(int j=0 ; j<mglo/((index)*2) ; j++){
    if(G[index][j].existe){
Afficher(0,mglo/((index)*2),mglo,index,G);
}}
for(int j=mglo/((index)*2); j<mglo ; j++){ //peut etre probleme
if(G[index][j].existe){
 DrawRectangleRec(G[index][j].box,RED); //une case 
        sprintf(text, "%d", G[index][j].val);
    DrawText(text,G[index][j].box.x + MeasureText(text,sizetext) ,G[index][j].box.y + sizec/2 - sizetext/2 ,sizetext, WHITE);}
}
for(int j=0 ; j<mglo/((index)*2) ; j++){
    if(D[index][j].existe){
 DrawRectangleRec(D[index][j].box,RED); //une case 
    sprintf(text, "%d", D[index][j].val);    
    DrawText(text,D[index][j].box.x + MeasureText(text,sizetext) ,D[index][j].box.y + sizec/2 - sizetext/2 ,sizetext, WHITE);
}}
for(int j=mglo/((index)*2); j<mglo ; j++){ //peut etre probleme
if(D[index][j].existe){
 DrawRectangleRec(D[index][j].box,RED); //une case 
    sprintf(text, "%d", D[index][j].val);    
    DrawText(text,D[index][j].box.x + MeasureText(text,sizetext) ,D[index][j].box.y + sizec/2 - sizetext/2 ,sizetext, WHITE);}
}
//---------------------------------------------
//OTHER SPLITS---------------------------------
for(int j=0 ; j<mglo/((indexvar)*2);j++)
{ if(G[indexvar][j].existe){
DrawRectangleRec(G[indexvar][j].box,RED); //une case 
        sprintf(text, "%d", G[indexvar][j].val);
    DrawText(text,G[indexvar][j].box.x + MeasureText(text,sizetext) ,G[indexvar][j].box.y + sizec/2 - sizetext/2 ,sizetext, WHITE);}
//------------------------------------------------------------------------------------------------
 if(D[indexvar][j].existe){ DrawRectangleRec(D[indexvar][j].box,RED); //une case 
        sprintf(text, "%d", D[indexvar][j].val);
    DrawText(text,D[indexvar][j].box.x + MeasureText(text,sizetext) ,D[indexvar][j].box.y + sizec/2 - sizetext/2 ,sizetext, WHITE); }}
for(int j=mglo/((indexvar)*2) ; j<mglo/((index)*2) ;j++)
{ if(G[indexvar][j].existe){
    DrawRectangleRec(G[indexvar][j].box,RED); //une case 
        sprintf(text, "%d", G[indexvar][j].val);
    DrawText(text,G[indexvar][j].box.x + MeasureText(text,sizetext) ,G[indexvar][j].box.y + sizec/2 - sizetext/2 ,sizetext, WHITE);}
    //-----------------------------------------------------------------------------------------------------------------------------------
    if(D[indexvar][j].existe){ DrawRectangleRec(D[indexvar][j].box,RED); //une case 
        sprintf(text, "%d", D[indexvar][j].val);
    DrawText(text,D[indexvar][j].box.x + MeasureText(text,sizetext) ,D[indexvar][j].box.y + sizec/2 - sizetext/2 ,sizetext, WHITE); }
    //-----------------------------------------------------------------------------------------------------------------------------------
}
for(int j=mglo/((index)*2) ; j<(3*mglo)/((indexvar)*2) ;j++)
    { if(G[indexvar][j].existe){
    DrawRectangleRec(G[indexvar][j].box,RED); //une case 
        sprintf(text, "%d", G[indexvar][j].val);
    DrawText(text,G[indexvar][j].box.x + MeasureText(text,sizetext) ,G[indexvar][j].box.y + sizec/2 - sizetext/2 ,sizetext, WHITE);}
        //-----------------------------------------------------------------------------------------------------------------------------------
    if(D[indexvar][j].existe){ DrawRectangleRec(D[indexvar][j].box,RED); //une case 
        sprintf(text, "%d", D[indexvar][j].val);
    DrawText(text,D[indexvar][j].box.x + MeasureText(text,sizetext) ,D[indexvar][j].box.y + sizec/2 - sizetext/2 ,sizetext, WHITE); }
    //-----------------------------------------------------------------------------------------------------------------------------------
}
for(int j=(3*mglo)/((indexvar)*2); j<mglo ;j++){
    if(G[indexvar][j].existe){
    DrawRectangleRec(G[indexvar][j].box,RED); //une case 
        sprintf(text, "%d", G[indexvar][j].val);
    DrawText(text,G[indexvar][j].box.x + MeasureText(text,sizetext) ,G[indexvar][j].box.y + sizec/2 - sizetext/2 ,sizetext, WHITE);}
    //-----------------------------------------------------------------------------------------------------------------------------------
    if(D[indexvar][j].existe){ DrawRectangleRec(D[indexvar][j].box,RED); //une case 
        sprintf(text, "%d", D[indexvar][j].val);
    DrawText(text,D[indexvar][j].box.x + MeasureText(text,sizetext) ,D[indexvar][j].box.y + sizec/2 - sizetext/2 ,sizetext, WHITE); }
    //-----------------------------------------------------------------------------------------------------------------------------------
}
// Draw -----------------------------------------------------------------------------------------------------------
// Draw -----------------------------------------------------------------------------------------------------------
// Draw -----------------------------------------------------------------------------------------------------------
// Draw -----------------------------------------------------------------------------------------------------------
// Draw -----------------------------------------------------------------------------------------------------------
// Draw -----------------------------------------------------------------------------------------------------------


  sizec=50;
    if(!Text) DrawText("Press SPACE",GetScreenWidth()/2-150,GetScreenHeight()/2-100,30,WHITE);
    if(IsKeyPressed(KEY_SPACE)){Replacement = true; Text=true;}
    if(Replacement){for(int j=0 ; j<n;j++){
C[j].speedy=2+i;
C[j].box.y-=C[j].speedy;
if(C[j].box.y <= 50){C[j].speedy=0; Replacement=false; Animation=true;}


    }}
 if(Animation){ 
for(int j=0 ; j<mglo;j++){
G[0][j].speedx=2;
G[0][j].speedy=2;
G[0][j].box.x-=G[0][j].speedx;
G[0][j].box.y+=G[0][j].speedy;
G[0][j].existe=true;

if(G[0][j].box.y >= 200) {G[0][j].speedy = 0; Animation=false; Animation2=true; }
}

for(int j=mglo; j<n ; j++){
D[0][j-mglo].speedx=2;
D[0][j-mglo].speedy=2;
D[0][j-mglo].box.x+=D[0][j-mglo].speedx;
D[0][j-mglo].box.y+=D[0][j-mglo].speedy;
D[0][j-mglo].existe=true;

} 

}

if(Animation2){
int m=mglo/((indexvar)*2);
 
for(int j=0 ; j<m ; j++){
G[indexvar][j].speedx=2*(indexvar+1);
G[indexvar][j].speedy=2*(indexvar+1);;
G[indexvar][j].box.x-=G[indexvar][j].speedx;
G[indexvar][j].box.y+=G[indexvar][j].speedy;
G[indexvar][j].existe=true;
G[indexvar][j].ligne=index;

if(G[indexvar][j].box.y >= 50*((indexvar+1)*3)+50) {G[indexvar][j].speedy = 0; Animation2=false; Animation3=true;}
}

for(int j=m; j<mglo ; j++){ //peut etre probleme
G[indexvar][j].speedx=1.2*(indexvar+1);
G[indexvar][j].speedy=2*(indexvar+1);
G[indexvar][j].box.x-=G[indexvar][j].speedx;
G[indexvar][j].box.y+=G[indexvar][j].speedy;
G[indexvar][j].existe=true;


} 
for(int j=0 ; j<m ; j++){
D[indexvar][j].speedx=1.2*(indexvar+1);
D[indexvar][j].speedy=2*(indexvar+1);;
D[indexvar][j].box.x+=D[indexvar][j].speedx;
D[indexvar][j].box.y+=D[indexvar][j].speedy;
D[indexvar][j].existe=true;

}
for(int j=m; j<mglo ; j++){ //peut etre probleme
D[indexvar][j].speedx=2*(indexvar+1);
D[indexvar][j].speedy=2*(indexvar+1);
D[indexvar][j].box.x+=D[indexvar][j].speedx;
D[indexvar][j].box.y+=D[indexvar][j].speedy;
D[indexvar][j].existe=true;
}

}


if (Animation3 ) { indexvar=2;
for(int j=0 ; j<mglo/((indexvar)*2);j++){
G[indexvar][j].speedx=2*(indexvar+1);
G[indexvar][j].speedy=2*(indexvar+1);;
G[indexvar][j].box.x-=G[indexvar][j].speedx;
G[indexvar][j].box.y+=G[indexvar][j].speedy;
G[indexvar][j].existe=true;
G[indexvar][j].ligne=index;
//---------------------------------
D[indexvar][j].speedx=1.10*(indexvar+1);
D[indexvar][j].speedy=1.7*(indexvar+1);
D[indexvar][j].box.x+=D[indexvar][j].speedx;
D[indexvar][j].box.y=G[indexvar][j].box.y;
D[indexvar][j].existe=true;
//--------------------------------------
if(G[indexvar][j].box.y >= 50*((indexvar+1)*3)+50){G[indexvar][j].speedy = 0; Animation3=false;}
}

for(int j=mglo/((indexvar)*2) ; j<mglo/((index)*2) ;j++){   
G[indexvar][j].speedx=1.2*(indexvar+1);
G[indexvar][j].speedy=2*(indexvar+1);
G[indexvar][j].box.x-=G[indexvar][j].speedx;
G[indexvar][j].box.y+=G[indexvar][j].speedy;
G[indexvar][j].existe=true;
//---------------------------------
D[indexvar][j].speedx=1.5*(indexvar+1);
D[indexvar][j].speedy=1.7*(indexvar+1);
D[indexvar][j].box.x+=D[indexvar][j].speedx;
D[indexvar][j].box.y=G[indexvar][j].box.y;
D[indexvar][j].existe=true;
//--------------------------------------
}

for(int j=mglo/((index)*2) ; j<(3*mglo)/((indexvar)*2) ;j++){
G[indexvar][j].speedx=0.5*(indexvar+1);
G[indexvar][j].speedy=2*(indexvar+1);
G[indexvar][j].box.x-=G[indexvar][j].speedx;
G[indexvar][j].box.y+=G[indexvar][j].speedy;
G[indexvar][j].existe=true;
//--------------------------------------
D[indexvar][j].speedx=1.8*(indexvar+1);
D[indexvar][j].speedy=2*(indexvar+1);
D[indexvar][j].box.x+=D[indexvar][j].speedx;
D[indexvar][j].box.y=G[indexvar][j].box.y;
D[indexvar][j].existe=true;
//--------------------------------------

}
for(int j=(3*mglo)/((indexvar)*2); j<mglo ;j++){
G[indexvar][j].speedx=0.15*(indexvar+1);
G[indexvar][j].speedy=2*(indexvar+1);
G[indexvar][j].box.x+=G[indexvar][j].speedx;
G[indexvar][j].box.y+=G[indexvar][j].speedy;
G[indexvar][j].existe=true;
//--------------------------------------
D[indexvar][j].speedx=2*(indexvar+1);
D[indexvar][j].speedy=2.2*(indexvar+1);
D[indexvar][j].box.x+=D[indexvar][j].speedx;
D[indexvar][j].box.y=G[indexvar][j].box.y;
D[indexvar][j].existe=true;
//--------------------------------------
}
}




        EndDrawing();
    }
    CloseWindow();

    return 0;
}
//gcc -I src/include -L src/lib -o tableaucase tableau.c -lraylib -lopengl32 -lgdi32 -lwinmm
//C:\Users\cephu\OneDrive\Documents\DEV VSC\RAYLIB
