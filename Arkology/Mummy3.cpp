#include "Arkology.h"
#include "Mummy3.h"
#include "Pivot.h"
#include <time.h>

// ---------------------------------------------------------------------------------

Mummy3::Mummy3(Partstatue* p)
{
    part = p;
    Sort = STOPEEDDD;
    spriteL = new Sprite("Resources/MumiaLabirintoL.png");
    spriteR = new Sprite("Resources/MumiaLabirintoR.png");

    // imagem do jogador é 30x30
    BBox(new Rect(-15, -15, 15, 15));
    MoveTo(47.0f, 49.0f, Layer::FRONT);
    type = MUMMY3;
}

// ---------------------------------------------------------------------------------

Mummy3::~Mummy3()
{
    delete spriteL;
    delete spriteR;
}

// ---------------------------------------------------------------------------------

void Mummy3::Stop()
{
    velX = 0;
    velY = 0;
}

// ---------------------------------------------------------------------------------

void Mummy3::Up()
{
    velX = 0;
    velY = -90.0f;
}

// ---------------------------------------------------------------------------------

void Mummy3::Down()
{
    velX = 0;
    velY = 90.0f;
}

// ---------------------------------------------------------------------------------

void Mummy3::Left()
{
    velX = -90.0f;
    velY = 0;
}

// ---------------------------------------------------------------------------------

void Mummy3::Right()
{
    velX = 90.0f;
    velY = 0;
}

// ---------------------------------------------------------------------------------

void Mummy3::OnCollision(Object* obj)
{
    if (obj->Type() == PIVOT)
        PivotCollision(obj);

    // Colisao com mummia 4
    if (obj->Type() == MUMMY4 && currState == LEFFTTT)
        nextState = RIGGHTTT;
    if (obj->Type() == MUMMY4 && currState == RIGGHTTT)
        nextState = LEFFTTT;
    if (obj->Type() == MUMMY4 && currState == UUPPP)
        nextState = DOWWNNN;
    if (obj->Type() == MUMMY4 && currState == DOWWNNN)
        nextState = UUPPP;
    
    // Colisao com mummia 5
    if (obj->Type() == MUMMY5 && currState == LEFFTTT)
        nextState = RIGGHTTT;
    if (obj->Type() == MUMMY5 && currState == RIGGHTTT)
        nextState = LEFFTTT;
    if (obj->Type() == MUMMY5 && currState == UUPPP)
        nextState = DOWWNNN;
    if (obj->Type() == MUMMY5 && currState == DOWWNNN)
        nextState = UUPPP;

    // Colisao com mummia 6
    if (obj->Type() == MUMMY6 && currState == LEFFTTT)
        nextState = RIGGHTTT;
    if (obj->Type() == MUMMY6 && currState == RIGGHTTT)
        nextState = LEFFTTT;
    if (obj->Type() == MUMMY6 && currState == UUPPP)
        nextState = DOWWNNN;
    if (obj->Type() == MUMMY6 && currState == DOWWNNN)
        nextState = UUPPP;

    // Colisao com mummia 7
    if (obj->Type() == MUMMY7 && currState == LEFFTTT)
        nextState = RIGGHTTT;
    if (obj->Type() == MUMMY7 && currState == RIGGHTTT)
        nextState = LEFFTTT;
    if (obj->Type() == MUMMY7 && currState == UUPPP)
        nextState = DOWWNNN;
    if (obj->Type() == MUMMY7 && currState == DOWWNNN)
        nextState = UUPPP;

    // Colisao com mummia 8
    if (obj->Type() == MUMMY8 && currState == LEFFTTT)
        nextState = RIGGHTTT;
    if (obj->Type() == MUMMY8 && currState == RIGGHTTT)
        nextState = LEFFTTT;
    if (obj->Type() == MUMMY8 && currState == UUPPP)
        nextState = DOWWNNN;
    if (obj->Type() == MUMMY8 && currState == DOWWNNN)
        nextState = UUPPP;

    // Colisao com mummia 9
    if (obj->Type() == MUMMY9 && currState == LEFFTTT)
        nextState = RIGGHTTT;
    if (obj->Type() == MUMMY9 && currState == RIGGHTTT)
        nextState = LEFFTTT;
    if (obj->Type() == MUMMY9 && currState == UUPPP)
        nextState = DOWWNNN;
    if (obj->Type() == MUMMY9 && currState == DOWWNNN)
        nextState = UUPPP;

    // Colisao com mummia 10
    if (obj->Type() == MUMMY10 && currState == LEFFTTT)
        nextState = RIGGHTTT;
    if (obj->Type() == MUMMY10 && currState == RIGGHTTT)
        nextState = LEFFTTT;
    if (obj->Type() == MUMMY10 && currState == UUPPP)
        nextState = DOWWNNN;
    if (obj->Type() == MUMMY10 && currState == DOWWNNN)
        nextState = UUPPP;

    // Colisao com mummia 11
    if (obj->Type() == MUMMY11 && currState == LEFFTTT)
        nextState = RIGGHTTT;
    if (obj->Type() == MUMMY11 && currState == RIGGHTTT)
        nextState = LEFFTTT;
    if (obj->Type() == MUMMY11 && currState == UUPPP)
        nextState = DOWWNNN;
    if (obj->Type() == MUMMY11 && currState == DOWWNNN)
        nextState = UUPPP;

    // Colisao com mummia 12
    if (obj->Type() == MUMMY12 && currState == LEFFTTT)
        nextState = RIGGHTTT;
    if (obj->Type() == MUMMY12 && currState == RIGGHTTT)
        nextState = LEFFTTT;
    if (obj->Type() == MUMMY12 && currState == UUPPP)
        nextState = DOWWNNN;
    if (obj->Type() == MUMMY12 && currState == DOWWNNN)
        nextState = UUPPP;

    // Colisao com mummia 13
    if (obj->Type() == MUMMY13 && currState == LEFFTTT)
        nextState = RIGGHTTT;
    if (obj->Type() == MUMMY13 && currState == RIGGHTTT)
        nextState = LEFFTTT;
    if (obj->Type() == MUMMY13 && currState == UUPPP)
        nextState = DOWWNNN;
    if (obj->Type() == MUMMY13 && currState == DOWWNNN)
        nextState = UUPPP;

    // Colisao com mummia 14
    if (obj->Type() == MUMMY14 && currState == LEFFTTT)
        nextState = RIGGHTTT;
    if (obj->Type() == MUMMY14 && currState == RIGGHTTT)
        nextState = LEFFTTT;
    if (obj->Type() == MUMMY14 && currState == UUPPP)
        nextState = DOWWNNN;
    if (obj->Type() == MUMMY14 && currState == DOWWNNN)
        nextState = UUPPP;
}

