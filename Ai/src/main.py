from Ai.src.player import Player
from Ai.src.algo import algorithm
from sys import argv
from argparse import ArgumentParser
from random import randint

def parse_args() -> list[int, str, str]:
    parser = ArgumentParser(add_help=False)
    parser.add_argument(
        "-p",
        dest="port",
        type=int,
        required=True,
        help="is the port number"
    )
    parser.add_argument(
        "-n",
        dest="team_name",
        type=str,
        required=True,
        help="is the name of the team"
    )
    parser.add_argument(
        "-h",
        dest="machine",
        type=str,
        required=False,
        help="is the name of the machine; localhost by default"
    )

    try:
        for argument in argv[1:]:
            if argument == '-help':
                parser.print_help()
                exit(0)
        args = parser.parse_args()
    except SystemExit:
        exit(84)
    if len(argv) == 5:
        return [args.port, args.team_name, "localhost"]
    return [args.port, args.team_name, args.machine]

def get_map_size(ai: Player, team_name: str) -> list[int, int]:
    ai.send(team_name)
    res = ai.receive()
    if res == "ko\n":
        exit(84)
    size = res.split("\n")[1]
    print("Map size: " + size)
    size = size.split(" ")
    return [int(size[0]), int(size[1])]

def main():
    port, name, host = parse_args()
    ai = Player(port, name, host)
    ai.connect()
    print(ai.receive())
    ai.map_size = get_map_size(ai, name)
    while (not ai.is_dead):
        algorithm(ai)
