#include "Arkology.h"
#include "Mummy11.h"
#include "Pivot.h"
#include <time.h>

// ---------------------------------------------------------------------------------

Mummy11::Mummy11(Partstatue* p)
{
    part = p;
    Sort = STOPEEDDDDDDDDDDD;
    spriteL = new Sprite("Resources/MumiaLabirintoL.png");
    spriteR = new Sprite("Resources/MumiaLabirintoR.png");

    // imagem do jogador é 30x30
    BBox(new Rect(-15, -15, 15, 15));
    MoveTo(795.0f, 615.0f, Layer::FRONT);
    type = MUMMY11;
}

// ---------------------------------------------------------------------------------

Mummy11::~Mummy11()
{
    delete spriteL;
    delete spriteR;
}

// ---------------------------------------------------------------------------------

void Mummy11::Stop()
{
    velX = 0;
    velY = 0;
}

// ---------------------------------------------------------------------------------

void Mummy11::Up()
{
    velX = 0;
    velY = -90.0f;
}

// ---------------------------------------------------------------------------------

void Mummy11::Down()
{
    velX = 0;
    velY = 90.0f;
}

// ---------------------------------------------------------------------------------

void Mummy11::Left()
{
    velX = -90.0f;
    velY = 0;
}

// ---------------------------------------------------------------------------------

void Mummy11::Right()
{
    velX = 90.0f;
    velY = 0;
}

// ---------------------------------------------------------------------------------

void Mummy11::OnCollision(Object* obj)
{
    if (obj->Type() == PIVOT)
        PivotCollision(obj);

    // Colisao com mummia 12
    if (obj->Type() == MUMMY12 && currState == LEFFTTTTTTTTTTT)
        nextState = RIGGHTTTTTTTTTTT;
    if (obj->Type() == MUMMY12 && currState == RIGGHTTTTTTTTTTT)
        nextState = LEFFTTTTTTTTTTT;
    if (obj->Type() == MUMMY12 && currState == UUPPPPPPPPPPP)
        nextState = DOWWNNNNNNNNNNN;
    if (obj->Type() == MUMMY12 && currState == DOWWNNNNNNNNNNN)
        nextState = UUPPPPPPPPPPP;

    // Colisao com mummia 13
    if (obj->Type() == MUMMY13 && currState == LEFFTTTTTTTTTTT)
        nextState = RIGGHTTTTTTTTTTT;
    if (obj->Type() == MUMMY13 && currState == RIGGHTTTTTTTTTTT)
        nextState = LEFFTTTTTTTTTTT;
    if (obj->Type() == MUMMY13 && currState == UUPPPPPPPPPPP)
        nextState = DOWWNNNNNNNNNNN;
    if (obj->Type() == MUMMY13 && currState == DOWWNNNNNNNNNNN)
        nextState = UUPPPPPPPPPPP;

    // Colisao com mummia 14
    if (obj->Type() == MUMMY14 && currState == LEFFTTTTTTTTTTT)
        nextState = RIGGHTTTTTTTTTTT;
    if (obj->Type() == MUMMY14 && currState == RIGGHTTTTTTTTTTT)
        nextState = LEFFTTTTTTTTTTT;
    if (obj->Type() == MUMMY14 && currState == UUPPPPPPPPPPP)
        nextState = DOWWNNNNNNNNNNN;
    if (obj->Type() == MUMMY14 && currState == DOWWNNNNNNNNNNN)
        nextState = UUPPPPPPPPPPP;
}

// ---------------------------------------------------------------------------------

