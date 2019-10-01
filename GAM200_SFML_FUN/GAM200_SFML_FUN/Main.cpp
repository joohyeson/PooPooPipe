#include <SFML/Graphics.hpp>
#include <iostream>

int main()
{
	sf::RenderWindow window(sf::VideoMode(1280, 720), "SFML works!", sf::Style::Close | sf::Style::Resize);


	sf::CircleShape circle(25.f);
	sf::CircleShape target(25.f);
	sf::RectangleShape canon(sf::Vector2f(100.f, 50.f));
	sf::RectangleShape ground(sf::Vector2f(2000.f, 100.f));
	circle.setPosition(100.f, 100.f);
	target.setPosition(500.f, 500.f);
	circle.setFillColor(sf::Color::Green);
	canon.setPosition(100.f, 600.f);
	canon.setRotation(-60.f);
	ground.setPosition(0.f, window.getSize().y-100.f);
	ground.setFillColor(sf::Color(0, 153, 0));



	
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
            //Using SFML function get mouse input.
            if(sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
            {

				std::cout << "Left mouse button is been pressed so" << std::endl;
				std::cout << "Button is on (" << sf::Mouse::getPosition().x <<","<< sf::Mouse::getPosition().y << ")" << std::endl;

				circle.setPosition(sf::Mouse::getPosition().x/*-360.f*/, sf::Mouse::getPosition().y/*-250.f*/);
            }


			if (event.type == sf::Event::Closed)
				window.close();
			//if (event.type == sf::Event::KeyEvent::code /*F key to fullscreen*/);
		}

		window.clear();
		window.draw(circle);
		window.draw(target);
		window.draw(canon);
		window.draw(ground);
		window.display();
	}

	return 0;
}