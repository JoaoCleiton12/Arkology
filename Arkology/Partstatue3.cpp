/**********************************************************************************
// Player (Código Fonte)
//
// Criação:     01 Jan 2013
// Atualização: 04 Mar 2023
// Compilador:  Visual C++ 2022
//
// Descrição:   Player do jogo PacMan
//
**********************************************************************************/

#include "Arkology.h"
#include "Partstatue3.h"


// ---------------------------------------------------------------------------------

Partstatue3::Partstatue3()
{
    sprite = new Sprite("Resources/Parte3Estatua.png");
    // imagem da pedra é 13x9 (com borda transparente de 4 pixels)
    BBox(new Rect(-7, -5, 7, 5));
    MoveTo(880.0f, 613.0f);
    type = PARTSTATUE;
}

// ---------------------------------------------------------------------------------

Partstatue3::~Partstatue3()
{
    delete sprite;
}

void Partstatue3::OnCollision(Object* obj)
{
    if (obj->Type() == PLAYER)
    {
        state3 = ONNN;
    }
}

void Partstatue3::Update()
{
}

void Partstatue3::Draw()
{
    if (state3 == OFFFF)
    {
        sprite->Draw(x, y, z);
    }
}

// ---------------------------------------------------------------------------------
