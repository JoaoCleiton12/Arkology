#ifndef _ARKOLOGY_MUMMY8_H_
#define _ARKOLOGY_MUMMY8_H_

// ---------------------------------------------------------------------------------
// Inclusões

#include "Types.h"                      // tipos específicos da engine
#include "Object.h"                     // interface de Object
#include "Sprite.h"                     // interface de Sprites
#include "PartStatue.h"

// ---------------------------------------------------------------------------------
// Constantes Globais

// estados possíveis para o jogador
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
    uint nextState = DOWWNNNNNNNN;            // próximo estado do jogador

    Mummy8(Partstatue* part);                           // construtor
    ~Mummy8();                          // destrutor

    void Stop();                        // pára jogador
    void Up();                          // muda direção para cima
    void Down();                        // muda direção para baixo
    void Left();                        // muda direção para esquerda
    void Right();                       // muda direção para direita

    float Width();                     // largura do personagem
    float Height();                    // altura do personagem

    void OnCollision(Object* obj);     // resolução da colisão
    void PivotCollision(Object* obj);  // revolve colisão com pivô

    void Update();                      // atualização do objeto
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