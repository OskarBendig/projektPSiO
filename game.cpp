#include "game.h"

game::game(){}


void game::initGame(){
    initWindow();
    initFonts();
    initMusic();
    initTex();
    makePlats();
    makeHan();
    makeShaks();
}

void game::initWindow(){
    window.create(sf::VideoMode(600,800), "Square Up >:<");
    window.setFramerateLimit(60);
}

void game::initFonts(){
    font.loadFromFile("data/fonts/TinyIslanders.ttf");
    points.setFont(font);
    points.setCharacterSize(60);
    points.setFillColor(sf::Color::Yellow);
}

void game::initMusic(){
    buffer.loadFromFile("data/music/musicc.ogg");
    music.setBuffer(buffer);
    music.setLoop(true);
    music.setVolume(50);
    music.play();
}

void game::initTex(){
    backgroundTex.loadFromFile("data/images/background.png");
    startTex.loadFromFile("data/images/start.png");
    menuTex.loadFromFile("data/images/menu.png");
    looseTex.loadFromFile("data/images/loose.png");
    backgroundSprite.setTexture(backgroundTex);
    startSprite.setTexture(startTex);
    menuSprite.setTexture(menuTex);
    looseSprite.setTexture(looseTex);
}

void game::cleanUp(){
    for(int i = 0; i < 10; i++){
        delete platforms[i];
    }
    if(score >= 20){
        for(int i = 0; i < nrHan; i++){
            delete hantle[i];
        }
    }
    score = 0;
}

void game::makePlats(){
    starter.makeplatform(0, 775);
    bool collidedP;
        for(int i =0; i < 13; i++){
            do{
                collidedP = false;
                platforms[i] = new platform();
                for(int j = 0; j < i; j++){
                    if(platforms[i]->collide(platforms[j])){
                        collidedP = true;
                        delete platforms[i];
                        continue;
                    }
                }
            }while(collidedP);
    }
}

void game::makeShaks(){
    bool collidedP;
        do{
            collidedP = false;
            shak = new shaker();
            for(int j = 0; j < 10; j++){
                if(shak->collide(platforms[j])){
                    collidedP = true;
                    delete shak;
                    break;
                }
            }
        }while(collidedP);
}

void game::makeHan(){ //z nigdy nie wieksze niz 7
    bool collidedP;
    for(int i = 0; i < 7; i++){
        do{
            collidedP = false;
            hantle[i] = new hantel();
            for(int j = 0; j < i; j++){
                if(hantle[i]->collide(hantle[j])){
                    collidedP = true;
                    delete hantle[i];
                    break;
                }
            }
        }while(collidedP);
    }
}


void game::windowEvent(){
    sf::Event event;
    while (window.pollEvent(event)){
        if((event.type == sf::Event::Closed) || (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)){
            window.close();
            cleanUp();
        }
    }
}

void game::platformsDown(){
    bool collidedP;
    if(mc.getY() < h){
        mc.setPosition(mc.getX(), h);
        for(int i = 0; i < 13; i++){
            platforms[i]->moveDown(dy);
            if (platforms[i]->getY() > 800){
                float height = 800;
                for(int k = 0; k < 10; k++){
                    if(platforms[k]->getY() < height && platforms[k]->getY() > 0){
                        height = platforms[k]->getY();
                    }
                }
                while(platforms[i]->getY() - height > 100){
                    do{
                        collidedP = false;
                        platforms[i]->reset();
                        for(int j = 0; j < 10; j++){
                            if(i == j){
                                continue;
                            }
                            if(platforms[i]->collide(platforms[j])){
                                collidedP = true;
                                break;
                            }
                        }
                    }while(collidedP);
                }
            }
        }
        starter.moveDown(dy);
        if(score >= 20){
            for (int l = 0; l < nrHan; l++){
                hantle[l]->moveHan(dy);
            }
        }
        if(score >= 30){
            shak->moveShak(dy);
        }
    }
}


