#include "Arkology.h"
#include "Mummy4.h"
#include "Pivot.h"
#include <time.h>

// ---------------------------------------------------------------------------------

Mummy4::Mummy4(Partstatue* p)
{
    part = p;
    Sort = STOPEEDDDD;
    spriteL = new Sprite("Resources/MumiaLabirintoL.png");
    spriteR = new Sprite("Resources/MumiaLabirintoR.png");

    // imagem do jogador é 30x30
    BBox(new Rect(-15, -15, 15, 15));
    MoveTo(167.0f, 158.0f, Layer::FRONT);
    type = MUMMY4;
}

// ---------------------------------------------------------------------------------

Mummy4::~Mummy4()
{
    delete spriteL;
    delete spriteR;
}

// ---------------------------------------------------------------------------------

void Mummy4::Stop()
{
    velX = 0;
    velY = 0;
}

// ---------------------------------------------------------------------------------

void Mummy4::Up()
{
    velX = 0;
    velY = -90.0f;
}

// ---------------------------------------------------------------------------------

void Mummy4::Down()
{
    velX = 0;
    velY = 90.0f;
}

// ---------------------------------------------------------------------------------

void Mummy4::Left()
{
    velX = -90.0f;
    velY = 0;
}

// ---------------------------------------------------------------------------------

void Mummy4::Right()
{
    velX = 90.0f;
    velY = 0;
}

// ---------------------------------------------------------------------------------

void Mummy4::OnCollision(Object* obj)
{
    if (obj->Type() == PIVOT)
        PivotCollision(obj);

    // Colisao com mummia 5
    if (obj->Type() == MUMMY5 && currState == LEFFTTTT)
        nextState = RIGGHTTTT;
    if (obj->Type() == MUMMY5 && currState == RIGGHTTTT)
        nextState = LEFFTTTT;
    if (obj->Type() == MUMMY5 && currState == UUPPPP)
        nextState = DOWWNNNN;
    if (obj->Type() == MUMMY5 && currState == DOWWNNNN)
        nextState = UUPPPP;

    // Colisao com mummia 6
    if (obj->Type() == MUMMY6 && currState == LEFFTTTT)
        nextState = RIGGHTTTT;
    if (obj->Type() == MUMMY6 && currState == RIGGHTTTT)
        nextState = LEFFTTTT;
    if (obj->Type() == MUMMY6 && currState == UUPPPP)
        nextState = DOWWNNNN;
    if (obj->Type() == MUMMY6 && currState == DOWWNNNN)
        nextState = UUPPPP;

    // Colisao com mummia 7
    if (obj->Type() == MUMMY7 && currState == LEFFTTTT)
        nextState = RIGGHTTTT;
    if (obj->Type() == MUMMY7 && currState == RIGGHTTTT)
        nextState = LEFFTTTT;
    if (obj->Type() == MUMMY7 && currState == UUPPPP)
        nextState = DOWWNNNN;
    if (obj->Type() == MUMMY7 && currState == DOWWNNNN)
        nextState = UUPPPP;

    // Colisao com mummia 8
    if (obj->Type() == MUMMY8 && currState == LEFFTTTT)
        nextState = RIGGHTTTT;
    if (obj->Type() == MUMMY8 && currState == RIGGHTTTT)
        nextState = LEFFTTTT;
    if (obj->Type() == MUMMY8 && currState == UUPPPP)
        nextState = DOWWNNNN;
    if (obj->Type() == MUMMY8 && currState == DOWWNNNN)
        nextState = UUPPPP;

    // Colisao com mummia 9
    if (obj->Type() == MUMMY9 && currState == LEFFTTTT)
        nextState = RIGGHTTTT;
    if (obj->Type() == MUMMY9 && currState == RIGGHTTTT)
        nextState = LEFFTTTT;
    if (obj->Type() == MUMMY9 && currState == UUPPPP)
        nextState = DOWWNNNN;
    if (obj->Type() == MUMMY9 && currState == DOWWNNNN)
        nextState = UUPPPP;

    // Colisao com mummia 10
    if (obj->Type() == MUMMY10 && currState == LEFFTTTT)
        nextState = RIGGHTTTT;
    if (obj->Type() == MUMMY10 && currState == RIGGHTTTT)
        nextState = LEFFTTTT;
    if (obj->Type() == MUMMY10 && currState == UUPPPP)
        nextState = DOWWNNNN;
    if (obj->Type() == MUMMY10 && currState == DOWWNNNN)
        nextState = UUPPPP;

    // Colisao com mummia 11
    if (obj->Type() == MUMMY11 && currState == LEFFTTTT)
        nextState = RIGGHTTTT;
    if (obj->Type() == MUMMY11 && currState == RIGGHTTTT)
        nextState = LEFFTTTT;
    if (obj->Type() == MUMMY11 && currState == UUPPPP)
        nextState = DOWWNNNN;
    if (obj->Type() == MUMMY11 && currState == DOWWNNNN)
        nextState = UUPPPP;

    // Colisao com mummia 12
    if (obj->Type() == MUMMY12 && currState == LEFFTTTT)
        nextState = RIGGHTTTT;
    if (obj->Type() == MUMMY12 && currState == RIGGHTTTT)
        nextState = LEFFTTTT;
    if (obj->Type() == MUMMY12 && currState == UUPPPP)
        nextState = DOWWNNNN;
    if (obj->Type() == MUMMY12 && currState == DOWWNNNN)
        nextState = UUPPPP;

    // Colisao com mummia 13
    if (obj->Type() == MUMMY13 && currState == LEFFTTTT)
        nextState = RIGGHTTTT;
    if (obj->Type() == MUMMY13 && currState == RIGGHTTTT)
        nextState = LEFFTTTT;
    if (obj->Type() == MUMMY13 && currState == UUPPPP)
        nextState = DOWWNNNN;
    if (obj->Type() == MUMMY13 && currState == DOWWNNNN)
        nextState = UUPPPP;

    // Colisao com mummia 14
    if (obj->Type() == MUMMY14 && currState == LEFFTTTT)
        nextState = RIGGHTTTT;
    if (obj->Type() == MUMMY14 && currState == RIGGHTTTT)
        nextState = LEFFTTTT;
    if (obj->Type() == MUMMY14 && currState == UUPPPP)
        nextState = DOWWNNNN;
    if (obj->Type() == MUMMY14 && currState == DOWWNNNN)
        nextState = UUPPPP;
}

