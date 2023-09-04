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
#include <string>
#include <fstream>
#include "Playermaze.h"
#include "Mummy.h"
#include "Mummy2.h"
#include "Mummy3.h"
#include "Mummy4.h"
#include "Mummy5.h"
#include "Mummy6.h"
#include "Mummy7.h"
#include "Mummy8.h"
#include "Mummy9.h"
#include "Mummy10.h"
#include "Mummy11.h"
#include "Mummy12.h"
#include "Mummy13.h"
#include "Mummy14.h"
#include "Arrow.h"
#include "Pivot.h"
#include "Statue.h"
#include "Partstatue.h"
#include "Partstatue2.h"
#include "Partstatue3.h"
#include "Partstatue4.h"
#include "Partstatue5.h"


using std::ifstream;
using std::string;

// ------------------------------------------------------------------------------

Scene* Maze::scene = nullptr;

// ------------------------------------------------------------------------------

void Maze::Init()
{
    // cria gerenciador de cena
    scene = new Scene();

    // cria background
    backg = new Sprite("Resources/FaseLabirinto.png");

    // cria jogador
    Playermaze* playermaze = new Playermaze();
    scene->Add(playermaze, MOVING);

    // cria parte 1 da estatua
    Partstatue* part1 = new Partstatue();
    scene->Add(part1, STATIC);

    // cria parte 2 da estatua
    Partstatue2* part2 = new Partstatue2();
    scene->Add(part2, STATIC);

    // cria parte 3 da estatua
    Partstatue3* part3 = new Partstatue3();
    scene->Add(part3, STATIC);

    // cria parte 4 da estatua
    Partstatue4* part4 = new Partstatue4();
    scene->Add(part4, STATIC);

    // cria parte 4 da estatua
    Partstatue5* part5 = new Partstatue5();
    scene->Add(part5, STATIC);

    // cria mumia
    Mummy * mummy = new Mummy(part1);
    scene->Add(mummy, MOVING);

    // cria mumia2
    Mummy2* mummy2 = new Mummy2(part1);
    scene->Add(mummy2, MOVING);

    // cria mumia3
    Mummy3* mummy3 = new Mummy3(part1);
    scene->Add(mummy3, MOVING);

    // cria mumia4
    Mummy4* mummy4 = new Mummy4(part1);
    scene->Add(mummy4, MOVING);

    // cria mumia5
    Mummy5* mummy5 = new Mummy5(part1);
    scene->Add(mummy5, MOVING);

    // cria mumia6
    Mummy6* mummy6 = new Mummy6(part1);
    scene->Add(mummy6, MOVING);

    // cria mumia7
    Mummy7* mummy7 = new Mummy7(part1);
    scene->Add(mummy7, MOVING);

    // cria mumia8
    Mummy8* mummy8 = new Mummy8(part1);
    scene->Add(mummy8, MOVING);

    // cria mumia9
    Mummy9* mummy9 = new Mummy9(part1);
    scene->Add(mummy9, MOVING);

    // cria mumia10
    Mummy10* mummy10 = new Mummy10(part1);
    scene->Add(mummy10, MOVING);

    // cria mumia11
    Mummy11* mummy11 = new Mummy11(part1);
    scene->Add(mummy11, MOVING);

    // cria mumia12
    Mummy12* mummy12 = new Mummy12(part1);
    scene->Add(mummy12, MOVING);

    // cria mumia13
    Mummy13* mummy13 = new Mummy13(part1);
    scene->Add(mummy13, MOVING);

    // cria mumia14
    Mummy14* mummy14 = new Mummy14(part1);
    scene->Add(mummy14, MOVING);

    // cria estatua
    Statue* statue = new Statue(part1, part2, part3, part4, part5);
    scene->Add(statue, STATIC);

    

    // cria pontos de mudança de direção
    Pivot* pivot;
    bool left, right, up, down;
    float posX, posY;

    // cria pivôs a partir do arquivo
    ifstream fin;
    fin.open("PivotsL1.txt");
    fin >> left;
    while (!fin.eof())
    {
        if (fin.good())
        {
            // lê linha de informações do pivô
            fin >> right; fin >> up; fin >> down; fin >> posX; fin >> posY;
            pivot = new Pivot(left, right, up, down);
            pivot->MoveTo(posX, posY);
            scene->Add(pivot, STATIC);
        }
        else
        {
            // ignora comentários
            fin.clear();
            char temp[80];
            fin.getline(temp, 80);
        }
        fin >> left;
    }
    fin.close();
}

// ------------------------------------------------------------------------------

void Maze::Finalize()
{
    delete backg;
    delete scene;
}

// ------------------------------------------------------------------------------

void Maze::Update()
{
    // habilita/desabilita bounding box
    /*if (window->KeyPress('B'))
    {
        viewBBox = !viewBBox;
    }*/
    if (window->KeyPress('N'))
    {
        Hack = true;
    }
        
      // atualiza cena
      scene->Update();
      scene->CollisionDetection();
      Maze::Verificafinal();
  
}



// ------------------------------------------------------------------------------

void Maze::Draw()
{
    // desenha cena
    backg->Draw(window->CenterX(), window->CenterY(), Layer::BACK);
    scene->Draw();

    // desenha bounding box dos objetos
    if (viewBBox)
        scene->DrawBBox();
}

// ------------------------------------------------------------------------------