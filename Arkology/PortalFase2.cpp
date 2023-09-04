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
#include "PortalFase2.h"
#include "Level1.h"


// ---------------------------------------------------------------------------------

PortalFase2::PortalFase2()
{
    // imagem da pedra � 126x122 (com borda transparente de 4 pixels)
    BBox(new Rect(-13, -25, 13, 13));
    MoveTo(480.0f, 800.0f);

    type = PORTALFASE2;
}

// ---------------------------------------------------------------------------------

PortalFase2::~PortalFase2()
{

}

void PortalFase2::Update()
{
    if (Level1::Impedirportal2)
    {
        Level1::scene->Delete();
    }
}

void PortalFase2::Draw()
{
}

// ---------------------------------------------------------------------------------
