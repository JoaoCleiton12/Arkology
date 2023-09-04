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
#include "Partstatue.h"


// ---------------------------------------------------------------------------------

Partstatue::Partstatue()
{
    sprite = new Sprite("Resources/Parte1Estatua.png");
    // imagem da pedra é 13x9 (com borda transparente de 4 pixels)
    BBox(new Rect(-7, -5, 7, 5));
    MoveTo(795.0f, 300.0f);
    type = PARTSTATUE;
}

// ---------------------------------------------------------------------------------

Partstatue::~Partstatue()
{
    delete sprite;
}

void Partstatue::OnCollision(Object* obj)
{
    if (obj->Type() == PLAYER)
    {
        state = ON;
    }
}

void Partstatue::Update()
{    
}

void Partstatue::Draw()
{
    if(state == OFF)
        sprite->Draw(x, y, z);
   
}

// ---------------------------------------------------------------------------------
