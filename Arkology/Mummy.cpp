#include "Arkology.h"
#include "Mummy.h"
#include "Pivot.h"
#include <time.h>

// ---------------------------------------------------------------------------------

Mummy::Mummy(Partstatue * p)
{
    part = p;
    Sort = STOPEDD;

    spriteL = new Sprite("Resources/MumiaLabirintoL.png");
    spriteR = new Sprite("Resources/MumiaLabirintoR.png");

    // imagem do jogador é 30x30
    BBox(new Rect(-15, -15, 15, 15));
    MoveTo(167.0f, 49.0f, Layer::FRONT);
    type = MUMMY;
}

// ---------------------------------------------------------------------------------

Mummy::~Mummy()
{
    delete spriteL;
    delete spriteR;
}

// ---------------------------------------------------------------------------------

void Mummy::Stop()
{
    velX = 0;
    velY = 0;
}

// ---------------------------------------------------------------------------------

void Mummy::Up()
{
    velX = 0;
    velY = -90.0f;
}

// ---------------------------------------------------------------------------------

void Mummy::Down()
{
    velX = 0;
    velY = 90.0f;
}

// ---------------------------------------------------------------------------------

void Mummy::Left()
{
    velX = -90.0f;
    velY = 0;
}

// ---------------------------------------------------------------------------------

void Mummy::Right()
{
    velX = 90.0f;
    velY = 0;
}

// ---------------------------------------------------------------------------------

void Mummy::OnCollision(Object* obj)
{
    if (obj->Type() == PIVOT)
        PivotCollision(obj);

    // Colisao com mummia 2
    if (obj->Type() == MUMMY2 && currState == LEFTT)
        nextState = RIGHTT;
    if(obj->Type() == MUMMY2 && currState == RIGHTT)
        nextState = LEFTT;
    if (obj->Type() == MUMMY2 && currState == UPP)
        nextState = DOWNN;
    if (obj->Type() == MUMMY2 && currState == DOWNN)
        nextState = UPP;

    // Colisao com mummia 3
    if (obj->Type() == MUMMY3 && currState == LEFTT)
        nextState = RIGHTT;
    if (obj->Type() == MUMMY3 && currState == RIGHTT)
        nextState = LEFTT;
    if (obj->Type() == MUMMY3 && currState == UPP)
        nextState = DOWNN;
    if (obj->Type() == MUMMY3 && currState == DOWNN)
        nextState = UPP;

    // Colisao com mummia 4
    if (obj->Type() == MUMMY4 && currState == LEFTT)
        nextState = RIGHTT;
    if (obj->Type() == MUMMY4 && currState == RIGHTT)
        nextState = LEFTT;
    if (obj->Type() == MUMMY4 && currState == UPP)
        nextState = DOWNN;
    if (obj->Type() == MUMMY4 && currState == DOWNN)
        nextState = UPP;

    // Colisao com mummia 5
    if (obj->Type() == MUMMY5 && currState == LEFTT)
        nextState = RIGHTT;
    if (obj->Type() == MUMMY5 && currState == RIGHTT)
        nextState = LEFTT;
    if (obj->Type() == MUMMY5 && currState == UPP)
        nextState = DOWNN;
    if (obj->Type() == MUMMY5 && currState == DOWNN)
        nextState = UPP;

    // Colisao com mummia 6
    if (obj->Type() == MUMMY6 && currState == LEFTT)
        nextState = RIGHTT;
    if (obj->Type() == MUMMY6 && currState == RIGHTT)
        nextState = LEFTT;
    if (obj->Type() == MUMMY6 && currState == UPP)
        nextState = DOWNN;
    if (obj->Type() == MUMMY6 && currState == DOWNN)
        nextState = UPP;

    // Colisao com mummia 7
    if (obj->Type() == MUMMY7 && currState == LEFTT)
        nextState = RIGHTT;
    if (obj->Type() == MUMMY7 && currState == RIGHTT)
        nextState = LEFTT;
    if (obj->Type() == MUMMY7 && currState == UPP)
        nextState = DOWNN;
    if (obj->Type() == MUMMY7 && currState == DOWNN)
        nextState = UPP;

    // Colisao com mummia 8
    if (obj->Type() == MUMMY8 && currState == LEFTT)
        nextState = RIGHTT;
    if (obj->Type() == MUMMY8 && currState == RIGHTT)
        nextState = LEFTT;
    if (obj->Type() == MUMMY8 && currState == UPP)
        nextState = DOWNN;
    if (obj->Type() == MUMMY8 && currState == DOWNN)
        nextState = UPP;

    // Colisao com mummia 9
    if (obj->Type() == MUMMY9 && currState == LEFTT)
        nextState = RIGHTT;
    if (obj->Type() == MUMMY9 && currState == RIGHTT)
        nextState = LEFTT;
    if (obj->Type() == MUMMY9 && currState == UPP)
        nextState = DOWNN;
    if (obj->Type() == MUMMY9 && currState == DOWNN)
        nextState = UPP;

    // Colisao com mummia 10
    if (obj->Type() == MUMMY10 && currState == LEFTT)
        nextState = RIGHTT;
    if (obj->Type() == MUMMY10 && currState == RIGHTT)
        nextState = LEFTT;
    if (obj->Type() == MUMMY10 && currState == UPP)
        nextState = DOWNN;
    if (obj->Type() == MUMMY10 && currState == DOWNN)
        nextState = UPP;

    // Colisao com mummia 11
    if (obj->Type() == MUMMY11 && currState == LEFTT)
        nextState = RIGHTT;
    if (obj->Type() == MUMMY11 && currState == RIGHTT)
        nextState = LEFTT;
    if (obj->Type() == MUMMY11 && currState == UPP)
        nextState = DOWNN;
    if (obj->Type() == MUMMY11 && currState == DOWNN)
        nextState = UPP;

    // Colisao com mummia 12
    if (obj->Type() == MUMMY12 && currState == LEFTT)
        nextState = RIGHTT;
    if (obj->Type() == MUMMY12 && currState == RIGHTT)
        nextState = LEFTT;
    if (obj->Type() == MUMMY12 && currState == UPP)
        nextState = DOWNN;
    if (obj->Type() == MUMMY12 && currState == DOWNN)
        nextState = UPP;

    // Colisao com mummia 13
    if (obj->Type() == MUMMY13 && currState == LEFTT)
        nextState = RIGHTT;
    if (obj->Type() == MUMMY13 && currState == RIGHTT)
        nextState = LEFTT;
    if (obj->Type() == MUMMY13 && currState == UPP)
        nextState = DOWNN;
    if (obj->Type() == MUMMY13 && currState == DOWNN)
        nextState = UPP;

    // Colisao com mummia 14
    if (obj->Type() == MUMMY14 && currState == LEFTT)
        nextState = RIGHTT;
    if (obj->Type() == MUMMY14 && currState == RIGHTT)
        nextState = LEFTT;
    if (obj->Type() == MUMMY14 && currState == UPP)
        nextState = DOWNN;
    if (obj->Type() == MUMMY14 && currState == DOWNN)
        nextState = UPP;
}

