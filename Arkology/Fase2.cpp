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
#include "Fase2.h"
#include <string>
#include <fstream>
#include "Arrow.h"
#include "Pivot.h"
#include "Playerfase2.h"
#include "Block10.h"
#include "Block11.h"
#include "Arrow.h"
#include "PortalFinalFase2.h"
#include "Mummyfase2.h"
#include <random>
#include <chrono>
#include <thread>
#include <iostream>


using namespace std::this_thread;

using std::ifstream;
using std::string;
using namespace std;

// ------------------------------------------------------------------------------

Scene* Fase2::scene = nullptr;
bool Fase2::fimdefase = false;
Playerfase2* player;
random_device rd;
mt19937 mt(rd());
uniform_int_distribution<> dis(0, 40);

// ------------------------------------------------------------------------------

Mummyfase2* mummyfas2 = new Mummyfase2();

void Fase2::Init()
{
    // cria gerenciador de cena
    scene = new Scene();

    // cria background
    backg = new Sprite("Resources/Fase2.png");

    // cria jogador
    player = new Playerfase2();
    scene->Add(player, MOVING);

    // mumia fase 2
    mummyfas2 = new Mummyfase2();
    mummyfas2->MoveTo(930.0f, 373.0f - dis(mt), Layer::FRONT);
    scene->Add(mummyfas2, MOVING);

    Block10* block10 = new Block10();
    block10->MoveTo(10.0f, 300.0f);
    scene->Add(block10, STATIC);

    Block11* block11 = new Block11();
    block11->MoveTo(10.0f, 461.0f);
    scene->Add(block11, STATIC);

    
    // adiciona portal final da Fase2
    PortalFinalFase2* portalfinalfase2 = new PortalFinalFase2();
    portalfinalfase2->MoveTo(945.0f, 390.0f);
    scene->Add(portalfinalfase2, MOVING);



    roundTime.Start();
    roundTime2.Start();
    roundTime3.Start();
    roundTime4.Start();

    roundTimeGamer.Start();

}

// ------------------------------------------------------------------------------

void Fase2::Finalize()
{
    delete backg;
    delete scene;
}

// ------------------------------------------------------------------------------

void Fase2::Update()
{

    if ((roundTime.Elapsed(tempo1)) && (fimdefase == false))
    {
        mummyfas2 = new Mummyfase2();
        mummyfas2->MoveTo(930.0f, 373.0f - dis(mt), Layer::FRONT);
        scene->Add(mummyfas2, MOVING);

        mummyfas2 = new Mummyfase2();
        mummyfas2->MoveTo(930.0f, 393.0f - dis(mt), Layer::FRONT);
        mummyfas2->velX = -90.0f;
        scene->Add(mummyfas2, MOVING);

        mummyfas2 = new Mummyfase2();
        mummyfas2->MoveTo(930.0f, 413.0f - dis(mt), Layer::FRONT);
        mummyfas2->velX = -120.0f;
        scene->Add(mummyfas2, MOVING);

        mummyfas2 = new Mummyfase2();
        mummyfas2->MoveTo(930.0f, 423.0f - dis(mt), Layer::FRONT);
        mummyfas2->velX = -150.0f;
        scene->Add(mummyfas2, MOVING);

        roundTime.Reset();
    }
    // habilita/desabilita bounding box
    /*if (window->KeyPress('B'))
    {
        viewBBox = !viewBBox;
    }*/

    if (roundTimeGamer.Elapsed(tempoGame) && fimdefase == false)
    {
        fimdefase = true;
        /*Sleep(1000);*/
    }
    else if (player->bateu == true)
    {
        Sleep(800);
        Engine::Next<Gameover>();
    }
    else
    {
        // atualiza cena
        scene->Update();
        scene->CollisionDetection();
        Verificafinal2();
    }
}

// ------------------------------------------------------------------------------

void Fase2::Draw()
{
    // desenha cena
    backg->Draw(window->CenterX(), window->CenterY(), Layer::BACK);
    scene->Draw();

    // desenha bounding box dos objetos
    if (viewBBox)
        scene->DrawBBox();
}

// ------------------------------------------------------------------------------