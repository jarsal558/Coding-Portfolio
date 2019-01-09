



#-------------------------------------------------------------------------------
# Name:        Rowan Zombie Text Adventure
# Purpose:
#
# Author:      Jared Salvatore
#
# Created:     22/02/2014
# Copyright:   (c) Jared Salvatore 2014
# Licence:     <your licence>
#-------------------------------------------------------------------------------

#def main():
#    pass

#Strength of Player
class Stats:
    def __inint__(self,power=0,toughness=0):
        self._power = power
        self._toughness = toughness
    def getPower(self):
        return self._power
    def getToughness(self):
        return self._toughness


class Range:
	def __init__(self, current = 0, min = 0, max = 10):
        #Store a min, max and value
		self._min = min
		self._current = current
		self._max = max

	def setMin(self, min):
      #  '''
       # Sets the min value, and makes sure it is less than max
      #  '''

		if min >= self._max:
			self._min = min - 1

	def getMin(self):
		return self._min

	def setMax(self, max):
		if max <= self._min:
			self._max = min + 1

	def getMax(self):
		return self._max

	def setCurrent(self, current):
		if current < self._min:
			self._current = self._min
		elif current > self._max:
			self._current = self._max
		else:
			self._current = current

	def getCurrent(self):
		return self._current

class Entity:
    def __init__(self, name):
        self.name = name

#Describes items that are found in inventory
class Item(Entity):
    def __init__(self, name, description, stats):
        self.description = description
        self.stats = stats

    def getDesctiption(self):
        return self.description

    def __str__(self):
        return "%s : %s Stats: %s" % (self.name, self.description, self.stats)

#Items/Way to combat Zombies
class ItemGenerator(Item):
    def  __init__(self, items):
        self.items = {none, stick, dagger, backpack, axe, denial}

        none = 'None', 'Unless you know fisticuffs, you are hosed!', Stats(0,0)
        stick = 'Stick', 'A plus-sized twig from outside. Batter UP!', Stats(1,1)
        dagger = 'Dagger', 'A sharp, double-edged knife', Stats(3,1),
        backpack = 'Backpack', 'A heavy knapsack filled with books', Stats(2,3)
        axe = 'Axe', 'A large, medieval weapon. Rusty, but Trusty.', Stats(6,3)
        denial = 'Denial', 'You do not exist, and you do not exist, and YOU do not exist', Stat(5,5)

    def getRandomItem(Item):
        rand_item = random.choice(items)
        return rand_item
    def getItem(itemName):
        return itemName

class Room(Entity):
    def __init__(self, name, description, zombies, connections, isSpawnPoint):
        self.description = description
        self.zombies = zombies
        self.connections = connections
        self.isSpawnPoint = isSpawnPoint

    def __str__(self):
        return "%s : %s : %s zombies : connected to %s rooms" % str(name), str(description), str(zombies), str(connections), str(isSpawnPoint)

#Player Stats
class Human(Entity):
    def __init__(self, name, power, toughness, hitpoints, locationName, items):
        self.power = power
        self.toughness = toughness
        self.hitpoints = hitpoints
        self.locationName = locationName
        self.items = items

    def getPower():
        return power

    def getToughness():
        return toughness

    def kill():
        hitpoints = 0

    def isAlive():
        return hitpoints > 0


    def __str__(self):
        return "Power: %s  Toughness: %s  Health: %s  Room: %s  Items: %s"


class Zombie(Human):
    pass

#Combat Manager between Zombie and Human Player
class BattleManager:
    def __init__(self, human, enemies):
        self.human = human
        self.enemies = enemies

    def battleLoop():
        prompt_flight = raw_input("Do you want to attack or flee?")
        if prompt_flight == "Charge!":
            while (enemies.hitpoints >= human.hitpoints):
                zombie.toughness - human.power

        if prompt_flight == 'Run':
            while (human.hitpoints > 0):
                print("Phew, that was close!")
                human.power - 1

        if prompt_flight == 'Suicide':
            print("Yoohoo, Zombies! Look, fresh meat!")
            quit()

        if prompt_flight == 'Stats':
            return human

#The Building Layout
class LayoutManager:

    class LayoutManager:
        def __init__(self, room):
            self.room = [Computer_Lab, Office, Hallway, Atrium, Kitchen, Auditorium]

    def createLayout(room):
        Computer_Lab = 'Computer Lab', 'A computer lab where students come to work.', zombies, Hallway, true
        Hallway = 'Hallway', 'a long hallway, with doors, and windows, and zombies.', zombies, (Computer_Lab,Office,Kitchen,Atrium,Auditorium), true
        Office = 'Office', 'an empty office, with a bunch of guys dragging themselves around. Just another Tuesday', zombies, Hallway, true
        Kitchen = 'Kitchen', 'a place for cookery', zombies, Hallway, false
        Atrium = 'Atrium', 'a large space with chairs and tables, and the occasional ficus.', zombies, (Hallway,Auditorium), false
        Auditorium = 'Auditorium', 'A wide stage area', zombies, seven, false

    def addOneWayConnection(roomFrom, roomTo):
         roomFrom = {Computer_Lab.connections.append(Hallway),
                    Atrium.connections.append(Auditorium)}
         roomTo = {Hallway.connections.append(Computer_Lab),
                Auditorium.connections.append(Atrium)}
    def addTwoWayConnection(roomFrom, roomTo):
        roomFrom = {Hallway.connections.append(Office),
                    Office.connections.append(Hallway),
                    Hallway.connections.append(Kitchen),
                    Kitchen.connections.append(Hallway),
                    Hallway.connections.append(Atrium),
                    Atrium.connections.append(Hallway),
                    Auditorium.connections.append(Atrium),
                    Atrium.connections.append(Auditorium),
                    Auditorium.connections.append(seven)}
        roomTo = {Hallway.connections.append(Office),
                    Office.connections.append(Hallway),
                    Hallway.connections.append(Kitchen),
                    Kitchen.connections.append(Hallway),
                    Hallway.connections.append(Atrium),
                    Atrium.connections.append(Hallway),
                    Auditorium.connections.append(Atrium),
                    Atrium.connections.append(Auditorium),
                    seven.connections.append(Auditorium)}

class GameManager:

    def __init__(layoutManager, player):
        self.layoutManager = layoutManageranager
        self.player = player

    while True:
        def __init__(layoutManager, player):
         self.layoutManager = layoutManager
        self.player = human

    def gameLoop():
        action = raw_input('What do you want to do?: Inspect, Explore, or Quit?' )

        if action == "Explore":
            newRoom = raw_input('Do you want to go out into the hallway?')
            if newRoom == "yes":
                    return room.connections.append(layoutManager)

        BattleManager()

        if action == "Inspect":
            itemFind = raw_input('You found something. You want keep it? ')
            if itemFind == "yes":
                     [stick.item.Lab,
                    dagger.item.Kitchen,
                    backpack.item.Atrium,
                    axe.item.Office]

            none.stats + item.stats

        if action == "Quit":
            quit()

#Main Menu: Start the Game or Quit the Game?
print "Menu\n"
print "(1)Start"
print "(2)Exit\n\n"
choice = (raw_input('>>'))
if choice=="1":
 #Asks Playerfor a Name
 person = raw_input('What is your name?: ')
 #Gives the name of the game and the goal before starting actual gameplay
 print('ZOMBIES HAVE INVADED! Well, not really, but when they do you must be')
 print('ready. So, here are some practice zombies for you to put back 6 feet')
 print('under. Do not hold back!')
gameLoop()
if choice=="2":
                     quit()

end
if __name__ == '__main__':
    main()
