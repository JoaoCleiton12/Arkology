#include "Arkology.h"
#include "Mummy7.h"
#include "Pivot.h"
#include <time.h>

// ---------------------------------------------------------------------------------

Mummy7::Mummy7(Partstatue* p)
{
    part = p;
    Sort = STOPEEDDDDDDD;
    spriteL = new Sprite("Resources/MumiaLabirintoL.png");
    spriteR = new Sprite("Resources/MumiaLabirintoR.png");

    // imagem do jogador é 30x30
    BBox(new Rect(-15, -15, 15, 15));
    MoveTo(915.0f, 158.0f, Layer::FRONT);
    type = MUMMY7;
}

// ---------------------------------------------------------------------------------

Mummy7::~Mummy7()
{
    delete spriteL;
    delete spriteR;
}

// ---------------------------------------------------------------------------------

void Mummy7::Stop()
{
    velX = 0;
    velY = 0;
}

// ---------------------------------------------------------------------------------

void Mummy7::Up()
{
    velX = 0;
    velY = -90.0f;
}

// ---------------------------------------------------------------------------------

void Mummy7::Down()
{
    velX = 0;
    velY = 90.0f;
}

// ---------------------------------------------------------------------------------

void Mummy7::Left()
{
    velX = -90.0f;
    velY = 0;
}

// ---------------------------------------------------------------------------------

void Mummy7::Right()
{
    velX = 90.0f;
    velY = 0;
}

// ---------------------------------------------------------------------------------

void Mummy7::OnCollision(Object* obj)
{
    if (obj->Type() == PIVOT)
        PivotCollision(obj);

    // Colisao com mummia 8
    if (obj->Type() == MUMMY8 && currState == LEFFTTTTTTT)
        nextState = RIGGHTTTTTTT;
    if (obj->Type() == MUMMY8 && currState == RIGGHTTTTTTT)
        nextState = LEFFTTTTTTT;
    if (obj->Type() == MUMMY8 && currState == UUPPPPPPP)
        nextState = DOWWNNNNNNN;
    if (obj->Type() == MUMMY8 && currState == DOWWNNNNNNN)
        nextState = UUPPPPPPP;

    // Colisao com mummia 9
    if (obj->Type() == MUMMY9 && currState == LEFFTTTTTTT)
        nextState = RIGGHTTTTTTT;
    if (obj->Type() == MUMMY9 && currState == RIGGHTTTTTTT)
        nextState = LEFFTTTTTTT;
    if (obj->Type() == MUMMY9 && currState == UUPPPPPPP)
        nextState = DOWWNNNNNNN;
    if (obj->Type() == MUMMY9 && currState == DOWWNNNNNNN)
        nextState = UUPPPPPPP;

    // Colisao com mummia 10
    if (obj->Type() == MUMMY10 && currState == LEFFTTTTTTT)
        nextState = RIGGHTTTTTTT;
    if (obj->Type() == MUMMY10 && currState == RIGGHTTTTTTT)
        nextState = LEFFTTTTTTT;
    if (obj->Type() == MUMMY10 && currState == UUPPPPPPP)
        nextState = DOWWNNNNNNN;
    if (obj->Type() == MUMMY10 && currState == DOWWNNNNNNN)
        nextState = UUPPPPPPP;

    // Colisao com mummia 11
    if (obj->Type() == MUMMY11 && currState == LEFFTTTTTTT)
        nextState = RIGGHTTTTTTT;
    if (obj->Type() == MUMMY11 && currState == RIGGHTTTTTTT)
        nextState = LEFFTTTTTTT;
    if (obj->Type() == MUMMY11 && currState == UUPPPPPPP)
        nextState = DOWWNNNNNNN;
    if (obj->Type() == MUMMY11 && currState == DOWWNNNNNNN)
        nextState = UUPPPPPPP;

    // Colisao com mummia 12
    if (obj->Type() == MUMMY12 && currState == LEFFTTTTTTT)
        nextState = RIGGHTTTTTTT;
    if (obj->Type() == MUMMY12 && currState == RIGGHTTTTTTT)
        nextState = LEFFTTTTTTT;
    if (obj->Type() == MUMMY12 && currState == UUPPPPPPP)
        nextState = DOWWNNNNNNN;
    if (obj->Type() == MUMMY12 && currState == DOWWNNNNNNN)
        nextState = UUPPPPPPP;

    // Colisao com mummia 13
    if (obj->Type() == MUMMY13 && currState == LEFFTTTTTTT)
        nextState = RIGGHTTTTTTT;
    if (obj->Type() == MUMMY13 && currState == RIGGHTTTTTTT)
        nextState = LEFFTTTTTTT;
    if (obj->Type() == MUMMY13 && currState == UUPPPPPPP)
        nextState = DOWWNNNNNNN;
    if (obj->Type() == MUMMY13 && currState == DOWWNNNNNNN)
        nextState = UUPPPPPPP;

    // Colisao com mummia 14
    if (obj->Type() == MUMMY14 && currState == LEFFTTTTTTT)
        nextState = RIGGHTTTTTTT;
    if (obj->Type() == MUMMY14 && currState == RIGGHTTTTTTT)
        nextState = LEFFTTTTTTT;
    if (obj->Type() == MUMMY14 && currState == UUPPPPPPP)
        nextState = DOWWNNNNNNN;
    if (obj->Type() == MUMMY14 && currState == DOWWNNNNNNN)
        nextState = UUPPPPPPP;
}