// ---------------------------------------------------------------------------------

void Mummy3::PivotCollision(Object* obj)
{
    Pivot* p = (Pivot*)obj;

    switch (currState)
    {
    case STOPEEDDD:
        // -----------------------
        // CurrentState == STOPED
        // -----------------------

        switch (nextState)
        {
        case LEFFTTT:
            if (p->left)
            {
                currState = LEFFTTT;
                Left();
            }
            break;
        case RIGGHTTT:
            if (p->right)
            {
                currState = RIGGHTTT;
                Right();
            }

            break;
        case UUPPP:
            if (p->up)
            {
                currState = UUPPP;
                Up();
            }
            break;
        case DOWWNNN:
            if (p->down)
            {
                currState = DOWWNNN;
                Down();
            }
            break;
        }
        break;

    case LEFFTTT:
        // -----------------------
        // CurrentState == LEFT
        // -----------------------

        if (x < p->X())
        {
            if (!p->left)
            {
                MoveTo(p->X(), Y());
                currState = STOPEEDDD;
                Stop();
            }
        }

        switch (nextState)
        {
        case LEFFTTT:
            if (x < p->X())
            {
                if (!p->left)
                {
                    MoveTo(p->X(), Y());
                    currState = STOPEEDDD;
                    Stop();
                }
            }
            break;
        case RIGGHTTT:
            currState = RIGGHTTT;
            Right();

            break;
        case UUPPP:
            if (x < p->X())
            {
                if (p->up)
                {
                    MoveTo(p->X(), Y());
                    currState = UUPPP;
                    Up();
                }
            }
            break;
        case DOWWNNN:
            if (x < p->X())
            {
                if (p->down)
                {
                    MoveTo(p->X(), Y());
                    currState = DOWWNNN;
                    Down();
                }
            }
            break;
        }
        break;

    case RIGGHTTT:
        // -----------------------
        // CurrentState == RIGHT
        // -----------------------

        if (x > p->X())
        {
            if (!p->right)
            {
                MoveTo(p->X(), Y());
                currState = STOPEEDDD;
                Stop();
            }
        }

        switch (nextState)
        {
        case LEFFTTT:
            currState = LEFFTTT;
            Left();
            break;
        case RIGGHTTT:
            if (x > p->X())
            {
                if (!p->right)
                {
                    MoveTo(p->X(), Y());
                    currState = STOPEEDDD;
                    Stop();
                }
            }

            break;
        case UUPPP:
            if (x > p->X())
            {
                if (p->up)
                {
                    MoveTo(p->X(), Y());
                    currState = UUPPP;
                    Up();
                }
            }
            break;
        case DOWWNNN:
            if (x > p->X())
            {
                if (p->down)
                {
                    MoveTo(p->X(), Y());
                    currState = DOWWNNN;
                    Down();
                }
            }
            break;
        }
        break;

    case UUPPP:
        // -----------------------
        // CurrentState == UP
        // -----------------------

        if (y < p->Y())
        {
            if (!p->up)
            {
                MoveTo(x, p->Y());
                currState = STOPEEDDD;
                Stop();
            }
        }

        switch (nextState)
        {
        case LEFFTTT:
            if (y < p->Y())
            {
                if (p->left)
                {
                    MoveTo(x, p->Y());
                    currState = LEFFTTT;
                    Left();
                }
            }
            break;
        case RIGGHTTT:
            if (y < p->Y())
            {
                if (p->right)
                {
                    MoveTo(x, p->Y());
                    currState = RIGGHTTT;
                    Right();
                }
            }
            break;
        case UUPPP:
            if (y < p->Y())
            {
                if (!p->up)
                {
                    MoveTo(x, p->Y());
                    currState = STOPEEDDD;
                    Stop();
                }
            }
            break;
        case DOWWNNN:
            currState = DOWWNNN;
            Down();
            break;
        }
        break;

    case DOWWNNN:
        // -----------------------
        // CurrentState == DOWN
        // -----------------------

        if (y > p->Y())
        {
            if (!p->down)
            {
                MoveTo(x, p->Y());
                currState = STOPEEDDD;
                Stop();
            }
        }

        switch (nextState)
        {
        case LEFFTTT:
            if (y > p->Y())
            {
                if (p->left)
                {
                    MoveTo(x, p->Y());
                    currState = LEFFTTT;
                    Left();
                }
            }
            break;
        case RIGGHTTT:
            if (y > p->Y())
            {
                if (p->right)
                {
                    MoveTo(x, p->Y());
                    currState = RIGGHTTT;
                    Right();
                }
            }
            break;
        case UUPPP:
            currState = UUPPP;
            Up();
            break;
        case DOWWNNN:
            if (y > p->Y())
            {
                if (!p->down)
                {
                    MoveTo(x, p->Y());
                    currState = STOPEEDDD;
                    Stop();
                }
            }
            break;
        }
        break;
    }
}