// ---------------------------------------------------------------------------------

void Mummy4::PivotCollision(Object* obj)
{
    Pivot* p = (Pivot*)obj;

    switch (currState)
    {
    case STOPEEDDDD:
        // -----------------------
        // CurrentState == STOPED
        // -----------------------

        switch (nextState)
        {
        case LEFFTTTT:
            if (p->left)
            {
                currState = LEFFTTTT;
                Left();
            }
            break;
        case RIGGHTTTT:
            if (p->right)
            {
                currState = RIGGHTTTT;
                Right();
            }

            break;
        case UUPPPP:
            if (p->up)
            {
                currState = UUPPPP;
                Up();
            }
            break;
        case DOWWNNNN:
            if (p->down)
            {
                currState = DOWWNNNN;
                Down();
            }
            break;
        }
        break;

    case LEFFTTTT:
        // -----------------------
        // CurrentState == LEFT
        // -----------------------

        if (x < p->X())
        {
            if (!p->left)
            {
                MoveTo(p->X(), Y());
                currState = STOPEEDDDD;
                Stop();
            }
        }

        switch (nextState)
        {
        case LEFFTTTT:
            if (x < p->X())
            {
                if (!p->left)
                {
                    MoveTo(p->X(), Y());
                    currState = STOPEEDDDD;
                    Stop();
                }
            }
            break;
        case RIGGHTTTT:
            currState = RIGGHTTTT;
            Right();

            break;
        case UUPPPP:
            if (x < p->X())
            {
                if (p->up)
                {
                    MoveTo(p->X(), Y());
                    currState = UUPPPP;
                    Up();
                }
            }
            break;
        case DOWWNNNN:
            if (x < p->X())
            {
                if (p->down)
                {
                    MoveTo(p->X(), Y());
                    currState = DOWWNNNN;
                    Down();
                }
            }
            break;
        }
        break;

    case RIGGHTTTT:
        // -----------------------
        // CurrentState == RIGHT
        // -----------------------

        if (x > p->X())
        {
            if (!p->right)
            {
                MoveTo(p->X(), Y());
                currState = STOPEEDDDD;
                Stop();
            }
        }

        switch (nextState)
        {
        case LEFFTTTT:
            currState = LEFFTTTT;
            Left();
            break;
        case RIGGHTTTT:
            if (x > p->X())
            {
                if (!p->right)
                {
                    MoveTo(p->X(), Y());
                    currState = STOPEEDDDD;
                    Stop();
                }
            }

            break;
        case UUPPPP:
            if (x > p->X())
            {
                if (p->up)
                {
                    MoveTo(p->X(), Y());
                    currState = UUPPPP;
                    Up();
                }
            }
            break;
        case DOWWNNNN:
            if (x > p->X())
            {
                if (p->down)
                {
                    MoveTo(p->X(), Y());
                    currState = DOWWNNNN;
                    Down();
                }
            }
            break;
        }
        break;

    case UUPPPP:
        // -----------------------
        // CurrentState == UP
        // -----------------------

        if (y < p->Y())
        {
            if (!p->up)
            {
                MoveTo(x, p->Y());
                currState = STOPEEDDDD;
                Stop();
            }
        }

        switch (nextState)
        {
        case LEFFTTTT:
            if (y < p->Y())
            {
                if (p->left)
                {
                    MoveTo(x, p->Y());
                    currState = LEFFTTTT;
                    Left();
                }
            }
            break;
        case RIGGHTTTT:
            if (y < p->Y())
            {
                if (p->right)
                {
                    MoveTo(x, p->Y());
                    currState = RIGGHTTTT;
                    Right();
                }
            }
            break;
        case UUPPPP:
            if (y < p->Y())
            {
                if (!p->up)
                {
                    MoveTo(x, p->Y());
                    currState = STOPEEDDDD;
                    Stop();
                }
            }
            break;
        case DOWWNNNN:
            currState = DOWWNNNN;
            Down();
            break;
        }
        break;

    case DOWWNNNN:
        // -----------------------
        // CurrentState == DOWN
        // -----------------------

        if (y > p->Y())
        {
            if (!p->down)
            {
                MoveTo(x, p->Y());
                currState = STOPEEDDDD;
                Stop();
            }
        }

        switch (nextState)
        {
        case LEFFTTTT:
            if (y > p->Y())
            {
                if (p->left)
                {
                    MoveTo(x, p->Y());
                    currState = LEFFTTTT;
                    Left();
                }
            }
            break;
        case RIGGHTTTT:
            if (y > p->Y())
            {
                if (p->right)
                {
                    MoveTo(x, p->Y());
                    currState = RIGGHTTTT;
                    Right();
                }
            }
            break;
        case UUPPPP:
            currState = UUPPPP;
            Up();
            break;
        case DOWWNNNN:
            if (y > p->Y())
            {
                if (!p->down)
                {
                    MoveTo(x, p->Y());
                    currState = STOPEEDDDD;
                    Stop();
                }
            }
            break;
        }
        break;
    }
}

