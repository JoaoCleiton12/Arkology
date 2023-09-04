#ifndef _ARKOLOGY_MUMMY8_H_
#define _ARKOLOGY_MUMMY8_H_

// ---------------------------------------------------------------------------------
// Inclus�es

#include "Types.h"                      // tipos espec�ficos da engine
#include "Object.h"                     // interface de Object
#include "Sprite.h"                     // interface de Sprites
#include "PartStatue.h"

// ---------------------------------------------------------------------------------
// Constantes Globais

// estados poss�veis para o jogador
enum MUMMYSTATE8 { STOPEEDDDDDDDD, UUPPPPPPPP, DOWWNNNNNNNN, LEFFTTTTTTTT, RIGGHTTTTTTTT };

// ---------------------------------------------------------------------------------

class Mummy8 : public Object
{
private:
    Partstatue* part;
    Sprite* spriteL = nullptr;         // sprite do player indo para esquerda
    Sprite* spriteR = nullptr;         // sprite do player indo para direita
    float velX = 0;                     // velocidade horizontal do player
    float velY = 0;                     // velocidade vertical do player

public:
    uint Sort;
    uint currState = STOPEEDDDDDDDD;            // estado atual do jogador
    uint nextState = DOWWNNNNNNNN;            // pr�ximo estado do jogador

    Mummy8(Partstatue* part);                           // construtor
    ~Mummy8();                          // destrutor

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

inline float Mummy8::Width()
{
    return float(spriteL->Width());
}

inline float Mummy8::Height()
{
    return float(spriteL->Height());
}

// ---------------------------------------------------------------------------------

#endif