void game::bounce(){
    for (int i = 0; i < 13; i++){
        if(platforms[i]->collideUp(&mc) && !(platforms[i]->wasTouched())){
            if(drinked == false){
                dy = -10;
            }
            score++;
            platforms[i]->setTouch(true);
        }
    }
    if((mc.getY() + 51 > starter.getY()) && (dy>0)){
        dy = -10;
    }
}

void game::bonked(){
    for(int i = 0; i < nrHan; i++){
        if(hantle[i]->collide(&mc)){
            dy = 10;
        }
    }
}

void game::drink(){
    if(shak->collide(&mc)){
        drinked = true;
        score += 5;
        startTime = GetTickCount();
    }
}

void game::draw(){
    window.draw(backgroundSprite);
    window.draw(mc.mcSprite);
    for(int i = 0; i < 13; i++){
        platforms[i]->platformSprite.setPosition(platforms[i]->getX(), platforms[i]->getY());
        if(!(platforms[i]->wasTouched())){
        window.draw(platforms[i]->platformSprite);
        }
    }
    startSprite.setPosition(starter.getX(), starter.getY());
    window.draw(startSprite);
    window.draw(points);
}

void game::drawHan(){
    for(int i = 0; i < nrHan ; i++){
        hantle[i]->hantelSprite.setPosition(hantle[i]->getX(), hantle[i]->getY());
        window.draw(hantle[i]->hantelSprite);
    }
}

void game::drawShak(){
    shak->shakerSprite.setPosition(shak->getX(), shak->getY());
    window.draw(shak->shakerSprite);
}

void game::resetHan(){
    for(int i = 0; i < nrHan; i++){
        hantle[i]->resetHantel();
    }
}

void game::showScore(){
    auto s = std::to_string(score);
    points.setString("Your score is: " + s);
    points.setPosition(0, 0);
    points.setFillColor(sf::Color::Yellow);
}


void game::gameLoop(){
    //gameloop
    while (window.isOpen()){
        windowEvent();

        //moving
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::D) && flip){
            flip = false;
            mc.mcSprite.scale(-1, 1);
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::A) && !(flip)){
            flip = true;
            mc.mcSprite.scale(-1, 1);
        }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)){mc.move(4, 0);}
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)){mc.move(-4, 0);}

        if(drinked){
            double currentTime = GetTickCount() - startTime;
            dy = -15;
            if( currentTime >= 2000 ){
                drinked = false;
            }
        }else{
            dy += 0.15;
        }
        mc.move(0, dy);

        //drawing sprites
        showScore();
        draw();

        nrHan = 1 + score/60;
        if(nrHan > 7){
            nrHan = 7;
        }
        if(score >= 20){
            if(score%20 == 0){
                resetHan();
            }
            for(int i = 0; i < nrHan; i++){
                hantle[i]->moveHan(-1);
            }
            //hantle things and stuff
            bonked();
            drawHan();
        }

        if (score >= 50){
            if(score%50 == 0){
                shak->resetShak();
            }
            drink();
            drawShak();
        }
        //map moving upwards
        platformsDown();

        //collisions
        bounce();

        //mc position
        mc.updatePosition();

        //death
        if(mc.isDead()){
             loosingScreen();
             cleanUp();
             makePlats();
             makeHan();
             mc.setPosition(25, 700);
        }

        window.display();
    }
}

void game::startingScreen(){
    while(window.isOpen()){
        window.draw(menuSprite);
        sf::Event event;
        while (window.pollEvent(event)){
            if((event.type == sf::Event::Closed) || (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)){
                cleanUp();
                window.close();
            }
            if(event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Enter){
                return;
            }
        }
        window.display();
    }
}

void game::loosingScreen(){
    while(window.isOpen()){
        window.draw(looseSprite);
        sf::Event event;
        while (window.pollEvent(event)){
            if((event.type == sf::Event::Closed) || (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)){
                cleanUp();
                window.close();
            }
            if(event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Enter){
                return;
            }
        }
        window.display();
    }
}
