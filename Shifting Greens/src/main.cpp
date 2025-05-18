#include "GameManager.h"

int main(int argc, char* argv[]) {
    try {
        GameManager game;  // Criando o GameManager
        game.Run();
        
    } catch (const std::exception& e) {
        std::cerr << "Erro: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}
