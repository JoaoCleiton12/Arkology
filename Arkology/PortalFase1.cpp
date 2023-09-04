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
#include "PortalFase1.h"
#include "Level1.h"


// ---------------------------------------------------------------------------------

PortalFase1::PortalFase1()
{
    // imagem da pedra é 126x122 (com borda transparente de 4 pixels)
    BBox(new Rect(-13, -25, 13, 13));
    MoveTo(480.0f, 450.0f);

    type = PORTALFASE1;
}

// ---------------------------------------------------------------------------------

PortalFase1::~PortalFase1()
{

}

void PortalFase1::Update()
{
    if (Level1::Impedirportal1)
    {
        Level1::scene->Delete();
    }
    
}

void PortalFase1::Draw()
{
}

// ---------------------------------------------------------------------------------
