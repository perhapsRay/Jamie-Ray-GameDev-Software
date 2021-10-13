# Rogue game project remake.


I started with the Rogue Game C++ Skeleton File that was available on moodle for all students.
The first feature I was required to implement was wall collision so that the player would not be able to leave the bounds of the map. I originally used switch cases which would store the characters next move and current position. It would then check to make sure that the tile the player was moving to was a valid tile, and if it was it would update the players current position to the new position, otherwise it would keep the current position so that the player would not move.

I have since updated the function so that instead it will receive the potential player position from the handleInput() function, the switch case will then check if it is a valid tile and if it is it will return true, allowing the player posistion to be updated.

For the inventory I currently have a vector which will store strings. I have 2 items which can be store named, "Health potion." and "Sword.". Using the switch case I can determine if the tile the player step on is an item tile. If it is an item tile a function called itemCheck() will be called which will choose a random number between 0 and 1 to decide which item is picked up, 0 being the health potion and 1 being the sword. The item is then added to the vector. Since my items have IDs (0=potion, 1=sword), I have a seperate vector which will store the item ID at the same time. Later, when I am dropping the items I can use this ID to determine which character to give the item.

The way I decided my item pick-up would work is to just walk on-top of the item and it would the be added to the inventory. Because of this I ran into the issue that if I were to drop the item on the player position, it would instantly be re-added to the player inventory. I decided instead that when the player is dropping items they will be instead placed beside the player on the right side. If the tile is unavailable it would be place on the left side instead.

My items currently work as such: When the program is started a number of items will be placed in the room. These items are unknown and are represented by the "?" symbol. When the player walks onto the "?" either the health potion or sword is added. Now that the player knows what the item is, when the item is dropped it is now represented by a new symbol. I have choosen "+" for the health potion and "/" for the sword.

The inventory interface is very simple. When the player press the "I" key the screen will be cleared and the inventory displayed. Items will be numbered. To drop an item the player must press the space bar and then the number representing the item they want to drop. If the player wishes to exit the inventory they simply need to press the "I" key again.

Currently multiple items can not be place on the same tile.
However, if you try to put an item on the same tile as a current item, it will find a different available space to place the item.

Most features are in a working state however there are still some small issues that are being worked on.
