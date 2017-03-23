/* Joshua Van Deren
 * Tower Breaks, Revisited!
 * 03.22.2017
 *
 * Description: -- Finds the player who will win a game of "Tower Breaks, Revisited!"
 *              -- Utilizes strategy from game of Nim to solve this problem (https://en.wikipedia.org/wiki/Nim)
 *
 * Recommended Video: https://youtu.be/ORaGSyewF9Q
 *
 * NOTE: Using "unsigned short" was too small for larger numbers used for "height"
 */

#include <iostream>

using namespace std;

unsigned short number_of_prime_factors(unsigned int number);

int main(void)
{
    unsigned int tower_height;
    unsigned short num_of_games, num_of_towers, current_game, current_tower, total_factors;
    unsigned char nim_value;        // Number of factors is not expected to surpass size of char (1 byte)

    cin >> num_of_games;

    for (current_game = 0; current_game < num_of_games; current_game++)
    {
        cin >> num_of_towers;
        nim_value = 0x00;           // Resets bits to all 0's

        for (current_tower = 0; current_tower < num_of_towers; current_tower++)
        {
            cin >> tower_height;
            total_factors = number_of_prime_factors(tower_height);
            nim_value ^= total_factors;
        }

        if (nim_value)              // If any bit is set, then it is possible to
            cout << 1 << endl;      // change a number to make all bits 0
        else
            cout << 2 << endl;
    }

    return 0;
}

unsigned short number_of_prime_factors(unsigned int number)
/*** Function to find the total number of prime factors used to make "number" ****************************************/
{
    unsigned int possible_factor;
    unsigned short count = 0;

    for (possible_factor = 2; possible_factor <= number; possible_factor++)
      while (number % possible_factor == 0)
      {
        count++;
        number /= possible_factor;
      }

    return count;
}