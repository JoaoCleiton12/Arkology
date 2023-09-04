#include "Arkology.h"
#include "Mummy5.h"
#include "Pivot.h"
#include <time.h>

// ---------------------------------------------------------------------------------

Mummy5::Mummy5(Partstatue* p)
{
    part = p;
    Sort = STOPEEDDDDD;
    spriteL = new Sprite("Resources/MumiaLabirintoL.png");
    spriteR = new Sprite("Resources/MumiaLabirintoR.png");

    // imagem do jogador é 30x30
    BBox(new Rect(-15, -15, 15, 15));
    MoveTo(795.0f, 49.0f, Layer::FRONT);
    type = MUMMY5;
}

// ---------------------------------------------------------------------------------

Mummy5::~Mummy5()
{
    delete spriteL;
    delete spriteR;
}

// ---------------------------------------------------------------------------------

void Mummy5::Stop()
{
    velX = 0;
    velY = 0;
}

// ---------------------------------------------------------------------------------

void Mummy5::Up()
{
    velX = 0;
    velY = -90.0f;
}

// ---------------------------------------------------------------------------------

void Mummy5::Down()
{
    velX = 0;
    velY = 90.0f;
}

// ---------------------------------------------------------------------------------

void Mummy5::Left()
{
    velX = -90.0f;
    velY = 0;
}

// ---------------------------------------------------------------------------------

void Mummy5::Right()
{
    velX = 90.0f;
    velY = 0;
}

// ---------------------------------------------------------------------------------

void Mummy5::OnCollision(Object* obj)
{
    if (obj->Type() == PIVOT)
        PivotCollision(obj);


    // Colisao com mummia 6
    if (obj->Type() == MUMMY6 && currState == LEFFTTTTT)
        nextState = RIGGHTTTTT;
    if (obj->Type() == MUMMY6 && currState == RIGGHTTTTT)
        nextState = LEFFTTTTT;
    if (obj->Type() == MUMMY6 && currState == UUPPPPP)
        nextState = DOWWNNNNN;
    if (obj->Type() == MUMMY6 && currState == DOWWNNNNN)
        nextState = UUPPPPP;

    // Colisao com mummia 7
    if (obj->Type() == MUMMY7 && currState == LEFFTTTTT)
        nextState = RIGGHTTTTT;
    if (obj->Type() == MUMMY7 && currState == RIGGHTTTTT)
        nextState = LEFFTTTTT;
    if (obj->Type() == MUMMY7 && currState == UUPPPPP)
        nextState = DOWWNNNNN;
    if (obj->Type() == MUMMY7 && currState == DOWWNNNNN)
        nextState = UUPPPPP;

    // Colisao com mummia 8
    if (obj->Type() == MUMMY8 && currState == LEFFTTTTT)
        nextState = RIGGHTTTTT;
    if (obj->Type() == MUMMY8 && currState == RIGGHTTTTT)
        nextState = LEFFTTTTT;
    if (obj->Type() == MUMMY8 && currState == UUPPPPP)
        nextState = DOWWNNNNN;
    if (obj->Type() == MUMMY8 && currState == DOWWNNNNN)
        nextState = UUPPPPP;

    // Colisao com mummia 9
    if (obj->Type() == MUMMY9 && currState == LEFFTTTTT)
        nextState = RIGGHTTTTT;
    if (obj->Type() == MUMMY9 && currState == RIGGHTTTTT)
        nextState = LEFFTTTTT;
    if (obj->Type() == MUMMY9 && currState == UUPPPPP)
        nextState = DOWWNNNNN;
    if (obj->Type() == MUMMY9 && currState == DOWWNNNNN)
        nextState = UUPPPPP;

    // Colisao com mummia 10
    if (obj->Type() == MUMMY10 && currState == LEFFTTTTT)
        nextState = RIGGHTTTTT;
    if (obj->Type() == MUMMY10 && currState == RIGGHTTTTT)
        nextState = LEFFTTTTT;
    if (obj->Type() == MUMMY10 && currState == UUPPPPP)
        nextState = DOWWNNNNN;
    if (obj->Type() == MUMMY10 && currState == DOWWNNNNN)
        nextState = UUPPPPP;

    // Colisao com mummia 11
    if (obj->Type() == MUMMY11 && currState == LEFFTTTTT)
        nextState = RIGGHTTTTT;
    if (obj->Type() == MUMMY11 && currState == RIGGHTTTTT)
        nextState = LEFFTTTTT;
    if (obj->Type() == MUMMY11 && currState == UUPPPPP)
        nextState = DOWWNNNNN;
    if (obj->Type() == MUMMY11 && currState == DOWWNNNNN)
        nextState = UUPPPPP;

    // Colisao com mummia 12
    if (obj->Type() == MUMMY12 && currState == LEFFTTTTT)
        nextState = RIGGHTTTTT;
    if (obj->Type() == MUMMY12 && currState == RIGGHTTTTT)
        nextState = LEFFTTTTT;
    if (obj->Type() == MUMMY12 && currState == UUPPPPP)
        nextState = DOWWNNNNN;
    if (obj->Type() == MUMMY12 && currState == DOWWNNNNN)
        nextState = UUPPPPP;

    // Colisao com mummia 13
    if (obj->Type() == MUMMY13 && currState == LEFFTTTTT)
        nextState = RIGGHTTTTT;
    if (obj->Type() == MUMMY13 && currState == RIGGHTTTTT)
        nextState = LEFFTTTTT;
    if (obj->Type() == MUMMY13 && currState == UUPPPPP)
        nextState = DOWWNNNNN;
    if (obj->Type() == MUMMY13 && currState == DOWWNNNNN)
        nextState = UUPPPPP;

    // Colisao com mummia 14
    if (obj->Type() == MUMMY14 && currState == LEFFTTTTT)
        nextState = RIGGHTTTTT;
    if (obj->Type() == MUMMY14 && currState == RIGGHTTTTT)
        nextState = LEFFTTTTT;
    if (obj->Type() == MUMMY14 && currState == UUPPPPP)
        nextState = DOWWNNNNN;
    if (obj->Type() == MUMMY14 && currState == DOWWNNNNN)
        nextState = UUPPPPP;
}

