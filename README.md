# Tartis | My Beginner C++ Tetris Practice Project
[![C++](https://img.shields.io/badge/C++-Standard-00599C?logo=c%2B%2B&logoColor=white)](https://isocpp.org/)
[![GitHub Repo](https://img.shields.io/badge/GitHub-DecentCoders/Tartis-181717?logo=github)](https://github.com/DecentCoders/Tartis)
[![Last Commit](https://img.shields.io/github/last-commit/DecentCoders/Tartis)](https://github.com/DecentCoders/Tartis/commits/main)
[![Top Language](https://img.shields.io/github/languages/top/DecentCoders/Tartis)](https://github.com/DecentCoders/Tartis)
[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)

Hi! This is my first hands-on C++ game project, a simple console-based Tetris clone (named Tartis here) built purely for learning and practicing C++ basics. I’m not a professional C++ developer at all — I built this while learning the language, and leaned heavily on online resources (including **kimi.ai**) to work through tricky parts, fix bugs, and understand how to implement core game features. Althou it still contains a bug...!!

## 🎮 What This Game Does
This is a fully playable console-based Tetris game, with these core features I built with help from learning resources:
- Classic Tetris block movement, rotation, and line-clearing gameplay
- Colored game blocks and console UI for better readability
- A basic scoring system that tracks your progress as you play
- Increasing game speed as your score goes up, to ramp up difficulty
- Runs directly in your Windows console, no fancy setup required

## 📚 What I Learned Building This
Since I’m new to C++, this project was all about learning the fundamentals. I used online guides and kimi.ai to help me understand and implement:
- Core C++ syntax, variables, loops, and conditional logic
- How to build a working game loop for real-time user input and screen updates
- Console input/output handling for game controls
- How to add color to the Windows console for a better UI
- Basic game difficulty scaling (increasing speed with score)
- How to compile C++ code into a runnable .exe file

## 🛠️ Tech Stack
This project uses only standard C++ with no external frameworks or libraries — perfect for a beginner learning the basics:
- Pure standard C++ (compatible with common Windows C++ compilers)
- Windows console API for color and screen updates
- No external dependencies or installations needed to run the game

## 📁 Project Files Explained
Here’s a simple breakdown of what each file in the repo is for:
```
Tartis/
├── .vscode/                # VS Code editor config files from my setup
├── tartis.cpp              # The main C++ source code for the entire game
├── tartis.exe              # Pre-compiled executable file to run the game instantly
├── tempCodeRunnerFile.cpp  # Temporary test file from my first commit (learning setup)
├── tempCodeRunnerFile.exe  # Temporary compiled test file from my first commit
└── README.md               # This file, explaining the project
```

## 🚀 How to Run the Game
Since this is a simple console app, it’s super easy to run, even if you’re also new to C++:

### Option 1: Run the pre-built game (instant, no setup)
1. Download the `tartis.exe` file from this repo
2. Double-click the file to open it
3. The game will launch directly in your Windows console, and you can start playing!

### Option 2: Compile the code yourself (if you want to edit or test changes)
1. Make sure you have a C++ compiler installed (like MinGW for Windows, or Visual Studio)
2. Clone or download this repo to your computer
3. Open your terminal/command prompt in the project folder
4. Compile the code with this command:
   ```bash
   g++ tartis.cpp -o tartis.exe
   ```
5. Run the compiled .exe file, and the game will start!

## 🤝 Resources I Used to Build This
I couldn’t have put this together without help from beginner-friendly learning resources. A huge thank you to:
- **kimi.ai**: For walking me through tricky parts like the game loop, console color implementation, and fixing bugs in my code when I got stuck
- Free online C++ beginner tutorials: For teaching me the basics of C++ syntax and structure
- Simple Tetris game logic guides for new programmers: For helping me understand how core Tetris mechanics work

## 🔮 Future Plans (As I Learn More C++)
This is a work in progress as I keep learning! I want to add these things later when I’m more comfortable with C++:
- A proper start screen and game over screen
- A saved high score system that keeps track of your best games
- More polished UI and better controls
- Fix any small bugs I haven’t caught yet
- Maybe add sound effects if I can figure that out

## 🤗 Contributing
If you’re also a C++ beginner, or just want to help improve this little practice project, feel free to jump in! You can open an issue if you find a bug, or submit a pull request with small improvements. This is a learning space for all of us.

## 📄 License
This project is open source and available under the [MIT License](LICENSE) — feel free to use it for your own C++ learning!

## 🙏 Acknowledgements
Again, a huge thank you to all the online learning resources and kimi.ai for helping me build this project and learn C++ along the way. This wouldn’t have come together without that guidance!
