#include "Arkology.h"
#include "Player.h"
#include "Level1.h"
#include "Engine.h"

// ---------------------------------------------------------------------------------
bool Level1::NextLevel = false;
bool Level1::NextLevel2 = false;
bool Level1::Continue = false;

Player::Player()
{
    spriteL = new Sprite("Resources/personagemL.png");
    spriteR = new Sprite("Resources/personagemR.png");
   // spriteU = new Sprite("Resources/PacManU.png");
   // spriteD = new Sprite("Resources/PacManD.png");

    // imagem do jogador é 30x30
    BBox(new Rect(-15, -15, 15, 15));
    MoveTo(495.0f, 700.0f, Layer::FRONT);
    type = PLAYER;
    velX = 160;
    velY = 160;
    state = LEFT;
}

// ---------------------------------------------------------------------------------

Player::~Player()
{
    delete spriteL;
    delete spriteR;
   // delete spriteU;
   // delete spriteD;
}

// ---------------------------------------------------------------------------------

void Player::Stop()
{
    velX = 0;
    velY = 0;
}

// ---------------------------------------------------------------------------------

void Player::Up()
{
    velX = 0;
    velY = -200.0f;
}

// ---------------------------------------------------------------------------------

void Player::Down()
{
    velX = 0;
    velY = 200.0f;
}

// ---------------------------------------------------------------------------------

void Player::Left()
{
    velX = -200.0f;
    velY = 0;
}

// ---------------------------------------------------------------------------------

void Player::Right()
{
    velX = 200.0f;
    velY = 0;
}

// ---------------------------------------------------------------------------------

void Player::OnCollision(Object* obj)
{
    if (obj->Type() == BLOCK)
    {
        MoveTo(x, 404);
    }
    if (obj->Type() == BLOCK2)
    {
        MoveTo(491, y);
    }
    if (obj->Type() == BLOCK3)
    {
        MoveTo(x, 385);
    }
    if (obj->Type() == BLOCK4)
    {
        MoveTo(491, y);
    }
    if (obj->Type() == BLOCK5)
    {
        MoveTo(499, y);
    }
    if (obj->Type() == BLOCK6)
    {
        MoveTo(x, 385);
    }
    if (obj->Type() == BLOCK7)
    {
        MoveTo(x, 404);
    }
    if (obj->Type() == BLOCK8)
    {
        MoveTo(499, y);
    }
    if (obj->Type() == BLOCK9)
    {
        MoveTo(x, 239);
    }
    if (obj->Type() == BLOCKPORTAL2)
    {
        MoveTo(907, y);
    }
    if (obj->Type() == BLOCKPORTAL1)
    {
        MoveTo(44, y);
    }
    if (obj->Type() == PORTALFASE1)
    {
        Level1::NextLevel = true;
    }
    if (obj->Type() == PORTALFASE2)
    {
        Level1::NextLevel2 = true;
    }
    if (obj->Type() == BLOCKFINAL)
    {
        Level1::Continue = true;
    }
}

// ---------------------------------------------------------------------------------

void Player::PivotCollision(Object* obj)
{
   
}

// ---------------------------------------------------------------------------------

void Player::Update()
{

    // atualiza posição X e muda o estado
    if (window->KeyDown(VK_RIGHT))
    {
        Translate(velX * gameTime, 0);
        state = RIGHT;
    }
    if (window->KeyDown(VK_LEFT))
    {
        Translate(-velX * gameTime, 0);
        state = LEFT;
    }
    // atualiza posição Y
    if (window->KeyDown(VK_UP))
        Translate(0, -velY * gameTime);
    if (window->KeyDown(VK_DOWN))
        Translate(0, velY*gameTime);

    //mantem jogador dentro da janela
    if (y > window->Height() - spriteL->Height() / 2.0f)
        MoveTo(x, window->Height() - spriteL->Height() / 2.0f);
    if (y < spriteL->Height()/2)
        MoveTo(x, spriteL->Height() / 2.0f);
    if (x - spriteL->Width() / 2.0f < 0)
        MoveTo(spriteL->Width() / 2.0f, y);
    if (x + spriteL->Width() / 2.0f > window->Width())
        MoveTo(window->Width() - spriteL->Width() / 2.0f, y);
    
}

// ---------------------------------------------------------------------------------

void Player::Draw()
{
    switch (state)
    {
    case LEFT: spriteL->Draw(x, y, z); break;
    case RIGHT: spriteR->Draw(x, y, z); break;
    default:
        break;
    }
    
}


// ---------------------------------------------------------------------------------