// ---------------------------------------------------------------------------------

void Mummy7::PivotCollision(Object* obj)
{
    Pivot* p = (Pivot*)obj;

    switch (currState)
    {
    case STOPEEDDDDDDD:
        // -----------------------
        // CurrentState == STOPED
        // -----------------------

        switch (nextState)
        {
        case LEFFTTTTTTT:
            if (p->left)
            {
                currState = LEFFTTTTTTT;
                Left();
            }
            break;
        case RIGGHTTTTTTT:
            if (p->right)
            {
                currState = RIGGHTTTTTTT;
                Right();
            }

            break;
        case UUPPPPPPP:
            if (p->up)
            {
                currState = UUPPPPPPP;
                Up();
            }
            break;
        case DOWWNNNNNNN:
            if (p->down)
            {
                currState = DOWWNNNNNNN;
                Down();
            }
            break;
        }
        break;

    case LEFFTTTTTTT:
        // -----------------------
        // CurrentState == LEFT
        // -----------------------

        if (x < p->X())
        {
            if (!p->left)
            {
                MoveTo(p->X(), Y());
                currState = STOPEEDDDDDDD;
                Stop();
            }
        }

        switch (nextState)
        {
        case LEFFTTTTTTT:
            if (x < p->X())
            {
                if (!p->left)
                {
                    MoveTo(p->X(), Y());
                    currState = STOPEEDDDDDDD;
                    Stop();
                }
            }
            break;
        case RIGGHTTTTTTT:
            currState = RIGGHTTTTTTT;
            Right();

            break;
        case UUPPPPPPP:
            if (x < p->X())
            {
                if (p->up)
                {
                    MoveTo(p->X(), Y());
                    currState = UUPPPPPPP;
                    Up();
                }
            }
            break;
        case DOWWNNNNNNN:
            if (x < p->X())
            {
                if (p->down)
                {
                    MoveTo(p->X(), Y());
                    currState = DOWWNNNNNNN;
                    Down();
                }
            }
            break;
        }
        break;

    case RIGGHTTTTTTT:
        // -----------------------
        // CurrentState == RIGHT
        // -----------------------

        if (x > p->X())
        {
            if (!p->right)
            {
                MoveTo(p->X(), Y());
                currState = STOPEEDDDDDDD;
                Stop();
            }
        }

        switch (nextState)
        {
        case LEFFTTTTTTT:
            currState = LEFFTTTTTTT;
            Left();
            break;
        case RIGGHTTTTTTT:
            if (x > p->X())
            {
                if (!p->right)
                {
                    MoveTo(p->X(), Y());
                    currState = STOPEEDDDDDDD;
                    Stop();
                }
            }

            break;
        case UUPPPPPPP:
            if (x > p->X())
            {
                if (p->up)
                {
                    MoveTo(p->X(), Y());
                    currState = UUPPPPPPP;
                    Up();
                }
            }
            break;
        case DOWWNNNNNNN:
            if (x > p->X())
            {
                if (p->down)
                {
                    MoveTo(p->X(), Y());
                    currState = DOWWNNNNNNN;
                    Down();
                }
            }
            break;
        }
        break;

    case UUPPPPPPP:
        // -----------------------
        // CurrentState == UP
        // -----------------------

        if (y < p->Y())
        {
            if (!p->up)
            {
                MoveTo(x, p->Y());
                currState = STOPEEDDDDDDD;
                Stop();
            }
        }

        switch (nextState)
        {
        case LEFFTTTTTTT:
            if (y < p->Y())
            {
                if (p->left)
                {
                    MoveTo(x, p->Y());
                    currState = LEFFTTTTTTT;
                    Left();
                }
            }
            break;
        case RIGGHTTTTTTT:
            if (y < p->Y())
            {
                if (p->right)
                {
                    MoveTo(x, p->Y());
                    currState = RIGGHTTTTTTT;
                    Right();
                }
            }
            break;
        case UUPPPPPPP:
            if (y < p->Y())
            {
                if (!p->up)
                {
                    MoveTo(x, p->Y());
                    currState = STOPEEDDDDDDD;
                    Stop();
                }
            }
            break;
        case DOWWNNNNNNN:
            currState = DOWWNNNNNNN;
            Down();
            break;
        }
        break;

    case DOWWNNNNNNN:
        // -----------------------
        // CurrentState == DOWN
        // -----------------------

        if (y > p->Y())
        {
            if (!p->down)
            {
                MoveTo(x, p->Y());
                currState = STOPEEDDDDDDD;
                Stop();
            }
        }

        switch (nextState)
        {
        case LEFFTTTTTTT:
            if (y > p->Y())
            {
                if (p->left)
                {
                    MoveTo(x, p->Y());
                    currState = LEFFTTTTTTT;
                    Left();
                }
            }
            break;
        case RIGGHTTTTTTT:
            if (y > p->Y())
            {
                if (p->right)
                {
                    MoveTo(x, p->Y());
                    currState = RIGGHTTTTTTT;
                    Right();
                }
            }
            break;
        case UUPPPPPPP:
            currState = UUPPPPPPP;
            Up();
            break;
        case DOWWNNNNNNN:
            if (y > p->Y())
            {
                if (!p->down)
                {
                    MoveTo(x, p->Y());
                    currState = STOPEEDDDDDDD;
                    Stop();
                }
            }
            break;
        }
        break;
    }
}

