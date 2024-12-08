#include "spaceship.hpp"
#include <raylib.h>

//Link do construtor escrito no spaceship.hpp
Spaceship::Spaceship() 
{
    //Criando a variável da posição no workspace da imagem gráfica da nave
    image = LoadTexture("images/ship.png");
    // image = LoadTexture("Graphics/spaceship.png");
    position.x = (GetScreenWidth() - image.width)/2;
    position.y = (GetScreenHeight() - image.height);
}

//Toda vez que eu carregar uma imagem eu tenho que descarregar quando fechar a janela do jogo, liberando o espaço de memória, pra isso crio um desconstrutor
Spaceship::~Spaceship()
{
    //RLAPI void UnloadTexture(Texture2D texture); Unload texture from GPU memory (VRAM)
    UnloadTexture(image);
}

void Spaceship::Draw()
{
    DrawTextureV(image, position, WHITE);
    //DrawTextureEx(image, (Vector2){position.x, position.y}, 0.0f, position.x, WHITE);
}
