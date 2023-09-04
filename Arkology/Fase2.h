/**********************************************************************************
// Level1 (Arquivo de Cabeçalho)
//
// Criação:     18 Jan 2013
// Atualização: 04 Mar 2023
// Compilador:  Visual C++ 2022
//
// Descrição:   Nível 1 do jogo PacMan
//
**********************************************************************************/

#ifndef _ARKOLOGY_FAZE_H_
#define _ARKOLOGY_FAZE_H_

// ------------------------------------------------------------------------------
// Inclusões

#include "Game.h"
#include "Sprite.h"
#include "Scene.h"
#include "Playerfase2.h"
#include "Telacarregamento2.h"
#include "Gameover.h"
#include "Engine.h"
#include "Timer.h"


// ------------------------------------------------------------------------------

class Fase2 : public Game
{
private:
    Sprite* backg = nullptr;        // background
    bool viewBBox = false;          // habilita visualização da bounding box

public:

    static bool GameOver2;
    static bool Levelwin2;
    static void Verificafinal2();
    static bool fimdefase;
    Timer roundTime;                // contador do game
    float tempo1 = 2.0f;
    Timer roundTime2;
    float tempo2 = 5.0f;
    Timer roundTime3;
    float tempo3 = 8.0f;
    Timer roundTime4;
    float tempo4 = 15.0f;
    Timer roundTimeGamer;
    float tempoGame = 30.0f;         // tempo limite do game

    static bool mummyleave;

    static Scene* scene;            // gerenciador de cena
    void Init();                    // inicializa jogo
    void Update();                  // atualiza lógica do jogo
    void Draw();                    // desenha jogo
    void Finalize();                // finaliza jogo
};

inline void Fase2::Verificafinal2()
{

    if (Levelwin2)
    {
        Engine::Next<Telacarregamento2>();
        Levelwin2 = false;
    }
    if (mummyleave)
    {
        Sleep(800);
        Engine::Next<Gameover>();
        mummyleave = false;
    }
}
// -----------------------------------------------------------------------------

#endif