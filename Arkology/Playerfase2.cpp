#include "Arkology.h"
#include "Playerfase2.h"
#include "Fase2.h"
#include "Engine.h"

// ---------------------------------------------------------------------------------

bool Fase2::Levelwin2 = false;

Playerfase2::Playerfase2()
{
    spriteL = new Sprite("Resources/personagemLArco.png");
    spriteR = new Sprite("Resources/personagemRArco.png");
    arrow = new Image("Resources/ArrowR.png");
    // spriteU = new Sprite("Resources/PacManU.png");
    // spriteD = new Sprite("Resources/PacManD.png");

     // imagem do jogador é 30x30
    BBox(new Rect(-15, -15, 15, 15));
    MoveTo(20.0f, 357.0f, Layer::FRONT);
    type = PLAYER;
    velX = 160;
    velY = 160;

}

// ---------------------------------------------------------------------------------

Playerfase2::~Playerfase2()
{
    delete spriteL;
    delete spriteR;
    delete arrow;
    // delete spriteU;
    // delete spriteD;
}

// ---------------------------------------------------------------------------------

void Playerfase2::Stop()
{
    velX = 0;
    velY = 0;
}

// ---------------------------------------------------------------------------------

void Playerfase2::Up()
{
    velX = 0;
    velY = -200.0f;
}

// ---------------------------------------------------------------------------------

void Playerfase2::Down()
{
    velX = 0;
    velY = 200.0f;
}

// ---------------------------------------------------------------------------------

void Playerfase2::Left()
{
    velX = -200.0f;
    velY = 0;
}

// ---------------------------------------------------------------------------------

void Playerfase2::Right()
{
    velX = 200.0f;
    velY = 0;
}

// ---------------------------------------------------------------------------------

void Playerfase2::OnCollision(Object* obj)
{
    if (obj->Type() == BLOCK10)
    {
        MoveTo(x, 325.0f);
    }
    if (obj->Type() == BLOCK11)
    {
        MoveTo(x, 436.0f);
    }
    if (obj->Type() == MUMMYARROW)
    {
        bateu = true;
    }
    if (obj->Type() == PORTALFINALFASE2)
    {
        Fase2::Levelwin2 = true;
    }
}

// ---------------------------------------------------------------------------------

void Playerfase2::PivotCollision(Object* obj)
{

}

// ---------------------------------------------------------------------------------

void Playerfase2::Update()
{

    if (window->KeyPress(VK_SPACE))
    {
        Arrow* a= new Arrow(arrow);
        a->MoveTo(x, y - spriteL->Height() / 2.0f, Layer::UPPER);
        Fase2::scene->Add(a, MOVING);
    }

    // atualiza posição X e muda o estado
    if (window->KeyDown(VK_RIGHT))
    {
        Translate(velX * gameTime, 0);
        state = RIIIGHTT;
    }
    if (window->KeyDown(VK_LEFT))
    {
        Translate(-velX * gameTime, 0);
        state = LEEEFTT;
    }
    // atualiza posição Y
    if (window->KeyDown(VK_UP))
        Translate(0, -velY * gameTime);
    if (window->KeyDown(VK_DOWN))
        Translate(0, velY * gameTime);

    //mantem jogador dentro da janela
    if (y > window->Height() - spriteL->Height() / 2.0f)
        MoveTo(x, window->Height() - spriteL->Height() / 2.0f);
    if (y < spriteL->Height() / 2)
        MoveTo(x, spriteL->Height() / 2.0f);
    if (x - spriteL->Width() / 2.0f < 0)
        MoveTo(spriteL->Width() / 2.0f, y);
    if (x + spriteL->Width() / 2.0f > window->Width())
        MoveTo(window->Width() - spriteL->Width() / 2.0f, y);

}

// ---------------------------------------------------------------------------------

void Playerfase2::Draw()
{
    switch (state)
    {
    case LEEEFTT: spriteL->Draw(x, y, z); break;
    case RIIIGHTT: spriteR->Draw(x, y, z); break;
    default:
        break;
    }

}


// ---------------------------------------------------------------------------------