#ifndef _ARKOLOGY_PLAYERMAZE_H_
#define _ARKOLOGY_PLAYERMAZE_H_

// ---------------------------------------------------------------------------------
// Inclusões

#include "Types.h"                      // tipos específicos da engine
#include "Object.h"                     // interface de Object
#include "Sprite.h"                     // interface de Sprites

// ---------------------------------------------------------------------------------
// Constantes Globais

// estados possíveis para o jogador
enum PLAYERSTATE2 { STOPED, UP, DOWN, LEFT, RIGHT, PLAYING };

// ---------------------------------------------------------------------------------

class Playermaze : public Object
{
private:
    Sprite* spriteLComArco = nullptr;         // sprite do player indo para esquerda
    Sprite* spriteRComArco = nullptr;         // sprite do player indo para direita
    Image* arrow;

    float velX = 0;                     // velocidade horizontal do player
    float velY = 0;                     // velocidade vertical do player

public:
    
    uint currState = STOPED;            // estado atual do jogador
    uint nextState = STOPED;            // próximo estado do jogador

    Playermaze();                           // construtor
    ~Playermaze();                          // destrutor

    void Stop();                        // parar jogador
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

inline float Playermaze::Width()
{
    return float(spriteLComArco->Width());
}

inline float Playermaze::Height()
{
    return float(spriteLComArco->Height());
}

// ---------------------------------------------------------------------------------

#endif