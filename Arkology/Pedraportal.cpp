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
#include "Pedraportal.h"


// ---------------------------------------------------------------------------------

Pedraportal::Pedraportal()
{

    spriteI = new Sprite("Resources/Portaldesativadofase2.png");
    spriteF = new Sprite("Resources/Portalativadofase2.png");
    MoveTo(480.0f, 355.0f);

    type = PEDRAPORTAL;
}

// ---------------------------------------------------------------------------------

Pedraportal::~Pedraportal()
{
    delete spriteI;
    delete spriteF;
}

void Pedraportal::Update()
{
}

void Pedraportal::Draw()
{
    

}

// ---------------------------------------------------------------------------------
