#include <SFML\Graphics.hpp>
#include <SFML\Audio.hpp>
#include <cstdlib>
#include <iostream>
using namespace std;

sf::RenderWindow window(sf::VideoMode(500, 500), "Shoot the target", sf::Style::Titlebar | sf::Style::Close);




class wallet {
    int points = 0;
    int fiftyrs_token = 0;
    int hundredrs_token = 0;


public:

    int getfiftyrstoken() {
        return fiftyrs_token;
    }

    void setfiftyrstoken(int a) {
        fiftyrs_token = fiftyrs_token + a;
    }

    int gethundredrstoken() {
        return hundredrs_token;
    }

    void sethundredrstoken(int a) {
        fiftyrs_token = hundredrs_token + a;
    }

    int getpoints() {
        return points;
    }

    void setpoints(int a) {
        points = a;
    }

    void addpoints(int a) {
        setpoints(getpoints() + a);
    }

    void redeempoints() {

        for (int k = 0;k < 1;) {
            cout << "ENTER" << endl;
            cout << "1.Redeem 50Rs. token for 100 points" << endl;
            cout << "2.Redeem 100Rs. token for 200 points" << endl;
            cout << "3.Return " << endl;
            char input;
            cin >> input;
            system("cls");
            if (input == '1') {
                if (getpoints() >= 100) {
                    setfiftyrstoken(getfiftyrstoken() + 1);
                    setpoints(getpoints() - 100);
                    cout << "You received a 50Rs. voucher" << endl;
                    cout << "Your remaining points are" << getpoints() << endl;
                }
                else {
                    cout << "Insufficient points" << endl;
                    cout << "Your remaining points are " << getpoints() << endl << endl;
                }
            }
            else if (input == '2') {
                if (getpoints() >= 200) {
                    sethundredrstoken(gethundredrstoken() + 1);
                    setpoints(getpoints() - 200);
                    cout << "You received a 100Rs. voucher" << endl;
                    cout << "Your remaining points are" << getpoints() << endl;
                }
                else {
                    cout << "Insufficient points" << endl;
                    cout << "Your remaining points are " << getpoints() << endl << endl;
                }
            }
            else if (input == '3') {
                k++;
            }
            else {

            }

        }


    }




    virtual void Playgame() {

    }


};



class playgame :public wallet {

public:

    int score = 0;
    int countdown = 60;
    int gamepoints = 0;



public:

    void Playgame() {

        start();
        game();
        end();

    }


    void end() {

        bool win = 0;

        sf::Clock clock;
        sf::SoundBuffer gameover_buffer;
        if (!gameover_buffer.loadFromFile("gameover.wav")) {
            cout << "error" << endl;
        }

        sf::Texture windowtexture;
        windowtexture.loadFromFile("space.png");
        sf::RectangleShape background(sf::Vector2f(500.0f, 500.0f));
        background.setOrigin(0.0f, 0.0f);
        background.setTexture(&windowtexture);


        sf::Font font;
        font.loadFromFile("digital-7.ttf");



        sf::Text scoretext("YOUR SCORE: ", font);
        scoretext.setCharacterSize(70);
        scoretext.setFillColor(sf::Color::Yellow);
        scoretext.setOrigin(-70.0f, -300.0f);

        string  a = to_string(score);
        sf::Text scorenum(a, font);
        scorenum.setCharacterSize(70);
        scorenum.setFillColor(sf::Color::Yellow);
        scorenum.setOrigin(-410.0f, -300.0f);

        sf::Sound gameover_sound;
        gameover_sound.setBuffer(gameover_buffer);
        gameover_sound.setVolume(50);
        gameover_sound.play();
        window.clear();



        sf::Text gameover_text("BETTER LUCK NEXT TIME", font);
        gameover_text.setCharacterSize(50);
        gameover_text.setFillColor(sf::Color::Cyan);
        gameover_text.setOrigin(-30.0f, -100.0f);

        sf::Text gamewin_text("CONGRATULATIONS", font);
        gamewin_text.setFillColor(sf::Color::Magenta);
        gamewin_text.setOrigin(-20.0f, -100.0f);
        gamewin_text.setCharacterSize(70);


        sf::Text reward_text("YOU GOT 50 POINTS", font);
        reward_text.setFillColor(sf::Color::Magenta);
        reward_text.setOrigin(-80.0f, -200.0f);
        reward_text.setCharacterSize(50);



        while (window.isOpen()) {
            sf::Event evnt;
            float a = clock.getElapsedTime().asSeconds();
            if (a < 10) {
                while (window.pollEvent(evnt))
                {

                    switch (evnt.type)
                    {

                    case sf::Event::Closed:

                        window.clear();
                        if (win == 1) {
                            addpoints(50);
                        }
                        window.setVisible(0);
                        win = 0;

                        return;
                        break;
                    case sf::Event::Resized:
                        window.clear();

                        window.display();

                        // cout << "New window height : " << evnt.size.height << " New window width " << evnt.size.width << endl;
                        break;

                    }
                }
                window.draw(background);
                if (score < 10) {
                    window.draw(gameover_text);
                }
                else {
                    win = 1;
                    window.draw(gamewin_text);
                    window.draw(reward_text);


                }
                window.draw(scorenum);
                window.draw(scoretext);

                window.display();

            }
            else {
                window.clear();
                return;
            }

        }

    }