void Mummy11::PivotCollision(Object* obj)
{
    Pivot* p = (Pivot*)obj;

    switch (currState)
    {
    case STOPEEDDDDDDDDDDD:
        // -----------------------
        // CurrentState == STOPED
        // -----------------------

        switch (nextState)
        {
        case LEFFTTTTTTTTTTT:
            if (p->left)
            {
                currState = LEFFTTTTTTTTTTT;
                Left();
            }
            break;
        case RIGGHTTTTTTTTTTT:
            if (p->right)
            {
                currState = RIGGHTTTTTTTTTTT;
                Right();
            }

            break;
        case UUPPPPPPPPPPP:
            if (p->up)
            {
                currState = UUPPPPPPPPPPP;
                Up();
            }
            break;
        case DOWWNNNNNNNNNNN:
            if (p->down)
            {
                currState = DOWWNNNNNNNNNNN;
                Down();
            }
            break;
        }
        break;

    case LEFFTTTTTTTTTTT:
        // -----------------------
        // CurrentState == LEFT
        // -----------------------

        if (x < p->X())
        {
            if (!p->left)
            {
                MoveTo(p->X(), Y());
                currState = STOPEEDDDDDDDDDDD;
                Stop();
            }
        }

        switch (nextState)
        {
        case LEFFTTTTTTTTTTT:
            if (x < p->X())
            {
                if (!p->left)
                {
                    MoveTo(p->X(), Y());
                    currState = STOPEEDDDDDDDDDDD;
                    Stop();
                }
            }
            break;
        case RIGGHTTTTTTTTTTT:
            currState = RIGGHTTTTTTTTTTT;
            Right();

            break;
        case UUPPPPPPPPPPP:
            if (x < p->X())
            {
                if (p->up)
                {
                    MoveTo(p->X(), Y());
                    currState = UUPPPPPPPPPPP;
                    Up();
                }
            }
            break;
        case DOWWNNNNNNNNNNN:
            if (x < p->X())
            {
                if (p->down)
                {
                    MoveTo(p->X(), Y());
                    currState = DOWWNNNNNNNNNNN;
                    Down();
                }
            }
            break;
        }
        break;

    case RIGGHTTTTTTTTTTT:
        // -----------------------
        // CurrentState == RIGHT
        // -----------------------

        if (x > p->X())
        {
            if (!p->right)
            {
                MoveTo(p->X(), Y());
                currState = STOPEEDDDDDDDDDDD;
                Stop();
            }
        }

        switch (nextState)
        {
        case LEFFTTTTTTTTTTT:
            currState = LEFFTTTTTTTTTTT;
            Left();
            break;
        case RIGGHTTTTTTTTTTT:
            if (x > p->X())
            {
                if (!p->right)
                {
                    MoveTo(p->X(), Y());
                    currState = STOPEEDDDDDDDDDDD;
                    Stop();
                }
            }

            break;
        case UUPPPPPPPPPPP:
            if (x > p->X())
            {
                if (p->up)
                {
                    MoveTo(p->X(), Y());
                    currState = UUPPPPPPPPPPP;
                    Up();
                }
            }
            break;
        case DOWWNNNNNNNNNNN:
            if (x > p->X())
            {
                if (p->down)
                {
                    MoveTo(p->X(), Y());
                    currState = DOWWNNNNNNNNNNN;
                    Down();
                }
            }
            break;
        }
        break;

    case UUPPPPPPPPPPP:
        // -----------------------
        // CurrentState == UP
        // -----------------------

        if (y < p->Y())
        {
            if (!p->up)
            {
                MoveTo(x, p->Y());
                currState = STOPEEDDDDDDDDDDD;
                Stop();
            }
        }

        switch (nextState)
        {
        case LEFFTTTTTTTTTTT:
            if (y < p->Y())
            {
                if (p->left)
                {
                    MoveTo(x, p->Y());
                    currState = LEFFTTTTTTTTTTT;
                    Left();
                }
            }
            break;
        case RIGGHTTTTTTTTTTT:
            if (y < p->Y())
            {
                if (p->right)
                {
                    MoveTo(x, p->Y());
                    currState = RIGGHTTTTTTTTTTT;
                    Right();
                }
            }
            break;
        case UUPPPPPPPPPPP:
            if (y < p->Y())
            {
                if (!p->up)
                {
                    MoveTo(x, p->Y());
                    currState = STOPEEDDDDDDDDDDD;
                    Stop();
                }
            }
            break;
        case DOWWNNNNNNNNNNN:
            currState = DOWWNNNNNNNNNNN;
            Down();
            break;
        }
        break;

    case DOWWNNNNNNNNNNN:
        // -----------------------
        // CurrentState == DOWN
        // -----------------------

        if (y > p->Y())
        {
            if (!p->down)
            {
                MoveTo(x, p->Y());
                currState = STOPEEDDDDDDDDDDD;
                Stop();
            }
        }

        switch (nextState)
        {
        case LEFFTTTTTTTTTTT:
            if (y > p->Y())
            {
                if (p->left)
                {
                    MoveTo(x, p->Y());
                    currState = LEFFTTTTTTTTTTT;
                    Left();
                }
            }
            break;
        case RIGGHTTTTTTTTTTT:
            if (y > p->Y())
            {
                if (p->right)
                {
                    MoveTo(x, p->Y());
                    currState = RIGGHTTTTTTTTTTT;
                    Right();
                }
            }
            break;
        case UUPPPPPPPPPPP:
            currState = UUPPPPPPPPPPP;
            Up();
            break;
        case DOWWNNNNNNNNNNN:
            if (y > p->Y())
            {
                if (!p->down)
                {
                    MoveTo(x, p->Y());
                    currState = STOPEEDDDDDDDDDDD;
                    Stop();
                }
            }
            break;
        }
        break;
    }
}

