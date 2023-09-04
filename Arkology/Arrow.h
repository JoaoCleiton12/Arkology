/**********************************************************************************
// Ball (Arquivo de Cabe�alho)
//
// Cria��o:     22 Dez 2012
// Atualiza��o: 28 Fev 2023
// Compilador:  Visual C++ 2022
//
// Descri��o:   Bola do jogo Breakout
//
**********************************************************************************/

#ifndef _ARKOLOGY_ARROW_H_
#define _ARKOLOGY_ARROW_H_

// ---------------------------------------------------------------------------------
// Inclus�es

#include "Types.h"                      // tipos espec�ficos da engine
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

    void Up();                          // muda dire��o para cima
    void Down();                        // muda dire��o para baixo
    void Left();                        // muda dire��o para esquerda
    void Right();                       // muda dire��o para direita

    Arrow(Image * img);                   // construtor
    ~Arrow();                           // destrutor


    void OnCollision(Object* obj);     // tratamento de colis�o
    void Update();                     // atualiza��o do objeto
    void Draw();                       // desenho do objeto
};

// ---------------------------------------------------------------------------------

inline void Arrow::Draw()
{
    sprite->Draw(x, y, z);
}


// ---------------------------------------------------------------------------------

#endif