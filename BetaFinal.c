#include "raylib.h"
#include <stdio.h>
#include "raymath.h"
#include <math.h>
#include <ctype.h>

#define MAX_INPUT_CHARS     9


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
    InitWindow(screenWidth, screenHeight, "PROJET ALGO");
    Image icon = LoadImage("logo.png");//LOGO de l'image
    SetWindowIcon(icon);
    Texture2D image = LoadTexture("./Lalgo.png");

    Camera2D cam = { 0 }; // initialiser les coordonnees de la camera 
    cam.zoom = 1; //cam.zoom=0.8;
    cam.offset.x = GetScreenWidth() / 100.0f;
    cam.offset.y =GetScreenHeight() / 10.0f;
    Vector2 prevMousePos = GetMousePosition();
    //on fait un tableau 

typedef struct ncase{
int val;
Rectangle box;
float speedx;
float speedy;
bool existe;
int ligne;
}ncase;
 SetTargetFPS(60); 
//MENU
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

//PARAMETRE DU MENU
bool Debut=false;
bool Dessin=false;
bool Saisie=false;

void BoutonFini(button button0,int width,int height,char* chaine){
    init_button(&button0 ,(Rectangle){width / 2 - 100, height / 4 -50 , 175 ,50},RED);
    if(mouseonbutton(button0)){
            button0.col=GREEN;
            if (IsMouseButtonDown(MOUSE_BUTTON_LEFT) && chaine=="TRIER")  Debut=true;
            if (IsMouseButtonDown(MOUSE_BUTTON_LEFT) && chaine=="VOIR ALGO")  Dessin=true;
            if (IsMouseButtonDown(MOUSE_BUTTON_LEFT) && chaine=="MODIF TAILLE")  Saisie=true;                                                                  

        }else{ button0.col=RED;} //Changement de couleur lors de l'approche d'une case par le curseur
     DrawRectangleRec(button0.rec,button0.col); //un des rectangles du menu
    DrawText(chaine,button0.rec.x + button0.rec.width / 2 - MeasureText(chaine,20) /2,button0.rec.y + button0.rec.height / 2 - 20 / 2,20, WHITE); // l'ecriture au dessus du texte
 


}


// LES FONCTIONS : ---------------------------------------------------------------------------
void Afficher(int LeIDebut,int Taille,int Milleu,int index,ncase D[index][Milleu]){
for(int i=LeIDebut ; i<Taille ; i++){
     int sizec=D[index][i-LeIDebut].box.height;
 DrawRectangleRec(D[index][i-LeIDebut].box,RED); //une case 
 sprintf(text, "%d", D[index][i-LeIDebut].val);
 DrawText(text,D[index][i-LeIDebut].box.x  + MeasureText(text,sizetext),D[index][i-LeIDebut].box.y + sizec/2 - sizetext/2 ,sizetext, WHITE);}}

  void tri( int indice_debut , int indice_fin,ncase T[],int n)
{int indice ;   
 int Min=T[indice_debut].val ; 
  for(int x=indice_debut ; x <indice_fin+1 ;x++)
   {
     for (int i = x; i < indice_fin+1; i++)
     {
        
        if(T[i].val<=Min)
        { 
         Min=T[i].val ;
         indice=i ;

         } 
    }
    int C ; 
    C=T[indice].val;
   T[indice].val=T[x].val ;
   T[x].val=Min ;
    Min=T[x+1].val ;
}   
}
//----------------------------------------------------------------------------------------------
//Tableau Gauche

//CHAINE VERS ENTIER-----------------------------------------
int cve(const char* chaine) {
    int resultat = 0;
    int i = 0;
    int signe = 1;

    // Gérer le signe (+ ou -)
    if (chaine[i] == '-') {
        signe = -1;
        i++;
    } else if (chaine[i] == '+') {
        i++;
    }

    // Convertir chaque caractère en entier jusqu'à rencontrer un non-chiffre
    while (chaine[i] != '\0' && isdigit(chaine[i])) {
        resultat = resultat * 10 + (chaine[i] - '0');
        i++;
    }

    return resultat * signe;
}

