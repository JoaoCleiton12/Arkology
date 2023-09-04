#include "Engine.h"
#include "Telafinal.h"
#include "Level1.h"

// ------------------------------------------------------------------------------

void Telafinal::Init()
{
    backg = new Sprite("Resources/Telafinal.png");
}

// ------------------------------------------------------------------------------

void Telafinal::Finalize()
{
    delete backg;
}

// ------------------------------------------------------------------------------

void Telafinal::Update()
{
    // sai do jogo com a tecla ESC
    if (window->KeyPress(VK_ESCAPE))
        window->Close();
    
}

// ------------------------------------------------------------------------------

void Telafinal::Draw()
{
    backg->Draw(window->CenterX(), window->CenterY(), Layer::BACK);
}

// ------------------------------------------------------------------------------