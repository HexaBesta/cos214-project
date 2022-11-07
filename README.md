# *The Art of War* by Segmentation Fault
![Arma 3](https://www.pcgamesn.com/wp-content/sites/pcgamesn/2021/09/the-best-war-games-on-pc-2021.jpg)

Run a simulation or create your own war. Let it run by itself or be the commander of your forces.

# Directory Structure
```
.                     # Root Directory
├── System          # Source code folder
├── Docs            # Documentation files
├── Data            # Map textfile templates
├── VPP             # Visual Paradigm files
├── Report          # Project Reports
└── README.md
```

# Installation
## Linux
1. You will need to install [SFML](https://www.sfml-dev.org/tutorials/2.5/start-linux.php) to run the GUI component. You can run `sudo apt-get install libsfml-dev` in your terminal to install it.
2. Once SFML is installed, download our archive and unzip it.
3. Open the folder in a terminal, and cd into the Code folder, `cd Code`.
4. To run the project, just run the make command in the terminal, `make` - note that compilation may take some time.

## Windows (WSL)
This only applies if you are running this project in WSL.
1. You will need to install VcXsev, you can find a tutorial guide [here](https://medium.com/javarevisited/using-wsl-2-with-x-server-linux-on-windows-a372263533c3).
2. Download the archive and unzip it.
3. Open the project inside of your WSL/Linux terminal in Windows.
4. cd into the Code folder, `cd Code`.
5. To run the project, just run the make command in the terminal, `make`, and the GUI will open inside of a XLaunch window.

We do recommend running this project inside of Native Linux, wether it being a Linux Virtual Machine or an actual instance of Linux running. There is a lot less setup and is easier to run.

# Documentation
- You can read our project documentation [here](https://docs.google.com/document/d/1wIGAnmKmzZtf5SyiAyfpMH3J3QU_R3UXf-i8mV9dXS0/).
- You can also view our project board [here](https://github.com/users/sloththedev/projects/6).

# Unit Tests
We have created unit tests to test our various classes and that they create the correct values upon return etc.

## Running the Unit Tests
1. Please ensure you have Google Tests installed on your machine, `sudo apt-get install libgtest-dev`, as well as CMake, `sudo apt-get install cmake`.
2. Go into the Code/UnitTesting file, `cd Code/UnitTesting`
3. You can go into either of the various test folders we have set up, namely:
 - builer_test, `cd builder_test`.
 - unit_test, `cd unit_test`.
 - platoon_test, `cd platoon_test`.
 - country_test, `cd country_test`.
 - branches_test, `cd branches_test`.
4. Once you are in the correct folder, simply run `make` and then run `./runTest`
5. Watch the tests run!