int mglo;
int n;
int  m;
int NbrDeSousTableau;


int index;
int indexvar =1;
Color new={13,17,23,255};

//BOOLEEN
bool Animation=false;
bool Animation2=false;
bool Animation3=false;
bool Replacement=false;
bool Affichage=false;
bool Text=false;
bool Anim=false;
bool couleur=false;
bool repeter=false;
bool Text2=true;
bool Replacement2=false;
bool init=false;

//--------------------------------------

//SAISIE------------------------------------


// LE TEXTE : ---------------------------------------------
char textee[MAX_INPUT_CHARS + 1]= "\0";
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

//données initialiation taille fenetre
//LOGO de l'image
button button0 = {0}; //le button
button button1 = {0};
button button2 = {0};
bool button0_clicked=false;

int cp=0;
int f=2;
int nbr=0;

    // Main game loop
    while (!WindowShouldClose()) {
        if(!Dessin && !Debut && !Saisie){
        ShowCursor();
        ClearBackground(BLACK);
         DrawText("MENU", screenWidth / 2 - 125, screenHeight / 4 -50 , 80, WHITE);
       BoutonFini(button0,screenWidth,(1.75)*screenHeight,"TRIER");
       BoutonFini(button1,screenWidth,(2.25)*screenHeight,"MODIF TAILLE");
       BoutonFini(button2,screenWidth,(2.75)*screenHeight ,"VOIR ALGO");
        sprintf(text, "%d", n);
    DrawText(text,poscx + MeasureText(text,sizetext) ,poscy + sizec/2 - sizetext/2 ,sizetext, WHITE);
      
       EndDrawing();}

       if(Dessin){
            BeginDrawing();
            ClearBackground(new);
            DrawTexture(image,300,-15,WHITE);
             DrawText("PRESS RETURN to return",screenWidth-300,22,22,WHITE);
            if(IsKeyPressed(KEY_BACKSPACE)){Dessin=false;}
            EndDrawing();
            }

        if(Saisie){
            DrawText("PRESS RETURN to return",screenWidth-300,22,22,RED);
            if(IsKeyPressed(KEY_BACKSPACE)){Saisie=false;}
            DrawText("PRESS ENTER to SAVE",screenWidth-275,52,22,GREEN);
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
        textee[cpt]=(char)Key;
        cpt++;
        textee[cpt]='\0';
        
     }
     
      Key=GetCharPressed();
    }

        
        if(IsKeyPressed(KEY_BACKSPACE))
        {   cpt--;
            textee[cpt]='\0';
            if(cpt<0) cpt=0;
        }
         if(IsKeyPressed(KEY_ENTER)) {interrupt=true; n=cve(textee);}


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

DrawText(textee,(int)Box.x+5,(int)Box.y+8,40,RAYWHITE);
DrawText(TextFormat(" %i/%i",cpt, MAX_INPUT_CHARS),Box.x+BoxWidth/2-20,Box.y+BoxHeight+20,20,RAYWHITE);// l'affichage est fini
//-------------------------------------------------------------------------------------------------------------------------
//ecriture visuelle :
if(mouseOnText)
 {
    if (cpt < MAX_INPUT_CHARS)
     {
        if(((tic/20)%2)==0) DrawText("_",(int)Box.x+8+ MeasureText(textee,40),(int)Box.y+12,40,MAROON);
     }else DrawText("SUPP pour supprimer un numero",Box.x,Box.y+BoxHeight+40,20,GRAY);
 }