// ---------------------------------------------------------------------------------

void Mummy::PivotCollision(Object* obj)
{
    Pivot* p = (Pivot*)obj;

    switch (currState)
    {
    case STOPEDD:
        // -----------------------
        // CurrentState == STOPED
        // -----------------------

        switch (nextState)
        {
        case LEFTT:
            if (p->left)
            {
                currState = LEFTT;
                Left();
            }
            break;
        case RIGHTT:
            if (p->right)
            {
                currState = RIGHTT;
                Right();
            }

            break;
        case UPP:
            if (p->up)
            {
                currState = UPP;
                Up();
            }
            break;
        case DOWNN:
            if (p->down)
            {
                currState = DOWNN;
                Down();
            }
            break;
        }
        break;

    case LEFTT:
        // -----------------------
        // CurrentState == LEFT
        // -----------------------

        if (x < p->X())
        {
            if (!p->left)
            {
                MoveTo(p->X(), Y());
                currState = STOPEDD;
                Stop();
            }
        }

        switch (nextState)
        {
        case LEFTT:
            if (x < p->X())
            {
                if (!p->left)
                {
                    MoveTo(p->X(), Y());
                    currState = STOPEDD;
                    Stop();
                }
            }
            break;
        case RIGHTT:
            currState = RIGHTT;
            Right();

            break;
        case UPP:
            if (x < p->X())
            {
                if (p->up)
                {
                    MoveTo(p->X(), Y());
                    currState = UPP;
                    Up();
                }
            }
            break;
        case DOWNN:
            if (x < p->X())
            {
                if (p->down)
                {
                    MoveTo(p->X(), Y());
                    currState = DOWNN;
                    Down();
                }
            }
            break;
        }
        break;

    case RIGHTT:
        // -----------------------
        // CurrentState == RIGHT
        // -----------------------

        if (x > p->X())
        {
            if (!p->right)
            {
                MoveTo(p->X(), Y());
                currState = STOPEDD;
                Stop();
            }
        }

        switch (nextState)
        {
        case LEFTT:
            currState = LEFTT;
            Left();
            break;
        case RIGHTT:
            if (x > p->X())
            {
                if (!p->right)
                {
                    MoveTo(p->X(), Y());
                    currState = STOPEDD;
                    Stop();
                }
            }

            break;
        case UPP:
            if (x > p->X())
            {
                if (p->up)
                {
                    MoveTo(p->X(), Y());
                    currState = UPP;
                    Up();
                }
            }
            break;
        case DOWNN:
            if (x > p->X())
            {
                if (p->down)
                {
                    MoveTo(p->X(), Y());
                    currState = DOWNN;
                    Down();
                }
            }
            break;
        }
        break;

    case UPP:
        // -----------------------
        // CurrentState == UP
        // -----------------------

        if (y < p->Y())
        {
            if (!p->up)
            {
                MoveTo(x, p->Y());
                currState = STOPEDD;
                Stop();
            }
        }

        switch (nextState)
        {
        case LEFTT:
            if (y < p->Y())
            {
                if (p->left)
                {
                    MoveTo(x, p->Y());
                    currState = LEFTT;
                    Left();
                }
            }
            break;
        case RIGHTT:
            if (y < p->Y())
            {
                if (p->right)
                {
                    MoveTo(x, p->Y());
                    currState = RIGHTT;
                    Right();
                }
            }
            break;
        case UPP:
            if (y < p->Y())
            {
                if (!p->up)
                {
                    MoveTo(x, p->Y());
                    currState = STOPEDD;
                    Stop();
                }
            }
            break;
        case DOWNN:
            currState = DOWNN;
            Down();
            break;
        }
        break;

    case DOWNN:
        // -----------------------
        // CurrentState == DOWN
        // -----------------------

        if (y > p->Y())
        {
            if (!p->down)
            {
                MoveTo(x, p->Y());
                currState = STOPEDD;
                Stop();
            }
        }

        switch (nextState)
        {
        case LEFTT:
            if (y > p->Y())
            {
                if (p->left)
                {
                    MoveTo(x, p->Y());
                    currState = LEFTT;
                    Left();
                }
            }
            break;
        case RIGHTT:
            if (y > p->Y())
            {
                if (p->right)
                {
                    MoveTo(x, p->Y());
                    currState = RIGHTT;
                    Right();
                }
            }
            break;
        case UPP:
            currState = UPP;
            Up();
            break;
        case DOWNN:
            if (y > p->Y())
            {
                if (!p->down)
                {
                    MoveTo(x, p->Y());
                    currState = STOPEDD;
                    Stop();
                }
            }
            break;
        }
        break;
    }
}

