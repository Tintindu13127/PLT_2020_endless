# Projet Logiciel Transversal (PLT) 2020-2021

> The goal of this project is to make a video game in C++ for our final year at ENSEA 


[![forthebadge](https://forthebadge.com/images/badges/made-with-c-plus-plus.svg)](https://forthebadge.com)



<!-- TABLE OF CONTENTS -->
## Table of Contents

* [About the Game](#about-the-game)
  * [Presentation](#Presentation)
  * [Game rules](#game-rules)
* [Getting Started](#getting-started)
  * [Prerequisites](#prerequisites)
  * [Installation](#installation)
* [Client](#client)
* [Release History](#release-history)
* [Contact](#contact)


## About the game

### Presentation
The objective of this project is to create a game of the type of [Endless Space 2](https://endless-space-2.fandom.com/wiki/Endless_Space_2_Wiki). Originally, Endless Space 2 is a turn-based strategy video game developed by Amplitude Studios and published by Sega, in which players embody a civilization that will have to extend its influence on a map, a galaxy made up of solar systems that are themselves composed of one to four planets, randomly generated. The solar systems act as "cities" (if compared to Civilization), they are connected to each other by stellar pathways, which serve as roads. The player can move around the galaxy with the help of military or colonizing spaceships.

### Game rules

At the beginning of the game, you only start with a colonized planet in one of the many star systems in the game. Each planet will produce in more or less important quantity four different resources ( Brume, Science, Food, Production ).
You will then be able to create buildings and ships, its last ones will be able to move only on the stellar ways and fight the enemy ships. 
The goal of the game is to extend its civilization to the whole galaxy and to destroy other peoples.

## Getting Started

To get a local copy up and running follow these simple steps.

### Prerequisites

Resynchronize the package index files 
```sh
sudo apt-get update
```

Install with apt-get
```sh
$ apt-get update
$ apt-get install python python3 libmicrohttpd-dev lcov libsfml-dev gcc cmake make libxml2-dev dia lcov libboost-all-dev gcovr python-pip \
   && pip install gcovr
```
### Installation

1. Clone the repo
```sh
git clone https://github.com/Tintindu13127/PLT_2020_endless
cd PLT_2021
```

2. Build it
```sh
$ cd plt
$ mkdir build
$ cd build
$ cmake .. && make
```

## Client

Print a message

```sh
$ ./bin/client hello
```

Print a rendering
```sh
$ ./bin/client hello
```

<!-- RELEASE HISTORY-->
## Release History

* 1.1
    * Implement the code to print a message
    * Report 1.1

* 1.final
    * State diagram 
    * State implementation
    * Test code coverage
    * Report 1.final

* 2.1
    * Report 2.1
    * Render diagram
    * Implemented code to print a rendering of state

* 2.2
    * Report 2.2
    * Engine diagram
    * Implemented code for the game engine
    * Print different renderings of state by calling the game engine 

<!-- CONTACT -->
## Contact 

* [**Amiel Quentin**](https://www.linkedin.com/in/quentin-amiel-a29138162/)
* [**Thierry Hugo**](https://www.linkedin.com/in/hugo-thierry-454245170/)
* [**Teng Tingyue**]


