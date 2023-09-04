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

#ifndef _ARKOLOGY_LEVEl1_H_
#define _ARKOLOGY_LEVEL1_H_

// ------------------------------------------------------------------------------
// Inclusões

#include "Game.h"
#include "Sprite.h"
#include "Scene.h"
#include "Player.h"
#include "Maze.h"
#include "Fase2.h"
#include "Engine.h"
#include "Telafinal.h"


// ------------------------------------------------------------------------------

class Level1 : public Game
{
private:
    Sprite* backg = nullptr;       // background
    Image* tile1 = nullptr;           // bloco verde
    bool viewBBox = false;          // habilita visualização da bounding box

public:
    //Player* player = nullptr;
    static Scene* scene;        // gerenciador de cena
    static bool NextLevel;
    static bool NextLevel2;
    static bool Continue;
    static bool Impedirportal1;
    static bool Impedirportal2;
    static void Verificaproxnivel();
    void Init();                    // inicializa jogo
    void Update();                  // atualiza lógica do jogo
    void Draw();                    // desenha jogo
    void Finalize();                // finaliza jogo
};

inline void Level1::Verificaproxnivel()
{
    if (NextLevel)
    {
        Engine::Next<Maze>();
        NextLevel = false;
    }

    if (NextLevel2)
    {
        Engine::Next<Fase2>();
        NextLevel2 = false;
    }
    if (Continue)
    {
        Engine::Next<Telafinal>();
        Continue = false;
    }
    
}
// -----------------------------------------------------------------------------

#endif