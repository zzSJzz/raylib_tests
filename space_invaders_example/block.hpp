#ifndef BLOCK_HPP
#define BLOCK_HPP

#include <raylib.h>

//Crio a classe Block que vai constar os obstaculos
class Block
{
    public:
        //Declaro os membros de acesso publico da classe(Construtor e método). O construtor recebe como parâmetro position do tipo Vector2 e é usado para inicializar o atributo privado position
        //Declaro também o método Draw(Desenhar)
        Block(Vector2 position);
        void Draw();

    private:
        //Declaro como privado o atributo do tipo Vector2 (x, y) que vai armazenar as coordenadas do objeto
        Vector2 position;

};

#endif
