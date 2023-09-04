#include "Arkology.h"
#include "Mummy10.h"
#include "Pivot.h"
#include <time.h>

// ---------------------------------------------------------------------------------

Mummy10::Mummy10(Partstatue* p)
{
    part = p;
    Sort = STOPEEDDDDDDDDDD;
    spriteL = new Sprite("Resources/MumiaLabirintoL.png");
    spriteR = new Sprite("Resources/MumiaLabirintoR.png");

    // imagem do jogador é 30x30
    BBox(new Rect(-15, -15, 15, 15));
    MoveTo(915.0f, 560.0f, Layer::FRONT);
    type = MUMMY10;
}

// ---------------------------------------------------------------------------------

Mummy10::~Mummy10()
{
    delete spriteL;
    delete spriteR;
}

// ---------------------------------------------------------------------------------

void Mummy10::Stop()
{
    velX = 0;
    velY = 0;
}

// ---------------------------------------------------------------------------------

void Mummy10::Up()
{
    velX = 0;
    velY = -90.0f;
}

// ---------------------------------------------------------------------------------

void Mummy10::Down()
{
    velX = 0;
    velY = 90.0f;
}

// ---------------------------------------------------------------------------------

void Mummy10::Left()
{
    velX = -90.0f;
    velY = 0;
}

// ---------------------------------------------------------------------------------

void Mummy10::Right()
{
    velX = 90.0f;
    velY = 0;
}

// ---------------------------------------------------------------------------------

void Mummy10::OnCollision(Object* obj)
{
    if (obj->Type() == PIVOT)
        PivotCollision(obj);

    // Colisao com mummia 11
    if (obj->Type() == MUMMY11 && currState == LEFFTTTTTTTTTT)
        nextState = RIGGHTTTTTTTTTT;
    if (obj->Type() == MUMMY11 && currState == RIGGHTTTTTTTTTT)
        nextState = LEFFTTTTTTTTTT;
    if (obj->Type() == MUMMY11 && currState == UUPPPPPPPPPP)
        nextState = DOWWNNNNNNNNNN;
    if (obj->Type() == MUMMY11 && currState == DOWWNNNNNNNNNN)
        nextState = UUPPPPPPPPPP;

    // Colisao com mummia 12
    if (obj->Type() == MUMMY12 && currState == LEFFTTTTTTTTTT)
        nextState = RIGGHTTTTTTTTTT;
    if (obj->Type() == MUMMY12 && currState == RIGGHTTTTTTTTTT)
        nextState = LEFFTTTTTTTTTT;
    if (obj->Type() == MUMMY12 && currState == UUPPPPPPPPPP)
        nextState = DOWWNNNNNNNNNN;
    if (obj->Type() == MUMMY12 && currState == DOWWNNNNNNNNNN)
        nextState = UUPPPPPPPPPP;

    // Colisao com mummia 13
    if (obj->Type() == MUMMY13 && currState == LEFFTTTTTTTTTT)
        nextState = RIGGHTTTTTTTTTT;
    if (obj->Type() == MUMMY13 && currState == RIGGHTTTTTTTTTT)
        nextState = LEFFTTTTTTTTTT;
    if (obj->Type() == MUMMY13 && currState == UUPPPPPPPPPP)
        nextState = DOWWNNNNNNNNNN;
    if (obj->Type() == MUMMY13 && currState == DOWWNNNNNNNNNN)
        nextState = UUPPPPPPPPPP;

    // Colisao com mummia 14
    if (obj->Type() == MUMMY14 && currState == LEFFTTTTTTTTTT)
        nextState = RIGGHTTTTTTTTTT;
    if (obj->Type() == MUMMY14 && currState == RIGGHTTTTTTTTTT)
        nextState = LEFFTTTTTTTTTT;
    if (obj->Type() == MUMMY14 && currState == UUPPPPPPPPPP)
        nextState = DOWWNNNNNNNNNN;
    if (obj->Type() == MUMMY14 && currState == DOWWNNNNNNNNNN)
        nextState = UUPPPPPPPPPP;
}

// ---------------------------------------------------------------------------------

