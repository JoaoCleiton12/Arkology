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
#include "Blockportal2.h"


// ---------------------------------------------------------------------------------

Blockportal2::Blockportal2()
{
    // imagem da pedra � 126x122 (com borda transparente de 4 pixels)
    BBox(new Rect(-10, 07, 10, 50));
    MoveTo(480.0f, 450.0f);

    type = BLOCKPORTAL2;
}

// ---------------------------------------------------------------------------------

Blockportal2::~Blockportal2()
{

}

void Blockportal2::Update()
{
}

void Blockportal2::Draw()
{
}

// ---------------------------------------------------------------------------------
