#include <SFML/Graphics.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "Movimentação, Ataque e Defesa do Personagem");

    sf::CircleShape character(50.f);
    character.setFillColor(sf::Color::Green);
    character.setPosition(400, 300);

    float speed = 5.0f;

    bool isAttacking = false;
    bool isDefending = false;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

            // Detecção de clique do mouse
            if (event.type == sf::Event::MouseButtonPressed)
            {
                if (event.mouseButton.button == sf::Mouse::Left)
                    isAttacking = true;
                else if (event.mouseButton.button == sf::Mouse::Right)
                    isDefending = true;
            }
            else if (event.type == sf::Event::MouseButtonReleased)
            {
                if (event.mouseButton.button == sf::Mouse::Left)
                    isAttacking = false;
                else if (event.mouseButton.button == sf::Mouse::Right)
                    isDefending = false;
            }
        }

        // Movimentação usando as teclas W, A, S e D
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
            character.move(0, -speed);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
            character.move(-speed, 0);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
            character.move(0, speed);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
            character.move(speed, 0);

        // Simulação de ataque e defesa
        if (isAttacking)
        {
            // Lógica de ataque aqui
            // Por exemplo, você pode alterar a cor do personagem para simular um ataque
            character.setFillColor(sf::Color::Red);
        }
        else if (isDefending)
        {
            // Lógica de defesa aqui
            // Por exemplo, você pode alterar a cor do personagem para simular uma defesa
            character.setFillColor(sf::Color::Blue);
        }
        else
        {
            // Caso nenhum ataque ou defesa esteja acontecendo, a cor padrão é restaurada
            character.setFillColor(sf::Color::Green);
        }

        window.clear();
        window.draw(character);
        window.display();
    }

    return 0;
}