    void start() {
        sf::Texture windowtexture;
        windowtexture.loadFromFile("space.png");
        sf::RectangleShape background(sf::Vector2f(500.0f, 500.0f));
        background.setOrigin(0.0f, 0.0f);
        background.setTexture(&windowtexture);




        sf::RectangleShape player2(sf::Vector2f(50.0f, 50.0f));

        player2.setOrigin(-130.0f, -125.0f);

        sf::CircleShape target1(15, 100);
        // target1.setFillColor(sf::Color::Green);
        target1.setOrigin(-140.0f, -200.0f);

        sf::RectangleShape spacebar(sf::Vector2f(100.0f, 30.0f));

        spacebar.setOrigin(-150.0f, -360.0f);
        sf::Texture spacebartexture;
        spacebartexture.loadFromFile("spacebar.png");
        spacebar.setTexture(&spacebartexture);

        sf::RectangleShape larrow(sf::Vector2f(30.0f, 30.0f));

        larrow.setOrigin(-160.0f, -440.0f);
        sf::Texture larrowtexture;
        larrowtexture.loadFromFile("leftarrow.png");
        larrow.setTexture(&larrowtexture);

        sf::RectangleShape rarrow(sf::Vector2f(30.0f, 30.0f));

        rarrow.setOrigin(-220.0f, -440.0f);
        sf::Texture rarrowtexture;
        rarrowtexture.loadFromFile("rightarrow.png");
        rarrow.setTexture(&rarrowtexture);

        sf::RectangleShape darrow(sf::Vector2f(30.0f, 30.0f));

        darrow.setOrigin(-190.0f, -440.0f);
        sf::Texture darrowtexture;
        darrowtexture.loadFromFile("darrow.jpg");
        darrow.setTexture(&darrowtexture);

        sf::RectangleShape uarrow(sf::Vector2f(30.0f, 30.0f));

        uarrow.setOrigin(-190.0f, -410.0f);
        sf::Texture uarrowtexture;
        uarrowtexture.loadFromFile("uarrow.png");
        uarrow.setTexture(&uarrowtexture);

        sf::RectangleShape asteroid(sf::Vector2f(50.0f, 50.0f));
        asteroid.setOrigin(-130.0f, -260.0f);
        sf::Texture asteroidtexture;
        asteroidtexture.loadFromFile("asteroid.png");
        asteroid.setTexture(&asteroidtexture);

        sf::Font font;
        font.loadFromFile("digital-7.ttf");


        sf::Text text1("YOUR SHIP ", font);
        text1.setCharacterSize(35);
        text1.setFillColor(sf::Color::Green);
        text1.setOrigin(-200.0f, -128.0f);

        sf::Text text2("TARGETS ", font);
        text2.setCharacterSize(35);
        text2.setFillColor(sf::Color::Green);
        text2.setOrigin(-200.0f, -192.0f);

        sf::Text text3(" USE                 TO SHOOT ", font);
        text3.setCharacterSize(35);
        text3.setFillColor(sf::Color::Blue);
        text3.setOrigin(-60.0f, -350.0f);

        sf::Text text4("   USE             TO MOVE ", font);
        text4.setCharacterSize(35);
        text4.setFillColor(sf::Color::Blue);
        text4.setOrigin(-60.0f, -430.0f);

        sf::Text text("INSTRUCTIONS : ", font);
        text.setCharacterSize(70);
        text.setStyle(sf::Text::Bold);
        text.setFillColor(sf::Color::Magenta);
        text.setOrigin(-50.0f, -20.0f);


        sf::Text text5("ASTEROIDS  ", font);
        text5.setCharacterSize(35);
        text5.setFillColor(sf::Color::Green);
        text5.setOrigin(-200.0f, -260.0f);

        sf::Text wintext("SCORE 10 OR MORE  ", font);
        wintext.setCharacterSize(60);
        wintext.setFillColor(sf::Color::Cyan);
        wintext.setOrigin(-40.0f, -100.0f);

        sf::Text wintext2("TO EARN  ", font);
        wintext2.setCharacterSize(60);
        wintext2.setFillColor(sf::Color::Cyan);
        wintext2.setOrigin(-150.0f, -170.0f);

        sf::Text wintext3("50   ", font);
        wintext3.setCharacterSize(80);
        wintext3.setFillColor(sf::Color::Yellow);
        wintext3.setOrigin(-210.0f, -230.0f);

        sf::Text wintext4("REWARD POINTS  ", font);
        wintext4.setCharacterSize(60);
        wintext4.setFillColor(sf::Color::Cyan);
        wintext4.setOrigin(-80.0f, -320.0f);

        sf::Texture playertexture;
        playertexture.loadFromFile("galaga1.png");
        player2.setTexture(&playertexture);

        sf::Texture targettexture;
        targettexture.loadFromFile("bug1.png");
        target1.setTexture(&targettexture);




        sf::Clock clock;

        while (window.isOpen()) {
            sf::Event evnt;
            float a = clock.getElapsedTime().asSeconds();
            if (a < 15) {
                while (window.pollEvent(evnt))
                {

                    switch (evnt.type)
                    {

                    case sf::Event::Closed:
                        window.clear();
                        window.close();

                        return;
                        break;
                    case sf::Event::Resized:
                        window.clear();
                        window.draw(player2);
                        window.draw(target1);
                        window.display();

                        // cout << "New window height : " << evnt.size.height << " New window width " << evnt.size.width << endl;
                        break;

                    }
                }
                if (a > 5) {
                    window.clear();
                    window.draw(spacebar);
                    window.draw(larrow);
                    window.draw(rarrow);
                    window.draw(darrow);
                    window.draw(uarrow);
                    window.draw(player2);
                    window.draw(target1);
                    window.draw(text);
                    window.draw(text1);
                    window.draw(text2);
                    window.draw(text3);
                    window.draw(text4);
                    window.draw(text5);

                    window.draw(asteroid);

                    window.display();
                }
                else {

                    window.clear();
                    window.draw(wintext);
                    window.draw(wintext2);
                    window.draw(wintext3);
                    window.draw(wintext4);

                    window.display();

                }

            }
            else {
                window.clear();
                return;
            }

        }
    }