// ---------------------------------------------------------------------------------

void Mummy4::Update()
{
    if (part->state == ON)
    {
        srand(time(NULL));
        Sort = 1 + rand() % 4;

        if (Sort == LEFFTTTT)
        {
            nextState = LEFFTTTT;

            if (currState == RIGGHTTTT || currState == STOPEEDDDD)
            {
                currState = LEFFTTTT;
                Left();
            }
        }

        if (Sort == RIGGHTTTT)
        {
            nextState = RIGGHTTTT;

            if (currState == LEFFTTTT || currState == STOPEEDDDD)
            {
                currState = RIGGHTTTT;
                Right();
            }
        }

        if (Sort == UUPPPP)
        {
            nextState = UUPPPP;

            if (currState == DOWWNNNN || currState == STOPEEDDDD)
            {
                currState = UUPPPP;
                Up();
            }
        }

        if (Sort == DOWWNNNN)
        {
            nextState = DOWWNNNN;

            if (currState == UUPPPP || currState == STOPEEDDDD)
            {
                currState = DOWWNNNN;
                Down();
            }
        }

    }
    else
    {
        nextState = STOPEEDDDD;

        if (currState == UUPPPP || currState == STOPEEDDDD)
        {
            currState = STOPEEDDDD;

        }
    }

    // atualiza posição
    Translate(velX * gameTime, velY * gameTime);

    Sort = 1 + rand() % 4;

}

// ---------------------------------------------------------------------------------

void Mummy4::Draw()
{
    switch (currState)
    {
    case LEFFTTTT:  spriteL->Draw(x, y, Layer::UPPER); break;
    case RIGGHTTTT: spriteR->Draw(x, y, Layer::UPPER); break;
    case UUPPPP:    spriteL->Draw(x, y, Layer::UPPER); break;
    case DOWWNNNN:  spriteL->Draw(x, y, Layer::UPPER); break;
    default:
        switch (nextState)
        {
        case LEFFTTTT:  spriteL->Draw(x, y, Layer::UPPER); break;
        case RIGGHTTTT: spriteR->Draw(x, y, Layer::UPPER); break;
        case UUPPPP:    spriteL->Draw(x, y, Layer::UPPER); break;
        case DOWWNNNN:  spriteL->Draw(x, y, Layer::UPPER); break;
        default:    spriteL->Draw(x, y, Layer::UPPER);
        }
    }
}


// ---------------------------------------------------------------------------------