void Mummy10::PivotCollision(Object* obj)
{
    Pivot* p = (Pivot*)obj;

    switch (currState)
    {
    case STOPEEDDDDDDDDDD:
        // -----------------------
        // CurrentState == STOPED
        // -----------------------

        switch (nextState)
        {
        case LEFFTTTTTTTTTT:
            if (p->left)
            {
                currState = LEFFTTTTTTTTTT;
                Left();
            }
            break;
        case RIGGHTTTTTTTTTT:
            if (p->right)
            {
                currState = RIGGHTTTTTTTTTT;
                Right();
            }

            break;
        case UUPPPPPPPPPP:
            if (p->up)
            {
                currState = UUPPPPPPPPPP;
                Up();
            }
            break;
        case DOWWNNNNNNNNNN:
            if (p->down)
            {
                currState = DOWWNNNNNNNNNN;
                Down();
            }
            break;
        }
        break;

    case LEFFTTTTTTTTTT:
        // -----------------------
        // CurrentState == LEFT
        // -----------------------

        if (x < p->X())
        {
            if (!p->left)
            {
                MoveTo(p->X(), Y());
                currState = STOPEEDDDDDDDDDD;
                Stop();
            }
        }

        switch (nextState)
        {
        case LEFFTTTTTTTTTT:
            if (x < p->X())
            {
                if (!p->left)
                {
                    MoveTo(p->X(), Y());
                    currState = STOPEEDDDDDDDDDD;
                    Stop();
                }
            }
            break;
        case RIGGHTTTTTTTTTT:
            currState = RIGGHTTTTTTTTTT;
            Right();

            break;
        case UUPPPPPPPPPP:
            if (x < p->X())
            {
                if (p->up)
                {
                    MoveTo(p->X(), Y());
                    currState = UUPPPPPPPPPP;
                    Up();
                }
            }
            break;
        case DOWWNNNNNNNNNN:
            if (x < p->X())
            {
                if (p->down)
                {
                    MoveTo(p->X(), Y());
                    currState = DOWWNNNNNNNNNN;
                    Down();
                }
            }
            break;
        }
        break;

    case RIGGHTTTTTTTTTT:
        // -----------------------
        // CurrentState == RIGHT
        // -----------------------

        if (x > p->X())
        {
            if (!p->right)
            {
                MoveTo(p->X(), Y());
                currState = STOPEEDDDDDDDDDD;
                Stop();
            }
        }

        switch (nextState)
        {
        case LEFFTTTTTTTTTT:
            currState = LEFFTTTTTTTTTT;
            Left();
            break;
        case RIGGHTTTTTTTTTT:
            if (x > p->X())
            {
                if (!p->right)
                {
                    MoveTo(p->X(), Y());
                    currState = STOPEEDDDDDDDDDD;
                    Stop();
                }
            }

            break;
        case UUPPPPPPPPPP:
            if (x > p->X())
            {
                if (p->up)
                {
                    MoveTo(p->X(), Y());
                    currState = UUPPPPPPPPPP;
                    Up();
                }
            }
            break;
        case DOWWNNNNNNNNNN:
            if (x > p->X())
            {
                if (p->down)
                {
                    MoveTo(p->X(), Y());
                    currState = DOWWNNNNNNNNNN;
                    Down();
                }
            }
            break;
        }
        break;

    case UUPPPPPPPPPP:
        // -----------------------
        // CurrentState == UP
        // -----------------------

        if (y < p->Y())
        {
            if (!p->up)
            {
                MoveTo(x, p->Y());
                currState = STOPEEDDDDDDDDDD;
                Stop();
            }
        }

        switch (nextState)
        {
        case LEFFTTTTTTTTTT:
            if (y < p->Y())
            {
                if (p->left)
                {
                    MoveTo(x, p->Y());
                    currState = LEFFTTTTTTTTTT;
                    Left();
                }
            }
            break;
        case RIGGHTTTTTTTTTT:
            if (y < p->Y())
            {
                if (p->right)
                {
                    MoveTo(x, p->Y());
                    currState = RIGGHTTTTTTTTTT;
                    Right();
                }
            }
            break;
        case UUPPPPPPPPPP:
            if (y < p->Y())
            {
                if (!p->up)
                {
                    MoveTo(x, p->Y());
                    currState = STOPEEDDDDDDDDDD;
                    Stop();
                }
            }
            break;
        case DOWWNNNNNNNNNN:
            currState = DOWWNNNNNNNNNN;
            Down();
            break;
        }
        break;

    case DOWWNNNNNNNNNN:
        // -----------------------
        // CurrentState == DOWN
        // -----------------------

        if (y > p->Y())
        {
            if (!p->down)
            {
                MoveTo(x, p->Y());
                currState = STOPEEDDDDDDDDDD;
                Stop();
            }
        }

        switch (nextState)
        {
        case LEFFTTTTTTTTTT:
            if (y > p->Y())
            {
                if (p->left)
                {
                    MoveTo(x, p->Y());
                    currState = LEFFTTTTTTTTTT;
                    Left();
                }
            }
            break;
        case RIGGHTTTTTTTTTT:
            if (y > p->Y())
            {
                if (p->right)
                {
                    MoveTo(x, p->Y());
                    currState = RIGGHTTTTTTTTTT;
                    Right();
                }
            }
            break;
        case UUPPPPPPPPPP:
            currState = UUPPPPPPPPPP;
            Up();
            break;
        case DOWWNNNNNNNNNN:
            if (y > p->Y())
            {
                if (!p->down)
                {
                    MoveTo(x, p->Y());
                    currState = STOPEEDDDDDDDDDD;
                    Stop();
                }
            }
            break;
        }
        break;
    }
}

