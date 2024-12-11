#ifndef GAME_HPP
#define GAME_HPP

#include "spaceship.hpp"
#include "obstacle.hpp"

class Game
{   
    public:
        Game();
        ~Game();
        void Draw();                    //Desenha os métodos do jogo
        void Update();                  //Atualiza as formas desenhadas
        void HandleInput();             //Manipula a entrada dos usuários
    
    private:
        void DeleteInactiveLasers();
        std::vector<Obstacle> CreateObstacles();
        Spaceship spaceship;            
        std::vector<Obstacle> obstacles;
};
#endif