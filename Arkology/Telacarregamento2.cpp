#include "Engine.h"
#include "Telacarregamento2.h"
#include "Level1.h"


// ------------------------------------------------------------------------------

bool Level1::Impedirportal2 = false;


void Telacarregamento2::Init()
{
    backg = new Sprite("Resources/Telacarregamento.png");
}

// ------------------------------------------------------------------------------

void Telacarregamento2::Finalize()
{
    delete backg;
}

// ------------------------------------------------------------------------------

void Telacarregamento2::Update()
{
    // sai do jogo com a tecla ESC
    if (window->KeyPress(VK_RETURN))
    {
        Level1::Impedirportal2 = true;
        Engine::Next<Level1>();

    }
}

// ------------------------------------------------------------------------------

void Telacarregamento2::Draw()
{
    backg->Draw(window->CenterX(), window->CenterY(), Layer::BACK);
}

// ------------------------------------------------------------------------------