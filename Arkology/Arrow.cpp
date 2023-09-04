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

#include "Arrow.h"
#include "Mummy.h"
#include "Fase2.h"
#include "Arkology.h"

// ---------------------------------------------------------------------------------

Arrow::Arrow(Image * img)
{
   

    // cria sprite da flecha
    sprite = new Sprite(img);
    // tamanho da flecha é 15x08
    BBox(new Rect(-8, -4, 8, 4));

    // tamanho do player é 100x20


    // velocidades iniciais
    velX = 250;
    velY = 0;

    // tipo do objeto
    type = ARROW;
}

// ---------------------------------------------------------------------------------

Arrow::~Arrow()
{
    delete sprite;
}

// ---------------------------------------------------------------------------------

void Arrow::Up()
{
    velX = 0;
    velY = -200.0f;
    Translate(velX * gameTime, velY * gameTime);
}

// ---------------------------------------------------------------------------------

void Arrow::Down()
{
    velX = 0;
    velY = 200.0f;
    Translate(velX * gameTime, velY * gameTime);
}

// ---------------------------------------------------------------------------------

void Arrow::Left()
{
    velX = -200.0f;
    velY = 0;
    Translate(velX * gameTime, velY * gameTime);
}

// ---------------------------------------------------------------------------------

void Arrow::Right()
{
    velX = 200.0f;
    velY = 0;
    Translate(velX * gameTime, velY * gameTime);
}

// ---------------------------------------------------------------------------------

void Arrow::OnCollision(Object* obj)
{
    if (obj->Type() == MUMMYARROW)
    {
        Fase2::scene->Delete(obj, MOVING);
    }
}

// ---------------------------------------------------------------------------------

void Arrow::Update()
{
    
      Translate(velX * gameTime, 0);
        if (x > window->Width())
            Fase2::scene->Delete();
}

// ---------------------------------------------------------------------------------
