#include "Arkology.h"
#include "Mummyfase2.h"
#include "Fase2.h"
#include <time.h>

// ---------------------------------------------------------------------------------
bool Fase2::mummyleave = false;


Mummyfase2::Mummyfase2()
{


    sprite = new Sprite("Resources/Mumia2LabirintoEsquerda.png");
 
    // imagem do jogador é 30x30
    BBox(new Rect(-15, -15, 15, 15));
    type = MUMMYARROW;
    velX = -100.0f;
    velY = 0.0f;
}

// ---------------------------------------------------------------------------------

Mummyfase2::~Mummyfase2()
{
    delete sprite;

}

// ---------------------------------------------------------------------------------

void Mummyfase2::OnCollision(Object* obj)
{
    if (obj->Type() == ARROW)
    {
        Fase2::scene->Delete(obj, MOVING);
    }
}

// ---------------------------------------------------------------------------------

void Mummyfase2::Update()
{
    // atualiza posição
    Translate(velX * gameTime, velY * gameTime);
    if (x < 0)
    {
        Fase2::scene->Delete();
        Fase2::mummyleave = true;
    }
        

}

// ---------------------------------------------------------------------------------

void Mummyfase2::Draw()
{
    sprite->Draw(x, y, z);
}


// ---------------------------------------------------------------------------------