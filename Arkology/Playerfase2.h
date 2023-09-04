#ifndef _ARKOLOGY_PLAYERFASE2_H_
#define _ARKOLOGY_PLAYERFASE2_H_

// ---------------------------------------------------------------------------------
// Inclus�es

#include "Types.h"                      // tipos espec�ficos da engine
#include "Object.h"                     // interface de Object
#include "Sprite.h"                     // interface de Sprites
#include "Arrow.h"
#include "Fase2.h"

// ---------------------------------------------------------------------------------
// Constantes Globais

// estados poss�veis para o jogador
enum PLAYERSTATE3 { LEEEFTT, RIIIGHTT };

// ---------------------------------------------------------------------------------

class Playerfase2 : public Object
{
private:
    Sprite* spriteL = nullptr;         // sprite do player indo para esquerda
    Sprite* spriteR = nullptr;         // sprite do player indo para direita
    Sprite* spriteU = nullptr;         // sprite do player indo para cima
    Sprite* spriteD = nullptr;         // sprite do player indo para baixo
    Image* arrow;
    float velX = 0;                     // velocidade horizontal do player
    float velY = 0;                     // velocidade vertical do player

public:

    bool bateu = false;
    uint state;
         

    Playerfase2();                           // construtor
    ~Playerfase2();                          // destrutor

    void Stop();                        // p�ra jogador
    void Up();                          // muda dire��o para cima
    void Down();                        // muda dire��o para baixo
    void Left();                        // muda dire��o para esquerda
    void Right();                       // muda dire��o para direita

    float Width();                     // largura do personagem
    float Height();                    // altura do personagem

    void OnCollision(Object* obj);     // resolu��o da colis�o
    void PivotCollision(Object* obj);  // revolve colis�o com piv�

    void Update();                      // atualiza��o do objeto
    void Draw();                        // desenho do objeto
};

// ---------------------------------------------------------------------------------

inline float Playerfase2::Width()
{
    return float(spriteL->Width());
}

inline float Playerfase2::Height()
{
    return float(spriteL->Height());
}

// ---------------------------------------------------------------------------------

#endif