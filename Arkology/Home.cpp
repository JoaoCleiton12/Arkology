#include "Engine.h"
#include "Home.h"
#include "Level1.h"

// ------------------------------------------------------------------------------

void Home::Init()
{
    backg = new Sprite("Resources/Telainicial.jpg");
}

// ------------------------------------------------------------------------------

void Home::Finalize()
{
    delete backg;
}

// ------------------------------------------------------------------------------

void Home::Update()
{
    // sai do jogo com a tecla ESC
    if (window->KeyPress(VK_ESCAPE))
        window->Close();
    // passa ao primeiro nível com ENTER
    if (window->KeyPress(VK_RETURN))
        Engine::Next<Level1>();
}

// ------------------------------------------------------------------------------

void Home::Draw()
{
    backg->Draw(window->CenterX(), window->CenterY(), Layer::BACK);
}

// ------------------------------------------------------------------------------