    int game()
    {
        int i = 0, o = 0;
        bool shoot = 0;
        int asteroidshot1 = 0;
        int asteroidshot2 = 0;
        int targetmovement = 0;
        float targetparameter = 0;

        sf::SoundBuffer buffer_bug;
        if (!buffer_bug.loadFromFile("bugdie.wav")) {
            cout << "ERROR" << endl;
        }

        sf::Sound bugdie_sound;
        bugdie_sound.setBuffer(buffer_bug);
        bugdie_sound.setVolume(100);



        sf::SoundBuffer buffer;

        if (!buffer.loadFromFile("lasersmol.wav")) {
            cout << "ERROR" << endl;

        }

        sf::Sound sound;
        sound.setBuffer(buffer);
        sound.setVolume(15);




        srand((unsigned)time(0));
        sf::Texture windowtexture;
        windowtexture.loadFromFile("space.png");
        sf::RectangleShape background(sf::Vector2f(500.0f, 500.0f));
        background.setOrigin(0.0f, 0.0f);
        background.setTexture(&windowtexture);




        sf::RectangleShape player2(sf::Vector2f(50.0f, 50.0f));

        player2.setOrigin(-0.0f, -450.0f);

        sf::CircleShape target1(15, 100);
        // target1.setFillColor(sf::Color::Green);
        target1.setOrigin(-250.0f, -100.0f);

        sf::RectangleShape targetarea(sf::Vector2f(27.0f, 27.0f));
        targetarea.setFillColor(sf::Color::Transparent);
        targetarea.setOrigin(-250.0f, -100.0f);

        sf::RectangleShape missile(sf::Vector2f(5.0f, 30.0f));
        missile.setFillColor(sf::Color::Red);
        missile.setOrigin(0.0f, 0.0f);

        sf::RectangleShape reset(sf::Vector2f(500.0f, 1.0f));

        reset.setOrigin(0.0f, 100.0f);
        reset.setFillColor(sf::Color::Cyan);

        sf::RectangleShape resetasteroid(sf::Vector2f(500.0f, 1.0f));

        resetasteroid.setOrigin(0.0f, -600.0f);
        resetasteroid.setFillColor(sf::Color::Cyan);

        sf::RectangleShape asteroid(sf::Vector2f(40.0f, 40.0f));
        asteroid.setOrigin(-250.0f, 40.0f);
        sf::Texture asteroidtexture;
        asteroidtexture.loadFromFile("asteroid.png");
        asteroid.setTexture(&asteroidtexture);

        sf::RectangleShape asteroid1(sf::Vector2f(40.0f, 40.0f));
        asteroid1.setOrigin(-20.0f, 40.0f);
        asteroid1.setTexture(&asteroidtexture);

        sf::Font font;
        font.loadFromFile("digital-7.ttf");

        // sf::RectangleShape civilian(sf::Vector2f(60.0f,40.0f));
        // civilian.setFillColor(sf::Color::Green);
        // civilian.setOrigin(-250.0f,-150.0f);



        sf::Text text("SCORE : ", font);
        text.setCharacterSize(50);
        text.setStyle(sf::Text::Bold);
        text.setFillColor(sf::Color::Magenta);
        text.setPosition(0.0f, 0.0f);

        sf::Texture playertexture;
        playertexture.loadFromFile("galaga1.png");
        player2.setTexture(&playertexture);

        sf::Texture targettexture;
        targettexture.loadFromFile("bug1.png");
        target1.setTexture(&targettexture);

        sf::Clock Clock;







        while (window.isOpen())
        {
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
                if (o == 0) {
                    sound.play();
                }o++;
            }
            float time_elapsed = Clock.getElapsedTime().asSeconds();
            if (time_elapsed >= 1.0) {
                countdown--;
                Clock.restart();
            }
            string  c = to_string(countdown);

            sf::Text time_displ(c, font);
            time_displ.setCharacterSize(50);
            time_displ.setStyle(sf::Text::Bold);
            time_displ.setFillColor(sf::Color::Yellow);
            time_displ.setPosition(450.0f, 0.0f);


            string  a = to_string(score);

            sf::Text b(a, font);
            b.setCharacterSize(50);
            b.setStyle(sf::Text::Bold);
            b.setFillColor(sf::Color::Magenta);

            b.setPosition(170.0f, 0.0f);

            sf::Event evnt;

            while (window.pollEvent(evnt))
            {

                switch (evnt.type)
                {

                case sf::Event::Closed:

                    window.close();
                    break;
                case sf::Event::Resized:
                    window.clear();
                    window.draw(player2);
                    window.draw(target1);
                    window.display();

                    // cout << "New window height : " << evnt.size.height << " New window width " << evnt.size.width << endl;
                    break;

                }
            }

            if (countdown < 55) {
                asteroid.move(0.0f, 0.15f);
            }
            if (countdown < 54) {
                asteroid1.move(0.0f, 0.15f);
            }

            if (asteroid1.getGlobalBounds().intersects(resetasteroid.getGlobalBounds())) {
                float b = (rand() % 200);
                asteroid1.setPosition(b, -40.0f);
                asteroidshot2 = 0;
            }
            if (asteroid.getGlobalBounds().intersects(resetasteroid.getGlobalBounds())) {
                float b = (rand() % 230);
                asteroid.setPosition(b, -40.0f);
                asteroidshot1 = 0;
            }

            if (asteroid.getGlobalBounds().intersects(player2.getGlobalBounds())) {
                asteroid.setPosition(asteroid.getPosition().x, -40.0f);

                countdown = 0;
            }
            if (asteroid1.getGlobalBounds().intersects(player2.getGlobalBounds())) {
                asteroid1.setPosition(asteroid1.getPosition().x, -40.0f);

                countdown = 0;
            }



            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
                player2.move(0.0f, -0.2f);

                if (player2.getPosition().y < -40.0f) {
                    player2.setPosition(player2.getPosition().x, -40.0f);
                }
            }

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
                player2.move(0.0f, 0.2f);

