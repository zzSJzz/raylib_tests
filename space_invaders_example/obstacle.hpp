#ifndef OBSTACLE_HPP
#define OBSTACLE_HPP

#include <vector>
#include <raylib.h>
#include "block.hpp"

//Crio a classe Obstacle que vai utilizar informações da biblioteca block.hpp. Na classe eu seto como público o construtor que tem como parâmetro o atributo position do tipo Vector2(x, y)
//Após isso eu adiciono o atributo position como público 
class Obstacle
{   public:
        Obstacle(Vector2 position);
        void Draw();
        Vector2 position;
        std::vector<Block> blocks;
        static std::vector<std::vector<int>> grid;
    private:
};


#endif