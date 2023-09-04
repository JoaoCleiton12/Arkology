#include "Arkology.h"
#include "Mummy8.h"
#include "Pivot.h"
#include <time.h>

// ---------------------------------------------------------------------------------

Mummy8::Mummy8(Partstatue* p)
{
    part = p;
    Sort = STOPEEDDDDDDDD;
    spriteL = new Sprite("Resources/MumiaLabirintoL.png");
    spriteR = new Sprite("Resources/MumiaLabirintoR.png");

    // imagem do jogador é 30x30
    BBox(new Rect(-15, -15, 15, 15));
    MoveTo(915.0f, 49.0f, Layer::FRONT);
    type = MUMMY8;
}

// ---------------------------------------------------------------------------------

Mummy8::~Mummy8()
{
    delete spriteL;
    delete spriteR;
}

// ---------------------------------------------------------------------------------

void Mummy8::Stop()
{
    velX = 0;
    velY = 0;
}

// ---------------------------------------------------------------------------------

void Mummy8::Up()
{
    velX = 0;
    velY = -90.0f;
}

// ---------------------------------------------------------------------------------

void Mummy8::Down()
{
    velX = 0;
    velY = 90.0f;
}

// ---------------------------------------------------------------------------------

void Mummy8::Left()
{
    velX = -90.0f;
    velY = 0;
}

// ---------------------------------------------------------------------------------

void Mummy8::Right()
{
    velX = 90.0f;
    velY = 0;
}

// ---------------------------------------------------------------------------------

void Mummy8::OnCollision(Object* obj)
{
    if (obj->Type() == PIVOT)
        PivotCollision(obj);

    // Colisao com mummia 9
    if (obj->Type() == MUMMY9 && currState == LEFFTTTTTTTT)
        nextState = RIGGHTTTTTTTT;
    if (obj->Type() == MUMMY9 && currState == RIGGHTTTTTTTT)
        nextState = LEFFTTTTTTTT;
    if (obj->Type() == MUMMY9 && currState == UUPPPPPPPP)
        nextState = DOWWNNNNNNNN;
    if (obj->Type() == MUMMY9 && currState == DOWWNNNNNNNN)
        nextState = UUPPPPPPPP;

    // Colisao com mummia 10
    if (obj->Type() == MUMMY10 && currState == LEFFTTTTTTTT)
        nextState = RIGGHTTTTTTTT;
    if (obj->Type() == MUMMY10 && currState == RIGGHTTTTTTTT)
        nextState = LEFFTTTTTTTT;
    if (obj->Type() == MUMMY10 && currState == UUPPPPPPPP)
        nextState = DOWWNNNNNNNN;
    if (obj->Type() == MUMMY10 && currState == DOWWNNNNNNNN)
        nextState = UUPPPPPPPP;

    // Colisao com mummia 11
    if (obj->Type() == MUMMY11 && currState == LEFFTTTTTTTT)
        nextState = RIGGHTTTTTTTT;
    if (obj->Type() == MUMMY11 && currState == RIGGHTTTTTTTT)
        nextState = LEFFTTTTTTTT;
    if (obj->Type() == MUMMY11 && currState == UUPPPPPPPP)
        nextState = DOWWNNNNNNNN;
    if (obj->Type() == MUMMY11 && currState == DOWWNNNNNNNN)
        nextState = UUPPPPPPPP;

    // Colisao com mummia 12
    if (obj->Type() == MUMMY12 && currState == LEFFTTTTTTTT)
        nextState = RIGGHTTTTTTTT;
    if (obj->Type() == MUMMY12 && currState == RIGGHTTTTTTTT)
        nextState = LEFFTTTTTTTT;
    if (obj->Type() == MUMMY12 && currState == UUPPPPPPPP)
        nextState = DOWWNNNNNNNN;
    if (obj->Type() == MUMMY12 && currState == DOWWNNNNNNNN)
        nextState = UUPPPPPPPP;

    // Colisao com mummia 13
    if (obj->Type() == MUMMY13 && currState == LEFFTTTTTTTT)
        nextState = RIGGHTTTTTTTT;
    if (obj->Type() == MUMMY13 && currState == RIGGHTTTTTTTT)
        nextState = LEFFTTTTTTTT;
    if (obj->Type() == MUMMY13 && currState == UUPPPPPPPP)
        nextState = DOWWNNNNNNNN;
    if (obj->Type() == MUMMY13 && currState == DOWWNNNNNNNN)
        nextState = UUPPPPPPPP;

    // Colisao com mummia 14
    if (obj->Type() == MUMMY14 && currState == LEFFTTTTTTTT)
        nextState = RIGGHTTTTTTTT;
    if (obj->Type() == MUMMY14 && currState == RIGGHTTTTTTTT)
        nextState = LEFFTTTTTTTT;
    if (obj->Type() == MUMMY14 && currState == UUPPPPPPPP)
        nextState = DOWWNNNNNNNN;
    if (obj->Type() == MUMMY14 && currState == DOWWNNNNNNNN)
        nextState = UUPPPPPPPP;
}