                if (player2.getPosition().y >= 0.0f) {
                    player2.setPosition(player2.getPosition().x, 0.0f);
                }
            }

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left))
            {
                player2.move(-0.2f, 0.0f);
                if (player2.getPosition().x <= 0)
                {
                    player2.setPosition(0, player2.getPosition().y);
                }
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right))
            {
                player2.move(0.2f, 0.0f);
                if (player2.getPosition().x >= 450)
                {
                    player2.setPosition(450, player2.getPosition().y);
                }
            }

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space))
            {
                if (shoot == 0)
                {
                    missile.setPosition(player2.getPosition().x + 23, 420.0f);
                    shoot = 1;
                }

            }

            if (countdown < 61) {

                if (targetmovement == 0) {
                    target1.move(0.1f, 0.0f);
                    targetarea.setPosition(target1.getPosition().x, target1.getPosition().y);
                    if (target1.getPosition().x >= targetparameter + 100.0f || target1.getPosition().x >= 230) {//if(target1.getPosition().x>=230)
                        targetmovement = 1;
                    }
                }

                if (targetmovement == 1) {
                    target1.move(-0.1f, 0.0f);
                    targetarea.setPosition(target1.getPosition().x, target1.getPosition().y);
                    if (target1.getPosition().x <= targetparameter - 100.0f || target1.getPosition().x <= -230) { //if(target1.getPosition().x<=-230)
                        targetmovement = 0;
                    }
                }
            }



            if (asteroid.getGlobalBounds().intersects(targetarea.getGlobalBounds()) || asteroid1.getGlobalBounds().intersects(targetarea.getGlobalBounds())) {

                bugdie_sound.play();
                float a = (rand() % 480) - 250;
                if (targetmovement == 0) {
                    targetmovement = 1;
                }
                else {
                    targetmovement = 0;
                }
                targetparameter = a;
                target1.setPosition(a, -0.0f);
                targetarea.setPosition(a, 0.0f);

            }

            if (shoot == 1)
            {

                missile.move(0.0f, -0.4f);


                if (missile.getGlobalBounds().intersects(targetarea.getGlobalBounds()))
                {
                    bugdie_sound.play();
                    float a = (rand() % 460) - 250;
                    if (targetmovement == 0) {
                        targetmovement = 1;
                    }
                    else {
                        targetmovement = 0;
                    }
                    targetparameter = a;
                    target1.setPosition(a, -0.0f);
                    targetarea.setPosition(a, 0.0f);
                    score++;
                    missile.setPosition(0.0f, 0.0f);

                    shoot = 0;
                    o = 0;

                }
                else if (missile.getGlobalBounds().intersects(reset.getGlobalBounds())) {
                    missile.setPosition(0.0f, 0.0f);
                    shoot = 0;
                    o = 0;
                }
                else if (missile.getGlobalBounds().intersects(asteroid.getGlobalBounds())) {
                    missile.setPosition(0.0f, 0.0f);
                    shoot = 0;
                    o = 0;
                    asteroidshot1++;
                    if (asteroidshot1 == 2) {
                        float a = (rand() % 230);
                        missile.setPosition(0.0f, 0.0f);
                        asteroid.setPosition(a, -80.0f);
                        shoot = 0;
                        o = 0;
                        asteroidshot1 = 0;
                    }
                }
                else if (missile.getGlobalBounds().intersects(asteroid1.getGlobalBounds())) {
                    missile.setPosition(0.0f, 0.0f);
                    shoot = 0;
                    o = 0;
                    asteroidshot2++;

                    if (asteroidshot2 == 2) {
                        float a = (rand() % 200);
                        missile.setPosition(0.0f, 0.0f);
                        asteroid1.setPosition(a, -80.0f);
                        shoot = 0;
                        o = 0;
                        asteroidshot2 = 0;
                    }
                }
            }





            window.clear();
            if (countdown > 0) {
                window.draw(background);
                if (missile.getPosition().x != 0.0f && missile.getPosition().y != 0.0f) {
                    window.draw(missile);
                }
                window.draw(time_displ);
                window.draw(b);
                window.draw(text);
                window.draw(target1);
                window.draw(player2);
                window.draw(asteroid);
                window.draw(asteroid1);
                window.display();
            }
            if (countdown == 0) {
                window.clear();
                return 0;
            }
            if (countdown == -2) {

                // window.close();
                return 0;
            }
        }

        return 0;
    }


};




class walletmenu : public wallet {

public:



    void display() {
        system("cls");
        wallet w;
        window.setVisible(1);
        wallet* w1 = new playgame;
        w1->Playgame();
        w.setpoints(w.getpoints() + w1->getpoints());
        delete w1;


        }
    




};



int main() {
    walletmenu w;
    w.display();

}