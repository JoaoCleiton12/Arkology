#include "Arkology.h"
#include "Mummy9.h"
#include "Pivot.h"
#include <time.h>

// ---------------------------------------------------------------------------------

Mummy9::Mummy9(Partstatue* p)
{
    part = p;
    Sort = STOPEEDDDDDDDDD;
    spriteL = new Sprite("Resources/MumiaLabirintoL.png");
    spriteR = new Sprite("Resources/MumiaLabirintoR.png");

    // imagem do jogador é 30x30
    BBox(new Rect(-15, -15, 15, 15));
    MoveTo(915.0f, 660.0f, Layer::FRONT);
    type = MUMMY9;
}

// ---------------------------------------------------------------------------------

Mummy9::~Mummy9()
{
    delete spriteL;
    delete spriteR;
}

// ---------------------------------------------------------------------------------

void Mummy9::Stop()
{
    velX = 0;
    velY = 0;
}

// ---------------------------------------------------------------------------------

void Mummy9::Up()
{
    velX = 0;
    velY = -90.0f;
}

// ---------------------------------------------------------------------------------

void Mummy9::Down()
{
    velX = 0;
    velY = 90.0f;
}

// ---------------------------------------------------------------------------------

void Mummy9::Left()
{
    velX = -90.0f;
    velY = 0;
}

// ---------------------------------------------------------------------------------

void Mummy9::Right()
{
    velX = 90.0f;
    velY = 0;
}

// ---------------------------------------------------------------------------------

void Mummy9::OnCollision(Object* obj)
{
    if (obj->Type() == PIVOT)
        PivotCollision(obj);

    // Colisao com mummia 10
    if (obj->Type() == MUMMY10 && currState == LEFFTTTTTTTTT)
        nextState = RIGGHTTTTTTTTT;
    if (obj->Type() == MUMMY10 && currState == RIGGHTTTTTTTTT)
        nextState = LEFFTTTTTTTTT;
    if (obj->Type() == MUMMY10 && currState == UUPPPPPPPPP)
        nextState = DOWWNNNNNNNNN;
    if (obj->Type() == MUMMY10 && currState == DOWWNNNNNNNNN)
        nextState = UUPPPPPPPPP;

    // Colisao com mummia 11
    if (obj->Type() == MUMMY11 && currState == LEFFTTTTTTTTT)
        nextState = RIGGHTTTTTTTTT;
    if (obj->Type() == MUMMY11 && currState == RIGGHTTTTTTTTT)
        nextState = LEFFTTTTTTTTT;
    if (obj->Type() == MUMMY11 && currState == UUPPPPPPPPP)
        nextState = DOWWNNNNNNNNN;
    if (obj->Type() == MUMMY11 && currState == DOWWNNNNNNNNN)
        nextState = UUPPPPPPPPP;

    // Colisao com mummia 12
    if (obj->Type() == MUMMY12 && currState == LEFFTTTTTTTTT)
        nextState = RIGGHTTTTTTTTT;
    if (obj->Type() == MUMMY12 && currState == RIGGHTTTTTTTTT)
        nextState = LEFFTTTTTTTTT;
    if (obj->Type() == MUMMY12 && currState == UUPPPPPPPPP)
        nextState = DOWWNNNNNNNNN;
    if (obj->Type() == MUMMY12 && currState == DOWWNNNNNNNNN)
        nextState = UUPPPPPPPPP;

    // Colisao com mummia 13
    if (obj->Type() == MUMMY13 && currState == LEFFTTTTTTTTT)
        nextState = RIGGHTTTTTTTTT;
    if (obj->Type() == MUMMY13 && currState == RIGGHTTTTTTTTT)
        nextState = LEFFTTTTTTTTT;
    if (obj->Type() == MUMMY13 && currState == UUPPPPPPPPP)
        nextState = DOWWNNNNNNNNN;
    if (obj->Type() == MUMMY13 && currState == DOWWNNNNNNNNN)
        nextState = UUPPPPPPPPP;

    // Colisao com mummia 14
    if (obj->Type() == MUMMY14 && currState == LEFFTTTTTTTTT)
        nextState = RIGGHTTTTTTTTT;
    if (obj->Type() == MUMMY14 && currState == RIGGHTTTTTTTTT)
        nextState = LEFFTTTTTTTTT;
    if (obj->Type() == MUMMY14 && currState == UUPPPPPPPPP)
        nextState = DOWWNNNNNNNNN;
    if (obj->Type() == MUMMY14 && currState == DOWWNNNNNNNNN)
        nextState = UUPPPPPPPPP;
}

