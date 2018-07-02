#include <iostream>
#include <string>
#include "Entity.hpp"
#include "Enemy.hpp"
#include "Player.hpp"
#include "Rock.hpp"
#include "Projectile.hpp"


int     main( void ) {
  /* on the stack;
  Entity en1 = Entity(10, 10, 10, 10, 5);
  Entity en2 = Entity(20, 20, 20, 20, 5);
  Entity en3;



  std::cout << en1.getHp() << " " << en1.getLives() << " "
            << en1.getPosX() << " " << en1.getPosY() << " "
            << en1.getSpeed() << std::endl;

  std::cout << en2.getHp() << " " << en2.getLives() << " "
            << en2.getPosX() << " " << en2.getPosY() << " "
            << en2.getSpeed() << std::endl;

  std::cout << en3.getHp() << " " << en3.getLives() << " "
            << en3.getPosX() << " " << en3.getPosY() << " "
            << en3.getSpeed() << std::endl;

  Enemy enemy1 = Enemy(30, 30, 30, 30, 30);

  std::cout << enemy1.getHp() << " " << enemy1.getLives() << " "
            << enemy1.getPosX() << " " << enemy1.getPosY() << " "
            << enemy1.getSpeed() << " " << enemy1.getName() << " "
            << enemy1.getSprite() << std::endl;


  Player player1 = Player(50, 50, 50, 50, 50);

  std::cout << player1.getHp() << " " << player1.getLives() << " "
            << player1.getPosX() << " " << player1.getPosY() << " "
            << player1.getSpeed() << " " << player1.getName() << " "
            << player1.getSprite() << std::endl;
  */

  /* on the stack
  Rock rock1 = Rock(2, 2, 5, 5, 5);
  rock1.takeDamage();
  std::cout << rock1.getHp() << " " << rock1.getLives() << " "
            << rock1.getPosX() << " " << rock1.getPosY() << " "
            << rock1.getSpeed() << " " << rock1.getName() << " "
            << rock1.getSprite() << std::endl;

  rock1.takeDamage();
  std::cout << rock1.getHp() << " " << rock1.getLives() << " "
            << rock1.getPosX() << " " << rock1.getPosY() << " "
            << rock1.getSpeed() << " " << rock1.getName() << " "
            << rock1.getSprite() << std::endl;
  rock1.takeDamage();
  std::cout << rock1.getHp() << " " << rock1.getLives() << " "
            << rock1.getPosX() << " " << rock1.getPosY() << " "
            << rock1.getSpeed() << " " << rock1.getName() << " "
            << rock1.getSprite() << std::endl;
  rock1.takeDamage();
  std::cout << rock1.getHp() << " " << rock1.getLives() << " "
            << rock1.getPosX() << " " << rock1.getPosY() << " "
            << rock1.getSpeed() << " " << rock1.getName() << " "
            << rock1.getSprite() << std::endl;
  rock1.takeDamage();
  std::cout << rock1.getHp() << " " << rock1.getLives() << " "
            << rock1.getPosX() << " " << rock1.getPosY() << " "
            << rock1.getSpeed() << " " << rock1.getName() << " "
            << rock1.getSprite() << std::endl;
  */
  /* on the heap
  Rock *rock1 = new Rock(2, 2, 5, 5, 5);

  rock1->takeDamage();
  std::cout << rock1->getHp() << " " << rock1->getLives() << " "
            << rock1->getPosX() << " " << rock1->getPosY() << " "
            << rock1->getSpeed() << " " << rock1->getName() << " "
            << rock1->getSprite() << std::endl;
  rock1->takeDamage();
  std::cout << rock1->getHp() << " " << rock1->getLives() << " "
            << rock1->getPosX() << " " << rock1->getPosY() << " "
            << rock1->getSpeed() << " " << rock1->getName() << " "
            << rock1->getSprite() << std::endl;
  rock1->takeDamage();
  std::cout << rock1->getHp() << " " << rock1->getLives() << " "
            << rock1->getPosX() << " " << rock1->getPosY() << " "
            << rock1->getSpeed() << " " << rock1->getName() << " "
            << rock1->getSprite() << std::endl;
  rock1->takeDamage();
  std::cout << rock1->getHp() << " " << rock1->getLives() << " "
            << rock1->getPosX() << " " << rock1->getPosY() << " "
            << rock1->getSpeed() << " " << rock1->getName() << " "
            << rock1->getSprite() << std::endl;

  delete rock1;
  */

  Enemy enemy = Enemy(2, 2, 5, 5, 5);
  // enemy.takeDamage();
  std::cout << enemy.getHp() << " " << enemy.getLives() << " "
            << enemy.getPosX() << " " << enemy.getPosY() << " "
            << enemy.getSpeed() << " " << enemy.getName() << " "
            << enemy.getSprite() << std::endl;
  Player player = Player(5, 5, 5, 5, 5);
  Player player2 = Player(1, 1, 1, 1, 1);
  // player.takeDamage();
  // std::cout << player.getHp() << " " << player.getLives() << " "
  //           << player.getPosX() << " " << player.getPosY() << " "
  //           << player.getSpeed() << " " << player.getName() << " "
  //           << player.getSprite() << std::endl;
  player.attacks(enemy);
  std::cout << enemy.getHp() << " " << enemy.getLives() << " "
            << enemy.getPosX() << " " << enemy.getPosY() << " "
            << enemy.getSpeed() << " " << enemy.getName() << " "
            << enemy.getSprite() << std::endl;
  player.attacks(enemy);
  std::cout << enemy.getHp() << " " << enemy.getLives() << " "
            << enemy.getPosX() << " " << enemy.getPosY() << " "
            << enemy.getSpeed() << " " << enemy.getName() << " "
            << enemy.getSprite() << std::endl;
  enemy.attacks(player);
  std::cout << player.getHp() << " " << player.getLives() << " "
            << player.getPosX() << " " << player.getPosY() << " "
            << player.getSpeed() << " " << player.getName() << " "
            << player.getSprite() << std::endl;

  std::cout << player2.getHp() << " " << player2.getLives() << " "
            << player2.getPosX() << " " << player2.getPosY() << " "
            << player2.getSpeed() << " " << player2.getName() << " "
            << player2.getSprite() << std::endl;

  enemy.moveLeft();
  std::cout << enemy.getHp() << "M Left: " << enemy.getLives() << " "
            << enemy.getPosX() << " " << enemy.getPosY() << " "
            << enemy.getSpeed() << " " << enemy.getName() << " "
            << enemy.getSprite() << std::endl;
  enemy.moveRight();
  std::cout << enemy.getHp() << "M Right " << enemy.getLives() << " "
            << enemy.getPosX() << " " << enemy.getPosY() << " "
            << enemy.getSpeed() << " " << enemy.getName() << " "
            << enemy.getSprite() << std::endl;
  enemy.moveDown();
  std::cout << enemy.getHp() << "M Down " << enemy.getLives() << " "
            << enemy.getPosX() << " " << enemy.getPosY() << " "
            << enemy.getSpeed() << " " << enemy.getName() << " "
            << enemy.getSprite() << std::endl;
  enemy.moveUp();
  std::cout << enemy.getHp() << "M UP " << enemy.getLives() << " "
            << enemy.getPosX() << " " << enemy.getPosY() << " "
            << enemy.getSpeed() << " " << enemy.getName() << " "
            << enemy.getSprite() << std::endl;
  return (0);
}
