#ifndef _ARKOLOGY_MUMMYFASE2_H_
#define _ARKOLOGY_MUMMYFASE2_H_

// ---------------------------------------------------------------------------------
// Inclusões

#include "Types.h"                      // tipos específicos da engine
#include "Object.h"                     // interface de Object
#include "Sprite.h"                     // interface de Sprites


// ---------------------------------------------------------------------------------
// Constantes Globais


// ---------------------------------------------------------------------------------

class Mummyfase2 : public Object
{
private:
    Sprite* sprite = nullptr;         // sprite da mumia

    

public:

    float velX = 0;                     // velocidade horizontal do player
    float velY = 0;                     // velocidade vertical do player

    Mummyfase2();                           // construtor
    ~Mummyfase2();                          // destrutor


    void OnCollision(Object* obj);     // resolução da colisão

    void Update();                      // atualização do objeto
    void Draw();                        // desenho do objeto
};

// ---------------------------------------------------------------------------------



#endif