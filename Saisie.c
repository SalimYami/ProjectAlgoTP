#include "raylib.h"
#include <stdio.h>
#include <stdio.h>

#define MAX_INPUT_CHARS     9

int main(int argc, char* argv[]) {

const int screenWidth = 1280;
const int screenHeight = 720;
InitWindow(screenWidth,screenHeight,"Saisie");
//----------------------------------------------------------DEBUT CODE


// LE TEXTE : ---------------------------------------------
char text[MAX_INPUT_CHARS + 1]= "\0";
int cpt=0;
//----------------------------------------------------------
//VALEURS DE LA BOX --------------------------------------------------------
int BoxWidth = screenWidth/4;
int BoxHeight = screenHeight/14;
int Boxpx = screenWidth/2 - BoxWidth/2;
int Boxpy = screenHeight/2 - BoxHeight;
Rectangle Box = {Boxpx,Boxpy,BoxWidth,BoxHeight};
bool mouseOnText = false;
int tic=0; // le nombre de tics ou on a la poistion de la souris sur la box
//--------------------------------------------------
char *Phrase="Nombre ...";
bool interrupt=false; //pour stopper la saisie
SetTargetFPS(10);
while(!WindowShouldClose()){
    //verification de la position de la souris

if(CheckCollisionPointRec(GetMousePosition(),Box)) mouseOnText=true;
else mouseOnText=false;
if(!interrupt){
if(mouseOnText)
{
 SetMouseCursor(MOUSE_CURSOR_IBEAM);
 int Key = GetCharPressed(); //pour ecrire


    while(Key>0)   
    {   
    if (((Key >= KEY_ZERO && Key <= KEY_NINE) || (Key>= KEY_KP_0 && Key<= KEY_KP_9 ) ) && (cpt < MAX_INPUT_CHARS))
     {
        text[cpt]=(char)Key;
        cpt++;
        text[cpt]='\0';
        
     }
     
      Key=GetCharPressed();
    }

        
        if(IsKeyPressed(KEY_BACKSPACE))
        {   cpt--;
            text[cpt]='\0';
            if(cpt<0) cpt=0;
        }
         if(IsKeyPressed(KEY_ENTER)) interrupt=true;
   

}else SetMouseCursor(MOUSE_CURSOR_DEFAULT);

if (mouseOnText) tic++;
else tic = 0;
//AFFICHAGE------------------------------------------------------------------------------------------------------------------------------
BeginDrawing(); 

ClearBackground(BLACK);

DrawText("Entrez le numero dans le champs",Box.x,Box.y-30,20,RAYWHITE);
DrawRectangleRec(Box,DARKGRAY);
if(mouseOnText) DrawRectangleLines((int)Box.x,(int)Box.y,(int)Box.width,(int)Box.height,GREEN); //Bonne idée pour faire les cases du tableau
else DrawRectangleLines((int)Box.x,(int)Box.y,(int)Box.width,(int)Box.height,RAYWHITE);

DrawText(text,(int)Box.x+5,(int)Box.y+8,40,RAYWHITE);
DrawText(TextFormat(" %i/%i",cpt, MAX_INPUT_CHARS),Box.x+BoxWidth/2-20,Box.y+BoxHeight+20,20,RAYWHITE);// l'affichage est fini
//-------------------------------------------------------------------------------------------------------------------------
//ecriture visuelle :
if(mouseOnText)
 {
    if (cpt < MAX_INPUT_CHARS)
     {
        if(((tic/20)%2)==0) DrawText("_",(int)Box.x+8+ MeasureText(text,40),(int)Box.y+12,40,MAROON);
     }else DrawText("SUPP pour supprimer un numero",Box.x,Box.y+BoxHeight+40,20,GRAY);
 }

EndDrawing();
}else{
ClearBackground(BLACK);
BeginDrawing();  
  
    DrawRectangleRec(Box,DARKGRAY);
    DrawRectangleLines((int)Box.x,(int)Box.y,(int)Box.width,(int)Box.height,GREEN);
    DrawText("Saisie Effectuée",Box.x,Box.y-30,20,GREEN);
DrawText(text,(int)Box.x+5,(int)Box.y+8,40,RAYWHITE);
SetMouseCursor(MOUSE_CURSOR_NOT_ALLOWED);
EndDrawing();
}

}

CloseWindow();
    return 0;
}
