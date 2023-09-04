#ifndef _ARKOLOGY_GAMEOVER_H_
#define _ARKOLOGY_GAMEOVER_H_

// ------------------------------------------------------------------------------
// Inclusões

#include "Game.h"
#include "Sprite.h"

// ------------------------------------------------------------------------------

class Gameover : public Game
{
private:
    Sprite* backg = nullptr;       // pano de fundo

public:
    void Init();                    // inicialização
    void Update();                  // atualização
    void Draw();                    // desenho
    void Finalize();                // finalização
};

// -----------------------------------------------------------------------------

#endif