#include <iostream>
#include <raylib.h>

using namespace std;

//Crio a classe bola que terá como variáveis públicas os parâmetros do DrawCircle, .
//

class Ball
{
public:
    float x, y;
    int speed_x, speed_y;
    int radius;
    
    void Draw()
    {
        DrawCircle(x, y, radius, WHITE);
    }

    void Update()
    {
        x += speed_x;
        y += speed_y;

        //Adicionando a interação de colisão com a bola. Basicamente se a coordenada y ou x + o valor do raio for maior que o width ou height
        //a bola automaticamente atualiza na direção contrária ao x / y, seguindo o padrão na direção contrária,
        //onde ele inverte novamente caso o código alcance 0
        if (y + radius >= GetScreenHeight() || y - radius <= 0)
        {
            speed_y *= -1;
        }
        if (x + radius >= GetScreenWidth() || x - radius <= 0)
        {
            speed_x *= -1;
        }

    }
};

class Paddle
{
protected:
    void LimitMoviment()
    {
        if (y <= 0)
        {
            y = 0;
        }
        if (y + height >= GetScreenHeight())
        {
            y = GetScreenHeight() - height;
        }
    }

public:
    float x, y;
    float width, height;
    int speed;
    
    void Draw()
    {
        DrawRectangle(x, y, width, height, WHITE);
    }

    void Update()
    {
        //bool IsKeyDown(int key); //Checa se a tecla foi pressionada
        if (IsKeyDown(KEY_UP))
        {
            y = y - speed;
        }
        if (IsKeyDown(KEY_DOWN))
        {
            y = y + speed;
        }

        // if (y <= 0)
        // {
        //     y = 0;
        // }
        // if (y + height >= GetScreenHeight())
        // {
        //     y = GetScreenHeight() - height;
        // }
        // Comentando a logica para a criação de um método protected
        LimitMoviment();
    }
};

class CpuPaddle: public Paddle
{
public:
    /*Ele herda todas as funções e variaveis declaradas da classe Paddle, 
      mas nesse eu adiciono o algoritmo da IA do robô que joga contra o player.
    */
    void Update(int ball_y)
    {
        if(y + height / 2 > ball_y)
        {
            y = y - speed;
        }
        if(y + height / 2 <= ball_y)
        {
            y = y + speed;
        }

        LimitMoviment();
    }

};

Ball ball;
Paddle player;
CpuPaddle cpu;

int main(){

    cout << "Starting Game" << endl;
    
    //Declaro as variáveis que representam o comprimento(width) e a altura(height) da interface gráfica e passando os valores da resolução VGA(640, 480)
    // const int width = 640;
    // const int height = 480;
    const int screen_width = 1280;
    const int screen_height = 720;
    
    ball.x = screen_width / 2;
    ball.y = screen_height / 2;
    ball.radius = 20;
    ball.speed_x = 5;
    ball.speed_y = 5;
    
    player.width = 25;
    player.height = 120;
    player.x = 10;
    player.y = screen_height / 2 - player.height / 2;
    player.speed = 6;

    cpu.width = 25;
    cpu.height = 120;   
    cpu.x = screen_width - cpu.width - 10;
    cpu.y = screen_height / 2 - cpu.height / 2;
    cpu.speed = 6;
    // player02.x = screen_width - 30;
    // player02.y = screen_height / 2 - 60;
    // player02.width = 25;
    // player02.height = 120;
    
    //Função initwindow que projeta a interface gráfica, tendo como parâmetro o comprimento e a altura da tela, finalizando ele pede um dado em string para adicionar ao cabeçalho
    InitWindow(screen_width, screen_height, "Pong Interface");

    //Seto a taxa de frames por segundo para 60
    SetTargetFPS(60);
    
    /* While passando como condição para quebra do laço a função WindowShouldClose(void). Essa função vai checar se alguma tecla foi pressionada ou se o botão de fechar da janela foi pressionado.
     Caso "true", ela interrompe o laço criado  
    */
    while (WindowShouldClose() == false){

        //Cria uma tela em branco onde vou "criar/desenhar" os objetos
        BeginDrawing();


        //Atualiza a posição dos objetos
        ball.Update();
        player.Update();

        //Imaginando que a cada ciclo, o objeto primeiro tem sua posição atualizada(ball.update) e depois é desenhado,
        //vou limpar a tela de fundo apagando a posição passada do objeto e mantendo a coordenada onde será desenhado
        //o objeto atual.
        ClearBackground(BLACK);

        //void DrawCircle(int centerX, int centerY, float radius, Color color);
        // DrawCircle(screen_width / 2, screen_height / 2, 20, WHITE);
        ball.Draw();

        //void DrawRectangle(int posX, int posY, int width, int height, Color color);
        //Retângulo esquerdo
        // DrawRectangle(5, screen_height / 2 - 60, 25, 120, WHITE);
        player.Draw();

        //Retângulo direito
        // DrawRectangle(screen_width - 30, screen_height / 2 - 60, 25, 120, WHITE);
        // player02.Draw();
        cpu.Draw();
        cpu.Update(ball.y);

        //DrawLine(int startPosX, int startPosY, int endPosX, int endPosY, Color color);                // Draw a line
        DrawLine(screen_width / 2, 0, screen_width / 2, screen_height, WHITE);

        //RLAPI bool CheckCollisionCircleRec(Vector2 center, float radius, Rectangle rec);                         // Check collision between circle and rectangle
        /*Utiliza um if com a função CheckCollisionCircleRec como condição,
        onde, se o struct Vector2 (que por padrão recebe um float x e y como parâmetro - centro do objeto), o raio do objeto,
        com outro objeto, no caso o struct Rectangle, que recebe por padrão 4 parâmetros do objeto(x, y, width, height), 
        como a função Check... é booleana, se for true ele executa a linha de código abaixo*/
        if(CheckCollisionCircleRec(Vector2{ball.x, ball.y}, ball.radius, Rectangle{player.x, player.y, player.width, player.height}))
        {
            ball.speed_x *= -1;
        }

        //Mesma coisa só que dessa vez a relação é ball - paddle do robô adversário
        if(CheckCollisionCircleRec(Vector2{ball.x, ball.y}, ball.radius, Rectangle{cpu.x, cpu.y, cpu.width, cpu.height}))
        {
            ball.speed_x *= -1;
        }

        //Comando pra fechar essa tela
        EndDrawing();
    }
    

    //Fecha a tela
    CloseWindow();
    return 0;
}