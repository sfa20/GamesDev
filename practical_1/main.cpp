#include <SFML/Graphics.hpp>

using namespace sf;
using namespace std;

const Keyboard::Key controls[4] = {
	Keyboard::A, //Player1 UP
	Keyboard::Z, //Player1 Down
	Keyboard::Up, //Player2 UP
	Keyboard::Down //Player2 Down
};

const Vector2f paddleSize(25.f, 100.f);
Vector2f ballVelocity;
bool server = false;
const float ballRadius = 10.f;
const int gameWidth = 800;
const int gameHeight = 600;
const float paddleSpeed = 400.f;




CircleShape ball;
RectangleShape paddles[2];

void reset()
{
	//Set size and origin of ball
	ball.setRadius(ballRadius - 3);
	ball.setOrigin(ballRadius / 2, ballRadius / 2);
	//reset paddle position
	paddles[0].setPosition(10 + paddleSize.x / 2, gameHeight / 2);
	paddles[1].setPosition(gameWidth - paddleSize.x / 2 - 10, gameHeight / 2);
	// reset Ball Position
	ball.setPosition(gameWidth / 2, gameHeight / 2);
	ballVelocity = { (server ? 100.0f : -100.0f), 60.0f };

}

void Load() {
	//Set size and origin of paddles
	for (auto &p : paddles) {
		p.setSize(paddleSize - Vector2f(3, 3));
		p.setOrigin(paddleSize / 2.f);
	}
	
	reset();
}

void Update(RenderWindow &window) {
	//Reset clock, recalculate deltatime
	static Clock clock;
	float dt = clock.restart().asSeconds();
	const float bx = ball.getPosition().x;
	const float by = ball.getPosition().y;
	if (by > gameHeight) {
		//bottomwall
		ballVelocity.x *= 1.1f;
		ballVelocity.y *= -1.1f;
		ball.move(0, -10);
	}
	else if (by < 0)
	{
		//top wall
		ballVelocity.x *= 1.1f;
		ballVelocity.y *= -1.1f;
		ball.move(0, 10);
	}
	else if (bx > gameWidth) {
		//rightwall
		reset();

	}
	else if (bx < 0) {
		//leftwall
		reset();
	}
	else if (
		//ball is inline or behind paddle
		bx < paddleSize.x &&
		//And  ball is below top edge of paddle
		by > paddles[0].getPosition().y - (paddleSize.y * 0.5) &&
		//And ball is above bottome edge of paddle
		by < paddles[0].getPosition().y + (paddleSize.y * 0.5)
		) { 
		//bounce of left paddle
		ballVelocity.x *= -1.1f;
		ballVelocity.y *= -1.1f;
		ball.move(0, -10);
	}
	else if (
		//ball is inline or behind paddle
		bx < paddleSize.x &&
		//And  ball is below top edge of paddle
		by > paddles[1].getPosition().y -(paddleSize.y * 0.5) &&
		//And ball is above bottome edge of paddle
		by < paddles[1].getPosition().y + (paddleSize.y * 0.5)
		){
		//bounce of right paddles
		ballVelocity.x = 1.1f;
		ballVelocity.y = 1.1f;
		ball.move(0, 10);
	}
	ball.move(ballVelocity * dt);
	// Check and consume events
	Event event;
	while (window.pollEvent(event)) {
		if (event.type == Event::Closed) {
			window.close();
			return;
		}
	}
	//Quit via Esc Key
	if (Keyboard::isKeyPressed(Keyboard::Escape)) {
		window.close();
	}

	//handle paddle movement
	float direction = 0.0f;
	float direction2 = 0.0f;
	if (Keyboard::isKeyPressed(controls[0]) && paddles[0].getPosition().y > 0) {
		direction--;
	}
	if (Keyboard::isKeyPressed(controls[1]) && paddles[0].getPosition().y < gameHeight) {
		direction++;
	}
	paddles[0].move(0, direction * paddleSpeed * dt);

	if (Keyboard::isKeyPressed(controls[2]) && paddles[1].getPosition().y > 0) {
		direction2--;
	}
	if (Keyboard::isKeyPressed(controls[3]) && paddles[1].getPosition().y < gameHeight) {
		direction2++;
	}
	paddles[1].move(0, direction2 * paddleSpeed * dt);
}

void Render(RenderWindow &window) {
	//draw everything
	window.draw(paddles[0]);
	window.draw(paddles[1]);
	window.draw(ball);
}

int main() {
	RenderWindow window(VideoMode(gameWidth, gameHeight), "PONG");
	Load();
	while (window.isOpen()) {
		window.clear();
		Update(window);
		Render(window);
		window.display();
	}
	return 0;
}




