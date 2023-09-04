#include "Engine.h"
#include "Telacarregamento.h"
#include "Level1.h"


// ------------------------------------------------------------------------------

bool Level1::Impedirportal1 = false;


void Telacarregamento::Init()
{
    backg = new Sprite("Resources/Telacarregamento.png");
}

// ------------------------------------------------------------------------------

void Telacarregamento::Finalize()
{
    delete backg;
}

// ------------------------------------------------------------------------------

void Telacarregamento::Update()
{
    // sai do jogo com a tecla ESC
    if (window->KeyPress(VK_RETURN))
    {
        Level1::Impedirportal1 = true;
        Engine::Next<Level1>();

    }
    
}

// ------------------------------------------------------------------------------

void Telacarregamento::Draw()
{
    backg->Draw(window->CenterX(), window->CenterY(), Layer::BACK);
}

// ------------------------------------------------------------------------------