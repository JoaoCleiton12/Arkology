#include "Arkology.h"
#include "Mummy6.h"
#include "Pivot.h"
#include <time.h>

// ---------------------------------------------------------------------------------

Mummy6::Mummy6(Partstatue* p)
{
    part = p;
    Sort = STOPEEDDDDDD;
    spriteL = new Sprite("Resources/MumiaLabirintoL.png");
    spriteR = new Sprite("Resources/MumiaLabirintoR.png");

    // imagem do jogador é 30x30
    BBox(new Rect(-15, -15, 15, 15));
    MoveTo(795.0f, 158.0f, Layer::FRONT);
    type = MUMMY6;
}

// ---------------------------------------------------------------------------------

Mummy6::~Mummy6()
{
    delete spriteL;
    delete spriteR;
}

// ---------------------------------------------------------------------------------

void Mummy6::Stop()
{
    velX = 0;
    velY = 0;
}

// ---------------------------------------------------------------------------------

void Mummy6::Up()
{
    velX = 0;
    velY = -90.0f;
}

// ---------------------------------------------------------------------------------

void Mummy6::Down()
{
    velX = 0;
    velY = 90.0f;
}

// ---------------------------------------------------------------------------------

void Mummy6::Left()
{
    velX = -90.0f;
    velY = 0;
}

// ---------------------------------------------------------------------------------

void Mummy6::Right()
{
    velX = 90.0f;
    velY = 0;
}

// ---------------------------------------------------------------------------------

void Mummy6::OnCollision(Object* obj)
{
    if (obj->Type() == PIVOT)
        PivotCollision(obj);

    // Colisao com mummia 7
    if (obj->Type() == MUMMY7 && currState == LEFFTTTTTT)
        nextState = RIGGHTTTTTT;
    if (obj->Type() == MUMMY7 && currState == RIGGHTTTTTT)
        nextState = LEFFTTTTTT;
    if (obj->Type() == MUMMY7 && currState == UUPPPPPP)
        nextState = DOWWNNNNNN;
    if (obj->Type() == MUMMY7 && currState == DOWWNNNNNN)
        nextState = UUPPPPPP;

    // Colisao com mummia 8
    if (obj->Type() == MUMMY8 && currState == LEFFTTTTTT)
        nextState = RIGGHTTTTTT;
    if (obj->Type() == MUMMY8 && currState == RIGGHTTTTTT)
        nextState = LEFFTTTTTT;
    if (obj->Type() == MUMMY8 && currState == UUPPPPPP)
        nextState = DOWWNNNNNN;
    if (obj->Type() == MUMMY8 && currState == DOWWNNNNNN)
        nextState = UUPPPPPP;

    // Colisao com mummia 9
    if (obj->Type() == MUMMY9 && currState == LEFFTTTTTT)
        nextState = RIGGHTTTTTT;
    if (obj->Type() == MUMMY9 && currState == RIGGHTTTTTT)
        nextState = LEFFTTTTTT;
    if (obj->Type() == MUMMY9 && currState == UUPPPPPP)
        nextState = DOWWNNNNNN;
    if (obj->Type() == MUMMY9 && currState == DOWWNNNNNN)
        nextState = UUPPPPPP;

    // Colisao com mummia 10
    if (obj->Type() == MUMMY10 && currState == LEFFTTTTTT)
        nextState = RIGGHTTTTTT;
    if (obj->Type() == MUMMY10 && currState == RIGGHTTTTTT)
        nextState = LEFFTTTTTT;
    if (obj->Type() == MUMMY10 && currState == UUPPPPPP)
        nextState = DOWWNNNNNN;
    if (obj->Type() == MUMMY10 && currState == DOWWNNNNNN)
        nextState = UUPPPPPP;

    // Colisao com mummia 11
    if (obj->Type() == MUMMY11 && currState == LEFFTTTTTT)
        nextState = RIGGHTTTTTT;
    if (obj->Type() == MUMMY11 && currState == RIGGHTTTTTT)
        nextState = LEFFTTTTTT;
    if (obj->Type() == MUMMY11 && currState == UUPPPPPP)
        nextState = DOWWNNNNNN;
    if (obj->Type() == MUMMY11 && currState == DOWWNNNNNN)
        nextState = UUPPPPPP;

    // Colisao com mummia 12
    if (obj->Type() == MUMMY12 && currState == LEFFTTTTTT)
        nextState = RIGGHTTTTTT;
    if (obj->Type() == MUMMY12 && currState == RIGGHTTTTTT)
        nextState = LEFFTTTTTT;
    if (obj->Type() == MUMMY12 && currState == UUPPPPPP)
        nextState = DOWWNNNNNN;
    if (obj->Type() == MUMMY12 && currState == DOWWNNNNNN)
        nextState = UUPPPPPP;

    // Colisao com mummia 13
    if (obj->Type() == MUMMY13 && currState == LEFFTTTTTT)
        nextState = RIGGHTTTTTT;
    if (obj->Type() == MUMMY13 && currState == RIGGHTTTTTT)
        nextState = LEFFTTTTTT;
    if (obj->Type() == MUMMY13 && currState == UUPPPPPP)
        nextState = DOWWNNNNNN;
    if (obj->Type() == MUMMY13 && currState == DOWWNNNNNN)
        nextState = UUPPPPPP;

    // Colisao com mummia 14
    if (obj->Type() == MUMMY14 && currState == LEFFTTTTTT)
        nextState = RIGGHTTTTTT;
    if (obj->Type() == MUMMY14 && currState == RIGGHTTTTTT)
        nextState = LEFFTTTTTT;
    if (obj->Type() == MUMMY14 && currState == UUPPPPPP)
        nextState = DOWWNNNNNN;
    if (obj->Type() == MUMMY14 && currState == DOWWNNNNNN)
        nextState = UUPPPPPP;
}

