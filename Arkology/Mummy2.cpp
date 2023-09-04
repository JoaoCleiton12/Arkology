#include "Arkology.h"
#include "Mummy2.h"
#include "Pivot.h"
#include <time.h>

// ---------------------------------------------------------------------------------

Mummy2::Mummy2(Partstatue* p)
{
    part = p;
    Sort = STOPEEDD;
    spriteL = new Sprite("Resources/MumiaLabirintoL.png");
    spriteR = new Sprite("Resources/MumiaLabirintoR.png");

    // imagem do jogador é 30x30
    BBox(new Rect(-15, -15, 15, 15));
    MoveTo(47.0f, 158.0f, Layer::FRONT);
    type = MUMMY2;
}

// ---------------------------------------------------------------------------------

Mummy2::~Mummy2()
{
    delete spriteL;
    delete spriteR;
}

// ---------------------------------------------------------------------------------

void Mummy2::Stop()
{
    velX = 0;
    velY = 0;
}

// ---------------------------------------------------------------------------------

void Mummy2::Up()
{
    velX = 0;
    velY = -90.0f;
}

// ---------------------------------------------------------------------------------

void Mummy2::Down()
{
    velX = 0;
    velY = 90.0f;
}

// ---------------------------------------------------------------------------------

void Mummy2::Left()
{
    velX = -90.0f;
    velY = 0;
}

// ---------------------------------------------------------------------------------

void Mummy2::Right()
{
    velX = 90.0f;
    velY = 0;
}

// ---------------------------------------------------------------------------------

void Mummy2::OnCollision(Object* obj)
{
    if (obj->Type() == PIVOT)
        PivotCollision(obj);
    // Colisao com mummia 3
    if (obj->Type() == MUMMY3 && currState == LEFFTT)
        nextState = RIGGHTT;
    if (obj->Type() == MUMMY3 && currState == RIGGHTT)
        nextState = LEFFTT;
    if (obj->Type() == MUMMY3 && currState == UUPP)
        nextState = DOWWNN;
    if (obj->Type() == MUMMY3 && currState == DOWWNN)
        nextState = UUPP;

    // Colisao com mummia 4
    if (obj->Type() == MUMMY4 && currState == LEFFTT)
        nextState = RIGGHTT;
    if (obj->Type() == MUMMY4 && currState == RIGGHTT)
        nextState = LEFFTT;
    if (obj->Type() == MUMMY4 && currState == UUPP)
        nextState = DOWWNN;
    if (obj->Type() == MUMMY4 && currState == DOWWNN)
        nextState = UUPP;
    
    // Colisao com mummia 5
    if (obj->Type() == MUMMY5 && currState == LEFFTT)
        nextState = RIGGHTT;
    if (obj->Type() == MUMMY5 && currState == RIGGHTT)
        nextState = LEFFTT;
    if (obj->Type() == MUMMY5 && currState == UUPP)
        nextState = DOWWNN;
    if (obj->Type() == MUMMY5 && currState == DOWWNN)
        nextState = UUPP;

    // Colisao com mummia 6
    if (obj->Type() == MUMMY6 && currState == LEFFTT)
        nextState = RIGGHTT;
    if (obj->Type() == MUMMY6 && currState == RIGGHTT)
        nextState = LEFFTT;
    if (obj->Type() == MUMMY6 && currState == UUPP)
        nextState = DOWWNN;
    if (obj->Type() == MUMMY6 && currState == DOWWNN)
        nextState = UUPP;

    // Colisao com mummia 7
    if (obj->Type() == MUMMY7 && currState == LEFFTT)
        nextState = RIGGHTT;
    if (obj->Type() == MUMMY7 && currState == RIGGHTT)
        nextState = LEFFTT;
    if (obj->Type() == MUMMY7 && currState == UUPP)
        nextState = DOWWNN;
    if (obj->Type() == MUMMY7 && currState == DOWWNN)
        nextState = UUPP;

    // Colisao com mummia 8
    if (obj->Type() == MUMMY8 && currState == LEFFTT)
        nextState = RIGGHTT;
    if (obj->Type() == MUMMY8 && currState == RIGGHTT)
        nextState = LEFFTT;
    if (obj->Type() == MUMMY8 && currState == UUPP)
        nextState = DOWWNN;
    if (obj->Type() == MUMMY8 && currState == DOWWNN)
        nextState = UUPP;

    // Colisao com mummia 9
    if (obj->Type() == MUMMY9 && currState == LEFFTT)
        nextState = RIGGHTT;
    if (obj->Type() == MUMMY9 && currState == RIGGHTT)
        nextState = LEFFTT;
    if (obj->Type() == MUMMY9 && currState == UUPP)
        nextState = DOWWNN;
    if (obj->Type() == MUMMY9 && currState == DOWWNN)
        nextState = UUPP;

    // Colisao com mummia 10
    if (obj->Type() == MUMMY10 && currState == LEFFTT)
        nextState = RIGGHTT;
    if (obj->Type() == MUMMY10 && currState == RIGGHTT)
        nextState = LEFFTT;
    if (obj->Type() == MUMMY10 && currState == UUPP)
        nextState = DOWWNN;
    if (obj->Type() == MUMMY10 && currState == DOWWNN)
        nextState = UUPP;

    // Colisao com mummia 11
    if (obj->Type() == MUMMY11 && currState == LEFFTT)
        nextState = RIGGHTT;
    if (obj->Type() == MUMMY11 && currState == RIGGHTT)
        nextState = LEFFTT;
    if (obj->Type() == MUMMY11 && currState == UUPP)
        nextState = DOWWNN;
    if (obj->Type() == MUMMY11 && currState == DOWWNN)
        nextState = UUPP;

    // Colisao com mummia 12
    if (obj->Type() == MUMMY12 && currState == LEFFTT)
        nextState = RIGGHTT;
    if (obj->Type() == MUMMY12 && currState == RIGGHTT)
        nextState = LEFFTT;
    if (obj->Type() == MUMMY12 && currState == UUPP)
        nextState = DOWWNN;
    if (obj->Type() == MUMMY12 && currState == DOWWNN)
        nextState = UUPP;

    // Colisao com mummia 13
    if (obj->Type() == MUMMY13 && currState == LEFFTT)
        nextState = RIGGHTT;
    if (obj->Type() == MUMMY13 && currState == RIGGHTT)
        nextState = LEFFTT;
    if (obj->Type() == MUMMY13 && currState == UUPP)
        nextState = DOWWNN;
    if (obj->Type() == MUMMY13 && currState == DOWWNN)
        nextState = UUPP;

    // Colisao com mummia 14
    if (obj->Type() == MUMMY14 && currState == LEFFTT)
        nextState = RIGGHTT;
    if (obj->Type() == MUMMY14 && currState == RIGGHTT)
        nextState = LEFFTT;
    if (obj->Type() == MUMMY14 && currState == UUPP)
        nextState = DOWWNN;
    if (obj->Type() == MUMMY14 && currState == DOWWNN)
        nextState = UUPP;
}

