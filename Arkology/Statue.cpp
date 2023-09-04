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
#include "Statue.h"
#include "Maze.h"


// ---------------------------------------------------------------------------------

bool Maze::Levelwin = false;
bool Maze::Hack = false;

Statue::Statue(Partstatue* p, Partstatue2* p2, Partstatue3* p3, Partstatue4* p4, Partstatue5* p5)
{
    part = p;
    part2 = p2;
    part3 = p3;
    part4 = p4;
    part5 = p5;
    spriteI = new Sprite("Resources/EstatuaIncompleta.png");
    spriteF = new Sprite("Resources/EstatuaCompleta.png");
    BBox(new Rect(-32, -32, 31, 31));
    MoveTo(480.0f, 355.0f);

    type = STATUE;
}

// ---------------------------------------------------------------------------------

Statue::~Statue()
{
    delete spriteI;
    delete spriteF;
}

void Statue::Update()
{

}

void Statue::Draw()
{
    if (((part->state == ON) && (part2->state2 == ONN) && (part3->state3 == ONNN) && (part4->state4 == ONNNN) && (part5->state5 == ONNNNN)) || (Maze::Hack) )
    {
        spriteF->Draw(x, y, z);
        Maze::Levelwin = true;
    }
    else
        spriteI->Draw(x, y, z);
    
}

// ---------------------------------------------------------------------------------
