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
#include "Block11.h"


// ---------------------------------------------------------------------------------

Block11::Block11()
{
    // imagem da pedra � 126x122 (com borda transparente de 4 pixels)
    BBox(new Rect(-10, -10, 943, 10));
    MoveTo(480.0f, 450.0f);

    type = BLOCK11;
}

// ---------------------------------------------------------------------------------

Block11::~Block11()
{

}

void Block11::Update()
{
}

void Block11::Draw()
{
}

// ---------------------------------------------------------------------------------