// ---------------------------------------------------------------------------------

void Mummy6::PivotCollision(Object* obj)
{
    Pivot* p = (Pivot*)obj;

    switch (currState)
    {
    case STOPEEDDDDDD:
        // -----------------------
        // CurrentState == STOPED
        // -----------------------

        switch (nextState)
        {
        case LEFFTTTTTT:
            if (p->left)
            {
                currState = LEFFTTTTTT;
                Left();
            }
            break;
        case RIGGHTTTTTT:
            if (p->right)
            {
                currState = RIGGHTTTTTT;
                Right();
            }

            break;
        case UUPPPPPP:
            if (p->up)
            {
                currState = UUPPPPPP;
                Up();
            }
            break;
        case DOWWNNNNNN:
            if (p->down)
            {
                currState = DOWWNNNNNN;
                Down();
            }
            break;
        }
        break;

    case LEFFTTTTTT:
        // -----------------------
        // CurrentState == LEFT
        // -----------------------

        if (x < p->X())
        {
            if (!p->left)
            {
                MoveTo(p->X(), Y());
                currState = STOPEEDDDDDD;
                Stop();
            }
        }

        switch (nextState)
        {
        case LEFFTTTTTT:
            if (x < p->X())
            {
                if (!p->left)
                {
                    MoveTo(p->X(), Y());
                    currState = STOPEEDDDDDD;
                    Stop();
                }
            }
            break;
        case RIGGHTTTTTT:
            currState = RIGGHTTTTTT;
            Right();

            break;
        case UUPPPPPP:
            if (x < p->X())
            {
                if (p->up)
                {
                    MoveTo(p->X(), Y());
                    currState = UUPPPPPP;
                    Up();
                }
            }
            break;
        case DOWWNNNNNN:
            if (x < p->X())
            {
                if (p->down)
                {
                    MoveTo(p->X(), Y());
                    currState = DOWWNNNNNN;
                    Down();
                }
            }
            break;
        }
        break;

    case RIGGHTTTTTT:
        // -----------------------
        // CurrentState == RIGHT
        // -----------------------

        if (x > p->X())
        {
            if (!p->right)
            {
                MoveTo(p->X(), Y());
                currState = STOPEEDDDDDD;
                Stop();
            }
        }

        switch (nextState)
        {
        case LEFFTTTTTT:
            currState = LEFFTTTTTT;
            Left();
            break;
        case RIGGHTTTTTT:
            if (x > p->X())
            {
                if (!p->right)
                {
                    MoveTo(p->X(), Y());
                    currState = STOPEEDDDDDD;
                    Stop();
                }
            }

            break;
        case UUPPPPPP:
            if (x > p->X())
            {
                if (p->up)
                {
                    MoveTo(p->X(), Y());
                    currState = UUPPPPPP;
                    Up();
                }
            }
            break;
        case DOWWNNNNNN:
            if (x > p->X())
            {
                if (p->down)
                {
                    MoveTo(p->X(), Y());
                    currState = DOWWNNNNNN;
                    Down();
                }
            }
            break;
        }
        break;

    case UUPPPPPP:
        // -----------------------
        // CurrentState == UP
        // -----------------------

        if (y < p->Y())
        {
            if (!p->up)
            {
                MoveTo(x, p->Y());
                currState = STOPEEDDDDDD;
                Stop();
            }
        }

        switch (nextState)
        {
        case LEFFTTTTTT:
            if (y < p->Y())
            {
                if (p->left)
                {
                    MoveTo(x, p->Y());
                    currState = LEFFTTTTTT;
                    Left();
                }
            }
            break;
        case RIGGHTTTTTT:
            if (y < p->Y())
            {
                if (p->right)
                {
                    MoveTo(x, p->Y());
                    currState = RIGGHTTTTTT;
                    Right();
                }
            }
            break;
        case UUPPPPPP:
            if (y < p->Y())
            {
                if (!p->up)
                {
                    MoveTo(x, p->Y());
                    currState = STOPEEDDDDDD;
                    Stop();
                }
            }
            break;
        case DOWWNNNNNN:
            currState = DOWWNNNNNN;
            Down();
            break;
        }
        break;

    case DOWWNNNNNN:
        // -----------------------
        // CurrentState == DOWN
        // -----------------------

        if (y > p->Y())
        {
            if (!p->down)
            {
                MoveTo(x, p->Y());
                currState = STOPEEDDDDDD;
                Stop();
            }
        }

        switch (nextState)
        {
        case LEFFTTTTTT:
            if (y > p->Y())
            {
                if (p->left)
                {
                    MoveTo(x, p->Y());
                    currState = LEFFTTTTTT;
                    Left();
                }
            }
            break;
        case RIGGHTTTTTT:
            if (y > p->Y())
            {
                if (p->right)
                {
                    MoveTo(x, p->Y());
                    currState = RIGGHTTTTTT;
                    Right();
                }
            }
            break;
        case UUPPPPPP:
            currState = UUPPPPPP;
            Up();
            break;
        case DOWWNNNNNN:
            if (y > p->Y())
            {
                if (!p->down)
                {
                    MoveTo(x, p->Y());
                    currState = STOPEEDDDDDD;
                    Stop();
                }
            }
            break;
        }
        break;
    }
}

