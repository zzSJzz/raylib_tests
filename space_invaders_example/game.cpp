#include "game.hpp"
#include "spaceship.hpp"
#include <iostream>

Game::Game()
{
    obstacles = CreateObstacles();
    aliens = CreateAliens();
}

Game::~Game()
{
    Alien::UnloadImages();
}

void Game::Draw()
{
    spaceship.Draw();
    for(auto& laser: spaceship.lasers)
    {
        laser.Draw();
    }

    for(auto& obstacle: obstacles)
    {
        obstacle.Draw();
    }

    for(auto& alien: aliens)
    {
        alien.Draw();
    }
}

void Game::Update()
{
    for(auto& laser: spaceship.lasers)
    {
        laser.Update();
    }

    DeleteInactiveLasers();
    // std::cout << "Vector size: " << spaceship.lasers.size() << std::endl;
    //  conta o numero de lasers na tela
}

void Game::HandleInput()
{
    if(IsKeyDown(KEY_LEFT))
    {
        spaceship.MoveLeft();
    } else if( IsKeyDown(KEY_RIGHT))
    {
        spaceship.MoveRight();
    } else if(IsKeyDown(KEY_SPACE))
    {
        spaceship.FireLaser();
    }
}

void Game::DeleteInactiveLasers()
{
    //Cria uma variavel de iteração it que começa no primeiro elemento do vetor lasers
    //Enquanto não estiver no ultimo elemento ele repete o ciclo
    //O auto faz ele determinar automaticamente o tipo do vector, no caso o std::vector<Laser>
    for(auto it = spaceship.lasers.begin(); it != spaceship.lasers.end(); )

    {
        //o operador -> acessa membros/metodos de um objeto apontado por um ponteiro/iterador
        //it -> active acessa o membro apontado pelo iterator 
        //No caso, se o iterator não esta ativo, ele é apagado com a funçao erase() e retorna um nove iterador que aponta para o proximo elemento apos a remoção
        if(!it -> active)
        {
            it = spaceship.lasers.erase(it);
        }else{
            //se ele estiver ativo incrementa o iterador, indo para a próxima função
            ++ it;
        }
    }    
}

std::vector<Obstacle> Game::CreateObstacles()
{
    int obstacleWidth = Obstacle::grid[0].size() * 3;
    float gap = (GetScreenWidth() - (4 * obstacleWidth))/5;
    
    for(int i = 0; i < 4; i++)
    {
        float offsetX = (i + 1) * gap + i * obstacleWidth;
        obstacles.push_back(Obstacle({offsetX, float(GetScreenHeight() - 100)}));
    }
    return obstacles;
}

std::vector<Alien> Game::CreateAliens()
{
    std::vector<Alien> aliens;
    for(int row = 0; row < 5; row++)
    {
        for(int columm = 0; columm < 11; columm++)
        {
            int alienType;
            if(row == 0)
            {
                alienType = 3;
            }else if(row == 1 || row == 2)
            {
                alienType = 2;
            }else
            {
                alienType = 1;
            }
            float x = 75 + columm * 55;    //Valor ok para cada pixel do alien
            float y = 110 + row * 55;
            aliens.push_back(Alien(alienType, {x, y}));
        }
    }
    return aliens;
}