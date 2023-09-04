#include "Arkology.h"
#include "Mummy12.h"
#include "Pivot.h"
#include <time.h>

// ---------------------------------------------------------------------------------

Mummy12::Mummy12(Partstatue* p)
{
    part = p;
    Sort = STOPEEDDDDDDDDDDDD;
    spriteL = new Sprite("Resources/MumiaLabirintoL.png");
    spriteR = new Sprite("Resources/MumiaLabirintoR.png");

    // imagem do jogador é 30x30
    BBox(new Rect(-15, -15, 15, 15));
    MoveTo(47.0f, 560.0f, Layer::FRONT);
    type = MUMMY12;
}

// ---------------------------------------------------------------------------------

Mummy12::~Mummy12()
{
    delete spriteL;
    delete spriteR;
}

// ---------------------------------------------------------------------------------

void Mummy12::Stop()
{
    velX = 0;
    velY = 0;
}

// ---------------------------------------------------------------------------------

void Mummy12::Up()
{
    velX = 0;
    velY = -90.0f;
}

// ---------------------------------------------------------------------------------

void Mummy12::Down()
{
    velX = 0;
    velY = 90.0f;
}

// ---------------------------------------------------------------------------------

void Mummy12::Left()
{
    velX = -90.0f;
    velY = 0;
}

// ---------------------------------------------------------------------------------

void Mummy12::Right()
{
    velX = 90.0f;
    velY = 0;
}

// ---------------------------------------------------------------------------------

void Mummy12::OnCollision(Object* obj)
{
    if (obj->Type() == PIVOT)
        PivotCollision(obj);

    // Colisao com mummia 13
    if (obj->Type() == MUMMY13 && currState == LEFFTTTTTTTTTTTT)
        nextState = RIGGHTTTTTTTTTTTT;
    if (obj->Type() == MUMMY13 && currState == RIGGHTTTTTTTTTTTT)
        nextState = LEFFTTTTTTTTTTTT;
    if (obj->Type() == MUMMY13 && currState == UUPPPPPPPPPPPP)
        nextState = DOWWNNNNNNNNNNNN;
    if (obj->Type() == MUMMY13 && currState == DOWWNNNNNNNNNNNN)
        nextState = UUPPPPPPPPPPPP;

    // Colisao com mummia 14
    if (obj->Type() == MUMMY14 && currState == LEFFTTTTTTTTTTTT)
        nextState = RIGGHTTTTTTTTTTTT;
    if (obj->Type() == MUMMY14 && currState == RIGGHTTTTTTTTTTTT)
        nextState = LEFFTTTTTTTTTTTT;
    if (obj->Type() == MUMMY14 && currState == UUPPPPPPPPPPPP)
        nextState = DOWWNNNNNNNNNNNN;
    if (obj->Type() == MUMMY14 && currState == DOWWNNNNNNNNNNNN)
        nextState = UUPPPPPPPPPPPP;
}

// ---------------------------------------------------------------------------------

