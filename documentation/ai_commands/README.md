<h1 align="center"> ⚙️ List of AI Commands ⚙️ </h1>

| Command | Description | Time limit | Response |
|:-------:|:-----------:|:----------:|:--------:|
| `Forward` | Move up one tile | 7/f | `ok` |
| `Right` | Turn 90° right | 7/f | `ok` |
| `Left` | Turn 90° left | 7/f | `ok` |
| `Look` | Look around | 7/f | `[tile1, tile2, …]` |
| `Inventory` | Inventory | 1/f | `[linemate n, sibur n, …]` |
| `Broadcast “text”` | Broadcast text | 7/f | `ok` |
| `Connect_nbr` | Number of team unused slots | - | `value` |
| `Fork` | Fork a player | 42/f | `ok` |
| `Eject` | Eject players from this tile | 7/f | `ok` or `ko` |
| `Take “object”` | Take object | 7/f | `ok` or `ko` |
| `Set “object”` | Set object down | 7/f | `ok` or `ko` |
| `Incantation` | Start incantation | 300/f | `Elevation underway` or `Current level: k` or `ko` |

All commands are transmitted through a character string that ends with a new line.

In case of a bad/unknown command, the server answer “ko”.


To implement your AI, you will need to send differents commands to the server.
All the commands are listed with the message to send.

For the `Forward` command :
    To make your AI move up one tile front of your AI.
    You need to send to the server `Forward\n`.

For the `Right` command :
    To make your AI turn 90° right.
    You need to send to the server `Right\n`.

For the `Left` command :
    To make your AI turn 90° left.
    You need to send to the server `Left\n`.

For the `Look` command :
    To make you AI look around.
    It's needed to see everything on tiles in front of view.
    You need to send to the server `Look\n`.

For the `Inventory` command :
    To see the inventory of your AI.
    You need to send to the server `Inventory\n`.

For the `Broadcast` command :
    To send message to every AI on the map.
    And every AI get a message with the position of the sender.
    You need to send to the server `Broadcast “text”\n`.

For the `Connect_nbr` command :
    To see the number of place in the team of the actual AI.
    You need to send to the server `Connect_nbr\n`.

For the `Fork` command :
    To produce an egg so a new AI can connect to the team.
    You need to send to the server `Fork\n`.

For the `Eject` command :
    To eject everyone of your tile in the oposite direction of your AI.
    You need to send to the server `Eject\n`.

For the `Take “object”` command :
    To take the object you want on the tile your AI are on.
    THe `“object”` is the food or one of the stone.
    You need to send to the server `Take “object”\n`.

For the `Set “object”` command :
    To drop an objet you have in your inventory on the floor.
    The `“object”` is the food or one of the stone.
    You need to send to the server `Set “object”\n`.

For the `Incantation` command :
    To level up you AI.
    You will need allies number depend on the level you want to get.
    You will need Stone number and types depend also on the level you want to get.
    Up to 8 different levels.
    You need to send to the server `Incantation\n`.

