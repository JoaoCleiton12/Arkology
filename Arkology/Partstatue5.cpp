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
#include "Partstatue5.h"


// ---------------------------------------------------------------------------------

Partstatue5::Partstatue5()
{
    sprite = new Sprite("Resources/Parte5Estatua.png");
    // imagem da pedra é 13x9 (com borda transparente de 4 pixels)
    BBox(new Rect(-7, -5, 7, 5));
    MoveTo(70.0f, 650.0f);
    type = PARTSTATUE;
}

// ---------------------------------------------------------------------------------

Partstatue5::~Partstatue5()
{
    delete sprite;
}

void Partstatue5::OnCollision(Object* obj)
{
    if (obj->Type() == PLAYER)
    {
        state5 = ONNNNN;
    }
}

void Partstatue5::Update()
{
}

void Partstatue5::Draw()
{
    if (state5 == OFFFFFF)
    {
        sprite->Draw(x, y, z);
    }
}

// ---------------------------------------------------------------------------------