void Mummy12::PivotCollision(Object* obj)
{
    Pivot* p = (Pivot*)obj;

    switch (currState)
    {
    case STOPEEDDDDDDDDDDDD:
        // -----------------------
        // CurrentState == STOPED
        // -----------------------

        switch (nextState)
        {
        case LEFFTTTTTTTTTTTT:
            if (p->left)
            {
                currState = LEFFTTTTTTTTTTTT;
                Left();
            }
            break;
        case RIGGHTTTTTTTTTTTT:
            if (p->right)
            {
                currState = RIGGHTTTTTTTTTTTT;
                Right();
            }

            break;
        case UUPPPPPPPPPPPP:
            if (p->up)
            {
                currState = UUPPPPPPPPPPPP;
                Up();
            }
            break;
        case DOWWNNNNNNNNNNNN:
            if (p->down)
            {
                currState = DOWWNNNNNNNNNNNN;
                Down();
            }
            break;
        }
        break;

    case LEFFTTTTTTTTTTTT:
        // -----------------------
        // CurrentState == LEFT
        // -----------------------

        if (x < p->X())
        {
            if (!p->left)
            {
                MoveTo(p->X(), Y());
                currState = STOPEEDDDDDDDDDDDD;
                Stop();
            }
        }

        switch (nextState)
        {
        case LEFFTTTTTTTTTTTT:
            if (x < p->X())
            {
                if (!p->left)
                {
                    MoveTo(p->X(), Y());
                    currState = STOPEEDDDDDDDDDDDD;
                    Stop();
                }
            }
            break;
        case RIGGHTTTTTTTTTTTT:
            currState = RIGGHTTTTTTTTTTTT;
            Right();

            break;
        case UUPPPPPPPPPPPP:
            if (x < p->X())
            {
                if (p->up)
                {
                    MoveTo(p->X(), Y());
                    currState = UUPPPPPPPPPPPP;
                    Up();
                }
            }
            break;
        case DOWWNNNNNNNNNNNN:
            if (x < p->X())
            {
                if (p->down)
                {
                    MoveTo(p->X(), Y());
                    currState = DOWWNNNNNNNNNNNN;
                    Down();
                }
            }
            break;
        }
        break;

    case RIGGHTTTTTTTTTTTT:
        // -----------------------
        // CurrentState == RIGHT
        // -----------------------

        if (x > p->X())
        {
            if (!p->right)
            {
                MoveTo(p->X(), Y());
                currState = STOPEEDDDDDDDDDDDD;
                Stop();
            }
        }

        switch (nextState)
        {
        case LEFFTTTTTTTTTTTT:
            currState = LEFFTTTTTTTTTTTT;
            Left();
            break;
        case RIGGHTTTTTTTTTTTT:
            if (x > p->X())
            {
                if (!p->right)
                {
                    MoveTo(p->X(), Y());
                    currState = STOPEEDDDDDDDDDDDD;
                    Stop();
                }
            }

            break;
        case UUPPPPPPPPPPPP:
            if (x > p->X())
            {
                if (p->up)
                {
                    MoveTo(p->X(), Y());
                    currState = UUPPPPPPPPPPPP;
                    Up();
                }
            }
            break;
        case DOWWNNNNNNNNNNNN:
            if (x > p->X())
            {
                if (p->down)
                {
                    MoveTo(p->X(), Y());
                    currState = DOWWNNNNNNNNNNNN;
                    Down();
                }
            }
            break;
        }
        break;

    case UUPPPPPPPPPPPP:
        // -----------------------
        // CurrentState == UP
        // -----------------------

        if (y < p->Y())
        {
            if (!p->up)
            {
                MoveTo(x, p->Y());
                currState = STOPEEDDDDDDDDDDDD;
                Stop();
            }
        }

        switch (nextState)
        {
        case LEFFTTTTTTTTTTTT:
            if (y < p->Y())
            {
                if (p->left)
                {
                    MoveTo(x, p->Y());
                    currState = LEFFTTTTTTTTTTTT;
                    Left();
                }
            }
            break;
        case RIGGHTTTTTTTTTTTT:
            if (y < p->Y())
            {
                if (p->right)
                {
                    MoveTo(x, p->Y());
                    currState = RIGGHTTTTTTTTTTTT;
                    Right();
                }
            }
            break;
        case UUPPPPPPPPPPPP:
            if (y < p->Y())
            {
                if (!p->up)
                {
                    MoveTo(x, p->Y());
                    currState = STOPEEDDDDDDDDDDDD;
                    Stop();
                }
            }
            break;
        case DOWWNNNNNNNNNNNN:
            currState = DOWWNNNNNNNNNNNN;
            Down();
            break;
        }
        break;

    case DOWWNNNNNNNNNNNN:
        // -----------------------
        // CurrentState == DOWN
        // -----------------------

        if (y > p->Y())
        {
            if (!p->down)
            {
                MoveTo(x, p->Y());
                currState = STOPEEDDDDDDDDDDDD;
                Stop();
            }
        }

        switch (nextState)
        {
        case LEFFTTTTTTTTTTTT:
            if (y > p->Y())
            {
                if (p->left)
                {
                    MoveTo(x, p->Y());
                    currState = LEFFTTTTTTTTTTTT;
                    Left();
                }
            }
            break;
        case RIGGHTTTTTTTTTTTT:
            if (y > p->Y())
            {
                if (p->right)
                {
                    MoveTo(x, p->Y());
                    currState = RIGGHTTTTTTTTTTTT;
                    Right();
                }
            }
            break;
        case UUPPPPPPPPPPPP:
            currState = UUPPPPPPPPPPPP;
            Up();
            break;
        case DOWWNNNNNNNNNNNN:
            if (y > p->Y())
            {
                if (!p->down)
                {
                    MoveTo(x, p->Y());
                    currState = STOPEEDDDDDDDDDDDD;
                    Stop();
                }
            }
            break;
        }
        break;
    }
}

