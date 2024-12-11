#include "block.hpp"

//Uso o construtor para inicializar os atributos do objeto, nele é inicializado o atributo privado "position"
Block::Block(Vector2 position)
{
    this -> position = position;

}

void Block::Draw()
{
    //No método Draw() eu uso a função drawRectangle para desenhar o quadrado de um unico pixel
    DrawRectangle(position.x, position.y, 3, 3, {51, 255, 51, 255});
}