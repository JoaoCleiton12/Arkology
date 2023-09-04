#include "Arkology.h"
#include "Mummy14.h"
#include "Pivot.h"
#include <time.h>

// ---------------------------------------------------------------------------------

Mummy14::Mummy14(Partstatue* p)
{
    part = p;
    Sort = STOPEEDDDDDDDDDDDDDD;
    spriteL = new Sprite("Resources/MumiaLabirintoL.png");
    spriteR = new Sprite("Resources/MumiaLabirintoR.png");

    // imagem do jogador é 30x30
    BBox(new Rect(-15, -15, 15, 15));
    MoveTo(112.0f, 660.0f, Layer::FRONT);
    type = MUMMY14;
}

// ---------------------------------------------------------------------------------

Mummy14::~Mummy14()
{
    delete spriteL;
    delete spriteR;
}

// ---------------------------------------------------------------------------------

void Mummy14::Stop()
{
    velX = 0;
    velY = 0;
}

// ---------------------------------------------------------------------------------

void Mummy14::Up()
{
    velX = 0;
    velY = -90.0f;
}

// ---------------------------------------------------------------------------------

void Mummy14::Down()
{
    velX = 0;
    velY = 90.0f;
}

// ---------------------------------------------------------------------------------

void Mummy14::Left()
{
    velX = -90.0f;
    velY = 0;
}

// ---------------------------------------------------------------------------------

void Mummy14::Right()
{
    velX = 90.0f;
    velY = 0;
}

// ---------------------------------------------------------------------------------

void Mummy14::OnCollision(Object* obj)
{
    if (obj->Type() == PIVOT)
        PivotCollision(obj);
}

// ---------------------------------------------------------------------------------

void Mummy14::PivotCollision(Object* obj)
{
    Pivot* p = (Pivot*)obj;

    switch (currState)
    {
    case STOPEEDDDDDDDDDDDDDD:
        // -----------------------
        // CurrentState == STOPED
        // -----------------------

        switch (nextState)
        {
        case LEFFTTTTTTTTTTTTTT:
            if (p->left)
            {
                currState = LEFFTTTTTTTTTTTTTT;
                Left();
            }
            break;
        case RIGGHTTTTTTTTTTTTTT:
            if (p->right)
            {
                currState = RIGGHTTTTTTTTTTTTTT;
                Right();
            }

            break;
        case UUPPPPPPPPPPPPPP:
            if (p->up)
            {
                currState = UUPPPPPPPPPPPPPP;
                Up();
            }
            break;
        case DOWWNNNNNNNNNNNNNN:
            if (p->down)
            {
                currState = DOWWNNNNNNNNNNNNNN;
                Down();
            }
            break;
        }
        break;

    case LEFFTTTTTTTTTTTTTT:
        // -----------------------
        // CurrentState == LEFT
        // -----------------------

        if (x < p->X())
        {
            if (!p->left)
            {
                MoveTo(p->X(), Y());
                currState = STOPEEDDDDDDDDDDDDDD;
                Stop();
            }
        }

        switch (nextState)
        {
        case LEFFTTTTTTTTTTTTTT:
            if (x < p->X())
            {
                if (!p->left)
                {
                    MoveTo(p->X(), Y());
                    currState = STOPEEDDDDDDDDDDDDDD;
                    Stop();
                }
            }
            break;
        case RIGGHTTTTTTTTTTTTTT:
            currState = RIGGHTTTTTTTTTTTTTT;
            Right();

            break;
        case UUPPPPPPPPPPPPPP:
            if (x < p->X())
            {
                if (p->up)
                {
                    MoveTo(p->X(), Y());
                    currState = UUPPPPPPPPPPPPPP;
                    Up();
                }
            }
            break;
        case DOWWNNNNNNNNNNNNNN:
            if (x < p->X())
            {
                if (p->down)
                {
                    MoveTo(p->X(), Y());
                    currState = DOWWNNNNNNNNNNNNNN;
                    Down();
                }
            }
            break;
        }
        break;

    case RIGGHTTTTTTTTTTTTTT:
        // -----------------------
        // CurrentState == RIGHT
        // -----------------------

        if (x > p->X())
        {
            if (!p->right)
            {
                MoveTo(p->X(), Y());
                currState = STOPEEDDDDDDDDDDDDDD;
                Stop();
            }
        }

        switch (nextState)
        {
        case LEFFTTTTTTTTTTTTTT:
            currState = LEFFTTTTTTTTTTTTTT;
            Left();
            break;
        case RIGGHTTTTTTTTTTTTTT:
            if (x > p->X())
            {
                if (!p->right)
                {
                    MoveTo(p->X(), Y());
                    currState = STOPEEDDDDDDDDDDDDDD;
                    Stop();
                }
            }

            break;
        case UUPPPPPPPPPPPPPP:
            if (x > p->X())
            {
                if (p->up)
                {
                    MoveTo(p->X(), Y());
                    currState = UUPPPPPPPPPPPPPP;
                    Up();
                }
            }
            break;
        case DOWWNNNNNNNNNNNNNN:
            if (x > p->X())
            {
                if (p->down)
                {
                    MoveTo(p->X(), Y());
                    currState = DOWWNNNNNNNNNNNNNN;
                    Down();
                }
            }
            break;
        }
        break;

    case UUPPPPPPPPPPPPPP:
        // -----------------------
        // CurrentState == UP
        // -----------------------

        if (y < p->Y())
        {
            if (!p->up)
            {
                MoveTo(x, p->Y());
                currState = STOPEEDDDDDDDDDDDDDD;
                Stop();
            }
        }

        switch (nextState)
        {
        case LEFFTTTTTTTTTTTTTT:
            if (y < p->Y())
            {
                if (p->left)
                {
                    MoveTo(x, p->Y());
                    currState = LEFFTTTTTTTTTTTTTT;
                    Left();
                }
            }
            break;
        case RIGGHTTTTTTTTTTTTTT:
            if (y < p->Y())
            {
                if (p->right)
                {
                    MoveTo(x, p->Y());
                    currState = RIGGHTTTTTTTTTTTTTT;
                    Right();
                }
            }
            break;
        case UUPPPPPPPPPPPPPP:
            if (y < p->Y())
            {
                if (!p->up)
                {
                    MoveTo(x, p->Y());
                    currState = STOPEEDDDDDDDDDDDDDD;
                    Stop();
                }
            }
            break;
        case DOWWNNNNNNNNNNNNNN:
            currState = DOWWNNNNNNNNNNNNNN;
            Down();
            break;
        }
        break;

    case DOWWNNNNNNNNNNNNNN:
        // -----------------------
        // CurrentState == DOWN
        // -----------------------

        if (y > p->Y())
        {
            if (!p->down)
            {
                MoveTo(x, p->Y());
                currState = STOPEEDDDDDDDDDDDDDD;
                Stop();
            }
        }

        switch (nextState)
        {
        case LEFFTTTTTTTTTTTTTT:
            if (y > p->Y())
            {
                if (p->left)
                {
                    MoveTo(x, p->Y());
                    currState = LEFFTTTTTTTTTTTTTT;
                    Left();
                }
            }
            break;
        case RIGGHTTTTTTTTTTTTTT:
            if (y > p->Y())
            {
                if (p->right)
                {
                    MoveTo(x, p->Y());
                    currState = RIGGHTTTTTTTTTTTTTT;
                    Right();
                }
            }
            break;
        case UUPPPPPPPPPPPPPP:
            currState = UUPPPPPPPPPPPPPP;
            Up();
            break;
        case DOWWNNNNNNNNNNNNNN:
            if (y > p->Y())
            {
                if (!p->down)
                {
                    MoveTo(x, p->Y());
                    currState = STOPEEDDDDDDDDDDDDDD;
                    Stop();
                }
            }
            break;
        }
        break;
    }
}

