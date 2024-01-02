#include "raylib.h"
#include <stdio.h>
#include <stdlib.h> 

typedef struct button button;
struct button{
    Rectangle rec;
    Color col;
};

void init_button(button *b,Rectangle r,Color c){
    b->rec=r;
    b->col=c;
}

bool mouseonbutton(button b){
    return CheckCollisionPointRec(GetMousePosition(),b.rec); //Check if point is inside rectangle
}

void BoutonFini(button button0,int width,int height,char* chaine){
    init_button(&button0 ,(Rectangle){width / 2 - 100, height / 4 -50 , 175 ,50},RED);
    if(mouseonbutton(button0)){
            button0.col=GREEN;
        }else{ button0.col=RED;} //Changement de couleur lors de l'approche d'une case par le curseur
     DrawRectangleRec(button0.rec,button0.col); //un des rectangles du menu
    DrawText(chaine,button0.rec.x + button0.rec.width / 2 - MeasureText(chaine,20) /2,button0.rec.y + button0.rec.height / 2 - 20 / 2,20, WHITE); // l'ecriture au dessus du texte
 


}

int main(int argc,char **argv){
    
    const int width = 1280;
    const int height = 720; //720p    
    char *title; //données initialiation taille fenetre
    Image icon = LoadImage("logospidey.png");//LOGO de l'image
button button0 = {0}; //le button
button button1 = {0};
button button2 = {0};
bool button0_clicked=false;

//Initialisation
//------------------------------------------------------------------------------------------------------------
    InitWindow(width,height,"MENU");
    SetWindowIcon(icon);
    SetTargetFPS(60);


//Initialisation du button
//------------------------------------------------------------------------------------------------------------
//init_button(&button0 ,(Rectangle){width / 2 - 100, height / 2 -50 , 200 ,100},RED);
//PROG
//-------------------------------------------------------------------------------------------------------------   
    while (!WindowShouldClose()) {
        ShowCursor();
        ClearBackground(BLACK);
         DrawText("MENU", width / 2 - 125, height / 4 -50 , 80, WHITE);
       BoutonFini(button0,width,(1.75)*height,"CHOIX 1");
       BoutonFini(button1,width,(2.25)*height,"CHOIX 2");
       BoutonFini(button2,width,(2.75)*height,"CHOIX 3");

         /* if(mouseonbutton(button0) && IsMouseButtonPressed(MOUSE_BUTTON_RIGHT)){
         button0_clicked = true;
         if( button0_clicked){
        ClearBackground(RED);
       }//essaie de configuaration de click
    }*/ //ca marche pas 
       

//SORTIE DE PROG
//-------------------------------------------------------------------------------------------------------------
       EndDrawing();}
       CloseWindow();
 
    return 0;
}

