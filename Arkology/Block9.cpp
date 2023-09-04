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
#include "Block9.h"
#include "Level1.h"


// ---------------------------------------------------------------------------------

Block9::Block9()
{
    // imagem da pedra é 126x122 (com borda transparente de 4 pixels)
    BBox(new Rect(-10, -10, 23, 10));
    MoveTo(480.0f, 450.0f);

    type = BLOCK9;
}

// ---------------------------------------------------------------------------------

Block9::~Block9()
{

}

void Block9::Update()
{
    if(Level1::Impedirportal1 == true && Level1::Impedirportal2 == true)
        Level1::scene->Delete();
    // Exclui a bbox do cenario
    /*if (window->KeyPress('L'))
        Level1::scene->Delete();*/
}

void Block9::Draw()
{
}

// ---------------------------------------------------------------------------------
