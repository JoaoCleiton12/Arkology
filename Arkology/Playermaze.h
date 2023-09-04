#ifndef _ARKOLOGY_PLAYERMAZE_H_
#define _ARKOLOGY_PLAYERMAZE_H_

// ---------------------------------------------------------------------------------
// Inclus�es

#include "Types.h"                      // tipos espec�ficos da engine
#include "Object.h"                     // interface de Object
#include "Sprite.h"                     // interface de Sprites

// ---------------------------------------------------------------------------------
// Constantes Globais

// estados poss�veis para o jogador
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
    uint nextState = STOPED;            // pr�ximo estado do jogador

    Playermaze();                           // construtor
    ~Playermaze();                          // destrutor

    void Stop();                        // parar jogador
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