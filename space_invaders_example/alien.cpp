#include "alien.hpp"

Texture2D Alien::alienImages[3] = {};   //O objetivo é deixar salvo essas imagens quando o jogo

Alien::Alien(int type, Vector2 position)
{
    this -> type = type;
    this -> position = position;

    Image reszImage; // Crio um objeto que vai carregar a imagem e usar a funcao resize para mudar seu tamanho

    switch (type)
    {
    case 1:
        reszImage = LoadImage("images/enemy/ship1.png");
        break;
    
    case 2:
        reszImage = LoadImage("images/enemy/ship2.png");
        break;
        
    case 3:
        reszImage = LoadImage("images/enemy/ship3.png");
        break;

    default:
        reszImage = LoadImage("images/enemy/ship1.png");
        break;
    }

    ImageResize(&reszImage, 50, 50); //Redimeniono a imagem
    image = LoadTextureFromImage(reszImage); //Converto a reszimagem em textura e a guardo na variavel imagem
    
    UnloadImage(reszImage); //Libero a memoria contendo a imagem original, ela ja foi transformada em textura
}

void Alien::Draw()
{
    DrawTextureV(image, position, WHITE);
}

int Alien::GetType()
{
    return type;
}