// ---------------------------------------------------------------------------------

void Mummy5::PivotCollision(Object* obj)
{
    Pivot* p = (Pivot*)obj;

    switch (currState)
    {
    case STOPEEDDDDD:
        // -----------------------
        // CurrentState == STOPED
        // -----------------------

        switch (nextState)
        {
        case LEFFTTTTT:
            if (p->left)
            {
                currState = LEFFTTTTT;
                Left();
            }
            break;
        case RIGGHTTTTT:
            if (p->right)
            {
                currState = RIGGHTTTTT;
                Right();
            }

            break;
        case UUPPPPP:
            if (p->up)
            {
                currState = UUPPPPP;
                Up();
            }
            break;
        case DOWWNNNNN:
            if (p->down)
            {
                currState = DOWWNNNNN;
                Down();
            }
            break;
        }
        break;

    case LEFFTTTTT:
        // -----------------------
        // CurrentState == LEFT
        // -----------------------

        if (x < p->X())
        {
            if (!p->left)
            {
                MoveTo(p->X(), Y());
                currState = STOPEEDDDDD;
                Stop();
            }
        }

        switch (nextState)
        {
        case LEFFTTTTT:
            if (x < p->X())
            {
                if (!p->left)
                {
                    MoveTo(p->X(), Y());
                    currState = STOPEEDDDDD;
                    Stop();
                }
            }
            break;
        case RIGGHTTTTT:
            currState = RIGGHTTTTT;
            Right();

            break;
        case UUPPPPP:
            if (x < p->X())
            {
                if (p->up)
                {
                    MoveTo(p->X(), Y());
                    currState = UUPPPPP;
                    Up();
                }
            }
            break;
        case DOWWNNNNN:
            if (x < p->X())
            {
                if (p->down)
                {
                    MoveTo(p->X(), Y());
                    currState = DOWWNNNNN;
                    Down();
                }
            }
            break;
        }
        break;

    case RIGGHTTTTT:
        // -----------------------
        // CurrentState == RIGHT
        // -----------------------

        if (x > p->X())
        {
            if (!p->right)
            {
                MoveTo(p->X(), Y());
                currState = STOPEEDDDDD;
                Stop();
            }
        }

        switch (nextState)
        {
        case LEFFTTTTT:
            currState = LEFFTTTTT;
            Left();
            break;
        case RIGGHTTTTT:
            if (x > p->X())
            {
                if (!p->right)
                {
                    MoveTo(p->X(), Y());
                    currState = STOPEEDDDDD;
                    Stop();
                }
            }

            break;
        case UUPPPPP:
            if (x > p->X())
            {
                if (p->up)
                {
                    MoveTo(p->X(), Y());
                    currState = UUPPPPP;
                    Up();
                }
            }
            break;
        case DOWWNNNNN:
            if (x > p->X())
            {
                if (p->down)
                {
                    MoveTo(p->X(), Y());
                    currState = DOWWNNNNN;
                    Down();
                }
            }
            break;
        }
        break;

    case UUPPPPP:
        // -----------------------
        // CurrentState == UP
        // -----------------------

        if (y < p->Y())
        {
            if (!p->up)
            {
                MoveTo(x, p->Y());
                currState = STOPEEDDDDD;
                Stop();
            }
        }

        switch (nextState)
        {
        case LEFFTTTTT:
            if (y < p->Y())
            {
                if (p->left)
                {
                    MoveTo(x, p->Y());
                    currState = LEFFTTTTT;
                    Left();
                }
            }
            break;
        case RIGGHTTTTT:
            if (y < p->Y())
            {
                if (p->right)
                {
                    MoveTo(x, p->Y());
                    currState = RIGGHTTTTT;
                    Right();
                }
            }
            break;
        case UUPPPPP:
            if (y < p->Y())
            {
                if (!p->up)
                {
                    MoveTo(x, p->Y());
                    currState = STOPEEDDDDD;
                    Stop();
                }
            }
            break;
        case DOWWNNNNN:
            currState = DOWWNNNNN;
            Down();
            break;
        }
        break;

    case DOWWNNNNN:
        // -----------------------
        // CurrentState == DOWN
        // -----------------------

        if (y > p->Y())
        {
            if (!p->down)
            {
                MoveTo(x, p->Y());
                currState = STOPEEDDDDD;
                Stop();
            }
        }

        switch (nextState)
        {
        case LEFFTTTTT:
            if (y > p->Y())
            {
                if (p->left)
                {
                    MoveTo(x, p->Y());
                    currState = LEFFTTTTT;
                    Left();
                }
            }
            break;
        case RIGGHTTTTT:
            if (y > p->Y())
            {
                if (p->right)
                {
                    MoveTo(x, p->Y());
                    currState = RIGGHTTTTT;
                    Right();
                }
            }
            break;
        case UUPPPPP:
            currState = UUPPPPP;
            Up();
            break;
        case DOWWNNNNN:
            if (y > p->Y())
            {
                if (!p->down)
                {
                    MoveTo(x, p->Y());
                    currState = STOPEEDDDDD;
                    Stop();
                }
            }
            break;
        }
        break;
    }
}

