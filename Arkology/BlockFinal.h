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

#ifndef _ARKOLOGY_BLOCKFINAL_H_
#define _ARKOLOGY_BLOCKFINAL_H_

// ---------------------------------------------------------------------------------
// Inclus�es

#include "Types.h"                      // tipos espec�ficos da engine
#include "Object.h"                     // interface de Object
#include "Sprite.h"                     // interface de Sprites

// ---------------------------------------------------------------------------------

class Blockfinal : public Object
{
private:
    Sprite* sprite = nullptr;         // sprite do player indo para esquerda


public:


    Blockfinal();                  // construtor
    ~Blockfinal();                            // destrutor
    void Update();                      // atualiza��o do objeto
    void Draw();                        // desenho do objeto
};

// ---------------------------------------------------------------------------------


#endif