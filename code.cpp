#include <SFML/Graphics.hpp>
#include <time.h>
#include <string>
#include <iostream>
using namespace sf;

struct point
{
	int x, y;
};

int main()
{
	srand(time(0));
	int steps = 0;
	int test_x = 0;
	int test_y = 0;
	int count_jump = 0;


	//рендеринг главного окна
	RenderWindow app(VideoMode(400, 533), " Chicken!");
	app.setFramerateLimit(60);


	
	Texture t1, t2, t3, t4, t5, sweet,twin,tp, num0, num1, num2, num3, num4,num5,num6,num7,num8,num9;

	//загружаем текстуры
	t1.loadFromFile("images/nebo23.png");
	t2.loadFromFile("images/platform.png");
	t3.loadFromFile("images/birdie/birdie_worth.png");
	t4.loadFromFile("images/birdie/birdie_flight.png");
	t5.loadFromFile("images/nebo_lose.png");
	sweet.loadFromFile("images/konfeta.png");
	twin.loadFromFile("images/nebo_w.png");
	tp.loadFromFile("images/nebo_p.png");


	num0.loadFromFile("images/123/0.png");
	num1.loadFromFile("images/123/1.png");
	num2.loadFromFile("images/123/2.png");
	num3.loadFromFile("images/123/3.png");
	num4.loadFromFile("images/123/4.png");
	num5.loadFromFile("images/123/5.png");
	num6.loadFromFile("images/123/6.png");
	num7.loadFromFile("images/123/7.png");
	num8.loadFromFile("images/123/8.png");
	num9.loadFromFile("images/123/9.png");


	//регистририруем спрайты
	Sprite sBackground(t1), sPlat(t2), sPers(t3), sNum(num0),sNum1(num0),swPlat(sweet) ;


	//создаем платформы
	point plat[14];
	point plat2[2];


	//определяем начальные координаты платформ
	for (int i = 0; i < 7; i++)
	{
		plat[i].x = rand() % 400 + 10;
		plat[i].y = rand() % 530-50;
	}

		plat2[0].x = rand() % 400 + 10;
		plat2[0].y = rand() % 530 - 50;

		//присываиваем значения переменным перед запуском игры
	int x = 100, y = 100, h = 200;
	float dx = 0, dy = 0;

	//запуск приложения

	while (app.isOpen())
	{
		Event e;
		while (app.pollEvent(e))
		{
			//обработка события закрытия
			if (e.type == Event::Closed)
				app.close();
		}
//обработка левой и правой клавиши
		if (Keyboard::isKeyPressed(Keyboard::Right)) x += 4;
		if (Keyboard::isKeyPressed(Keyboard::Left)) x -= 4;


		//плавное падение
		dy += 0.2;
		y += dy;

		//обработка проигрыша
		if (y > 500) {
			sBackground.setTexture(t5);
		
		}

		//движение платформ вместе с экраном
		if (y < h){
			for (int i = 0; i < 7; i++)
			{
				y = h;
				plat[i].y = plat[i].y - dy;
				if (plat[i].y > 533) { plat[i].y = 0; plat[i].x = rand() % 400; }

				
			}

			//движение платформы батута
			plat2[0].y = plat2[0].y - dy;
			if (plat2[0].y > 533) { plat2[0].y = 0; plat2[0].x = rand() % 400; }
		}
//реализация прыжка от платформы
		for (int i = 0; i < 7; i++){
			if ((x + 50 > plat[i].x) && (x + 20 < plat[i].x + 68)
				&& (y + 70 > plat[i].y) && (y + 70 < plat[i].y + 14) && (dy > 0)) {

				
					dy = -10;
				
				
			//обработка счета	
				
				if (test_x != plat[i].x && test_y != plat[i].y ){
					count_jump = count_jump + 1;
					
					test_x = plat[i].x;
					test_y = plat[i].y;
				}
			}
		}

			
		//обработка прыжка для батута
			if ((x + 50 > plat2[0].x) && (x + 20 < plat2[0].x + 68)
				&& (y + 70 > plat2[0].y) && (y + 70 < plat2[0].y + 14) && (dy > 0)) {
				dy = -30;
	
				if (test_x != plat2[0].x && test_y != plat2[0].y) {
					count_jump = count_jump + 1;
					test_x = plat[0].x;
					test_y = plat[0].y;
				}
			}


			// реализацич появления персонажа с другой стороныб если он вылетел за пределы карты горизонтально
		if (x > 400) {
			x = x - 400;
		}
		if (x < 0) {
			x = x + 400;
		}
		// позиционирование персонажа
		sPers.setPosition(x, y);
		/ прорисовка фона
		app.draw(sBackground);


		// анимация персонажа
		if (dy < 0) {
			sPers.setTexture(t4);
		}
		else {
			sPers.setTexture(t3);
		}

		//отображение персонажа
		app.draw(sPers);
		
// отображение счета как картинки
		if (count_jump / 10 == 0) { sNum.setTexture(num0); }
		if (count_jump / 10 == 1) { sNum.setTexture(num1); }
		if (count_jump / 10 == 2) { sNum.setTexture(num2); }
		if (count_jump / 10 == 3) { sNum.setTexture(num3); }
		if (count_jump / 10 == 4) { sNum.setTexture(num4); }
		if (count_jump / 10 == 5) { sNum.setTexture(num5); }
		if (count_jump / 10 == 6) { sNum.setTexture(num6); }
		if (count_jump / 10 == 7) { sNum.setTexture(num7); }
		if (count_jump / 10 == 8) { sNum.setTexture(num8); }
		if (count_jump / 10 == 9) { sNum.setTexture(num9); }

		if (count_jump % 10 == 0) {sNum1.setTexture(num0);}
		if (count_jump % 10 == 1) {sNum1.setTexture(num1);}
		if (count_jump % 10 == 2) {sNum1.setTexture(num2);}
		if (count_jump % 10 == 3) {sNum1.setTexture(num3);}
		if (count_jump % 10 == 4) {sNum1.setTexture(num4);}
		if (count_jump % 10 == 5) {sNum1.setTexture(num5);}
		if (count_jump % 10 == 6) {sNum1.setTexture(num6);}
		if (count_jump % 10 == 7) {sNum1.setTexture(num7);}
		if (count_jump % 10 == 8) {sNum1.setTexture(num8);}
		if (count_jump % 10 == 9) {sNum1.setTexture(num9);}

//функция выигрыша и продолжения игры далее
		if (count_jump > 20 && count_jump<25) {
			sBackground.setTexture(twin);
		}

		if ( count_jump> 25) {
			sBackground.setTexture(tp);
		}

		//отображение всех остальных спрайтов и позиционирование их
		sNum.setPosition(0, 10);
		app.draw(sNum);

		sNum1.setPosition(20, 10);
		app.draw(sNum1);


		for (int i = 0; i < 7; i++)
		{
			sPlat.setPosition(plat[i].x, plat[i].y);
			app.draw(sPlat);
		}


		swPlat.setPosition(plat2[0].x, plat2[0].y);
		app.draw(swPlat);


		//отображение приложения
		app.display();
	}


	return 0;
}