// ---------------------------------------------------------------------------------

void Mummy9::PivotCollision(Object* obj)
{
    Pivot* p = (Pivot*)obj;

    switch (currState)
    {
    case STOPEEDDDDDDDDD:
        // -----------------------
        // CurrentState == STOPED
        // -----------------------

        switch (nextState)
        {
        case LEFFTTTTTTTTT:
            if (p->left)
            {
                currState = LEFFTTTTTTTTT;
                Left();
            }
            break;
        case RIGGHTTTTTTTTT:
            if (p->right)
            {
                currState = RIGGHTTTTTTTTT;
                Right();
            }

            break;
        case UUPPPPPPPPP:
            if (p->up)
            {
                currState = UUPPPPPPPPP;
                Up();
            }
            break;
        case DOWWNNNNNNNNN:
            if (p->down)
            {
                currState = DOWWNNNNNNNNN;
                Down();
            }
            break;
        }
        break;

    case LEFFTTTTTTTTT:
        // -----------------------
        // CurrentState == LEFT
        // -----------------------

        if (x < p->X())
        {
            if (!p->left)
            {
                MoveTo(p->X(), Y());
                currState = STOPEEDDDDDDDDD;
                Stop();
            }
        }

        switch (nextState)
        {
        case LEFFTTTTTTTTT:
            if (x < p->X())
            {
                if (!p->left)
                {
                    MoveTo(p->X(), Y());
                    currState = STOPEEDDDDDDDDD;
                    Stop();
                }
            }
            break;
        case RIGGHTTTTTTTTT:
            currState = RIGGHTTTTTTTTT;
            Right();

            break;
        case UUPPPPPPPPP:
            if (x < p->X())
            {
                if (p->up)
                {
                    MoveTo(p->X(), Y());
                    currState = UUPPPPPPPPP;
                    Up();
                }
            }
            break;
        case DOWWNNNNNNNNN:
            if (x < p->X())
            {
                if (p->down)
                {
                    MoveTo(p->X(), Y());
                    currState = DOWWNNNNNNNNN;
                    Down();
                }
            }
            break;
        }
        break;

    case RIGGHTTTTTTTTT:
        // -----------------------
        // CurrentState == RIGHT
        // -----------------------

        if (x > p->X())
        {
            if (!p->right)
            {
                MoveTo(p->X(), Y());
                currState = STOPEEDDDDDDDDD;
                Stop();
            }
        }

        switch (nextState)
        {
        case LEFFTTTTTTTTT:
            currState = LEFFTTTTTTTTT;
            Left();
            break;
        case RIGGHTTTTTTTTT:
            if (x > p->X())
            {
                if (!p->right)
                {
                    MoveTo(p->X(), Y());
                    currState = STOPEEDDDDDDDDD;
                    Stop();
                }
            }

            break;
        case UUPPPPPPPPP:
            if (x > p->X())
            {
                if (p->up)
                {
                    MoveTo(p->X(), Y());
                    currState = UUPPPPPPPPP;
                    Up();
                }
            }
            break;
        case DOWWNNNNNNNNN:
            if (x > p->X())
            {
                if (p->down)
                {
                    MoveTo(p->X(), Y());
                    currState = DOWWNNNNNNNNN;
                    Down();
                }
            }
            break;
        }
        break;

    case UUPPPPPPPPP:
        // -----------------------
        // CurrentState == UP
        // -----------------------

        if (y < p->Y())
        {
            if (!p->up)
            {
                MoveTo(x, p->Y());
                currState = STOPEEDDDDDDDDD;
                Stop();
            }
        }

        switch (nextState)
        {
        case LEFFTTTTTTTTT:
            if (y < p->Y())
            {
                if (p->left)
                {
                    MoveTo(x, p->Y());
                    currState = LEFFTTTTTTTTT;
                    Left();
                }
            }
            break;
        case RIGGHTTTTTTTTT:
            if (y < p->Y())
            {
                if (p->right)
                {
                    MoveTo(x, p->Y());
                    currState = RIGGHTTTTTTTTT;
                    Right();
                }
            }
            break;
        case UUPPPPPPPPP:
            if (y < p->Y())
            {
                if (!p->up)
                {
                    MoveTo(x, p->Y());
                    currState = STOPEEDDDDDDDDD;
                    Stop();
                }
            }
            break;
        case DOWWNNNNNNNNN:
            currState = DOWWNNNNNNNNN;
            Down();
            break;
        }
        break;

    case DOWWNNNNNNNNN:
        // -----------------------
        // CurrentState == DOWN
        // -----------------------

        if (y > p->Y())
        {
            if (!p->down)
            {
                MoveTo(x, p->Y());
                currState = STOPEEDDDDDDDDD;
                Stop();
            }
        }

        switch (nextState)
        {
        case LEFFTTTTTTTTT:
            if (y > p->Y())
            {
                if (p->left)
                {
                    MoveTo(x, p->Y());
                    currState = LEFFTTTTTTTTT;
                    Left();
                }
            }
            break;
        case RIGGHTTTTTTTTT:
            if (y > p->Y())
            {
                if (p->right)
                {
                    MoveTo(x, p->Y());
                    currState = RIGGHTTTTTTTTT;
                    Right();
                }
            }
            break;
        case UUPPPPPPPPP:
            currState = UUPPPPPPPPP;
            Up();
            break;
        case DOWWNNNNNNNNN:
            if (y > p->Y())
            {
                if (!p->down)
                {
                    MoveTo(x, p->Y());
                    currState = STOPEEDDDDDDDDD;
                    Stop();
                }
            }
            break;
        }
        break;
    }
}

