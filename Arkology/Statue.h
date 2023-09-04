/**********************************************************************************
// Player (Arquivo de Cabe�alho)
//
// Cria��o:     01 Jan 2013
// Atualiza��o: 04 Mar 2023
// Compilador:  Visual C++ 2022
//
// Descri��o:   Player do jogo PacMan
//
**********************************************************************************/

#ifndef _ARKOLOGY_STATUE_H_
#define _ARKOLOGY_STATUE_H_

// ---------------------------------------------------------------------------------
// Inclus�es

#include "Types.h"                      // tipos espec�ficos da engine
#include "Object.h"                     // interface de Object
#include "Sprite.h"                     // interface de Sprites
#include "Partstatue.h"
#include "Partstatue2.h"
#include "Partstatue3.h"
#include "Partstatue4.h"
#include "Partstatue5.h"

// ---------------------------------------------------------------------------------

class Statue: public Object
{
private:
    Partstatue* part;
    Partstatue2* part2;
    Partstatue3* part3;
    Partstatue4* part4;
    Partstatue5* part5;
    Sprite* spriteI = nullptr;         // sprite do player indo para esquerda
    Sprite* spriteF = nullptr;         // sprite do player indo para esquerda


public:


    Statue(Partstatue* p, Partstatue2* p2, Partstatue3* p3, Partstatue4* p4, Partstatue5* p5);                  // construtor
    ~Statue();                            // destrutor
    void Update();                      // atualiza��o do objeto
    void Draw();                        // desenho do objeto
};

// ---------------------------------------------------------------------------------


#endif