#include "alien.hpp"

Texture2D Alien::alienTexture[3] = {};
bool Alien::txtStatusLoaded[3] = {false, false, false};

Alien::Alien(int type, Vector2 position)
{
    this -> type = type;
    this -> position = position;

    /*Otimizacao: Toda vez que começa o game carrega do disco as 55 imagens dos aliens, com isso vai precisar carregar somente uma vez
      Feature diferente da referencia(Indiano): Eu adiciono um sistema onde a imagem é redimensionada para a imagem desejada
      Para isso eu uso 2 arrays que armazenam o atributo inicializado e atualiza a situação
    */ 
    if (alienTexture[type - 1].id == 0)                 //Verifica se ja existe uma textura carregada
    {
        if (txtStatusLoaded[type - 1] != true)      
        {
            switch (type)
            {
            case 1:
                img = LoadImage("images/enemy/ship1.png");
                break;
            
            case 2:
                img = LoadImage("images/enemy/ship2.png");
                break;
                
            case 3:
                img = LoadImage("images/enemy/ship3.png");
                break;

            default:
                img = LoadImage("images/enemy/ship1.png");
                break;
            }
            txtStatusLoaded[type - 1] = true;

            ImageResize(&img, 50, 50); //Redimeniono a imagem
            alienTexture[type - 1] = LoadTextureFromImage(img); //Converto a imagem em textura e a guardo no array estatico alienTexture
            UnloadImage(img);           //Libero o espaço da mem RAM ja que a imagem ja foi convertida em textura
        }
    }
}

void Alien::Draw()
{
    DrawTextureV(alienTexture[type - 1], position, WHITE);
}

void Alien::UnloadImages()
{
    for(int i = 0; i < 4; i++)
    {
        UnloadTexture(alienTexture[i]);
    }
}

int Alien::GetType()
{
    return type;
}