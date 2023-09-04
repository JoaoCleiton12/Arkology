/**********************************************************************************
// Player (Arquivo de Cabeçalho)
//
// Criação:     01 Jan 2013
// Atualização: 04 Mar 2023
// Compilador:  Visual C++ 2022
//
// Descrição:   Player do jogo PacMan
//
**********************************************************************************/

#ifndef _ARKOLOGY_BLOCKPORTAL1_H_
#define _ARKOLOGY_BLOCKPORTAL1_H_

// ---------------------------------------------------------------------------------
// Inclusões

#include "Types.h"                      // tipos específicos da engine
#include "Object.h"                     // interface de Object
#include "Sprite.h"                     // interface de Sprites

// ---------------------------------------------------------------------------------

class Blockportal1 : public Object
{
private:
    Sprite* sprite = nullptr;         // sprite do player indo para esquerda


public:


    Blockportal1();                  // construtor
    ~Blockportal1();                            // destrutor
    void Update();                      // atualização do objeto
    void Draw();                        // desenho do objeto
};

// ---------------------------------------------------------------------------------


#endif