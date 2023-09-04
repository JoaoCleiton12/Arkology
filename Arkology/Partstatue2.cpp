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
#include "Partstatue2.h"


// ---------------------------------------------------------------------------------

Partstatue2::Partstatue2()
{
    sprite = new Sprite("Resources/Parte2Estatua.png");
    // imagem da pedra é 13x9 (com borda transparente de 4 pixels)
    BBox(new Rect(-7, -5, 7, 5));
    MoveTo(70.0f, 50.0f);
    type = PARTSTATUE;
}

// ---------------------------------------------------------------------------------

Partstatue2::~Partstatue2()
{
    delete sprite;
}

void Partstatue2::OnCollision(Object* obj)
{
    if (obj->Type() == PLAYER)
    {
        state2 = ONN;
    }
}

void Partstatue2::Update()
{
}

void Partstatue2::Draw()
{
    if (state2 == OFFF)
    {
        sprite->Draw(x, y, z);
    }
}

// ---------------------------------------------------------------------------------
