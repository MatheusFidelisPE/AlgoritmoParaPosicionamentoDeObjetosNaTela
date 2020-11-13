#include <stdio.h>
#include <stdlib.h>
#include "raylib.h"
#include <unistd.h>
typedef struct
{
    Rectangle dimen;
    Texture2D imagem;

}Tret;

const int screenwidth = 900;
const int screenheight = 680;
int contagem = 0, contador;

 Vector2 Positions[] = {{552,65},
                                    {699,384},
                                    {406,570},
                                    {262,292},
                                    {357,433},
                                    {357,155},
                                    {598,616},
                                    {747,201},
                                    {67,247}};
int main()
{
    int qte_inimigos = sizeof(Positions)/8;
    int qte_obstaculos= 50;
    Tret retangulo[qte_obstaculos];

    int dimension_width = 43 ;
    int dimension_height = 43;

    Vector2 positions[] = { {65,108},
                            {65,154},
                            {66,198},
                            {163,200},
                            {113,199},
                            {66,336},
                            {114,336},
                            {115,107},
                            {212,108},
                            {262,107},
                            {309,107},
                            {308,200},
                            {309,247},
                            {308,292},
                            {18,476},
                            {65,475},
                            {115,475},
                            {113,522},
                            {162,475},
                            {307,475},
                            {359,476},
                            {260,522},
                            {405,523},
                            {357,568},
                            {405,198},
                            {406,338},
                            {746,523},
                            {795,523},
                            {697,568},
                            {794,613},
                            {843,522},
                            {794,198},
                            {747,244},
                            {744,292},
                            {745,154},
                            {744,108},
                            {453,198},
                            {503,199},
                            {502,244},
                            {503,292},
                            {503,336},
                            {453,428},
                            {503,429},
                            {258,430},
                            {503,613},
                            {599,62},
                            {453,17},
                            {599,152},
                            {358,107},
                            {648,336},
                            {648,384},
                            {744,428},
                            {210,613},
                            {549,523},
                            {601,523},
                            {795,430},
                            {599,198},
                            {794,290},
                            {794,17}};

    SetTargetFPS(100);
    int tam = sizeof(positions)/8;

    InitWindow(screenwidth, screenheight,"Construcao mapa");
    Texture2D mapa = LoadTexture("caixasprontas.png");

        for(int contador = 0; contador < qte_obstaculos; contador++)
        {
            retangulo[contador].dimen = (Rectangle){0};
            retangulo[contador].imagem = LoadTexture("porta.png");

        }



        while(!WindowShouldClose())
        {
            BeginDrawing();
                ClearBackground(RAYWHITE);
                DrawTexture(mapa,0,0,RAYWHITE);

              for(contador = 0; contador < qte_inimigos; contador++)
              {
                  DrawRectangle(Positions[contador].x,Positions[contador].y,20,20,GRAY);
              }
              for(contador = 0; contador <= contagem; contador++)
                {
                        DrawTexture(retangulo[contador].imagem,retangulo[contador].dimen.x, retangulo[contador].dimen.y,RAYWHITE);
                }


            EndDrawing();


            if(IsKeyDown(KEY_LEFT))
            {
                retangulo[contagem].dimen.x -= 1;
            }
            if(IsKeyDown(KEY_RIGHT))
            {
                retangulo[contagem].dimen.x += 1;
            }
            if(IsKeyDown(KEY_DOWN))
            {
                retangulo[contagem].dimen.y += 1;
            }
            if(IsKeyDown(KEY_UP))
            {
                retangulo[contagem].dimen.y -= 1;
            }
            if(IsKeyDown(KEY_ENTER))
            {
                retangulo[contagem].dimen = (Rectangle){retangulo[contagem].dimen.x, retangulo[contagem].dimen.y,dimension_width, dimension_height};

                contagem++;
                sleep(1);
            }

        }
    CloseWindow();
    for (contador = 0; contador < contagem; contador++)
        {
            printf("{%.f,%.f},\n", retangulo[contador].dimen.x, retangulo[contador].dimen.y);
        }
    return 0;
}
