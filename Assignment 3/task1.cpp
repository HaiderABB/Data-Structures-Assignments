#include <SFML/Graphics.hpp>
#include <iostream>
#include <queue>

void drawStickFigure(sf::RenderWindow& window, int position) {
    // Create a head (circle)
    sf::CircleShape head(15);
    head.setFillColor(sf::Color::White);
    head.setPosition(200 + position * 50, 200);

    // Create a body (rectangle)
    sf::RectangleShape body(sf::Vector2f(10, 30));
    body.setFillColor(sf::Color::White);
    body.setPosition(205 + position * 50, 215);

    // Create arms (lines)
    sf::Vertex leftArm[] = {
        sf::Vertex(sf::Vector2f(205 + position * 50, 215)),
        sf::Vertex(sf::Vector2f(195 + position * 50, 230))
    };

    sf::Vertex rightArm[] = {
        sf::Vertex(sf::Vector2f(215 + position * 50, 215)),
        sf::Vertex(sf::Vector2f(225 + position * 50, 230))
    };

    // Create legs (lines)
    sf::Vertex leftLeg[] = {
        sf::Vertex(sf::Vector2f(205 + position * 50, 245)),
        sf::Vertex(sf::Vector2f(195 + position * 50, 260))
    };

    sf::Vertex rightLeg[] = {
        sf::Vertex(sf::Vector2f(215 + position * 50, 245)),
        sf::Vertex(sf::Vector2f(225 + position * 50, 260))
    };

    window.draw(head);
    window.draw(body);
    window.draw(leftArm, 2, sf::Lines);
    window.draw(rightArm, 2, sf::Lines);
    window.draw(leftLeg, 2, sf::Lines);
    window.draw(rightLeg, 2, sf::Lines);
}

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "Josephus Problem");

    int numPeople = 0;
    int k = 0;
    bool solved = false;

    std::queue<int> people;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            else if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::Enter) {
                    if (!solved) {
                        std::cout << "Enter the total number of people: ";
                        std::cin >> numPeople;
                        std::cout << "Enter the elimination step (K): ";
                        std::cin >> k;
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear the input buffer

                        // Initialize the queue with people
                        for (int i = 1; i <= numPeople; i++) {
                            people.push(i);
                        }

                        solved = true;
                    }
                }
            }
        }

        window.clear(sf::Color::Black);

        if (!solved) {
            sf::Font font;
            font.loadFromFile("arial.ttf"); // Load a font

            sf::Text instructions("Press Enter to start.", font, 24);
            instructions.setFillColor(sf::Color::White);
            instructions.setPosition(260, 270);

            window.draw(instructions);
        }
        else {
            for (int step = 0; step < numPeople; step++) {
                if (!people.empty()) {
                    // Perform elimination step
                    for (int i = 0; i < k - 1; i++) {
                        int front = people.front();
                        people.pop();
                        people.push(front);
                    }
                    int eliminatedPerson = people.front();
                    people.pop();

                    // Draw the stick figure representation for the eliminated person
                    drawStickFigure(window, eliminatedPerson - 1);

                    // Display the eliminated person's number
                    sf::Font font;
                    font.loadFromFile("arial.ttf");
                    sf::Text eliminatedPersonText("Eliminating: " + std::to_string(eliminatedPerson), font, 24);
                    eliminatedPersonText.setFillColor(sf::Color::White);
                    eliminatedPersonText.setPosition(300, 270);
                    window.draw(eliminatedPersonText);

                    window.display();

                    // Pause to show the elimination step
                    sf::Clock clock;
                    while (clock.getElapsedTime().asSeconds() < 1.0) {
                        // Wait for 1 second
                    }
                }
            }
        }

        window.display();
    }

    return 0;
}