EndDrawing();
}else{
ClearBackground(BLACK);
BeginDrawing();  
  
    DrawRectangleRec(Box,DARKGRAY);
    DrawRectangleLines((int)Box.x,(int)Box.y,(int)Box.width,(int)Box.height,GREEN);
    DrawText("Saisie Effectuée",Box.x,Box.y-30,20,GREEN);
DrawText(textee,(int)Box.x+5,(int)Box.y+8,40,RAYWHITE);
SetMouseCursor(MOUSE_CURSOR_NOT_ALLOWED);
EndDrawing();
}

            
        }

  // Zoom 
       float mouseDelta = GetMouseWheelMove(); //  recupere la quantite de mouvement de la molette

        float newZoom = cam.zoom + mouseDelta * 0.01f;
        if (newZoom <= 0)
            newZoom = 0.01f;

        cam.zoom = newZoom;
        // deplacement
        Vector2 thisPos = GetMousePosition(); //  recupere la position actuelle de la souris

        Vector2 delta = Vector2Subtract(prevMousePos, thisPos); // calcule de la difference entre la position initial et position actuelle 
        prevMousePos = thisPos;

       /* if (IsMouseButtonDown(0))
            cam.target = GetScreenToWorld2D(Vector2Add(cam.offset, delta),cam);*/ //  convertire les coordonnees de l'écran (en pixels) en coordonnees du monde

       // rotation
        if (IsKeyPressed(KEY_LEFT)) // rotation a gauche
            cam.offset.x+=50;
        else if (IsKeyPressed(KEY_RIGHT)) // rotation a droit 
            cam.offset.x-=50;