// ---------------------------------------------------------------------------------

void Mummy2::PivotCollision(Object* obj)
{
    Pivot* p = (Pivot*)obj;

    switch (currState)
    {
    case STOPEEDD:
        // -----------------------
        // CurrentState == STOPED
        // -----------------------

        switch (nextState)
        {
        case LEFFTT:
            if (p->left)
            {
                currState = LEFFTT;
                Left();
            }
            break;
        case RIGGHTT:
            if (p->right)
            {
                currState = RIGGHTT;
                Right();
            }

            break;
        case UUPP:
            if (p->up)
            {
                currState = UUPP;
                Up();
            }
            break;
        case DOWWNN:
            if (p->down)
            {
                currState = DOWWNN;
                Down();
            }
            break;
        }
        break;

    case LEFFTT:
        // -----------------------
        // CurrentState == LEFT
        // -----------------------

        if (x < p->X())
        {
            if (!p->left)
            {
                MoveTo(p->X(), Y());
                currState = STOPEEDD;
                Stop();
            }
        }

        switch (nextState)
        {
        case LEFFTT:
            if (x < p->X())
            {
                if (!p->left)
                {
                    MoveTo(p->X(), Y());
                    currState = STOPEEDD;
                    Stop();
                }
            }
            break;
        case RIGGHTT:
            currState = RIGGHTT;
            Right();

            break;
        case UUPP:
            if (x < p->X())
            {
                if (p->up)
                {
                    MoveTo(p->X(), Y());
                    currState = UUPP;
                    Up();
                }
            }
            break;
        case DOWWNN:
            if (x < p->X())
            {
                if (p->down)
                {
                    MoveTo(p->X(), Y());
                    currState = DOWWNN;
                    Down();
                }
            }
            break;
        }
        break;

    case RIGGHTT:
        // -----------------------
        // CurrentState == RIGHT
        // -----------------------

        if (x > p->X())
        {
            if (!p->right)
            {
                MoveTo(p->X(), Y());
                currState = STOPEEDD;
                Stop();
            }
        }

        switch (nextState)
        {
        case LEFFTT:
            currState = LEFFTT;
            Left();
            break;
        case RIGGHTT:
            if (x > p->X())
            {
                if (!p->right)
                {
                    MoveTo(p->X(), Y());
                    currState = STOPEEDD;
                    Stop();
                }
            }

            break;
        case UUPP:
            if (x > p->X())
            {
                if (p->up)
                {
                    MoveTo(p->X(), Y());
                    currState = UUPP;
                    Up();
                }
            }
            break;
        case DOWWNN:
            if (x > p->X())
            {
                if (p->down)
                {
                    MoveTo(p->X(), Y());
                    currState = DOWWNN;
                    Down();
                }
            }
            break;
        }
        break;

    case UUPP:
        // -----------------------
        // CurrentState == UP
        // -----------------------

        if (y < p->Y())
        {
            if (!p->up)
            {
                MoveTo(x, p->Y());
                currState = STOPEEDD;
                Stop();
            }
        }

        switch (nextState)
        {
        case LEFFTT:
            if (y < p->Y())
            {
                if (p->left)
                {
                    MoveTo(x, p->Y());
                    currState = LEFFTT;
                    Left();
                }
            }
            break;
        case RIGGHTT:
            if (y < p->Y())
            {
                if (p->right)
                {
                    MoveTo(x, p->Y());
                    currState = RIGGHTT;
                    Right();
                }
            }
            break;
        case UUPP:
            if (y < p->Y())
            {
                if (!p->up)
                {
                    MoveTo(x, p->Y());
                    currState = STOPEEDD;
                    Stop();
                }
            }
            break;
        case DOWWNN:
            currState = DOWWNN;
            Down();
            break;
        }
        break;

    case DOWWNN:
        // -----------------------
        // CurrentState == DOWN
        // -----------------------

        if (y > p->Y())
        {
            if (!p->down)
            {
                MoveTo(x, p->Y());
                currState = STOPEEDD;
                Stop();
            }
        }

        switch (nextState)
        {
        case LEFFTT:
            if (y > p->Y())
            {
                if (p->left)
                {
                    MoveTo(x, p->Y());
                    currState = LEFFTT;
                    Left();
                }
            }
            break;
        case RIGGHTT:
            if (y > p->Y())
            {
                if (p->right)
                {
                    MoveTo(x, p->Y());
                    currState = RIGGHTT;
                    Right();
                }
            }
            break;
        case UUPP:
            currState = UUPP;
            Up();
            break;
        case DOWWNN:
            if (y > p->Y())
            {
                if (!p->down)
                {
                    MoveTo(x, p->Y());
                    currState = STOPEEDD;
                    Stop();
                }
            }
            break;
        }
        break;
    }
}

