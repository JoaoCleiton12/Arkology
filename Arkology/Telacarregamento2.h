#ifndef _ARKOLOGY_TELACARREGAMENTO2_H_
#define _ARKOLOGY_TELACARREGAMENTO2_H_

// ------------------------------------------------------------------------------
// Inclusões

#include "Game.h"
#include "Sprite.h"

// ------------------------------------------------------------------------------

class Telacarregamento2 : public Game
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