// ---------------------------------------------------------------------------------

void Mummy11::Update()
{
    if (part->state == ON)
    {
        srand(time(NULL));
        Sort = 1 + rand() % 4;

        if (Sort == LEFFTTTTTTTTTTT)
        {
            nextState = LEFFTTTTTTTTTTT;

            if (currState == RIGGHTTTTTTTTTTT || currState == STOPEEDDDDDDDDDDD)
            {
                currState = LEFFTTTTTTTTTTT;
                Left();
            }
        }

        if (Sort == RIGGHTTTTTTTTTTT)
        {
            nextState = RIGGHTTTTTTTTTTT;

            if (currState == LEFFTTTTTTTTTTT || currState == STOPEEDDDDDDDDDDD)
            {
                currState = RIGGHTTTTTTTTTTT;
                Right();
            }
        }

        if (Sort == UUPPPPPPPPPPP)
        {
            nextState = UUPPPPPPPPPPP;

            if (currState == DOWWNNNNNNNNNNN || currState == STOPEEDDDDDDDDDDD)
            {
                currState = UUPPPPPPPPPPP;
                Up();
            }
        }

        if (Sort == DOWWNNNNNNNNNNN)
        {
            nextState = DOWWNNNNNNNNNNN;

            if (currState == UUPPPPPPPPPPP || currState == STOPEEDDDDDDDDDDD)
            {
                currState = DOWWNNNNNNNNNNN;
                Down();
            }
        }

    }
    else
    {
        nextState = STOPEEDDDDDDDDDDD;

        if (currState == UUPPPPPPPPPPP || currState == STOPEEDDDDDDDDDDD)
        {
            currState = STOPEEDDDDDDDDDDD;

        }
    }

    // atualiza posição
    Translate(velX * gameTime, velY * gameTime);

    Sort = 1 + rand() % 4;
}

// ---------------------------------------------------------------------------------

void Mummy11::Draw()
{
    switch (currState)
    {
    case LEFFTTTTTTTTTTT:  spriteL->Draw(x, y, Layer::UPPER); break;
    case RIGGHTTTTTTTTTTT: spriteR->Draw(x, y, Layer::UPPER); break;
    case UUPPPPPPPPPPP:    spriteL->Draw(x, y, Layer::UPPER); break;
    case DOWWNNNNNNNNNNN:  spriteL->Draw(x, y, Layer::UPPER); break;
    default:
        switch (nextState)
        {
        case LEFFTTTTTTTTTTT:  spriteL->Draw(x, y, Layer::UPPER); break;
        case RIGGHTTTTTTTTTTT: spriteR->Draw(x, y, Layer::UPPER); break;
        case UUPPPPPPPPPPP:    spriteL->Draw(x, y, Layer::UPPER); break;
        case DOWWNNNNNNNNNNN:  spriteL->Draw(x, y, Layer::UPPER); break;
        default:    spriteL->Draw(x, y, Layer::UPPER);
        }
    }
}


// ---------------------------------------------------------------------------------