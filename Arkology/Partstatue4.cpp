/**********************************************************************************
// Player (C�digo Fonte)
//
// Cria��o:     01 Jan 2013
// Atualiza��o: 04 Mar 2023
// Compilador:  Visual C++ 2022
//
// Descri��o:   Player do jogo PacMan
//
**********************************************************************************/

#include "Arkology.h"
#include "Partstatue4.h"


// ---------------------------------------------------------------------------------

Partstatue4::Partstatue4()
{
    sprite = new Sprite("Resources/Parte4Estatua.png");
    // imagem da pedra � 13x9 (com borda transparente de 4 pixels)
    BBox(new Rect(-7, -5, 7, 5));
    MoveTo(880.0f, 55.0f);
    type = PARTSTATUE;
}

// ---------------------------------------------------------------------------------

Partstatue4::~Partstatue4()
{
    delete sprite;
}

void Partstatue4::OnCollision(Object* obj)
{
    if (obj->Type() == PLAYER)
    {
        state4 = ONNNN;
    }
}

void Partstatue4::Update()
{
}

void Partstatue4::Draw()
{
    if (state4 == OFFFFF)
    {
        sprite->Draw(x, y, z);
    }
}

// ---------------------------------------------------------------------------------