// ---------------------------------------------------------------------------------

void Mummy::Update()
{
    if (part->state == ON)
    {
        srand(time(NULL));
        Sort = 1 + rand() % 4;

        if (Sort == LEFTT)
        {
            nextState = LEFTT;

            if (currState == RIGHTT || currState == STOPEDD)
            {
                currState = LEFTT;
                Left();
            }
        }

        if (Sort == RIGHTT)
        {
            nextState = RIGHTT;

            if (currState == LEFTT || currState == STOPEDD)
            {
                currState = RIGHTT;
                Right();
            }
        }

        if (Sort == UPP)
        {
            nextState = UPP;

            if (currState == DOWNN || currState == STOPEDD)
            {
                currState = UPP;
                Up();
            }
        }

        if (Sort == DOWNN)
        {
            nextState = DOWNN;

            if (currState == UPP || currState == STOPEDD)
            {
                currState = DOWNN;
                Down();
            }
        }
        
    }
    else
    {
        nextState = STOPEDD;

        if (currState == UPP || currState == STOPEDD)
        {
            currState = STOPEDD;

        }
    }
    
    

    // atualiza posição
    Translate(velX * gameTime, velY * gameTime);
    Sort = 1 + rand() % 4;

}

// ---------------------------------------------------------------------------------

void Mummy::Draw()
{
    switch (currState)
    {
    case LEFTT:  spriteL->Draw(x, y, Layer::UPPER); break;
    case RIGHTT: spriteR->Draw(x, y, Layer::UPPER); break;
    case UPP:    spriteL->Draw(x, y, Layer::UPPER); break;
    case DOWNN:  spriteL->Draw(x, y, Layer::UPPER); break;
    default:
        switch (nextState)
        {
        case LEFTT:  spriteL->Draw(x, y, Layer::UPPER); break;
        case RIGHTT: spriteR->Draw(x, y, Layer::UPPER); break;
        case UPP:    spriteL->Draw(x, y, Layer::UPPER); break;
        case DOWNN:  spriteL->Draw(x, y, Layer::UPPER); break;
        default:    spriteL->Draw(x, y, Layer::UPPER);
        }
    }
}


// ---------------------------------------------------------------------------------