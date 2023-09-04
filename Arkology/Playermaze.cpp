#include "Arkology.h"
#include "Playermaze.h"
#include "Maze.h"
#include "Arrow.h"
#include "Pivot.h"

// ---------------------------------------------------------------------------------

bool Maze::GameOver = false;

Playermaze::Playermaze()
{
    spriteLComArco = new Sprite("Resources/personagemL.png");
    spriteRComArco = new Sprite("Resources/personagemR.png");
    arrow = new Image("Resources/ArrowL.png");

     // imagem do jogador é 30x30
    BBox(new Rect(-15, -15, 15, 15));
    MoveTo(900.0f, 357.0f, Layer::FRONT);
    type = PLAYER;
}

// ---------------------------------------------------------------------------------

Playermaze::~Playermaze()
{
    delete spriteLComArco;
    delete spriteRComArco;
    delete arrow;
}

// ---------------------------------------------------------------------------------

void Playermaze::Stop()
{
    velX = 0;
    velY = 0;
}

// ---------------------------------------------------------------------------------

void Playermaze::Up()
{
    velX = 0;
    velY = -180.0f;
}

// ---------------------------------------------------------------------------------

void Playermaze::Down()
{
    velX = 0;
    velY = 180.0f;
}

// ---------------------------------------------------------------------------------

void Playermaze::Left()
{
    velX = -180.0f;
    velY = 0;
}

// ---------------------------------------------------------------------------------

void Playermaze::Right()
{
    velX = 180.0f;
    velY = 0;
}

// ---------------------------------------------------------------------------------

void Playermaze::OnCollision(Object* obj)
{
    if (obj->Type() == PIVOT)
        PivotCollision(obj);
    if (obj->Type() == MUMMY)
        Maze::GameOver = true;
    if (obj->Type() == MUMMY2)
        Maze::GameOver = true;
    if (obj->Type() == MUMMY3)
        Maze::GameOver = true;
    if (obj->Type() == MUMMY4)
        Maze::GameOver = true;
    if (obj->Type() == MUMMY5)
        Maze::GameOver = true;
    if (obj->Type() == MUMMY6)
        Maze::GameOver = true;
    if (obj->Type() == MUMMY7)
        Maze::GameOver = true;
    if (obj->Type() == MUMMY8)
        Maze::GameOver = true;
    if (obj->Type() == MUMMY9)
        Maze::GameOver = true;
    if (obj->Type() == MUMMY10)
        Maze::GameOver = true;
    if (obj->Type() == MUMMY11)
        Maze::GameOver = true;
    if (obj->Type() == MUMMY12)
        Maze::GameOver = true;
    if (obj->Type() == MUMMY13)
        Maze::GameOver = true;
    if (obj->Type() == MUMMY14)
        Maze::GameOver = true;
}

// ---------------------------------------------------------------------------------

