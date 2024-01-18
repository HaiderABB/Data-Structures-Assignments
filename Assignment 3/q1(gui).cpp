//#include "my_queue.h"
//#include "SFML/Graphics.hpp"
//#include "SFML/System.hpp"
//#include "SFML//Window.hpp"
//#include <cstdlib> 
//#include <cmath>
//#include <math.h> 
//#include <thread>
//#include <chrono>
//#include <windows.h>
//
//void questionWithoutGUI()
//{
//    /*int n;
//    cout << "Enter Number of People to add in game" << endl;
//    cin >> n;
//    while (n <= 1)
//    {
//        cout << "Re-Enter Number of People to add in game (can't be less than 2 persons)" << endl;
//        cin >> n;
//    }
//    int k;
//    cout << "Enter Number k" << endl;
//    cin >> k;
//    while (k < 1)
//    {
//        cout << "Re-Enter Number k (can't be less than 1)" << endl;
//        cin >> k;
//    }
//    int counter = 0;
//    queue<int> jose(n);
//    srand(time(0));
//    int S = rand() % n;*/
//   
//}
//
//void N_K(int&n,int& k )
//{
//    cout << "Enter Number of People to add in game" << endl;
//    cin >> n;
//    while (n <= 1)
//    {
//        cout << "Re-Enter Number of People to add in game (can't be less than 2 persons)" << endl;
//        cin >> n;
//    }
//    cout << "Enter Number k" << endl;
//    cin >> k;
//    while (k < 1)
//    {
//        cout << "Re-Enter Number k (can't be less than 1)" << endl;
//        cin >> k;
//    }
//}
//int main() {
//    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML Example");
//    sf::Font font;
//    if (!font.loadFromFile("arial.ttf")) {
//        // Handle font loading error
//        return -1;
//    }
//    int n=-1,k=-1;
//    N_K(n, k);
//    int counter = 0;
//    queue<int> jose(n);
//    srand(time(0));
//    int S = rand() % n;
//    //S = 0;
//    sf::CircleShape* circles = new sf::CircleShape[n];
//    sf::Vector2u windowSize = window.getSize();
//    float center_x = windowSize.x / 2.0f;
//    float center_y = windowSize.y / 2.0f;
//    float radius = 100.0f;  // Adjust this ran;
//    if (n > 10)
//        radius = radius * 2;
//    for (int i = 0; i < n; i++) {
//        circles[i].setFillColor(sf::Color::Red);
//        float angle = 360.0f / n * i;  // Spread the circles evenly around the center
//        float radian = angle * (3.14159265f / 180.0f);
//        float x_cord = center_x + radius * cos(radian);
//        float y_cord = center_y + radius * sin(radian);
//        circles[i].setPosition(x_cord, y_cord);
//        circles[i].setRadius(20.0f);
//    }
//    sf::Text * texts = new sf::Text[n];
//    for (int i = 0; i < n; i++) {
//        texts[i].setFont(font);
//        texts[i].setFillColor(sf::Color::Black);
//        texts[i].setString(to_string(i+1)); 
//        texts[i].setCharacterSize(20);
//        sf::FloatRect textBounds = texts[i].getLocalBounds();
//        float textX = circles[i].getPosition().x + 6.0f;
//        float textY = circles[i].getPosition().y;
//        texts[i].setPosition(textX, textY);
//    }
//    while (window.isOpen()) {
//        sf::Event event;
//        while (window.pollEvent(event)) {
//            if (event.type == sf::Event::Closed)
//                window.close();
//        }
//
//        window.clear();
//        for (int i = 0;i < n;i++)
//        {
//            window.draw(circles[i]);
//            window.draw(texts[i]);
//        }
//        window.display();
//        Sleep(2000);
//        if (jose.isSize1()==false)
//        {
//            if (S <= 0)
//            {
//                if (S == 0)
//                    cout << "we are starting from position  = " << jose.getFront() << endl;
//                if (counter == k - 1)//
//                {
//                    counter = 0;
//                    //cout << "Person " << jose.dequeue() << " got eliminated" << endl;
//                    //jose.dequeue();
//                    circles[jose.dequeue() - 1].setFillColor(sf::Color::Black);
//                }// 2 3 4 5 1
//                 //s = 0 counter = 1
//                counter++;
//            }
//            S--;
//            jose.enqueue(jose.dequeue());
//        }
//        else if (jose.isSize1()==true)
//        { 
//            circles[jose.getFront() - 1].setFillColor(sf::Color::Green);
//            for (int i = 0;i < n;i++)
//            {
//                window.draw(circles[i]);
//                window.draw(texts[i]);
//            }
//            window.display();
//            Sleep(5000);
//            window.close();
//        }
//    }
//
//    delete[] circles; // Don't forget to free the memory
//    delete[] texts;
//    return 0;
//}