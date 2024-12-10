#ifndef GAME_HPP
#define GAME_HPP

#include "spaceship.hpp"

class Game
{   
    public:
        Game();
        ~Game();
        void Draw(); //Desenha os métodos do jogo
        void Update(); //Atualiza as formas desenhadas
        void HandleInput(); //Manipula a entrada dos usuários
        void DeleteInactiveLasers();
    
    private:
        Spaceship spaceship;
};
#endif