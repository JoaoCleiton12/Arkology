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

#ifndef _ARKOLOGY_PARTSTATUE_H_
#define _ARKOLOGY_PARTSTATUE_H_

// ---------------------------------------------------------------------------------
// Inclusões

#include "Types.h"                      // tipos específicos da engine
#include "Object.h"                     // interface de Object
#include "Sprite.h"                     // interface de Sprites

// ---------------------------------------------------------------------------------

enum STATEPART
{
    ON ,OFF
};

// ---------------------------------------------------------------------------------

class Partstatue : public Object
{
private:
    Sprite* sprite = nullptr;         // sprite do pedaço 1 da estatua


public:
    uint state = OFF;
    Partstatue();                       // construtor
    ~Partstatue();                      // destrutor
    void OnCollision(Object * obj);
    void Update();                      // atualização do objeto
    void Draw();                        // desenho do objeto
};

// ---------------------------------------------------------------------------------


#endif