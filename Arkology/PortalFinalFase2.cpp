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
#include "PortalFinalFase2.h"
#include "Fase2.h"


// ---------------------------------------------------------------------------------

PortalFinalFase2::PortalFinalFase2()
{
    // imagem da pedra � 126x122 (com borda transparente de 4 pixels)
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
