#include "raylib.h"
#include <stdio.h>

/*void AfficherCaseTab(int *T,int sizec,int sizetext,int poscx,int poscy,int screenWidth,int screenHeight,char *text){
for(int j=0 ; j<10 ; j++){
 poscx=(screenWidth/(10))*(j+1)-(sizec+sizec/4);
            poscy=screenHeight/2-50;
            sizec=50;
            sizetext=20;           
        DrawRectangle(poscx,poscy,sizec,sizec,BLUE); //une case 
        sprintf(text, "%d", T[j]);
    DrawText(text,poscx + MeasureText(text,sizetext) ,poscy + sizec/2 - sizetext/2 ,sizetext, WHITE);}}*/

    



int main(int argc, char* argv[]) {
    // Initialization
    const int screenWidth = 800;
    const int screenHeight = 450;
    int i=5;
    int x=0;
    char text[20];
    //int poscx; //position case en x
    //sprintf(text, "%d", number); pour convertir d'un entier a une chaine de caractere
    int sizec,sizetext,poscx,poscy;
    InitWindow(screenWidth, screenHeight, "Hello, Raylib!");
    int T[10];
    //on fait un tableau 
for(int j=0 ; j<10 ; j++){
    T[j]=j;
    printf(" | %d | ",T[j]);
    SetTargetFPS(60);
    




}

    // Main game loop
    while (!WindowShouldClose()) {


        // Draw
        BeginDrawing();
        ClearBackground(BLACK);
        DrawRectangle(x-50,0,50,50,GRAY);
        DrawRectangle(screenWidth-x-50,0,50,50,GREEN);
   // AfficherCaseTab(T,poscx,poscy,sizec,sizec,screenWidth,screenHeight,text); FONCTION FAIL 
   for(int j=0 ; j<10 ; j++){
 poscx=(screenWidth/(10))*(j+1)-(sizec+sizec/4);
            poscy=screenHeight/2-50;
            sizec=50;
            sizetext=20;           
        DrawRectangle(poscx,poscy,sizec,sizec,BLUE); //une case 
        sprintf(text, "%d", T[j]);
    DrawText(text,poscx + MeasureText(text,sizetext) ,poscy + sizec/2 - sizetext/2 ,sizetext, WHITE);}   
        
        x+=i;
        if(x==screenWidth/2){DrawRectangle(screenWidth/2-50,0,50,50,ORANGE);
      
                           i=0; }
    
        EndDrawing();
    }

    // De-Initialization
    CloseWindow();

    return 0;
}
//gcc -I src/include -L src/lib -o tableau tableau.c -lraylib -lopengl32 -lgdi32 -lwinmm
//C:\Users\cephu\OneDrive\Documents\DEV VSC\RAYLIB