// ---------------------------------------------------------------------------------

void Mummy2::Update()
{
    if (part->state == ON)
    {
        srand(time(NULL));
        Sort = 1 + rand() % 4;

        if (Sort == LEFFTT)
        {
            nextState = LEFFTT;

            if (currState == RIGGHTT || currState == STOPEEDD)
            {
                currState = LEFFTT;
                Left();
            }
        }

        if (Sort == RIGGHTT)
        {
            nextState = RIGGHTT;

            if (currState == LEFFTT || currState == STOPEEDD)
            {
                currState = RIGGHTT;
                Right();
            }
        }

        if (Sort == UUPP)
        {
            nextState = UUPP;

            if (currState == DOWWNN || currState == STOPEEDD)
            {
                currState = UUPP;
                Up();
            }
        }

        if (Sort == DOWWNN)
        {
            nextState = DOWWNN;

            if (currState == UUPP || currState == STOPEEDD)
            {
                currState = DOWWNN;
                Down();
            }
        }

    }
    else
    {
        nextState = STOPEEDD;

        if (currState == UUPP || currState == STOPEEDD)
        {
            currState = STOPEEDD;

        }
    }

    // atualiza posição
    Translate(velX * gameTime, velY * gameTime);

    Sort = 1 + rand() % 4;

}

// ---------------------------------------------------------------------------------

void Mummy2::Draw()
{
    switch (currState)
    {
    case LEFFTT:  spriteL->Draw(x, y, Layer::UPPER); break;
    case RIGGHTT: spriteR->Draw(x, y, Layer::UPPER); break;
    case UUPP:    spriteL->Draw(x, y, Layer::UPPER); break;
    case DOWWNN:  spriteL->Draw(x, y, Layer::UPPER); break;
    default:
        switch (nextState)
        {
        case LEFFTT:  spriteL->Draw(x, y, Layer::UPPER); break;
        case RIGGHTT: spriteR->Draw(x, y, Layer::UPPER); break;
        case UUPP:    spriteL->Draw(x, y, Layer::UPPER); break;
        case DOWWNN:  spriteL->Draw(x, y, Layer::UPPER); break;
        default:    spriteL->Draw(x, y, Layer::UPPER);
        }
    }
}


// ---------------------------------------------------------------------------------