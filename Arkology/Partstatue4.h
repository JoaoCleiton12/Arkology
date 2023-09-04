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

#ifndef _ARKOLOGY_PARTSTATUE4_H_
#define _ARKOLOGY_PARTSTATUE4_H_

// ---------------------------------------------------------------------------------
// Inclus�es

#include "Types.h"                      // tipos espec�ficos da engine
#include "Object.h"                     // interface de Object
#include "Sprite.h"                     // interface de Sprites

// ---------------------------------------------------------------------------------

enum Partactict4
{
    ONNNN, OFFFFF
};

// ---------------------------------------------------------------------------------

class Partstatue4 : public Object
{
private:
    Sprite* sprite = nullptr;         // sprite do peda�o 1 da estatua
public:

    uint state4 = OFFFFF;
    Partstatue4();                       // construtor
    ~Partstatue4();                      // destrutor
    void OnCollision(Object* obj);
    void Update();                      // atualiza��o do objeto
    void Draw();                        // desenho do objeto
};

// ---------------------------------------------------------------------------------


#endif