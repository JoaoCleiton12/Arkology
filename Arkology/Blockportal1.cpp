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
#include "Blockportal1.h"


// ---------------------------------------------------------------------------------

Blockportal1::Blockportal1()
{
    // imagem da pedra é 126x122 (com borda transparente de 4 pixels)
    BBox(new Rect(-10, 07, 10, 50));
    MoveTo(480.0f, 450.0f);

    type = BLOCKPORTAL1;
}

// ---------------------------------------------------------------------------------

Blockportal1::~Blockportal1()
{

}

void Blockportal1::Update()
{
}

void Blockportal1::Draw()
{
}

// ---------------------------------------------------------------------------------