// ---------------------------------------------------------------------------------

void Mummy8::PivotCollision(Object* obj)
{
    Pivot* p = (Pivot*)obj;

    switch (currState)
    {
    case STOPEEDDDDDDDD:
        // -----------------------
        // CurrentState == STOPED
        // -----------------------

        switch (nextState)
        {
        case LEFFTTTTTTTT:
            if (p->left)
            {
                currState = LEFFTTTTTTTT;
                Left();
            }
            break;
        case RIGGHTTTTTTTT:
            if (p->right)
            {
                currState = RIGGHTTTTTTTT;
                Right();
            }

            break;
        case UUPPPPPPPP:
            if (p->up)
            {
                currState = UUPPPPPPPP;
                Up();
            }
            break;
        case DOWWNNNNNNNN:
            if (p->down)
            {
                currState = DOWWNNNNNNNN;
                Down();
            }
            break;
        }
        break;

    case LEFFTTTTTTTT:
        // -----------------------
        // CurrentState == LEFT
        // -----------------------

        if (x < p->X())
        {
            if (!p->left)
            {
                MoveTo(p->X(), Y());
                currState = STOPEEDDDDDDDD;
                Stop();
            }
        }

        switch (nextState)
        {
        case LEFFTTTTTTTT:
            if (x < p->X())
            {
                if (!p->left)
                {
                    MoveTo(p->X(), Y());
                    currState = STOPEEDDDDDDDD;
                    Stop();
                }
            }
            break;
        case RIGGHTTTTTTTT:
            currState = RIGGHTTTTTTTT;
            Right();

            break;
        case UUPPPPPPPP:
            if (x < p->X())
            {
                if (p->up)
                {
                    MoveTo(p->X(), Y());
                    currState = UUPPPPPPPP;
                    Up();
                }
            }
            break;
        case DOWWNNNNNNNN:
            if (x < p->X())
            {
                if (p->down)
                {
                    MoveTo(p->X(), Y());
                    currState = DOWWNNNNNNNN;
                    Down();
                }
            }
            break;
        }
        break;

    case RIGGHTTTTTTTT:
        // -----------------------
        // CurrentState == RIGHT
        // -----------------------

        if (x > p->X())
        {
            if (!p->right)
            {
                MoveTo(p->X(), Y());
                currState = STOPEEDDDDDDDD;
                Stop();
            }
        }

        switch (nextState)
        {
        case LEFFTTTTTTTT:
            currState = LEFFTTTTTTTT;
            Left();
            break;
        case RIGGHTTTTTTTT:
            if (x > p->X())
            {
                if (!p->right)
                {
                    MoveTo(p->X(), Y());
                    currState = STOPEEDDDDDDDD;
                    Stop();
                }
            }

            break;
        case UUPPPPPPPP:
            if (x > p->X())
            {
                if (p->up)
                {
                    MoveTo(p->X(), Y());
                    currState = UUPPPPPPPP;
                    Up();
                }
            }
            break;
        case DOWWNNNNNNNN:
            if (x > p->X())
            {
                if (p->down)
                {
                    MoveTo(p->X(), Y());
                    currState = DOWWNNNNNNNN;
                    Down();
                }
            }
            break;
        }
        break;

    case UUPPPPPPPP:
        // -----------------------
        // CurrentState == UP
        // -----------------------

        if (y < p->Y())
        {
            if (!p->up)
            {
                MoveTo(x, p->Y());
                currState = STOPEEDDDDDDDD;
                Stop();
            }
        }

        switch (nextState)
        {
        case LEFFTTTTTTTT:
            if (y < p->Y())
            {
                if (p->left)
                {
                    MoveTo(x, p->Y());
                    currState = LEFFTTTTTTTT;
                    Left();
                }
            }
            break;
        case RIGGHTTTTTTTT:
            if (y < p->Y())
            {
                if (p->right)
                {
                    MoveTo(x, p->Y());
                    currState = RIGGHTTTTTTTT;
                    Right();
                }
            }
            break;
        case UUPPPPPPPP:
            if (y < p->Y())
            {
                if (!p->up)
                {
                    MoveTo(x, p->Y());
                    currState = STOPEEDDDDDDDD;
                    Stop();
                }
            }
            break;
        case DOWWNNNNNNNN:
            currState = DOWWNNNNNNNN;
            Down();
            break;
        }
        break;

    case DOWWNNNNNNNN:
        // -----------------------
        // CurrentState == DOWN
        // -----------------------

        if (y > p->Y())
        {
            if (!p->down)
            {
                MoveTo(x, p->Y());
                currState = STOPEEDDDDDDDD;
                Stop();
            }
        }

        switch (nextState)
        {
        case LEFFTTTTTTTT:
            if (y > p->Y())
            {
                if (p->left)
                {
                    MoveTo(x, p->Y());
                    currState = LEFFTTTTTTTT;
                    Left();
                }
            }
            break;
        case RIGGHTTTTTTTT:
            if (y > p->Y())
            {
                if (p->right)
                {
                    MoveTo(x, p->Y());
                    currState = RIGGHTTTTTTTT;
                    Right();
                }
            }
            break;
        case UUPPPPPPPP:
            currState = UUPPPPPPPP;
            Up();
            break;
        case DOWWNNNNNNNN:
            if (y > p->Y())
            {
                if (!p->down)
                {
                    MoveTo(x, p->Y());
                    currState = STOPEEDDDDDDDD;
                    Stop();
                }
            }
            break;
        }
        break;
    }
}

