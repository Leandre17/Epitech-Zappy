<h1 align="center"> ⚙️ GUI Protocol ⚙️ </h1>

<div style="display: flex;">
  <div>
    <table>
      <tr>
        <th align="left">Symbol</th>
        <th align="left">Description</th>
      </tr>
      <tr>
        <td>X</td>
        <td>width or horizontal position</td>
      </tr>
      <tr>
        <td>Y</td>
        <td>height or vertical position</td>
      </tr>
      <tr>
        <td>q0</td>
        <td>quantity of resource 0 (food)</td>
      </tr>
      <tr>
        <td>q1</td>
        <td>quantity of resource 1 (linemate)</td>
      </tr>
      <tr>
        <td>q2</td>
        <td>quantity of resource 2 (deraumere)</td>
      </tr>
      <tr>
        <td>q3</td>
        <td>quantity of resource 3 (sibur)</td>
      </tr>
      <tr>
        <td>q4</td>
        <td>quantity of resource 4 (mendiane)</td>
      </tr>
      <tr>
        <td>q5</td>
        <td>quantity of resource 5 (phiras)</td>
      </tr>
      <tr>
        <td>q6</td>
        <td>quantity of resource 6 (thystame)</td>
      </tr>
    </table>
  </div>
  <div style="width: 16px;"></div>
  <div>
    <table>
      <tr>
        <th align="left">Symbol</th>
        <th align="left">Description</th>
      </tr>
      <tr>
        <td>n</td>
        <td>player number</td>
      </tr>
      <tr>
        <td>O</td>
        <td>orientation: 1(N), 2(E), 3(S), 4(W)</td>
      </tr>
      <tr>
        <td>L</td>
        <td>player or incantation level</td>
      </tr>
      <tr>
        <td>e</td>
        <td>egg number</td>
      </tr>
      <tr>
        <td>T</td>
        <td>time unit</td>
      </tr>
      <tr>
        <td>N</td>
        <td>name of the team</td>
      </tr>
      <tr>
        <td>R</td>
        <td>incantation result</td>
      </tr>
      <tr>
        <td>M</td>
        <td>message</td>
      </tr>
      <tr>
        <td>i</td>
        <td>resource number</td>
      </tr>
    </table>
  </div>
</div>

| Server | Client | Description |
|:-------|:-------|:------------|
| msz X Y\n | msz\n | map size |
| bct X Y q0 q1 q2 q3 q4 q5 q6\n | bct X Y\n | content of a tile |
| bct X Y q0 q1 q2 q3 q4 q5 q6\n * nbr_tiles | mct\n | content of the map (all the tiles) |
| tna N\n * nbr_teams | tna\n | name of all the teams |
| pnw #n X Y O L N\n | | connection of a new player |
| ppo n X Y O\n | ppo #n\n | player’s position |
| plv n L\n | plv #n\n | player’s level |
| pin n X Y q0 q1 q2 q3 q4 q5 q6\n | pin #n\n | player’s inventory |
| pex n\n | | expulsion |
| pbc n M\n | | broadcast |
| pic X Y L n n . . . \n | | start of an incantation (by the first player) |
| pie X Y R\n | | end of an incantation |
| pfk n\n | | egg laying by the player |
| pdr n i\n | | resource dropping |
| pgt n i\n | | resource collecting |
| pdi n\n | | death of a player |
| enw e n X Y\n | | an egg was laid by a player |
| ebo e\n | | player connection for an egg |
| edi e\n | | death of an egg |
| sgt T\n | sgt\n | time unit request |
| sst T\n | sst T\n | time unit modification |
| seg N\n | | end of game |
| smg M\n | | message from the server |
| suc\n | | unknown command |
| sbp\n | | command parameter |
