#ifndef _ARKOLOGY_HOME_H_
#define _ARKOLOGY_HOME_H_

// ------------------------------------------------------------------------------
// Inclus�es

#include "Game.h"
#include "Sprite.h"

// ------------------------------------------------------------------------------

class Home : public Game
{
private:
    Sprite* backg = nullptr;       // pano de fundo

public:
    void Init();                    // inicializa��o
    void Update();                  // atualiza��o
    void Draw();                    // desenho
    void Finalize();                // finaliza��o
};

// -----------------------------------------------------------------------------

#endif