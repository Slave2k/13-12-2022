#include "settings.h"
#include "functions.h"
using namespace sf;

int main()
{
	setlocale(LC_ALL, "rus");
	srand(time(nullptr));
	// Îáúåêò, êîòîðûé, ñîáñòâåííî, ÿâëÿåòñÿ ãëàâíûì îêíîì ïðèëîæåíèÿ
	RenderWindow window(VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), WINDOW_TITLE);
	window.setFramerateLimit(FPS);
	//ñîçäàíèå îáúåêòîâ èãðû

	//ðàêåòêè
	RectangleShape leftBat, rightBat;
	{
		/*leftBat.setSize(batSize);
		leftBat.setFillColor(leftBatColor);
		leftBat.setPosition(batOffset, (WINDOW_HEIGHT - batHeight) / 2); //= initBat
		*/
		initBat(leftBat, leftBatColor, leftBatStartPos);

		/*rightBat.setSize(batSize);
		rightBat.setFillColor(rightBatColor);
		rightBat.setPosition(WINDOW_WIDTH - batOffset, (WINDOW_HEIGHT - batHeight) / 2);*/ //initBat
		initBat(rightBat, rightBatColor, rightBatStartPos);
	}
	float leftBatSpeedY = 0.f;
	float rightBatSpeedY = 0.f;

	//øàðèê
	CircleShape ball(ballRadius);
	/*ball.setRadius(ballRadius);
	ball.setFillColor(ballColor);
	ball.setPosition((WINDOW_WIDTH - 2 * ballRadius) / 2,
		(WINDOW_HEIGHT - 2 * ballRadius) / 2);*/// =initBall
	initBall(ball, ballColor, ballStartPos);

	float arr_speed[]{ -5.f,-4.f,-3.f,-2.f,-1.f,1.f,2.f,3.f,4.f,5.f };
	int index = rand() % 10;
	float ball_speedx = arr_speed[index];
	index = rand() % 10;
	float ball_speedy = arr_speed[index];

	//Ñ×ÅÒ
	int leftPlayerScore = 0;
	int rightPlayerScore = 0;

	Font font;
	font.loadFromFile("ds-digib.ttf");

	Text leftPlayerScoreText;
	leftPlayerScoreText.setString(std::to_string(leftPlayerScore));//ïåðåäàòü ñòðîêó äëÿ îòîáðàæåíèÿ
	leftPlayerScoreText.setFont(font);
	leftPlayerScoreText.setCharacterSize(64);
	leftPlayerScoreText.setPosition(200.f, 10.f);

	Text rightPlayerScoreText;
	rightPlayerScoreText.setString(std::to_string(rightPlayerScore));
	rightPlayerScoreText.setFont(font);
	rightPlayerScoreText.setCharacterSize(64);
	rightPlayerScoreText.setPosition(550.f, 10.f);

	// Ãëàâíûé öèêë ïðèëîæåíèÿ. Âûïîëíÿåòñÿ, ïîêà îòêðûòî îêíî
	while (window.isOpen())
	{
		//1 Îáðàáàòûâàåì î÷åðåäü ñîáûòèé â öèêëå
		Event event;
		while (window.pollEvent(event))
		{
			// Ïîëüçîâàòåëü íàæàë íà «êðåñòèê» è õî÷åò çàêðûòü îêíî?
			if (event.type == Event::Closed)
				// òîãäà çàêðûâàåì åãî
				window.close();
		}

		//2 Îáíîâëåíèå îáúåêòîâ
		//øàðèê
		//äâèæåíèå øàðèêà
		ball.move(ball_speedx, ball_speedy);
		//ïîïàë-âûøåë çà ëåâóþ 
		if (ball.getPosition().x <= 0)
		{
			//ñêîðîñòü ïî îñè õ ñìåíèëàñü íà ïðîòèâîïîëîæíóþ
			ball_speedx = -ball_speedx;
			//ïðàâûé èãðîê çàáèë ãîë
			rightPlayerScore++;
			rightPlayerScoreText.setString(std::to_string(rightPlayerScore));
		}
		//èëè ïðàâóþ ãðàíèöó
		if (ball.getPosition().x >= (WINDOW_WIDTH - 2 * ballRadius))
		{
			//ñêîðîñòü ïî îñè õ ñìåíèëàñü íà ïðîòèâîïîëîæíóþ
			ball_speedx = -ball_speedx;
			//ëåâûé èãðîê çàáèë ãîë
			leftPlayerScore++;
			leftPlayerScoreText.setString(std::to_string(leftPlayerScore));
		}
		if (ball.getPosition().y <= 0 || ball.getPosition().y >=
			(WINDOW_HEIGHT - 2 * ballRadius))
		{
			//ñêîðîñòü ïî îñè y ñìåíèëàñü íà ïðîòèâîïîëîæíóþ
			ball_speedy = -ball_speedy;
		}

		//Ïðîâåðêà íàæàòèé êëàâèø
		//åñëè êëàâèøà W íàæàòà - ëåâà ðàêåòêà âíèç
		if (Keyboard::isKeyPressed(Keyboard::W)) {
			leftBatSpeedY = -batSpeed;
		}
		if (Keyboard::isKeyPressed(Keyboard::S)) {
			leftBatSpeedY = batSpeed;
		}
		if (Keyboard::isKeyPressed(Keyboard::Up)) {
			rightBatSpeedY = -batSpeed;
		}
		if (Keyboard::isKeyPressed(Keyboard::Down)) {
			rightBatSpeedY = batSpeed;
		}
		//äâèãàåì ðàêåòêó		
		leftBat.move(0, leftBatSpeedY);
		//è ñðàçó îáíóëÿåì ñêîðîñòü
		leftBatSpeedY = 0;
		rightBat.move(0, rightBatSpeedY);
		//è ñðàçó îáíóëÿåì ñêîðîñòü
		rightBatSpeedY = 0;




		//3 Îòðèñîâêà îêíà
		//3.1 Î÷èñòêà îêíà
		window.clear();
		//3.2 Îòðèñîâêà îáúåêòîâ (Â ÏÀÌßÒÈ!)
		window.draw(leftBat);
		window.draw(rightBat);
		window.draw(ball);
		window.draw(leftPlayerScoreText);
		window.draw(rightPlayerScoreText);
		//3.3 âûâîä íà ýêðàí
		window.display();
	}

	return 0;
}