// ---------------------------------------------------------------------------------

void Mummy14::Update()
{
    if (part->state == ON)
    {
        srand(time(NULL));
        Sort = 1 + rand() % 4;

        if (Sort == LEFFTTTTTTTTTTTTTT)
        {
            nextState = LEFFTTTTTTTTTTTTTT;

            if (currState == RIGGHTTTTTTTTTTTTTT || currState == STOPEEDDDDDDDDDDDDDD)
            {
                currState = LEFFTTTTTTTTTTTTTT;
                Left();
            }
        }

        if (Sort == RIGGHTTTTTTTTTTTTTT)
        {
            nextState = RIGGHTTTTTTTTTTTTTT;

            if (currState == LEFFTTTTTTTTTTTTTT || currState == STOPEEDDDDDDDDDDDDDD)
            {
                currState = RIGGHTTTTTTTTTTTTTT;
                Right();
            }
        }

        if (Sort == UUPPPPPPPPPPPPPP)
        {
            nextState = UUPPPPPPPPPPPPPP;

            if (currState == DOWWNNNNNNNNNNNNNN || currState == STOPEEDDDDDDDDDDDDDD)
            {
                currState = UUPPPPPPPPPPPPPP;
                Up();
            }
        }

        if (Sort == DOWWNNNNNNNNNNNNNN)
        {
            nextState = DOWWNNNNNNNNNNNNNN;

            if (currState == UUPPPPPPPPPPPPPP || currState == STOPEEDDDDDDDDDDDDDD)
            {
                currState = DOWWNNNNNNNNNNNNNN;
                Down();
            }
        }

    }
    else
    {
        nextState = STOPEEDDDDDDDDDDDDDD;

        if (currState == UUPPPPPPPPPPPPPP || currState == STOPEEDDDDDDDDDDDDDD)
        {
            currState = STOPEEDDDDDDDDDDDDDD;

        }
    }

    // atualiza posição
    Translate(velX * gameTime, velY * gameTime);

    Sort = 1 + rand() % 4;
}

// ---------------------------------------------------------------------------------

void Mummy14::Draw()
{
    switch (currState)
    {
    case LEFFTTTTTTTTTTTTTT:  spriteL->Draw(x, y, Layer::UPPER); break;
    case RIGGHTTTTTTTTTTTTTT: spriteR->Draw(x, y, Layer::UPPER); break;
    case UUPPPPPPPPPPPPPP:    spriteL->Draw(x, y, Layer::UPPER); break;
    case DOWWNNNNNNNNNNNNNN:  spriteL->Draw(x, y, Layer::UPPER); break;
    default:
        switch (nextState)
        {
        case LEFFTTTTTTTTTTTTTT:  spriteL->Draw(x, y, Layer::UPPER); break;
        case RIGGHTTTTTTTTTTTTTT: spriteR->Draw(x, y, Layer::UPPER); break;
        case UUPPPPPPPPPPPPPP:    spriteL->Draw(x, y, Layer::UPPER); break;
        case DOWWNNNNNNNNNNNNNN:  spriteL->Draw(x, y, Layer::UPPER); break;
        default:    spriteL->Draw(x, y, Layer::UPPER);
        }
    }
}


// ---------------------------------------------------------------------------------