// ---------------------------------------------------------------------------------

void Mummy8::Update()
{
    if (part->state == ON)
    {
        srand(time(NULL));
        Sort = 1 + rand() % 4;

        if (Sort == LEFFTTTTTTTT)
        {
            nextState = LEFFTTTTTTTT;

            if (currState == RIGGHTTTTTTTT || currState == STOPEEDDDDDDDD)
            {
                currState = LEFFTTTTTTTT;
                Left();
            }
        }

        if (Sort == RIGGHTTTTTTTT)
        {
            nextState = RIGGHTTTTTTTT;

            if (currState == LEFFTTTTTTTT || currState == STOPEEDDDDDDDD)
            {
                currState = RIGGHTTTTTTTT;
                Right();
            }
        }

        if (Sort == UUPPPPPPPP)
        {
            nextState = UUPPPPPPPP;

            if (currState == DOWWNNNNNNNN || currState == STOPEEDDDDDDDD)
            {
                currState = UUPPPPPPPP;
                Up();
            }
        }

        if (Sort == DOWWNNNNNNNN)
        {
            nextState = DOWWNNNNNNNN;

            if (currState == UUPPPPPPPP || currState == STOPEEDDDDDDDD)
            {
                currState = DOWWNNNNNNNN;
                Down();
            }
        }

    }
    else
    {
        nextState = STOPEEDDDDDDDD;

        if (currState == UUPPPPPPPP || currState == STOPEEDDDDDDDD)
        {
            currState = STOPEEDDDDDDDD;

        }
    }

    // atualiza posição
    Translate(velX * gameTime, velY * gameTime);

    Sort = 1 + rand() % 4;

}

// ---------------------------------------------------------------------------------

void Mummy8::Draw()
{
    switch (currState)
    {
    case LEFFTTTTTTTT:  spriteL->Draw(x, y, Layer::UPPER); break;
    case RIGGHTTTTTTTT: spriteR->Draw(x, y, Layer::UPPER); break;
    case UUPPPPPPPP:    spriteL->Draw(x, y, Layer::UPPER); break;
    case DOWWNNNNNNNN:  spriteL->Draw(x, y, Layer::UPPER); break;
    default:
        switch (nextState)
        {
        case LEFFTTTTTTTT:  spriteL->Draw(x, y, Layer::UPPER); break;
        case RIGGHTTTTTTTT: spriteR->Draw(x, y, Layer::UPPER); break;
        case UUPPPPPPPP:    spriteL->Draw(x, y, Layer::UPPER); break;
        case DOWWNNNNNNNN:  spriteL->Draw(x, y, Layer::UPPER); break;
        default:    spriteL->Draw(x, y, Layer::UPPER);
        }
    }
}


// ---------------------------------------------------------------------------------