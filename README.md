🕹️ SFML Paddle Game

A simple paddle game built using C++ and SFML, where a ball bounces around the screen and the player must prevent it from falling using a paddle. If the ball falls past the paddle, the game ends with a "Game Over" screen and can be restarted.


🚀 Features

Ball bounces around the window.

Paddle movement with arrow keys.

Collision detection between ball and paddle.

Game Over screen when ball misses the paddle.

Restart the game by pressing R.

🧱 Requirements

macOS with Apple Silicon (M1/M2)

SFML 2.6.x installed via Homebrew:

```
brew install sfml@2
brew link --overwrite --force sfml@2
```

CLion or any C++ IDE with CMake support

⚙️ Build Instructions
```
git clone https://github.com/your-username/SFMLGame.git
cd SFMLGame
```

Ensure your CMakeLists.txt includes SFML like this:

```
find_package(SFML 2.5 COMPONENTS graphics window system audio REQUIRED)
target_link_libraries(SFMLGame sfml-graphics sfml-window sfml-system sfml-audio)
```

Then build with CLion or use:
```
cmake -B build
cmake --build build
```

🎮 Controls

| Key         | Action               |
| ----------- | -------------------- |
| ← / →       | Move Paddle          |
| R           | Restart on Game Over |
| Esc / Close | Exit Game            |
| Any Key     | Start Game           |


📁 Project Structure
```
SFMLGame/
├── src/
│   ├── Ball.cpp
│   ├── Paddle.cpp
│   ├── Ball.h
│   └── Paddle.h
├── main.cpp
├── CMakeLists.txt
└── README.md
```
🛠️ TODO (Next Steps)

Add score tracking

Add bricks (Breakout style)

Add lives/pause/menu screens

Sound effects

🧑‍💻 Author

Tarun Hawdia – @HawdiaTarun