// ---------------------------------------------------------------------------------

void Mummy9::Update()
{
    if (part->state == ON)
    {
        srand(time(NULL));
        Sort = 1 + rand() % 4;

        if (Sort == LEFFTTTTTTTTT)
        {
            nextState = LEFFTTTTTTTTT;

            if (currState == RIGGHTTTTTTTTT || currState == STOPEEDDDDDDDDD)
            {
                currState = LEFFTTTTTTTTT;
                Left();
            }
        }

        if (Sort == RIGGHTTTTTTTTT)
        {
            nextState = RIGGHTTTTTTTTT;

            if (currState == LEFFTTTTTTTTT || currState == STOPEEDDDDDDDDD)
            {
                currState = RIGGHTTTTTTTTT;
                Right();
            }
        }

        if (Sort == UUPPPPPPPPP)
        {
            nextState = UUPPPPPPPPP;

            if (currState == DOWWNNNNNNNNN || currState == STOPEEDDDDDDDDD)
            {
                currState = UUPPPPPPPPP;
                Up();
            }
        }

        if (Sort == DOWWNNNNNNNNN)
        {
            nextState = DOWWNNNNNNNNN;

            if (currState == UUPPPPPPPPP || currState == STOPEEDDDDDDDDD)
            {
                currState = DOWWNNNNNNNNN;
                Down();
            }
        }

    }
    else
    {
        nextState = STOPEEDDDDDDDDD;

        if (currState == UUPPPPPPPPP || currState == STOPEEDDDDDDDDD)
        {
            currState = STOPEEDDDDDDDDD;

        }
    }

    // atualiza posição
    Translate(velX * gameTime, velY * gameTime);

    Sort = 1 + rand() % 4;
}

// ---------------------------------------------------------------------------------

void Mummy9::Draw()
{
    switch (currState)
    {
    case LEFFTTTTTTTTT:  spriteL->Draw(x, y, Layer::UPPER); break;
    case RIGGHTTTTTTTTT: spriteR->Draw(x, y, Layer::UPPER); break;
    case UUPPPPPPPPP:    spriteL->Draw(x, y, Layer::UPPER); break;
    case DOWWNNNNNNNNN:  spriteL->Draw(x, y, Layer::UPPER); break;
    default:
        switch (nextState)
        {
        case LEFFTTTTTTTTT:  spriteL->Draw(x, y, Layer::UPPER); break;
        case RIGGHTTTTTTTTT: spriteR->Draw(x, y, Layer::UPPER); break;
        case UUPPPPPPPPP:    spriteL->Draw(x, y, Layer::UPPER); break;
        case DOWWNNNNNNNNN:  spriteL->Draw(x, y, Layer::UPPER); break;
        default:    spriteL->Draw(x, y, Layer::UPPER);
        }
    }
}


// ---------------------------------------------------------------------------------