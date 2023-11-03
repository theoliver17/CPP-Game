#include <conio.h>
#include <iostream>
#include <cstdlib>

using namespace std;
int y = 1;
int x = 1;
char player = 'O';

void draw(char (*array)[3])
{
  // inconvéient: pas dynamique
  cout << "\033[2J\033[1;1H"; // clear screen
  cout << "Current player: " << player << endl;
  cout << " " << array[0][0] << " | " << array[0][1] << " | " << array[0][2] << endl;
  cout << "-----------" << endl;
  cout << " " << array[1][0] << " | " << array[1][1] << " | " << array[1][2] << endl;
  cout << "-----------" << endl;
  cout << " " << array[2][0] << " | " << array[2][1] << " | " << array[2][2] << endl;
}

void goToFirstEmptySpace(char (*array)[3])
{
  // Go to the first empty space except the one where the player is
  for (int i = 0; i < 3; i++)
  {
    for (int j = 0; j < 3; j++)
    {
      if (array[i][j] == ' ' && i != x && j != y)
      {
        array[i][j] = '.';
        x = i;
        y = j;
        return;
      }
    }
  }
}

void up(char (*array)[3])
{
  if (x > 0 && array[x - 1][y] == ' ')
  {
    array[x - 1][y] = '.';
    array[x][y] = ' ';
    x--;
  }
  else if (x > 0 && array[x - 1][y] == 'O' || array[x - 1][y] == 'X')
  {
    if (x > 1 && array[x - 2][y] == ' ')
    {
      array[x - 2][y] = '.';
      array[x][y] = ' ';
      x -= 2;
    }
    else
    {
      array[x][y] = ' ';
      goToFirstEmptySpace(array);
    }
  }
}

void down(char (*array)[3])
{
  if (x < 2 && array[x + 1][y] == ' ')
  {
    array[x + 1][y] = '.';
    array[x][y] = ' ';
    x += 1;
  }
  else if (x < 2 && array[x + 1][y] == 'O' || array[x + 1][y] == 'X')
  {
    if (x < 1 && array[x + 2][y] == ' ')
    {
      array[x + 2][y] = '.';
      array[x][y] = ' ';
      x += 2;
    }
    else
    {
      array[x][y] = ' ';
      goToFirstEmptySpace(array);
    }
  }
}

void left(char (*array)[3])
{
  if (y > 0 && array[x][y - 1] == ' ')
  {
    array[x][y - 1] = '.';
    array[x][y] = ' ';
    y -= 1;
  }
  else if (y > 0 && array[x][y - 1] == 'O' || array[x][y - 1] == 'X')
  {
    if (y > 1 && array[x][y - 2] == ' ')
    {
      array[x][y - 2] = '.';
      array[x][y] = ' ';
      y -= 2;
    }
    else
    {
      array[x][y] = ' ';
      goToFirstEmptySpace(array);
    }
  }
}

void right(char (*array)[3])
{
  if (y < 2 && array[x][y + 1] == ' ')
  {
    array[x][y + 1] = '.';
    array[x][y] = ' ';
    y += 1;
  }
  else if (y < 2 && array[x][y + 1] == 'O' || array[x][y + 1] == 'X')
  {
    if (y < 1 && array[x][y + 2] == ' ')
    {
      array[x][y + 2] = '.';
      array[x][y] = ' ';
      y += 2;
    }
    else
    {
      array[x][y] = ' ';
      goToFirstEmptySpace(array);
    }
  }
}

void checkWinCondition(char (*array)[3])
{
  // Check if there is a win condition
  if (array[0][0] == array[0][1] && array[0][1] == array[0][2] && array[0][0] != ' ')
  {
    cout << "Player " << array[0][0] << " wins!" << endl;
    exit(0);
  }
  else if (array[1][0] == array[1][1] && array[1][1] == array[1][2] && array[1][0] != ' ')
  {
    cout << "Player " << array[1][0] << " wins!" << endl;
    exit(0);
  }
  else if (array[2][0] == array[2][1] && array[2][1] == array[2][2] && array[2][0] != ' ')
  {
    cout << "Player " << array[2][0] << " wins!" << endl;
    exit(0);
  }
  else if (array[0][0] == array[1][0] && array[1][0] == array[2][0] && array[0][0] != ' ')
  {
    cout << "Player " << array[0][0] << " wins!" << endl;
    exit(0);
  }
  else if (array[0][1] == array[1][1] && array[1][1] == array[2][1] && array[0][1] != ' ')
  {
    cout << "Player " << array[0][1] << " wins!" << endl;
    exit(0);
  }
  else if (array[0][2] == array[1][2] && array[1][2] == array[2][2] && array[0][2] != ' ')
  {
    cout << "Player " << array[0][2] << " wins!" << endl;
    exit(0);
  }
  else if (array[0][0] == array[1][1] && array[1][1] == array[2][2] && array[0][0] != ' ')
  {
    cout << "Player " << array[0][0] << " wins!" << endl;
    exit(0);
  }
  else if (array[0][2] == array[1][1] && array[1][1] == array[2][0] && array[0][2] != ' ')
  {
    cout << "Player " << array[0][2] << " wins!" << endl;
    exit(0);
  }
}

void playIntputs(char (*array)[3])
{
  bool done = false;
  char input;
  while (!done)
  {
    input = _getch();
    switch (input)
    {
    case 'z':
      up(array);
      break;
    case 's':
      down(array);
      break;
    case 'q':
      left(array);
      break;
    case 'd':
      right(array);
      break;
    case 32:
      array[x][y] = player;
      done = true;
      break;

    default:
      cout << "Invalid command, " << input << endl;
      break;
    }
    draw(array);
    checkWinCondition(array);
  }
}

int main()
{
  bool end = false;
  char array[3][3] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};
  cout << "Welcome to the game of the century!" << endl;
  cout << "Player O starts." << endl;
  cout << "Press space to place your player." << endl;
  cout << "Use z, s, q, d to start the game and move the player." << endl;
  while (!end)
  {
    player = player == 'O' ? 'X' : 'O'; // Switch player
    cout << "Next turn: player " << player << "." << endl;
    goToFirstEmptySpace(array);
    playIntputs(array);
  }
}

// Samuel Lagarde 2023