// Draw -----------------------------------------------------------------------------------------------------------
// Draw -----------------------------------------------------------------------------------------------------------
// Draw -----------------------------------------------------------------------------------------------------------
// Draw -----------------------------------------------------------------------------------------------------------
// Draw
if(Debut){
ncase C[n];
ncase T[n];
if(n%2==0) NbrDeSousTableau=log2(n);
else{NbrDeSousTableau=log2(n)+1;}
mglo=n/2;
ncase G[NbrDeSousTableau][mglo];
ncase D[NbrDeSousTableau][n-mglo];

    if(!init){
for(int j=0 ; j<n ; j++){
    C[j].box.height=50;
    C[j].box.width=50;
    C[j].box.x=(screenWidth/(n))*(j+1);
    C[j].box.y=screenHeight/2-C[j].box.height;
    C[j].val=j;
    C[j].existe=false;
    C[j].ligne=0;
    printf(" | %d | ",C[j].val);
    }
for(int j=0 ; j<n ; j++){
T[j]=C[j];
T[j].box.x=(screenWidth/(n)+50)*(j+1)-(C[j].box.width*n/2);
T[j].box.y=screenHeight+150;
T[j].speedx=0;
T[j].speedy=0;
printf("\n ");
printf(" | %d | ",T[j].val);
}

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
 index=1;
 init=true;}
  printf(" | %d | ",C[11].val);
        BeginDrawing();
        ClearBackground(BLACK);
        BeginMode2D(cam);
   for(int j=0 ; j<n ; j++){
    poscx= C[j].box.x;
    poscy=C[j].box.y;
    sizec=C[j].box.height;
    sizetext=20;          
        DrawRectangleRec(C[j].box,BLUE); //une case 
        sprintf(text, "%d", C[j].val);
    DrawText(text,poscx +20 ,poscy + sizec/2 - sizetext/2 ,sizetext, WHITE);}
//FIRST SPLIT-----------------------------------------------------------------------------------------------
for(int j=0 ; j<mglo;j++){
if(G[0][j].existe) {
//Afficher(0,mglo,mglo,0,G);
 DrawRectangleRec(G[0][j].box,RED); //une case 
        sprintf(text, "%d", G[0][j].val);
    DrawText(text,G[0][j].box.x + MeasureText(text,sizetext) ,G[0][j].box.y + sizec/2 - sizetext/2 ,sizetext, WHITE);}

for(int j=mglo; j<=n ; j++){
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
for(int j=mglo/((index)*2); j<=mglo ; j++){ //peut etre probleme
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
for(int j=(3*mglo)/((indexvar)*2); j<=mglo ;j++){
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
// DEUXIEME PARTIE DE L'ANIMATION :
  for(int j=0 ; j<n ; j++){
    sizetext=20; 
    sizec=50;         
        DrawRectangleRec(T[j].box,BLUE); //une case 
        sprintf(text, "%d", T[j].val);
    DrawText(text,T[j].box.x + MeasureText(text,sizetext) ,T[j].box.y + T[j].box.height/2 - sizetext/2 ,sizetext, WHITE);
    DrawText(text,poscx + MeasureText(text,sizetext) ,poscy + sizec/2 - sizetext/2 ,sizetext, WHITE);}


 for(int j=0 ; j<n ; j++){
    if(T[j].existe){
    sizetext=20; 
    sizec=50;         
        DrawRectangleRec(T[j].box,BLUE); //une case 
        sprintf(text, "%d", T[j].val);
    DrawText(text,T[j].box.x + MeasureText(text,sizetext) ,T[j].box.y + T[j].box.height/2 - sizetext/2 ,sizetext, WHITE);}}
// Draw -----------------------------------------------------------------------------------------------------------




  sizec=50;
    if(!Text) DrawText("Press SPACE",GetScreenWidth()/2-150,GetScreenHeight()/2-100,30,WHITE);
    if(IsKeyPressed(KEY_SPACE)){Replacement = true; Text=true;}
    if(Replacement){for(int j=0 ; j<n;j++){
C[j].speedy=2+i;
C[j].box.y-=C[j].speedy;
if(cam.zoom>=0.8 ) cam.zoom-=0.001;
//if(cam.offset.x >= 250 ) cam.offset.x=cam.offset.x-1000;
cam.offset.x=100;
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
for(int j=m; j<=mglo ; j++){ //peut etre probleme
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
if(G[indexvar][j].box.y >= 50*((indexvar+1)*3)+50){G[indexvar][j].speedy = 0; Animation3=false; /*Affichage=true;*/ Text2=false; }
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
G[indexvar][j].existe=true;}
//--------------------------------------
for(int j=(3*mglo)/((indexvar)*2); j<=mglo ;j++){
D[indexvar][j].speedx=2*(indexvar+1);
D[indexvar][j].speedy=1.52*(indexvar+1);
D[indexvar][j].box.x+=D[indexvar][j].speedx;
if(j==mglo){D[indexvar][j].box.y+=D[indexvar][j].speedy;}
else{D[indexvar][j].box.y=G[indexvar][j].box.y;}

D[indexvar][j].existe=true;}
//--------------------------------------

} 
if(!Text2) DrawText("Press ENTER to MERGE",GetScreenWidth()/2-150,GetScreenHeight()/2+GetScreenHeight()/4+GetScreenHeight()/8,30,RED);
    if(IsKeyPressed(KEY_ENTER)){ Text2=true; Replacement2=true; Affichage = true;}
if(Replacement2){if(cam.offset.y >= -500){cam.offset.y =cam.offset.y-50; }
                 //if(cam.zoom>=0.7 ) cam.zoom-=0.001;
                                            }

//---------------------------------Debut De DERNIERE PARTIE D'ANIMATION

int N;
if(n%2==0){ N=n;}
else{ N=n-1;}
 sizetext=20; 

 if(Affichage){   
for(int j=cp ; j<cp+f ;j++)
{

    T[j].existe=true;
   
    if(!couleur){ 
    DrawRectangleRec(T[j].box,ORANGE);
     sprintf(text, "%d", T[j].val);
     DrawText(text,T[j].box.x + MeasureText(text,sizetext) ,T[j].box.y + T[j].box.height/2 - sizetext/2 ,sizetext, WHITE);
    T[j].speedy+=0.01;
    T[j].box.y+=T[j].speedy;
    if(T[j].box.y >= screenHeight+165){tri(cp,cp+f-1,T,N);}
    if(T[j].box.y >= screenHeight+200){T[j].speedy=0;  couleur=true;}}
if(couleur){
    T[j].speedy+=4;
    T[j].box.y+=T[j].speedy;
    if(T[j].box.y >= screenHeight+250){T[j].speedy=0; T[j].box.y=screenHeight+300; Affichage=false;  repeter=true; couleur=false;}
    }}
if(T[N].existe && n!=N ){  T[n].box.y+=screenHeight+250;}
}

if(f>N){f=0;}
if(cp>=N-f+1){cp=0; f=f*2; Affichage=true; repeter=false; WaitTime(1);}
if(repeter){cp+=f; Affichage=true; repeter=false; }






        EndDrawing();
    }}
    CloseWindow();

    return 0;
}
