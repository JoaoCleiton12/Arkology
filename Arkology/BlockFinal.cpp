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
#include "Blockfinal.h"


// ---------------------------------------------------------------------------------

Blockfinal::Blockfinal()
{
    // imagem da pedra � 126x122 (com borda transparente de 4 pixels)
    BBox(new Rect(-10, -10, 23, 10));
    MoveTo(480.0f, 450.0f);

    type = BLOCKFINAL;
}

// ---------------------------------------------------------------------------------

Blockfinal::~Blockfinal()
{

}

void Blockfinal::Update()
{
}

void Blockfinal::Draw()
{
}

// ---------------------------------------------------------------------------------
