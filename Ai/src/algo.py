from Ai.src.player import Player
from Ai.src.constants import INCANTATION_REQUIREMENTS, PLAYER_REQUIREMENT

def algorithm(player):
    player.needed_resources = get_needed_resources(player)
    #print(f"Needed resources: {player.needed_resources}")
    player.inventory = player.get_inventory()
    #print(f"Inventory: {player.inventory}")
    print(f"Level: {player.level}")
    while not has_enough_resources(player):
        #print(f"Inventory: {player.inventory}")
        take_needed_resources(player)
    test_incantation(player)

def get_needed_resources(player) -> dict[str, int]:
    needed_resources: dict[str, int] = {}
    for resource in INCANTATION_REQUIREMENTS:
        needed_resources[resource] = INCANTATION_REQUIREMENTS[resource][player.level - 1]
    return needed_resources

def has_enough_resources(player) -> bool:
    for resource in player.needed_resources:
        if not player.inventory or player.inventory is None:
            return False
        if resource not in player.inventory:
            return False
        if player.inventory[resource] < player.needed_resources[resource]:
            return False
    return True

def take_needed_resources(player) -> None:
    if not player.inventory or player.inventory is None:
        return
    if player.inventory["food"] < 50:
        player.take("food")
    for resource in player.needed_resources:
        if player.inventory[resource] < player.needed_resources[resource]:
            if not player.take(resource):
                player.go_to_tile_with_most_objects()
                player.take(resource)

def drop_resources(player) -> None:
    for resource in player.inventory:
        if resource != "food":
            for _ in range(player.inventory[resource]):
                player.set(resource)

def test_incantation(player) -> None:
    for _ in range(get_max_moves(player)):
        if not has_enough_players(player):
            call_players(player)
    if has_enough_players(player):
        drop_resources(player)
        player.incantation()
    else:
        player.fork()

def get_max_moves(player) -> int:
    max_moves: int = 0
    if player.map_size[0] > player.map_size[1]:
        max_moves = player.map_size[0]
    else:
        max_moves = player.map_size[1]
    return max_moves + 1

def has_enough_players(player) -> bool:
    tiles = player.look()
    if tiles == None:
        return False
    players = 0
    for tile in tiles:
        items = tile.split(' ')
        for item in items:
            if item == "player":
                players += 1
    return players >= PLAYER_REQUIREMENT[player.level - 1]

def call_players(player) -> None:
    player.broadcast(f"elevation {player.level}")
