<h1 align="center"> ⚙️ Technical documentation ⚙️ </h1>

<img src="https://d35fo82fjcw0y8.cloudfront.net/2020/02/05081844/technical-documentation-post-header1.jpg" alt="Technical documentation" width="100%">

## ℹ️ Overview

This documentation is made to help developers implementing their own AIs or GUIs for the Zappy project. It contains all the information needed to understand how the server works and how to communicate with it.

## 📚 Table of Contents

- [ℹ️ Overview](#ℹ️-overview)
- [📚 Table of Contents](#-table-of-contents)
  - [🖼️ Implementation of a GUI](#️-implementation-of-a-gui)
    - [Connection to the server](#connection-to-the-server)
    - [Commands](#commands)
  - [🤖 Implementation of an AI](#-implementation-of-an-ai)
    - [Connection to the server](#connection-to-the-server-1)
    - [Commands](#commands-1)

<br>
<br>

### 🖼️ Implementation of a GUI

The GUI is a graphical interface that allows you to visualize the game in real time. In the Zappy project, there is a GUI protocol that allows the GUI to communicate with the server and to receive all the information needed to display the game.

<br>

#### Connection to the server
Your GUI must be able to connect to the server using the TCP protocol. To be recognized as a GUI, you must send the following message to the server:
```
GRAPHIC
```
<br>
If the server accepts your connection, it will send you the following message:
```
msz X Y
sgt T
mct
tna
```
- **X** and **Y** are the width and height of the map respectively.
- **T** is the frequency of the server.
- **mct** is the content of the map (see [Map content](#map-content)).
- **tna** is the name of all the teams (see [Team names](#team-names)).

<br>

#### Commands
The GUI protocol allows you to send commands to the server. These commands are used to get information about the game. The server will send you the answer to your command in the form of a message.
> Sometimes, the server will send you automatic messages without you having to send a command. These messages are used to update the GUI in real time.

The list of **available commands**, can be found [here](./gui_protocol/).

<br>

```c++
class Commands {
  RecupereInfo(string) 
    HandleLine(string) 
      handleMSZ(), handleSGT() 
      handleTNA(), handleBCT() 
      handlePBC(), handlePPO()
  InitalizeDisplay() 
  Display() 
}
struct Display_t { 
  Class tilesMap tiles; 
  Resource res; 
  RenderWindow window; 
  vector2u windiw_size; 
  Class Rockpopup pop; 
  Class Message broadcast; 
  sf::Text team_text; 
  sf::Front team_front; 
}
``` 

La classe commande sert à interpréter les commandes envoyées par le serveur grâce aux fonctions : “RecupereInfos()” “HandleLine(string)” “handleMSZ(string)” “handleSGT(string)” “andleTNA(string)” “handleBCT(string)” “handlePPO(string)” ” handlePBC()”. 

La fonction “InitalizeDisplay()” initialise la structure “Display_t” qui contient tous les éléments principaux de la window (tiles, res, pop, broadcast, ...). 

 

```c++ 

class Ressources {
	generateRocks()
		generateFood(), generateLimate(), generateMendiane(), generateDeraumere() 
		generatePhiras(), genrateSibur(), generateThystame() 
	private:
		sf::Texture foodTexture, limateTexture, MendianeTexture, 
		DeraumereTexture, PhirasTexture, SiburTexture, ThystameTexture 
}
```

Elle contient tous les cailloux et la nourriture. Elle permet de les générer et de les stocker. 

```c++ 
namespace ZappyGUI {
  class TileMap : public sf::Drawable, public sf::Transformable { 
    public: 
      bool load(const std::string& tileset, sf::Vector2u tileSize, unsigned int width, unsigned int height);
    private:
      virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const; 
      sf::VertexArray m_vertices;
      sf::Texture m_tileset;
  };
}
``` 

Elle permet de générer les tuiles de la map ainsi que de les afficher. 

```c++ 

namespace ZappyGUI {
  class IPopup {
    public:
      virtual ~IPopup() = default;
      virtual void update(tile_t tile) = 0;
      virtual void update(void) = 0;
      sf::Texture PopUpTexture;
      sf::Sprite PopUpSprite;
      std::vector<sf::Text> PopUpTexts;
      sf::Font PopUpFont; 
      bool isVisible; 
  };
  class RockPopup : public IPopup { 
    public:
      RockPopup();
      ~RockPopup() = default;
      void update(tile_t tile);
      void update(void); 
  };
}
```

Elle permet d’afficher les informations données (Rocks et Foods). Les fonctions permettent de mettre à jour les informations affichées. 

```c++

namespace ZappyGUI {
  typedef struct Broadcast_s {
    std::string cmds;
    int playerID; 
  } Broadcast_t;

class Message {
  public:
    Message();
    Message(Message &&) = default;
    Message(const Message &) = default;
    Message &operator=(Message &&) = default;
    Message &operator=(const Message &) = default;
    ~Message() = default;
    void AddMessage(std::string msg);
    void ResetMessage();
    void AddBroadcast(Broadcast_t broadcast);
    sf::Text &GetText();
  private:
    std::string FormatMessage(std::string msg);
    void FormatMessageEnd(); 
    int CountLine();
    std::string message;
    sf::Text BrText;
    sf::Font BrFont;
  };
}
```

La classe message permet d’afficher un message provenant d’un joueur. De plus, elle permet d’afficher des messages de debug.  


La classe menu et SettingMenu permettent d’afficher un menu ainsi que l’interactivité avec celle-ci. 

<br>
<br>

### 🤖 Implementation of an AI
The AI is a program that controls player. The goal of the AI is to make the player evolve in the game by making him perform actions such as moving, collecting resources, etc.

<br>

#### Connection to the server
Your AI must be able to connect to the server using the TCP protocol. To be recognized as an AI, you must send the following message to the server:
```
teamX
```
- **teamX** is the name of your team.


<br>

#### Commands
The AI protocol allows you to send commands to the server. These commands are used to make the player perform actions. The server will send you the answer to your command in the form of a message.
> Sometimes, your AI will receive messages that have been sent by other players. See [Broadcast](https://github.com/X-VINCENT/Zappy/documentation/ai_commands/Broadcast.md) for more information.

The list of **available commands**, can be found [here](./ai_commands/).