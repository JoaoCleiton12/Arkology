#ifndef _ARKOLOGY_MUMMY14_H_
#define _ARKOLOGY_MUMMY14_H_

// ---------------------------------------------------------------------------------
// Inclusões

#include "Types.h"                      // tipos específicos da engine
#include "Object.h"                     // interface de Object
#include "Sprite.h"                     // interface de Sprites
#include "PartStatue.h"

// ---------------------------------------------------------------------------------
// Constantes Globais

// estados possíveis para o jogador
enum MUMMYSTATE14 { STOPEEDDDDDDDDDDDDDD, UUPPPPPPPPPPPPPP, DOWWNNNNNNNNNNNNNN, LEFFTTTTTTTTTTTTTT, RIGGHTTTTTTTTTTTTTT };

// ---------------------------------------------------------------------------------

class Mummy14 : public Object
{
private:
    Partstatue* part;
    Sprite* spriteL = nullptr;         // sprite do player indo para esquerda
    Sprite* spriteR = nullptr;         // sprite do player indo para direita
    float velX = 0;                     // velocidade horizontal do player
    float velY = 0;                     // velocidade vertical do player

public:
    uint Sort;
    uint currState = STOPEEDDDDDDDDDDDDDD;            // estado atual do jogador
    uint nextState = DOWWNNNNNNNNNNNNNN;            // próximo estado do jogador

    Mummy14(Partstatue* part);                           // construtor
    ~Mummy14();                          // destrutor

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

inline float Mummy14::Width()
{
    return float(spriteL->Width());
}

inline float Mummy14::Height()
{
    return float(spriteL->Height());
}

// ---------------------------------------------------------------------------------

#endif