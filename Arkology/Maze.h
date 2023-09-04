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

#ifndef _ARKOLOGY_MAZE_H_
#define _ARKOLOGY_MAZE_H_

// ------------------------------------------------------------------------------
// Inclusões

#include "Game.h"
#include "Sprite.h"
#include "Scene.h"
#include "Engine.h"
#include "Gameover.h"
#include "Telacarregamento.h"


// ------------------------------------------------------------------------------

class Maze : public Game
{
private:
    Sprite* backg = nullptr;        // background
    bool viewBBox = false;          // habilita visualização da bounding box

public:
    static bool GameOver;
    static bool Levelwin;
    static bool Hack;
    static void Verificafinal();
    static Scene* scene;            // gerenciador de cena
    void Init();                    // inicializa jogo
    void Update();                  // atualiza lógica do jogo
    void Draw();                    // desenha jogo
    void Finalize();                // finaliza jogo
};

inline void Maze::Verificafinal()
{
    if (GameOver)
    {
        Engine::Next<Gameover>();
        GameOver = false;
    }
    if (Levelwin)
    {
        // Espera um tempo para a imagem da estatua completa ser desenhada na tela
        Sleep(3000);
        // Apos isso passa para a tela de carregamento
        Engine::Next<Telacarregamento>();
        Levelwin = false;
    }
}
// -----------------------------------------------------------------------------

#endif