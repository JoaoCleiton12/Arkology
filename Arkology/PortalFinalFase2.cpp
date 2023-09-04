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
#include "PortalFinalFase2.h"
#include "Fase2.h"


// ---------------------------------------------------------------------------------

PortalFinalFase2::PortalFinalFase2()
{
    // imagem da pedra é 126x122 (com borda transparente de 4 pixels)
    BBox(new Rect(-13, -25, 13, 13));
    MoveTo(480.0f, 800.0f);

    type = PORTALFINALFASE2;
}

// ---------------------------------------------------------------------------------

PortalFinalFase2::~PortalFinalFase2()
{

}

void PortalFinalFase2::Update()
{
    // Exclui a bbox do cenario
    /*if (window->KeyPress('L'))
        Fase2::scene->Delete();*/
}

void PortalFinalFase2::Draw()
{
}

// ---------------------------------------------------------------------------------