// ---------------------------------------------------------------------------------

void Mummy5::Update()
{
    if (part->state == ON)
    {
        srand(time(NULL));
        Sort = 1 + rand() % 4;

        if (Sort == LEFFTTTTT)
        {
            nextState = LEFFTTTTT;

            if (currState == RIGGHTTTTT || currState == STOPEEDDDDD)
            {
                currState = LEFFTTTTT;
                Left();
            }
        }

        if (Sort == RIGGHTTTTT)
        {
            nextState = RIGGHTTTTT;

            if (currState == LEFFTTTTT || currState == STOPEEDDDDD)
            {
                currState = RIGGHTTTTT;
                Right();
            }
        }

        if (Sort == UUPPPPP)
        {
            nextState = UUPPPPP;

            if (currState == DOWWNNNNN || currState == STOPEEDDDDD)
            {
                currState = UUPPPPP;
                Up();
            }
        }

        if (Sort == DOWWNNNNN)
        {
            nextState = DOWWNNNNN;

            if (currState == UUPPPPP || currState == STOPEEDDDDD)
            {
                currState = DOWWNNNNN;
                Down();
            }
        }

    }
    else
    {
        nextState = STOPEEDDDDD;

        if (currState == UUPPPPP || currState == STOPEEDDDDD)
        {
            currState = STOPEEDDDDD;

        }
    }

    // atualiza posição
    Translate(velX * gameTime, velY * gameTime);

    Sort = 1 + rand() % 4;

}

// ---------------------------------------------------------------------------------

void Mummy5::Draw()
{
    switch (currState)
    {
    case LEFFTTTTT:  spriteL->Draw(x, y, Layer::UPPER); break;
    case RIGGHTTTTT: spriteR->Draw(x, y, Layer::UPPER); break;
    case UUPPPPP:    spriteL->Draw(x, y, Layer::UPPER); break;
    case DOWWNNNNN:  spriteL->Draw(x, y, Layer::UPPER); break;
    default:
        switch (nextState)
        {
        case LEFFTTTTT:  spriteL->Draw(x, y, Layer::UPPER); break;
        case RIGGHTTTTT: spriteR->Draw(x, y, Layer::UPPER); break;
        case UUPPPPP:    spriteL->Draw(x, y, Layer::UPPER); break;
        case DOWWNNNNN:  spriteL->Draw(x, y, Layer::UPPER); break;
        default:    spriteL->Draw(x, y, Layer::UPPER);
        }
    }
}


// ---------------------------------------------------------------------------------