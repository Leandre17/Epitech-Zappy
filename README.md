<h1 align="center"> 🤖 Zappy 🤖 </h1>

<img src="https://github.com/X-VINCENT/Zappy/blob/main/documentation/assets/zappy_home.png?raw=true" alt="Zappy" width="100%">

## 📖 About

Zappy is a tribute to Zaphod Beeblebrox, a network game inspired by the world of Trantor. The goal of the game is to manage a world and its inhabitants, where teams confront each other on a tiles map containing resources. The winning team is the first one to have at least **6 players** reach the **maximum elevation**.

The game world, Trantor, is geographically made up of zero-relief planes without craters, valleys, or mountains. It is represented as a world map, and if a player exits from one side of the board, they will reappear on the opposite side.

The environment is rich in resources, including both minerals and food. The resources include **linemate**, **deraumere**, **sibur**, **mendiane**, **phiras**, and **thystame**. The server spawns resources at the start and every 20 units of time, following specific rules for their distribution.

Trantor's inhabitants focus on two activities: **feeding themselves** and **collecting stones**. These activities determine their elevation in the Trantorian hierarchy.

The inhabitants of Trantor are **bodiless**, **blurry**, and take up the entire tile they are in. They are pacifists and interact peacefully with their fellow creatures. They can see within their visual capacities but cannot distinguish their direction when they encounter each other.

The goal of each player is to rise up in the Trantorian hierarchy. The **elevation ritual** requires gathering a certain number of stones and players with the same level on the same tile. Once initiated, the elevation increases the player's level. The prerequisites and levels are specified in the project description.

Players have a limited **field of vision**. With each elevation, their vision range increases. The client can use the "**look**" command to receive information about the objects and players on the surrounding tiles.

**Sound** can be transmitted in the game, allowing players to communicate without revealing their identities. The direction of sound is indicated by the tile number affected by the sound before reaching the player's tile.


<br>

## 📚 Table of Contents