// ---------------------------------------------------------------------------------

void Mummy12::Update()
{
    if (part->state == ON)
    {
        srand(time(NULL));
        Sort = 1 + rand() % 4;

        if (Sort == LEFFTTTTTTTTTTTT)
        {
            nextState = LEFFTTTTTTTTTTTT;

            if (currState == RIGGHTTTTTTTTTTTT || currState == STOPEEDDDDDDDDDDDD)
            {
                currState = LEFFTTTTTTTTTTTT;
                Left();
            }
        }

        if (Sort == RIGGHTTTTTTTTTTTT)
        {
            nextState = RIGGHTTTTTTTTTTTT;

            if (currState == LEFFTTTTTTTTTTTT || currState == STOPEEDDDDDDDDDDDD)
            {
                currState = RIGGHTTTTTTTTTTTT;
                Right();
            }
        }

        if (Sort == UUPPPPPPPPPPPP)
        {
            nextState = UUPPPPPPPPPPPP;

            if (currState == DOWWNNNNNNNNNNNN || currState == STOPEEDDDDDDDDDDDD)
            {
                currState = UUPPPPPPPPPPPP;
                Up();
            }
        }

        if (Sort == DOWWNNNNNNNNNNNN)
        {
            nextState = DOWWNNNNNNNNNNNN;

            if (currState == UUPPPPPPPPPPPP || currState == STOPEEDDDDDDDDDDDD)
            {
                currState = DOWWNNNNNNNNNNNN;
                Down();
            }
        }

    }
    else
    {
        nextState = STOPEEDDDDDDDDDDDD;

        if (currState == UUPPPPPPPPPPPP || currState == STOPEEDDDDDDDDDDDD)
        {
            currState = STOPEEDDDDDDDDDDDD;

        }
    }

    // atualiza posição
    Translate(velX * gameTime, velY * gameTime);

    Sort = 1 + rand() % 4;
}

// ---------------------------------------------------------------------------------

void Mummy12::Draw()
{
    switch (currState)
    {
    case LEFFTTTTTTTTTTTT:  spriteL->Draw(x, y, Layer::UPPER); break;
    case RIGGHTTTTTTTTTTTT: spriteR->Draw(x, y, Layer::UPPER); break;
    case UUPPPPPPPPPPPP:    spriteL->Draw(x, y, Layer::UPPER); break;
    case DOWWNNNNNNNNNNNN:  spriteL->Draw(x, y, Layer::UPPER); break;
    default:
        switch (nextState)
        {
        case LEFFTTTTTTTTTTTT:  spriteL->Draw(x, y, Layer::UPPER); break;
        case RIGGHTTTTTTTTTTTT: spriteR->Draw(x, y, Layer::UPPER); break;
        case UUPPPPPPPPPPPP:    spriteL->Draw(x, y, Layer::UPPER); break;
        case DOWWNNNNNNNNNNNN:  spriteL->Draw(x, y, Layer::UPPER); break;
        default:    spriteL->Draw(x, y, Layer::UPPER);
        }
    }
}


// ---------------------------------------------------------------------------------