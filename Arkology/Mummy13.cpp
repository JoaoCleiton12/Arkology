#include "Arkology.h"
#include "Mummy13.h"
#include "Pivot.h"
#include <time.h>

// ---------------------------------------------------------------------------------

Mummy13::Mummy13(Partstatue* p)
{
    part = p;
    Sort = STOPEEDDDDDDDDDDDDD;
    spriteL = new Sprite("Resources/MumiaLabirintoL.png");
    spriteR = new Sprite("Resources/MumiaLabirintoR.png");

    // imagem do jogador é 30x30
    BBox(new Rect(-15, -15, 15, 15));
    MoveTo(167.0f, 615.0f, Layer::FRONT);
    type = MUMMY13;
}

// ---------------------------------------------------------------------------------

Mummy13::~Mummy13()
{
    delete spriteL;
    delete spriteR;
}

// ---------------------------------------------------------------------------------

void Mummy13::Stop()
{
    velX = 0;
    velY = 0;
}

// ---------------------------------------------------------------------------------

void Mummy13::Up()
{
    velX = 0;
    velY = -90.0f;
}

// ---------------------------------------------------------------------------------

void Mummy13::Down()
{
    velX = 0;
    velY = 90.0f;
}

// ---------------------------------------------------------------------------------

void Mummy13::Left()
{
    velX = -90.0f;
    velY = 0;
}

// ---------------------------------------------------------------------------------

void Mummy13::Right()
{
    velX = 90.0f;
    velY = 0;
}

// ---------------------------------------------------------------------------------

void Mummy13::OnCollision(Object* obj)
{
    if (obj->Type() == PIVOT)
        PivotCollision(obj);

    // Colisao com mummia 14
    if (obj->Type() == MUMMY14 && currState == LEFFTTTTTTTTTTTTT)
        nextState = RIGGHTTTTTTTTTTTTT;
    if (obj->Type() == MUMMY14 && currState == RIGGHTTTTTTTTTTTTT)
        nextState = LEFFTTTTTTTTTTTTT;
    if (obj->Type() == MUMMY14 && currState == UUPPPPPPPPPPPPP)
        nextState = DOWWNNNNNNNNNNNNN;
    if (obj->Type() == MUMMY14 && currState == DOWWNNNNNNNNNNNNN)
        nextState = UUPPPPPPPPPPPPP;
}

// ---------------------------------------------------------------------------------

void Mummy13::PivotCollision(Object* obj)
{
    Pivot* p = (Pivot*)obj;

    switch (currState)
    {
    case STOPEEDDDDDDDDDDDDD:
        // -----------------------
        // CurrentState == STOPED
        // -----------------------

        switch (nextState)
        {
        case LEFFTTTTTTTTTTTTT:
            if (p->left)
            {
                currState = LEFFTTTTTTTTTTTTT;
                Left();
            }
            break;
        case RIGGHTTTTTTTTTTTTT:
            if (p->right)
            {
                currState = RIGGHTTTTTTTTTTTTT;
                Right();
            }

            break;
        case UUPPPPPPPPPPPPP:
            if (p->up)
            {
                currState = UUPPPPPPPPPPPPP;
                Up();
            }
            break;
        case DOWWNNNNNNNNNNNNN:
            if (p->down)
            {
                currState = DOWWNNNNNNNNNNNNN;
                Down();
            }
            break;
        }
        break;

    case LEFFTTTTTTTTTTTTT:
        // -----------------------
        // CurrentState == LEFT
        // -----------------------

        if (x < p->X())
        {
            if (!p->left)
            {
                MoveTo(p->X(), Y());
                currState = STOPEEDDDDDDDDDDDDD;
                Stop();
            }
        }

        switch (nextState)
        {
        case LEFFTTTTTTTTTTTTT:
            if (x < p->X())
            {
                if (!p->left)
                {
                    MoveTo(p->X(), Y());
                    currState = STOPEEDDDDDDDDDDDDD;
                    Stop();
                }
            }
            break;
        case RIGGHTTTTTTTTTTTTT:
            currState = RIGGHTTTTTTTTTTTTT;
            Right();

            break;
        case UUPPPPPPPPPPPPP:
            if (x < p->X())
            {
                if (p->up)
                {
                    MoveTo(p->X(), Y());
                    currState = UUPPPPPPPPPPPPP;
                    Up();
                }
            }
            break;
        case DOWWNNNNNNNNNNNNN:
            if (x < p->X())
            {
                if (p->down)
                {
                    MoveTo(p->X(), Y());
                    currState = DOWWNNNNNNNNNNNNN;
                    Down();
                }
            }
            break;
        }
        break;

    case RIGGHTTTTTTTTTTTTT:
        // -----------------------
        // CurrentState == RIGHT
        // -----------------------

        if (x > p->X())
        {
            if (!p->right)
            {
                MoveTo(p->X(), Y());
                currState = STOPEEDDDDDDDDDDDDD;
                Stop();
            }
        }

        switch (nextState)
        {
        case LEFFTTTTTTTTTTTTT:
            currState = LEFFTTTTTTTTTTTTT;
            Left();
            break;
        case RIGGHTTTTTTTTTTTTT:
            if (x > p->X())
            {
                if (!p->right)
                {
                    MoveTo(p->X(), Y());
                    currState = STOPEEDDDDDDDDDDDDD;
                    Stop();
                }
            }

            break;
        case UUPPPPPPPPPPPPP:
            if (x > p->X())
            {
                if (p->up)
                {
                    MoveTo(p->X(), Y());
                    currState = UUPPPPPPPPPPPPP;
                    Up();
                }
            }
            break;
        case DOWWNNNNNNNNNNNNN:
            if (x > p->X())
            {
                if (p->down)
                {
                    MoveTo(p->X(), Y());
                    currState = DOWWNNNNNNNNNNNNN;
                    Down();
                }
            }
            break;
        }
        break;

    case UUPPPPPPPPPPPPP:
        // -----------------------
        // CurrentState == UP
        // -----------------------

        if (y < p->Y())
        {
            if (!p->up)
            {
                MoveTo(x, p->Y());
                currState = STOPEEDDDDDDDDDDDDD;
                Stop();
            }
        }

        switch (nextState)
        {
        case LEFFTTTTTTTTTTTTT:
            if (y < p->Y())
            {
                if (p->left)
                {
                    MoveTo(x, p->Y());
                    currState = LEFFTTTTTTTTTTTTT;
                    Left();
                }
            }
            break;
        case RIGGHTTTTTTTTTTTTT:
            if (y < p->Y())
            {
                if (p->right)
                {
                    MoveTo(x, p->Y());
                    currState = RIGGHTTTTTTTTTTTTT;
                    Right();
                }
            }
            break;
        case UUPPPPPPPPPPPPP:
            if (y < p->Y())
            {
                if (!p->up)
                {
                    MoveTo(x, p->Y());
                    currState = STOPEEDDDDDDDDDDDDD;
                    Stop();
                }
            }
            break;
        case DOWWNNNNNNNNNNNNN:
            currState = DOWWNNNNNNNNNNNNN;
            Down();
            break;
        }
        break;

    case DOWWNNNNNNNNNNNNN:
        // -----------------------
        // CurrentState == DOWN
        // -----------------------

        if (y > p->Y())
        {
            if (!p->down)
            {
                MoveTo(x, p->Y());
                currState = STOPEEDDDDDDDDDDDDD;
                Stop();
            }
        }

        switch (nextState)
        {
        case LEFFTTTTTTTTTTTTT:
            if (y > p->Y())
            {
                if (p->left)
                {
                    MoveTo(x, p->Y());
                    currState = LEFFTTTTTTTTTTTTT;
                    Left();
                }
            }
            break;
        case RIGGHTTTTTTTTTTTTT:
            if (y > p->Y())
            {
                if (p->right)
                {
                    MoveTo(x, p->Y());
                    currState = RIGGHTTTTTTTTTTTTT;
                    Right();
                }
            }
            break;
        case UUPPPPPPPPPPPPP:
            currState = UUPPPPPPPPPPPPP;
            Up();
            break;
        case DOWWNNNNNNNNNNNNN:
            if (y > p->Y())
            {
                if (!p->down)
                {
                    MoveTo(x, p->Y());
                    currState = STOPEEDDDDDDDDDDDDD;
                    Stop();
                }
            }
            break;
        }
        break;
    }
}