// ---------------------------------------------------------------------------------

void Mummy10::Update()
{
    if (part->state == ON)
    {
        srand(time(NULL));
        Sort = 1 + rand() % 4;

        if (Sort == LEFFTTTTTTTTTT)
        {
            nextState = LEFFTTTTTTTTTT;

            if (currState == RIGGHTTTTTTTTTT || currState == STOPEEDDDDDDDDDD)
            {
                currState = LEFFTTTTTTTTTT;
                Left();
            }
        }

        if (Sort == RIGGHTTTTTTTTTT)
        {
            nextState = RIGGHTTTTTTTTTT;

            if (currState == LEFFTTTTTTTTTT || currState == STOPEEDDDDDDDDDD)
            {
                currState = RIGGHTTTTTTTTTT;
                Right();
            }
        }

        if (Sort == UUPPPPPPPPPP)
        {
            nextState = UUPPPPPPPPPP;

            if (currState == DOWWNNNNNNNNNN || currState == STOPEEDDDDDDDDDD)
            {
                currState = UUPPPPPPPPPP;
                Up();
            }
        }

        if (Sort == DOWWNNNNNNNNNN)
        {
            nextState = DOWWNNNNNNNNNN;

            if (currState == UUPPPPPPPPPP || currState == STOPEEDDDDDDDDDD)
            {
                currState = DOWWNNNNNNNNNN;
                Down();
            }
        }

    }
    else
    {
        nextState = STOPEEDDDDDDDDDD;

        if (currState == UUPPPPPPPPPP || currState == STOPEEDDDDDDDDDD)
        {
            currState = STOPEEDDDDDDDDDD;

        }
    }

    // atualiza posição
    Translate(velX * gameTime, velY * gameTime);

    Sort = 1 + rand() % 4;
}

// ---------------------------------------------------------------------------------

void Mummy10::Draw()
{
    switch (currState)
    {
    case LEFFTTTTTTTTTT:  spriteL->Draw(x, y, Layer::UPPER); break;
    case RIGGHTTTTTTTTTT: spriteR->Draw(x, y, Layer::UPPER); break;
    case UUPPPPPPPPPP:    spriteL->Draw(x, y, Layer::UPPER); break;
    case DOWWNNNNNNNNNN:  spriteL->Draw(x, y, Layer::UPPER); break;
    default:
        switch (nextState)
        {
        case LEFFTTTTTTTTTT:  spriteL->Draw(x, y, Layer::UPPER); break;
        case RIGGHTTTTTTTTTT: spriteR->Draw(x, y, Layer::UPPER); break;
        case UUPPPPPPPPPP:    spriteL->Draw(x, y, Layer::UPPER); break;
        case DOWWNNNNNNNNNN:  spriteL->Draw(x, y, Layer::UPPER); break;
        default:    spriteL->Draw(x, y, Layer::UPPER);
        }
    }
}


// ---------------------------------------------------------------------------------