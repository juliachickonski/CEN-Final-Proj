# Minigamers - CEN 3031 Project 

_Beta v.2.0_

A program that features different type of classic mini-games. Games featured in this version:
* Breakout
* Hangman

## Description

This project compiles two popular minigames: Breakout and Hangman into a short series for a quick & fun play session. We've used C++ & the SFML visual library to achieve this. By using the **agile development cycle**, the team has devised a system to use good programing practices by using comments effectivly and efficiently within the C++ code of this project.


## Getting Started 

* Import the C++ Code into an IDE with a C++ Complier (we used CLion).
* Once files are imported, run the code. A console should pop-up featuring a menu. 
*In the menu, using the arrow keys, navigate to what option you want.
  * ** Hangman** - a game in which one player tries to guess the letters of a word, and failed attempts are recorded.
  * ** Breakout** - a game that contains a layer of bricks represented by lines the top and the goal is to destroy them all by repeatedly bouncing a ball off     a paddle into them.

### Dependencies

* C++ Compiler
* [SFML](sfml-dev.org) 2.5.1

### Installing

Windows:  
- Install the files in your preferred IDE, along with SFML if not already installed to handle local dependencies
- Alter the CMAKE.txt file to point to your directory & project name
- Run the minigame  

Mac:
- Install the files into your IDE, along with SFML libraries
- ***If m1 mac** -* Alter the CMAKE to change x64 to x86 compile support
- Run the minigame

## Authors

Tyler MacPhee
[@tjmacphee](https://github.com/tjmacphee)

Christina Aragon
[@csaragon1941](https://github.com/csaragon1941)

Julia Chickonski
[@juliachickonski](https://github.com/juliachickonski)


## Version History

**v.1.0 changes:**
- _Pre-release software, minimal working code_
- Added basic filestructure
- Created Menu system class
- Linked SFML libraries
- Got github synced across team-members environments

**v.1.1 changes:**
- Got menu system to be functioning (can use arrow keys to navigate & enter key to select)
- 'Play' button now links to the hangman game
- Menu font now works

**v.2.0 changes:**
- Updated menu to include Breakout & Hangman options
- Added breakout game
- Hangman now has difficulty options

## License

MIT License

Copyright (c) [2022] [Tyler MacPhee, Julia Chickonski, Christina Aragon]

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.

