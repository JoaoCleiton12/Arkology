#ifndef _ARKOLOGY_MUMMY3_H_
#define _ARKOLOGY_MUMMY3_H_

// ---------------------------------------------------------------------------------
// Inclusões

#include "Types.h"                      // tipos específicos da engine
#include "Object.h"                     // interface de Object
#include "Sprite.h"                     // interface de Sprites
#include "PartStatue.h"

// ---------------------------------------------------------------------------------
// Constantes Globais

// estados possíveis para o jogador
enum MUMMYSTATE3 { STOPEEDDD, UUPPP, DOWWNNN, LEFFTTT, RIGGHTTT };

// ---------------------------------------------------------------------------------

class Mummy3 : public Object
{
private:
    unsigned seed;
    Partstatue* part;
    Sprite* spriteL = nullptr;         // sprite do player indo para esquerda
    Sprite* spriteR = nullptr;         // sprite do player indo para direita
    float velX = 0;                     // velocidade horizontal do player
    float velY = 0;                     // velocidade vertical do player

public:
    uint Sort;
    uint currState = STOPEEDDD;            // estado atual do jogador
    uint nextState = DOWWNNN;            // próximo estado do jogador

    Mummy3(Partstatue* part);                           // construtor
    ~Mummy3();                          // destrutor

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

inline float Mummy3::Width()
{
    return float(spriteL->Width());
}

inline float Mummy3::Height()
{
    return float(spriteL->Height());
}

// ---------------------------------------------------------------------------------

#endif