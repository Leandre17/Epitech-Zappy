import socket
import os
from Ai.src.constants import INCANTATION_REQUIREMENTS

OK = "ok\n"
KO = "ko\n"

class Player:

    def __init__(self, port, player_team, ip="localhost") -> None:
        self.port = port
        self.team = player_team
        self.ip = ip
        self.sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        self.level = 1
        self.is_dead = False
        self.map_size = []
        self.inventory: dict[str, int] = {
            "food": 10,
            "linemate": 0,
            "deraumere": 0,
            "sibur": 0,
            "mendiane": 0,
            "phiras": 0,
            "thystame": 0
        }
        self.needed_resources = {}

    def connect(self):
        self.sock.connect((self.ip, self.port))

    def send(self, msg):
        msg += "\n"
        encoded = msg.encode()
        totalsent = 0
        while totalsent < len(encoded):
            try:
                sent = self.sock.send(encoded[totalsent:])
            except BrokenPipeError:
                return
            totalsent = totalsent + sent

    def receive(self):
        chunks = []
        bytes_recd = 1
        while bytes_recd > 0:
            chunk = self.sock.recv(1024)
            if chunk == 'b':
                raise RuntimeError("socket connection broken")
            chunks.append(chunk.decode())
            bytes_recd = len(chunk)
            if bytes_recd < 1024:
                break
        return ''.join(chunks)

    def isAttendedResponse(self, res: str, calling_function: str) -> str:
        if calling_function == "Forward":
            return res == OK or res == KO
        if calling_function == "Right":
            return res == OK or res == KO
        if calling_function == "Left":
            return res == OK or res == KO
        if calling_function == "Look":
            return res.startswith("[") and res.endswith("]\n")
        if calling_function == "Inventory":
            return res.startswith("[") and res.endswith("]\n")
        if calling_function == "Broadcast":
            return res == OK
        if calling_function == "Connect_nbr":
            return res.isdigit()
        if calling_function == "Fork":
            return res == OK
        if calling_function == "Eject":
            return res == OK or res == KO
        if calling_function == "Take":
            return res == OK or res == KO
        if calling_function == "Set":
            return res == OK or res == KO

    def myreceive(self, calling_function: str) -> str:
        response = self.receive()
        response = response.split('\n')[0] + '\n'
        while not self.isAttendedResponse(response, calling_function):
            if response == "dead\n":
                self.player_died()
            if response.startswith("message"):
                self.handle_message(response)
            if response.startswith("Elevation underway"):
                print("Elevation underway")
            if response.startswith("Current level"):
                print(response)
                self.level = int(response.split('\n')[0].split(' ')[2])
                print("Current level " + str(self.level))
            response = self.receive()
        return response

    def handle_message(self, message):
        #print(f"Message received: {message[:-1]} | Player level: {self.level}")
        source_tile_id = int(message.split(' ')[1][:-1])
        message = ' '.join(message.split(' ')[2:])
        level = int(message.split('\n')[0].split(' ')[-1])
        if source_tile_id == 0 or self.level != level:
            return
        print(f"Message from tile {source_tile_id}: {message}")
        if self.inventory["food"] < 50:
            self.take("food")
        self.move_to_calling_player(source_tile_id)

    def forward(self):
        self.send('Forward')
        answer = self.myreceive("Forward")
        return answer == OK

    def right(self):
        self.send("Right")
        answer = self.myreceive("Right")
        return answer == OK

    def left(self):
        self.send("Left")
        answer = self.myreceive("Left")
        return answer == OK

    def look(self):
        self.send("Look")
        answer = self.myreceive("Look")
        answer = self.parse_look(answer)
        if answer == None:
            return None
        answer = self.add_empty_look(answer)
        if type(answer) != list:
            return None
        return answer

    def parse_look(self, look: str) -> list[list[str]]:
        split = look.strip('][').split(', ')
        clean = False
        new_look = []
        for ligne in split:
            new_look.append(ligne)
        if new_look == ['']:
            return None
        if new_look[0][0] == ' ':
            new_look[0] = new_look[0][1:]
        try:
            if new_look[-1][-1] == "\n" and new_look[-1][-2] == ']' and new_look[-1][-3] == ' ':
                new_look[-1] = new_look[-1][:-3]
                clean = True
        except IndexError:
            pass
        if not clean and new_look[-1][-1] == "\n" and new_look[-1][-2] == ']':
            new_look[-1] = new_look[-1][:-2]
        return new_look

    def add_empty_look(self, look: list[list[str]]) -> list[list[str]]:
        line_added = False
        new_look = []
        for line in look:
            for case in line:
                if case == ',' and not line_added:
                    line = line.replace(',', '', 1)
                    new_look.append(line)
                    new_look.append('')
                    line_added = True
                elif case == ',' and line_added:
                    line = line.replace(',', '', 1)
                    new_look[line.index(line)] = line
                    new_look.append('')
            if not line_added:
                new_look.append(line)
            line_added = False
        return new_look

    def get_inventory(self):
        self.send("Inventory")
        answer = self.myreceive("Inventory")
        answer = self.parse_inventory(answer)
        if type(answer) != dict:
            return None
        return answer

    def parse_inventory(self, inventory: str) -> dict[str:int]:
        new_inventory = {
            "linemate": 0,
            "deraumere": 0,
            "sibur": 0,
            "mendiane": 0,
            "phiras": 0,
            "thystame": 0,
            "food": 0
        }
        split = inventory.strip('][').split(', ')
        if split == ['']:
            return None
        if split[0][0] == ' ':
            split[0] = split[0][1:]
        if split[0] == KO:
            return None
        for item in split:
            item = item.split(' ')
            try:
                new_inventory[item[0]] = int(item[1])
            except (ValueError, IndexError):
                return new_inventory
        return new_inventory

    def broadcast(self, text):
        self.send(f"Broadcast {text}")
        answer = self.myreceive("Broadcast")
        return answer

    def connect_nbr(self):
        self.send("Connect_nbr")
        answer = self.myreceive("Connect_nbr")
        answer = answer.strip('\n')
        if answer.isnumeric():
            return int(answer)
        return -1

    def fork(self):
        self.send("Fork")
        answer = self.myreceive("Fork")
        if answer == OK:
            pid = os.fork()
            if pid == 0:
                os.execvp("./zappy_ai", ["./zappy_ai", "-p", str(self.port), "-n", self.team, "-h", self.ip])
        return answer == OK

    def eject(self):
        self.send("Eject")
        answer = self.myreceive("Eject")
        return answer == OK

    def player_died(self):
        self.is_dead = True
        self.sock.close()
        exit(0)

    def take(self, objects):
        self.send(f"Take {objects}")
        answer = self.myreceive("Take")
        if answer == KO:
            return False
        self.inventory[objects] += 1
        return True

    def set(self, objects):
        self.send(f"Set {objects}")
        answer = self.myreceive("Set")
        if answer == KO:
            return False
        self.inventory[objects] -= 1
        return True

    def incantation(self):
        self.send("Incantation")

    def move_to_calling_player(self, source_tile_id):
        if source_tile_id == 0:
            return None
        elif source_tile_id == 1:
            self.forward()
        elif source_tile_id == 2:
            self.forward()
            self.left()
            self.forward()
        elif source_tile_id == 3:
            self.left()
            self.forward()
        elif source_tile_id == 4:
            self.left()
            self.forward()
            self.left()
            self.forward()
        elif source_tile_id == 5:
            self.right()
            self.right()
            self.forward()
        elif source_tile_id == 6:
            self.right()
            self.forward()
            self.right()
            self.forward()
        elif source_tile_id == 7:
            self.right()
            self.forward()
        elif source_tile_id == 8:
            self.forward()
            self.right()
            self.forward()
        else:
            return None

    def go_to_tile_with_most_objects(self) -> None:
        look = self.look()
        if look == None or []:
            return None
        look = look[:3]
        list_len = []
        list_object = []
        for tile in look:
            list_len.append(len(tile.split(" ")))
            list_object.append(tile.split(" "))
        if list_len == []:
            return None
        max_len = max(list_len)
        index_max = list_len.index(max_len)
        self.move_to_tile_with_more_object(index_max)

    def move_to_tile_with_more_object(self, index_tile):
        if index_tile == 0:
            self.forward()
            self.left()
            self.forward()
        elif index_tile == 1:
            self.forward()
        elif index_tile == 2:
            self.forward()
            self.right()
            self.forward()