// ---------------------------------------------------------------------------------

void Mummy13::Update()
{
    if (part->state == ON)
    {
        srand(time(NULL));
        Sort = rand() % 5;

        if (Sort == LEFFTTTTTTTTTTTTT)
        {
            nextState = LEFFTTTTTTTTTTTTT;

            if (currState == RIGGHTTTTTTTTTTTTT || currState == STOPEEDDDDDDDDDDDDD)
            {
                currState = LEFFTTTTTTTTTTTTT;
                Left();
            }
        }

        if (Sort == RIGGHTTTTTTTTTTTTT)
        {
            nextState = RIGGHTTTTTTTTTTTTT;

            if (currState == LEFFTTTTTTTTTTTTT || currState == STOPEEDDDDDDDDDDDDD)
            {
                currState = RIGGHTTTTTTTTTTTTT;
                Right();
            }
        }

        if (Sort == UUPPPPPPPPPPPPP)
        {
            nextState = UUPPPPPPPPPPPPP;

            if (currState == DOWWNNNNNNNNNNNNN || currState == STOPEEDDDDDDDDDDDDD)
            {
                currState = UUPPPPPPPPPPPPP;
                Up();
            }
        }

        if (Sort == DOWWNNNNNNNNNNNNN)
        {
            nextState = DOWWNNNNNNNNNNNNN;

            if (currState == UUPPPPPPPPPPPPP || currState == STOPEEDDDDDDDDDDDDD)
            {
                currState = DOWWNNNNNNNNNNNNN;
                Down();
            }
        }

    }
    else
    {
        nextState = STOPEEDDDDDDDDDDDDD;

        if (currState == UUPPPPPPPPPPPPP || currState == STOPEEDDDDDDDDDDDDD)
        {
            currState = STOPEEDDDDDDDDDDDDD;

        }
    }

    // atualiza posição
    Translate(velX * gameTime, velY * gameTime);

    Sort = rand() % 5;
}

// ---------------------------------------------------------------------------------

void Mummy13::Draw()
{
    switch (currState)
    {
    case LEFFTTTTTTTTTTTTT:  spriteL->Draw(x, y, Layer::UPPER); break;
    case RIGGHTTTTTTTTTTTTT: spriteR->Draw(x, y, Layer::UPPER); break;
    case UUPPPPPPPPPPPPP:    spriteL->Draw(x, y, Layer::UPPER); break;
    case DOWWNNNNNNNNNNNNN:  spriteL->Draw(x, y, Layer::UPPER); break;
    default:
        switch (nextState)
        {
        case LEFFTTTTTTTTTTTTT:  spriteL->Draw(x, y, Layer::UPPER); break;
        case RIGGHTTTTTTTTTTTTT: spriteR->Draw(x, y, Layer::UPPER); break;
        case UUPPPPPPPPPPPPP:    spriteL->Draw(x, y, Layer::UPPER); break;
        case DOWWNNNNNNNNNNNNN:  spriteL->Draw(x, y, Layer::UPPER); break;
        default:    spriteL->Draw(x, y, Layer::UPPER);
        }
    }
}


// ---------------------------------------------------------------------------------