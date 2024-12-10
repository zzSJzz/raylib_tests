#include "game.hpp"
#include "spaceship.hpp"
#include <iostream>

Game::Game()
{

}

Game::~Game()
{

}

void Game::Draw()
{
    spaceship.Draw();
    for(auto& laser: spaceship.lasers)
    {
        laser.Draw();
    }
}

void Game::Update()
{
    for(auto& laser: spaceship.lasers)
    {
        laser.Update();
    }

    DeleteInactiveLasers();
    std::cout << "Vector size: " << spaceship.lasers.size() << std::endl;
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
    