// ---------------------------------------------------------------------------------

void Mummy6::Update()
{
    if (part->state == ON)
    {
        srand(time(NULL));
        Sort = 1 + rand() % 4;

        if (Sort == LEFFTTTTTT)
        {
            nextState = LEFFTTTTTT;

            if (currState == RIGGHTTTTTT || currState == STOPEEDDDDDD)
            {
                currState = LEFFTTTTTT;
                Left();
            }
        }

        if (Sort == RIGGHTTTTTT)
        {
            nextState = RIGGHTTTTTT;

            if (currState == LEFFTTTTTT || currState == STOPEEDDDDDD)
            {
                currState = RIGGHTTTTTT;
                Right();
            }
        }

        if (Sort == UUPPPPPP)
        {
            nextState = UUPPPPPP;

            if (currState == DOWWNNNNNN || currState == STOPEEDDDDDD)
            {
                currState = UUPPPPPP;
                Up();
            }
        }

        if (Sort == DOWWNNNNNN)
        {
            nextState = DOWWNNNNNN;

            if (currState == UUPPPPPP || currState == STOPEEDDDDDD)
            {
                currState = DOWWNNNNNN;
                Down();
            }
        }

    }
    else
    {
        nextState = STOPEEDDDDDD;

        if (currState == UUPPPPPP || currState == STOPEEDDDDDD)
        {
            currState = STOPEEDDDDDD;

        }
    }

    // atualiza posição
    Translate(velX * gameTime, velY * gameTime);

    Sort = 1 + rand() % 4;

}

// ---------------------------------------------------------------------------------

void Mummy6::Draw()
{
    switch (currState)
    {
    case LEFFTTTTTT:  spriteL->Draw(x, y, Layer::UPPER); break;
    case RIGGHTTTTTT: spriteR->Draw(x, y, Layer::UPPER); break;
    case UUPPPPPP:    spriteL->Draw(x, y, Layer::UPPER); break;
    case DOWWNNNNNN:  spriteL->Draw(x, y, Layer::UPPER); break;
    default:
        switch (nextState)
        {
        case LEFFTTTTTT:  spriteL->Draw(x, y, Layer::UPPER); break;
        case RIGGHTTTTTT: spriteR->Draw(x, y, Layer::UPPER); break;
        case UUPPPPPP:    spriteL->Draw(x, y, Layer::UPPER); break;
        case DOWWNNNNNN:  spriteL->Draw(x, y, Layer::UPPER); break;
        default:    spriteL->Draw(x, y, Layer::UPPER);
        }
    }
}


// ---------------------------------------------------------------------------------