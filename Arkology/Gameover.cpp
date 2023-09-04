#include "Engine.h"
#include "Gameover.h"
#include "Home.h"

// ------------------------------------------------------------------------------

void Gameover::Init()
{
    backg = new Sprite("Resources/Gameover.png");
}

// ------------------------------------------------------------------------------

void Gameover::Finalize()
{
    delete backg;
}

// ------------------------------------------------------------------------------

void Gameover::Update()
{
    // sai do jogo com a tecla ESC
    if (window->KeyPress('N'))
        window->Close();
    // passa ao primeiro nível com ENTER
    if (window->KeyPress('Y'))
        Engine::Next<Home>();
}

// ------------------------------------------------------------------------------

void Gameover::Draw()
{
    backg->Draw(window->CenterX(), window->CenterY(), Layer::BACK);
}

// ------------------------------------------------------------------------------