- [📖 About](#-about)
- [📚 Table of Contents](#-table-of-contents)
- [📦 Installation](#-installation)
- [🚀 Usage](#-usage)
  - [⚙️ Launch Server](#️-launch-server)
  - [🖼️ Launch GUI](#️-launch-gui)
  - [🤖 Launch AI](#-launch-ai)
- [📚 Documentation](#-documentation)
- [😎 Contributors 😎](#-contributors-)
  - [⚙️ Server Team](#️-server-team)
  - [🖼️ GUI Team](#️-gui-team)
  - [🤖 AI Team](#-ai-team)

<br>

## 📦 Installation

```bash
git clone git@github.com:X-VINCENT/Zappy.git
cd Zappy
make
```

<br>

## 🚀 Usage

### ⚙️ Launch Server
```bash
./zappy_server -p port -x width -y height -n name1 name2 ... -c clientsNb -f freq
```
- **port** is the port number
- **width** is the width of the world
- **height** is the height of the world
- **nameX** is the name of the team X
- **clientsNb** is the number of authorized clients per team
- **freq** is the reciprocal of time unit for execution of actions

> If you need additional information about the server, you can use the `-h` or `--help` flag.

### 🖼️ Launch GUI
```bash
./zappy_gui -p port -h machine
```
- **port** is the port number ofthe server
- **machine** is the name of the machine; localhost by default

### 🤖 Launch AI
```bash
./zappy_ai -p PORT -n NAME -h machine
```
- **port** is the port number of the server
- **name** is the name of the team the AI will join
- **machine** is the name of the machine; localhost by default

<br>

## 📚 Documentation

The full and technical documentation is available [here](https://github.com/X-VINCENT/Zappy/tree/main/documentation).

<br>
<div align="center">

## 😎 Contributors 😎

</div>

### ⚙️ Server Team
<div align="center">
    <table>
        <td align="center" style="min-width: 150px; border: 2px solid; padding: 20px">
            <a href="https://github.com/X-VINCENT">
                <img src="https://media.licdn.com/dms/image/C4D03AQERYR3cOO8fQg/profile-displayphoto-shrink_800_800/0/1646215295414?e=2147483647&v=beta&t=qk088hcnqNHZIxGEwcrA7DJomG90MouNBwzP3sGlmbg" width="150px;" alt="Xavier VINCENT profile picture"/>
                <br />
                <b>Xavier VINCENT</b>
            </a>
            <br />
            <div>
                <a href="https://github.com/X-VINCENT/Zappy/commits?author=X-VINCENT" title="Code">👨‍💻</a>
                <a href="mailto:xavier.vincent@epitech.eu">✉️</a>
            </div>
        </td>
    </table>
</div>

<br>

### 🖼️ GUI Team
<div align="center">
    <table>
        <td align="center" style="min-width: 150px; border: 2px solid; padding: 20px">
            <a href="https://github.com/4lrick">
                <img src="https://media.licdn.com/dms/image/D4E03AQEZcitdjJt7OA/profile-displayphoto-shrink_800_800/0/1646729291457?e=2147483647&v=beta&t=7V7Tg25ad2JzK1bwNn63XWXTCSb8BLV57VTzBkJiifU" width="150px;" alt="Alrick RUBIO profile picture"/>
                <br />
                <b>Alrick RUBIO</b>
            </a>
            <br />
            <div>
                <a href="https://github.com/X-VINCENT/Zappy/commits?author=4lrick" title="Code">👨‍💻</a>
                <a href="mailto:alrick.rubio@epitech.eu">✉️</a>
            </div>
        </td>
        <td align="center" style="min-width: 150px; border: 2px solid; padding: 20px">
            <a href="https://github.com/Johannabureau">
                <img src="https://media.licdn.com/dms/image/C4D03AQGIKHXmhFy2zw/profile-displayphoto-shrink_800_800/0/1635671946147?e=2147483647&v=beta&t=ZWSxIlagFfKK2kMmgEDLzXizjxE5ur7Veiahbm0Z9DM" width="150px;" alt="Johanna BUREAU profile picture"/>
                <br />
                <b>Johanna BUREAU</b>
            </a>
            <br />
            <div>
                <a href="https://github.com/X-VINCENT/Zappy/commits?author=Johannabureau" title="Code">👨‍💻</a>
                <a href="mailto:johanna.bureau@epitech.eu">✉️</a>
            </div>
        </td>
        <td align="center" style="min-width: 150px; border: 2px solid; padding: 20px">
            <a href="https://github.com/JulesTrolle">
                <img src="https://media.licdn.com/dms/image/C4E03AQGgXBlLciLSDQ/profile-displayphoto-shrink_800_800/0/1646729754582?e=2147483647&v=beta&t=TfkSRhlx-ryFkuFU76HZr7Uu6-r1ab077ntv4qP2vDM" width="150px;" alt="Jules TROLLE profile picture"/>
                <br />
                <b>Jules TROLLÉ</b>
            </a>
            <br />
            <div>
                <a href="https://github.com/X-VINCENT/Zappy/commits?author=JulesTrolle" title="Code">👨‍💻</a>
                <a href="mailto:jules.trolle@epitech.eu">✉️</a>
            </div>
        </td>
        <td align="center" style="min-width: 150px; border: 2px solid; padding: 20px">
            <a href="https://github.com/Leandre17">
                <img src="https://media.licdn.com/dms/image/D4E03AQGOJK5u8TI7Jw/profile-displayphoto-shrink_400_400/0/1675071278589?e=1692230400&v=beta&t=KcKvDf85ui89yx2S9b_XQ_FeM8Xn0EckaBaJzKKcUKY" width="150px;" alt="Léandre GODET profile picture"/>
                <br />
                <b>Léandre GODET</b>
            </a>
            <br />
            <div>
                <a href="https://github.com/X-VINCENT/Zappy/commits?author=Leandre17" title="Code">👨‍💻</a>
                <a href="mailto:leandre.godet@epitech.eu">✉️</a>
            </div>
        </td>
    </table>
</div>

<br>

### 🤖 AI Team
<div align="center">
    <table>
        <td align="center" style="min-width: 150px; border: 2px solid; padding: 20px">
            <a href="https://github.com/FiirePirate">
                <img src="https://media.licdn.com/dms/image/C4E03AQEf-Ck_EW--MA/profile-displayphoto-shrink_800_800/0/1646328215917?e=2147483647&v=beta&t=bfrin-oCEMISnMDfVyZvNh3XL0M5Y3mhCC2lCwB3kYI" width="150px;" alt="Romain DELARUELLE profile picture"/>
                <br />
                <b>Romain DELARUELLE</b>
            </a>
            <br />
            <div>
                <a href="https://github.com/X-VINCENT/Zappy/commits?author=FiirePirate" title="Code">👨‍💻</a>
                <a href="mailto:romain.delaruelle@epitech.eu">✉️</a>
            </div>
        </td>
        <td align="center" style="min-width: 150px; border: 2px solid; padding: 20px">
            <a href="https://github.com/skyli3spro">
                <img src="https://media.licdn.com/dms/image/D4D03AQE7eDi0JtOjoA/profile-displayphoto-shrink_800_800/0/1683106834190?e=2147483647&v=beta&t=a4S6Mn85HwenUMamFLguoinIH51THQ_y5MpSOZzF5fA" width="150px;" alt="Quentin CHARPENTIER profile picture"/>
                <br />
                <b>Quentin CHARPENTIER</b>
            </a>
            <br />
            <div>
                <a href="https://github.com/X-VINCENT/Zappy/commits?author=skyli3spro" title="Code">👨‍💻</a>
                <a href="mailto:quentin.charpentier@epitech.eu">✉️</a>
            </div>
        </td>
        <td align="center" style="min-width: 150px; border: 2px solid; padding: 20px">
            <a href="https://github.com/X-VINCENT">
                <img src="https://media.licdn.com/dms/image/C4D03AQERYR3cOO8fQg/profile-displayphoto-shrink_800_800/0/1646215295414?e=2147483647&v=beta&t=qk088hcnqNHZIxGEwcrA7DJomG90MouNBwzP3sGlmbg" width="150px;" alt="Xavier VINCENT profile picture"/>
                <br />
                <b>Xavier VINCENT</b>
            </a>
            <br />
            <div>
                <a href="https://github.com/X-VINCENT/Zappy/commits?author=X-VINCENT" title="Code">👨‍💻</a>
                <a href="mailto:xavier.vincent@epitech.eu">✉️</a>
            </div>
        </td>
    </table>
</div>

</div>

<br>
<br>
<div align="center" href="">

![ForTheBadge built-by-developers](http://ForTheBadge.com/images/badges/built-by-developers.svg)
![ForTheBadge built-with-love](http://ForTheBadge.com/images/badges/built-with-love.svg)

![ForTheBadge made-with-c](https://forthebadge.com/images/badges/made-with-c.svg)
![ForTheBadge made-with-cpp](https://forthebadge.com/images/badges/made-with-c-plus-plus.svg)
![ForTheBadge made-with-python](https://forthebadge.com/images/badges/made-with-python.svg)

</div>