// ---------------------------------------------------------------------------------

void Mummy7::Update()
{
    if (part->state == ON)
    {
        srand(time(NULL));
        Sort = 1 + rand() % 4;

        if (Sort == LEFFTTTTTTT)
        {
            nextState = LEFFTTTTTTT;

            if (currState == RIGGHTTTTTTT || currState == STOPEEDDDDDDD)
            {
                currState = LEFFTTTTTTT;
                Left();
            }
        }

        if (Sort == RIGGHTTTTTTT)
        {
            nextState = RIGGHTTTTTTT;

            if (currState == LEFFTTTTTTT || currState == STOPEEDDDDDDD)
            {
                currState = RIGGHTTTTTTT;
                Right();
            }
        }

        if (Sort == UUPPPPPPP)
        {
            nextState = UUPPPPPPP;

            if (currState == DOWWNNNNNNN || currState == STOPEEDDDDDDD)
            {
                currState = UUPPPPPPP;
                Up();
            }
        }

        if (Sort == DOWWNNNNNNN)
        {
            nextState = DOWWNNNNNNN;

            if (currState == UUPPPPPPP || currState == STOPEEDDDDDDD)
            {
                currState = DOWWNNNNNNN;
                Down();
            }
        }

    }
    else
    {
        nextState = STOPEEDDDDDDD;

        if (currState == UUPPPPPPP || currState == STOPEEDDDDDDD)
        {
            currState = STOPEEDDDDDDD;

        }
    }

    // atualiza posição
    Translate(velX * gameTime, velY * gameTime);

    Sort = 1 + rand() % 4;

}

// ---------------------------------------------------------------------------------

void Mummy7::Draw()
{
    switch (currState)
    {
    case LEFFTTTTTTT:  spriteL->Draw(x, y, Layer::UPPER); break;
    case RIGGHTTTTTTT: spriteR->Draw(x, y, Layer::UPPER); break;
    case UUPPPPPPP:    spriteL->Draw(x, y, Layer::UPPER); break;
    case DOWWNNNNNNN:  spriteL->Draw(x, y, Layer::UPPER); break;
    default:
        switch (nextState)
        {
        case LEFFTTTTTTT:  spriteL->Draw(x, y, Layer::UPPER); break;
        case RIGGHTTTTTTT: spriteR->Draw(x, y, Layer::UPPER); break;
        case UUPPPPPPP:    spriteL->Draw(x, y, Layer::UPPER); break;
        case DOWWNNNNNNN:  spriteL->Draw(x, y, Layer::UPPER); break;
        default:    spriteL->Draw(x, y, Layer::UPPER);
        }
    }
}


// ---------------------------------------------------------------------------------