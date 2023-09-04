/**********************************************************************************
// Level1 (Código Fonte)
//
// Criação:     18 Jan 2013
// Atualização: 04 Mar 2023
// Compilador:  Visual C++ 2022
//
// Descrição:   Nível 1 do jogo PacMan
//
**********************************************************************************/

#include "Engine.h"
#include "Home.h"
#include "Maze.h"
#include "Level1.h"
#include <string>
#include <fstream>
#include "Player.h"
#include "Block.h"
#include "Block2.h"
#include "Block3.h"
#include "Block4.h"
#include "Block5.h"
#include "Block6.h"
#include "Block7.h"
#include "Block8.h"
#include "Block9.h"
#include "Blockportal2.h"
#include "Blockportal1.h"
#include "Blockfinal.h"
#include "PortalFase1.h"
#include "PortalFase2.h"

using std::ifstream;
using std::string;

// ------------------------------------------------------------------------------

Scene* Level1::scene = nullptr;


void Level1::Init()
{

    // cria gerenciador de cena
    scene = new Scene();

    // cria background
    backg = new Sprite("Resources/Fase1.png");

    // cria jogador
    Player * player = new Player();
    scene->Add(player, MOVING);


    // adiciona paredes invisíveis no cenário (bbox)

    Block* block = new Block();
    block->MoveTo(window->CenterX() - 400.0f, 437.0f);
    scene->Add(block, STATIC);

    Block2* block2 = new Block2();
    block2->MoveTo(window->CenterX() - 14.0f, 568.0f);
    scene->Add(block2, STATIC);

    Block3* block3 = new Block3();
    block3->MoveTo(window->CenterX() - 333.0f, 360.0f);
    scene->Add(block3, STATIC);

    Block4* block4 = new Block4();
    block4->MoveTo(466.0f, 219.0f);
    scene->Add(block4, STATIC);

    Block5* block5 = new Block5();
    block5->MoveTo( 524.0f, 219.0f);
    scene->Add(block5, STATIC);

    Block6* block6 = new Block6();
    block6->MoveTo(630.0f, 360.0f);
    scene->Add(block6, STATIC);

    Block7* block7 = new Block7();
    block7->MoveTo(630.0f, 429.0f);
    scene->Add(block7, STATIC);

    Block8* block8 = new Block8();
    block8->MoveTo(524.0f, 430.0f);
    scene->Add(block8, STATIC);

    // Block que impede entrar na piramide
    Block9* block9 = new Block9();
    block9->MoveTo(488.0f, 214.0f);
    scene->Add(block9, STATIC);

    // Block que leva para Tela Final
    Blockfinal* blockfinal = new Blockfinal();
    blockfinal->MoveTo(488.0f, 212.0f);
    scene->Add(blockfinal, STATIC);

    // adiciona portal para Fase1
    PortalFase1* portalfase1 = new PortalFase1();
    portalfase1->MoveTo(21.0f, 400.0f);
    scene->Add(portalfase1, MOVING);

    // adiciona portal para Fase2
    PortalFase2* portalfase2 = new PortalFase2();
    portalfase2->MoveTo(930.0f, 400.0f);
    scene->Add(portalfase2, MOVING);

    // Block que impede portal 1
    Blockportal1* blockPortal1 = new Blockportal1();
    blockPortal1->MoveTo(19.0f, 359.0f);
    scene->Add(blockPortal1, STATIC);

    // Block que impede portal 2
    Blockportal2* blockPortal2 = new Blockportal2();
    blockPortal2->MoveTo(932.0f, 359.0f);
    scene->Add(blockPortal2, STATIC);


}

// ------------------------------------------------------------------------------

void Level1::Finalize()
{
    delete backg;
    delete scene;
}

// ------------------------------------------------------------------------------

void Level1::Update()
{
    // habilita/desabilita bounding box
    /*if (window->KeyPress('B'))
    {
        viewBBox = !viewBBox;
    } */  
    if (window->KeyPress(VK_ESCAPE))
    {
        // volta para a tela de abertura
        Engine::Next<Home>();
    }
    /*else if (window->KeyPress('N'))
    {
        Engine::Next<Maze>();
    }*/
    else
    {
        // atualiza cena
        scene->Update();
        scene->CollisionDetection();
        Level1::Verificaproxnivel();
    }
}

// ------------------------------------------------------------------------------

void Level1::Draw()
{
    // desenha cena
    backg->Draw(window->CenterX(), window->CenterY(), Layer::BACK);
    scene->Draw();

    // desenha bounding box dos objetos
    if (viewBBox)
        scene->DrawBBox();
}

// ------------------------------------------------------------------------------