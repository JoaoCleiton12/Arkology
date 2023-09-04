/**********************************************************************************
// Ball (Arquivo de Cabeçalho)
//
// Criação:     22 Dez 2012
// Atualização: 28 Fev 2023
// Compilador:  Visual C++ 2022
//
// Descrição:   Bola do jogo Breakout
//
**********************************************************************************/

#ifndef _ARKOLOGY_ARROW_H_
#define _ARKOLOGY_ARROW_H_

// ---------------------------------------------------------------------------------
// Inclusões

#include "Types.h"                      // tipos específicos da engine
#include "Object.h"                     // interface de Object
#include "Sprite.h"                     // interface de Sprites

// ---------------------------------------------------------------------------------


class Arrow : public Object
{
private:
    Sprite* sprite;                    // sprite da bola

public:
    static uint* state;
    float velX;                        // velocidade horizontal
    float velY;                        // velocidade vertical  

    void Up();                          // muda direção para cima
    void Down();                        // muda direção para baixo
    void Left();                        // muda direção para esquerda
    void Right();                       // muda direção para direita

    Arrow(Image * img);                   // construtor
    ~Arrow();                           // destrutor


    void OnCollision(Object* obj);     // tratamento de colisão
    void Update();                     // atualização do objeto
    void Draw();                       // desenho do objeto
};

// ---------------------------------------------------------------------------------

inline void Arrow::Draw()
{
    sprite->Draw(x, y, z);
}


// ---------------------------------------------------------------------------------

#endif