void Playermaze::PivotCollision(Object* obj)
{
    Pivot* p = (Pivot*)obj;

    switch (currState)
    {
    case STOPED:
        // -----------------------
        // CurrentState == STOPED
        // -----------------------

        switch (nextState)
        {
        case LEFT:
            if (p->left)
            {
                currState = LEFT;
                Left();
            }
            break;
        case RIGHT:
            if (p->right)
            {
                currState = RIGHT;
                Right();
            }

            break;
        case UP:
            if (p->up)
            {
                currState = UP;
                Up();
            }
            break;
        case DOWN:
            if (p->down)
            {
                currState = DOWN;
                Down();
            }
            break;
        }
        break;

    case LEFT:
        // -----------------------
        // CurrentState == LEFT
        // -----------------------

        if (x < p->X())
        {
            if (!p->left)
            {
                MoveTo(p->X(), Y());
                currState = STOPED;
                Stop();
            }
        }

        switch (nextState)
        {
        case LEFT:
            if (x < p->X())
            {
                if (!p->left)
                {
                    MoveTo(p->X(), Y());
                    currState = STOPED;
                    Stop();
                }
            }
            break;
        case RIGHT:
            currState = RIGHT;
            Right();

            break;
        case UP:
            if (x < p->X())
            {
                if (p->up)
                {
                    MoveTo(p->X(), Y());
                    currState = UP;
                    Up();
                }
            }
            break;
        case DOWN:
            if (x < p->X())
            {
                if (p->down)
                {
                    MoveTo(p->X(), Y());
                    currState = DOWN;
                    Down();
                }
            }
            break;
        }
        break;

    case RIGHT:
        // -----------------------
        // CurrentState == RIGHT
        // -----------------------

        if (x > p->X())
        {
            if (!p->right)
            {
                MoveTo(p->X(), Y());
                currState = STOPED;
                Stop();
            }
        }

        switch (nextState)
        {
        case LEFT:
            currState = LEFT;
            Left();
            break;
        case RIGHT:
            if (x > p->X())
            {
                if (!p->right)
                {
                    MoveTo(p->X(), Y());
                    currState = STOPED;
                    Stop();
                }
            }

            break;
        case UP:
            if (x > p->X())
            {
                if (p->up)
                {
                    MoveTo(p->X(), Y());
                    currState = UP;
                    Up();
                }
            }
            break;
        case DOWN:
            if (x > p->X())
            {
                if (p->down)
                {
                    MoveTo(p->X(), Y());
                    currState = DOWN;
                    Down();
                }
            }
            break;
        }
        break;

    case UP:
        // -----------------------
        // CurrentState == UP
        // -----------------------

        if (y < p->Y())
        {
            if (!p->up)
            {
                MoveTo(x, p->Y());
                currState = STOPED;
                Stop();
            }
        }

        switch (nextState)
        {
        case LEFT:
            if (y < p->Y())
            {
                if (p->left)
                {
                    MoveTo(x, p->Y());
                    currState = LEFT;
                    Left();
                }
            }
            break;
        case RIGHT:
            if (y < p->Y())
            {
                if (p->right)
                {
                    MoveTo(x, p->Y());
                    currState = RIGHT;
                    Right();
                }
            }
            break;
        case UP:
            if (y < p->Y())
            {
                if (!p->up)
                {
                    MoveTo(x, p->Y());
                    currState = STOPED;
                    Stop();
                }
            }
            break;
        case DOWN:
            currState = DOWN;
            Down();
            break;
        }
        break;

    case DOWN:
        // -----------------------
        // CurrentState == DOWN
        // -----------------------

        if (y > p->Y())
        {
            if (!p->down)
            {
                MoveTo(x, p->Y());
                currState = STOPED;
                Stop();
            }
        }

        switch (nextState)
        {
        case LEFT:
            if (y > p->Y())
            {
                if (p->left)
                {
                    MoveTo(x, p->Y());
                    currState = LEFT;
                    Left();
                }
            }
            break;
        case RIGHT:
            if (y > p->Y())
            {
                if (p->right)
                {
                    MoveTo(x, p->Y());
                    currState = RIGHT;
                    Right();
                }
            }
            break;
        case UP:
            currState = UP;
            Up();
            break;
        case DOWN:
            if (y > p->Y())
            {
                if (!p->down)
                {
                    MoveTo(x, p->Y());
                    currState = STOPED;
                    Stop();
                }
            }
            break;
        }
        break;
    }
}

// ---------------------------------------------------------------------------------

void Playermaze::Update()
{

    if (window->KeyDown(VK_LEFT))
    {
        nextState = LEFT;

        if (currState == RIGHT || currState == STOPED)
        {
            currState = LEFT;
            Left();
        }
    }

    if (window->KeyDown(VK_RIGHT))
    {
        nextState = RIGHT;

        if (currState == LEFT || currState == STOPED)
        {
            currState = RIGHT;
            Right();
        }
    }

    if (window->KeyDown(VK_UP))
    {
        nextState = UP;

        if (currState == DOWN || currState == STOPED)
        {
            currState = UP;
            Up();
        }
    }

    if (window->KeyDown(VK_DOWN))
    {
        nextState = DOWN;

        if (currState == UP || currState == STOPED)
        {
            currState = DOWN;
            Down();
        }
    }

    // atualiza posição
    Translate(velX * gameTime, velY * gameTime);



}

// ---------------------------------------------------------------------------------

void Playermaze::Draw()
{
    switch (currState)
    {
    case LEFT:  spriteLComArco->Draw(x, y, Layer::UPPER); break;
    case RIGHT: spriteRComArco->Draw(x, y, Layer::UPPER); break;
    case UP:    spriteLComArco->Draw(x, y, Layer::UPPER); break;
    case DOWN:  spriteLComArco->Draw(x, y, Layer::UPPER); break;
    default:
        switch (nextState)
        {
        case LEFT:  spriteLComArco->Draw(x, y, Layer::UPPER); break;
        case RIGHT: spriteRComArco->Draw(x, y, Layer::UPPER); break;
        case UP:    spriteLComArco->Draw(x, y, Layer::UPPER); break;
        case DOWN:  spriteLComArco->Draw(x, y, Layer::UPPER); break;
        default:    spriteLComArco->Draw(x, y, Layer::UPPER);
        }
    }
}


// ---------------------------------------------------------------------------------