// ---------------------------------------------------------------------------------

void Mummy3::Update()
{
    if (part->state == ON)
    {
        
        srand(time(NULL));
        //COPIAR A LINHA ABAIXO PARA AS OUTRA MUMIAS
        Sort = 1 + rand() % 4;

        if (Sort == LEFFTTT)
        {
            nextState = LEFFTTT;

            if (currState == RIGGHTTT || currState == STOPEEDDD)
            {
                currState = LEFFTTT;
                Left();
            }
        }

        if (Sort == RIGGHTTT)
        {
            nextState = RIGGHTTT;

            if (currState == LEFFTTT || currState == STOPEEDDD)
            {
                currState = RIGGHTTT;
                Right();
            }
        }

        if (Sort == UUPPP)
        {
            nextState = UUPPP;

            if (currState == DOWWNNN || currState == STOPEEDDD)
            {
                currState = UUPPP;
                Up();
            }
        }

        if (Sort == DOWWNNN)
        {
            nextState = DOWWNNN;

            if (currState == UUPPP || currState == STOPEEDDD)
            {
                currState = DOWWNNN;
                Down();
            }
        }

    }
    else
    {
        nextState = STOPEEDDD;

        if (currState == UUPPP || currState == STOPEEDDD)
        {
            currState = STOPEEDDD;

        }
    }

    // atualiza posição
    Translate(velX * gameTime, velY * gameTime);

    Sort = 1 + rand() % 4;

}

// ---------------------------------------------------------------------------------

void Mummy3::Draw()
{
    switch (currState)
    {
    case LEFFTTT:  spriteL->Draw(x, y, Layer::UPPER); break;
    case RIGGHTTT: spriteR->Draw(x, y, Layer::UPPER); break;
    case UUPPP:    spriteL->Draw(x, y, Layer::UPPER); break;
    case DOWWNNN:  spriteL->Draw(x, y, Layer::UPPER); break;
    default:
        switch (nextState)
        {
        case LEFFTTT:  spriteL->Draw(x, y, Layer::UPPER); break;
        case RIGGHTTT: spriteR->Draw(x, y, Layer::UPPER); break;
        case UUPPP:    spriteL->Draw(x, y, Layer::UPPER); break;
        case DOWWNNN:  spriteL->Draw(x, y, Layer::UPPER); break;
        default:    spriteL->Draw(x, y, Layer::UPPER);
        }
    }
}


// ---------------------------------------------------------------------------------