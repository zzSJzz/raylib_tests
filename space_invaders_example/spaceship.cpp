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
    lastFireTime = 0.0;
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

void Spaceship::MoveLeft()
{
    position.x -= 7;
    if (position.x < 0)
    {
        position.x = 0;
    }
}

void Spaceship::MoveRight()
{
    position.x += 7;
    if (position.x > GetScreenHeight())
    {
        position.x = GetScreenHeight();
    }
}

void Spaceship::FireLaser()
{   
    if(GetTime() - lastFireTime >= 0.350)
    {
        lastFireTime = GetTime();
        //-2 porque o valor do laser é de 4 pixels, logo 2 pixels de largura
        //push_back tera a função de adicionar um valor ao ultimo vetor, dessa forma posso lançar varios objetos(lasers)
        lasers.push_back(Laser({position.x  + image.width/2 - 2, position.y}, 6));
    }

}
